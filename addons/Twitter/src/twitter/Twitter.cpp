#include <twitter/Twitter.h>

// TWITTER
// -------
Twitter::Twitter() 
  :request_token_received_callback(NULL)
  ,request_token_received_callback_data(NULL)
  ,access_token_received_callback(NULL)
  ,access_token_received_callback_data(NULL)
  ,ssl_ctx(NULL)
{
}

Twitter::~Twitter() {
}

void Twitter::setConsumer(const char* k) {
  auth.setConsumerKey(k);
}

void Twitter::setConsumerSecret(const char* s) {
  auth.setConsumerSecret(s);
}

void Twitter::setToken(const char* t) {
  auth.setToken(t);
}

void Twitter::setTokenSecret(const char* s) {
  auth.setTokenSecret(s);
}

bool Twitter::hasConsumerKeyAndSecret() {
  if(!auth.hasConsumerKey() || !auth.hasConsumerSecret()) {
    printf("ERROR: set consumer key and secret first\n");
    return false;
  }
  return true;
}

void Twitter::requestToken(cb_request_token_received receivedCB, void* receivedData) { 
  if(!hasConsumerKeyAndSecret()) {
    return;
  }
  request_token_received_callback = receivedCB;
  request_token_received_callback_data = receivedData;

  auth.setCallback("oob");

  HTTPRequest req;
  req.setURL(HTTPURL("http", "api.twitter.com", "/oauth/request_token"));
  req.addHeader(HTTPHeader("User-Agent", "twitter-client"));
  req.setMethod(REQUEST_POST);
  auth.addAuthorizationHeadersToRequest(req);

  HTTPConnection* c = http.sendRequest(req, Twitter::requestTokenCallback, this, NULL, NULL);
}

void Twitter::requestTokenCallback(const char* data, size_t len, void* twitter) {
  Twitter* t = static_cast<Twitter*>(twitter);
  std::string body(data, len);
  HTTPParameters parameters;
  size_t found = parameters.createFromVariableString(body);
  if(found > 0
     && parameters.exist("oauth_token") 
     && parameters.exist("oauth_token_secret") 
     && parameters.exist("oauth_callback_confirmed")) 
    {
      if(t->request_token_received_callback) {
        std::string redirect_url = "https://api.twitter.com/oauth/authenticate?oauth_token=" +parameters["oauth_token"].value;
        t->request_token_received_callback(
                                        parameters["oauth_token"].value
                                        ,parameters["oauth_token_secret"].value
                                        ,redirect_url
                                        ,t->request_token_received_callback_data
                                        );
      }
    }
  else {
    printf("ERROR: Unhandled. We did not find any variables in response from twitter..\n");
  }
}

void Twitter::exchangeRequestTokenForAccessToken(
                                                 std::string requestToken
                                                 ,std::string verifier
                                                 ,cb_access_token_received accessCB
                                                 ,void* accessData
                                                 )
{

  if(!hasConsumerKeyAndSecret()) {
    return;
  }
  access_token_received_callback = accessCB;
  access_token_received_callback_data = accessData;
  
  auth.reset();

  HTTPRequest req;
  req.setURL(HTTPURL("http", "api.twitter.com", "/oauth/access_token"));
  req.addContentParameter(HTTPParameter("oauth_verifier", verifier));
  req.setMethod(REQUEST_POST);
  req.addHeader(HTTPHeader("User-Agent", "twitter-client"));

  auth.setToken(requestToken);
  auth.addAuthorizationHeadersToRequest(req);
  HTTPConnection* c = http.sendRequest(req, Twitter::exchangeRequestTokenForAccessTokenCallback, this, NULL, NULL);
}

