/* 

   # ClientIPC

   This class is used as the client side for pipe based inter process communication (IPC). 
   The `ServerIPC` and `ClientIPC` classes allow you to create a safe and super fast communication
   system between multiple processes.

   Make sure to call `update()` often.

*/
#ifndef ROXLU_CLIENT_IPC_H
#define ROXLU_CLIENT_IPC_H

extern "C" {
#  include <uv.h>
};

#include <roxlu/core/Log.h>
#include <roxlu/core/Utils.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class ClientIPC;
typedef void(*client_ipc_on_connected_cb)(ClientIPC* ipc, void* user);
typedef void(*client_ipc_on_read_cb)(ClientIPC* ipc, char* buf, size_t nbytes, void* user);

void client_ipc_on_connect(uv_connect_t* req, int status);
void client_ipc_on_read(uv_stream_t* handle, ssize_t nbytes, uv_buf_t buf);
void client_ipc_on_write(uv_write_t* req, int status);
void client_ipc_on_shutdown(uv_shutdown_t* req, int status);
void client_ipc_on_close(uv_handle_t* handle);
uv_buf_t client_ipc_on_alloc(uv_handle_t* handle, size_t nbytes);

class ClientIPC {
 public:
  ClientIPC();
  ~ClientIPC();
  bool setup(std::string sockfile, bool datapath,
             client_ipc_on_connected_cb conCB = NULL,  
             client_ipc_on_read_cb readCB = NULL, 
             void* user = NULL);
  void update();
  void write(char* data, size_t nbytes);
  void write(const char* data, size_t nbytes);
 public:
  uv_loop_t* loop;
  uv_pipe_t pipe;
  uv_connect_t connect_req;
  uv_shutdown_t shutdown_req;
  client_ipc_on_connected_cb cb_con;
  client_ipc_on_read_cb cb_read;
  void* cb_user;
};

inline void ClientIPC::write(const char* data, size_t nbytes) {
  write((char*)data, nbytes);
}

#endif