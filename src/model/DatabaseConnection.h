#include "Risk.h"
#include "User.h"
#include <Wt/Auth/HashFunction.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/MySQL.h>

#ifndef DBC
#define DBC

class DatabaseConnection {
private:
  Wt::Dbo::backend::MySQL *connection;
  Wt::Dbo::Session session;
  Wt::Auth::MD5HashFunction hashFunction;

public:
  DatabaseConnection();
  bool addUser(std::unique_ptr<User>);
  std::unique_ptr<User> authenticateUser(std::string, std::string);
  std::unique_ptr<User> CreateUserFromDB(Wt::Dbo::ptr<User>::mutator);
  std::vector<std::unique_ptr<User>> select_all();
  bool addRisk(std::unique_ptr<Risk>);
  bool editRisk(std::string, std::string, std::string, std::string, std::string,
                std::string, std::string, std::string, int, int);
};

#endif
