#include <iostream>
#include <sqlite/Database.h>
#include <roxlu/Roxlu.h>

int main() {
  printf("SQLite example.\n");
  roxlu::Database db;
  
  // open a database + create a table.
  db.open("test.db");
  db.query("CREATE TABLE IF NOT EXISTS tweets (" \
           "id INTEGER PRIMARY KEY AUTOINCREMENT, " \
           "name TEXT, " \
           "score INTEGER);");

  // insert data
  int num = 10;
  for(int i = 0; i < num; ++i) {
    char name[512];
    sprintf(name, "User-%03d", i);
    db.insert("tweets")
      .use("name",name)
      .use("score", i)
      .execute();
  }
  

  // Retrieve data
  roxlu::QueryResult result(db);
  db.select("id,name,score")
    .from("tweets")
    .execute(result);

  if(result.isOK()) {
    while(result.next()) {
      printf("Name: %s, Score: %lld, ID: %lld\n", result.getString(1).c_str(), result.getInt(2), result.getInt(0));
    }
  }

  // Update some data..
  return 1;
};