void Twitter::exchangeRequestTokenForAccessTokenCallback(const char* data, size_t len, void* twitter) {
  std::copy(data, data+len, std::ostream_iterator<char>(std::cout, ""));
  Twitter* t = static_cast<Twitter*>(twitter);
  std::string body(data, len);
  HTTPParameters p;
  size_t found = p.createFromVariableString(body);
  if(found > 0
     && p.exist("oauth_token")
     && p.exist("oauth_token_secret")
     && p.exist("user_id")
     && p.exist("screen_name"))
    {
      if(t->access_token_received_callback) {
        TwitterTokenInfo info;
        info.oauth_token = p["oauth_token"].value;
        info.oauth_token_secret = p["oauth_token_secret"].value;
        info.user_id = p["user_id"].value;
        info.screen_name = p["screen_name"].value;
        t->access_token_received_callback(info, t->access_token_received_callback_data);
      }
  }
}

void Twitter::makeAPICall(TwitterCallParams& p) {
  int test = 0; // 0 = no test, 1 = secure test, 2 = test with gist server, 3 = normal http test
  auth.reset(); // makes new nonce/timestamp
  HTTPRequest req;

  if(test == 0) {
    req.setURL(HTTPURL((p.secure) ? "https" : "http", p.host, p.endpoint));
    req.setMethod(REQUEST_POST);
  } 
  else if(test == 1) {
    //secure = true;
    p.secure = true;
    req.setURL(HTTPURL("https", "test.localhost", "/chunked.php"));
    req.setMethod(REQUEST_GET);
  }
  else if(test == 2) {
    p.secure = true;
    req.setURL(HTTPURL("https", "gist.github.com", "/"));
    req.setMethod(REQUEST_GET);
  }
  else if(test == 3) {
    p.secure = false;
    req.setURL(HTTPURL("http", "test.localhost", "/stream2.html"));
    req.setMethod(REQUEST_GET);
  }
   
  req.addHeader(HTTPHeader("User-Agent", "twitter-client/1.0"));
  req.addHeader(HTTPHeader("Accept", "*/*"));
  req.copyContentParameters(p.params);
  req.setVersion(HTTP11);
  auth.addAuthorizationHeadersToRequest(req);
  HTTPConnection* c = NULL;

  if(p.secure) {
    c = http.sendSecureRequest(ssl_ctx, req, p.cb, p.data, NULL, NULL);
  }
  else {
    c = http.sendRequest(req, p.cb, p.data, NULL, NULL);
  }
  if(c == NULL) {
    printf("ERROR: send(Secure)Request does not return a valid HTTPConnection.\n");
    return;
  }
}

void Twitter::update() {
  http.update();
}

void Twitter::setSSLContext(SSL_CTX* ctx) {
  ssl_ctx = ctx;
}

// API SPECIFIC PARAMETER TYPES
// ----------------------------
TwitterStatusesFilter::TwitterStatusesFilter(const std::string& track) {
  this->track.push_back(track);
}

std::string TwitterStatusesFilter::getCommaSeparatedTrackList() const {
  return join(track, ",");
}

// API IMPLEMENTATION
// -----------------------------------------------------------------
void Twitter::apiStatusesUpdate(const TwitterStatusesUpdate& param, cb_request_read_body bodyCB, void* bodyData) {
  HTTPParameters p;
  p.add("status", param.status);

  TwitterCallParams cp;
  cp.endpoint = "/1.1/statuses/update.json";
  cp.host = "api.twitter.com";
  cp.secure = false;
  cp.params = p;
  cp.cb = bodyCB;
  cp.data = bodyData;
  makeAPICall(cp);
}

void Twitter::apiStatusesFilter(const TwitterStatusesFilter& param, cb_request_read_body bodyCB, void* bodyData) {
  HTTPParameters p;
  p.add("track", param.getCommaSeparatedTrackList());

  TwitterCallParams cp;
  cp.endpoint = "/1.1/statuses/filter.json";
  cp.host = "stream.twitter.com";
  cp.secure = true;
  cp.cb = bodyCB;
  cp.data = bodyData;
  cp.params = p;
  makeAPICall(cp);
}
