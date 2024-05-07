#include "User.h"
#include "Risk.h"
#include <Wt/Auth/HashFunction.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/MySQL.h>

#ifndef DBC
#define DBC

class DatabaseConnection {
private:
  Wt::Dbo::backend::MySQL *connection;
  Wt::Dbo::Session session;
  Wt::Auth::BCryptHashFunction hashFunction;

public:
  DatabaseConnection();
  bool addUser(std::unique_ptr<User>);
  bool removeUser(std::string);
  std::unique_ptr<User> authenticateUser(std::string, std::string);
  std::unique_ptr<User> CreateUserFromDB(Wt::Dbo::ptr<User>::mutator, bool, std::string);
  std::unique_ptr<Risk> CreateRiskFromDB(Wt::Dbo::ptr<Risk>::mutator);
  std::vector<std::unique_ptr<User>> selectAllUser();
  std::vector<std::unique_ptr<Risk>> selectAllRisk();
  int riskPriority(std::string);
  bool addRisk(std::unique_ptr<Risk>);
  bool editRisk(std::string, std::string, std::string, std::string, std::string,
                std::string, std::string, std::string, int, int);
};

#endif
