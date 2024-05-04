#include <Wt/Dbo/Dbo.h>
#include <string>
#ifndef USER_H
#define USER_H

class User {
private:
  std::string role;
  std::string username;
  std::string password;
  std::string email;

public:
  User();
  User(std::string, std::string, std::string, std::string);
  std::string getRole();
  std::string getUsername();
  std::string getPassword();
  std::string getEmail();
  void setPassword(std::string);
  bool saveUser();
  bool operator==(User);
  template <class Action> void persist(Action &a) {
    Wt::Dbo::field(a, role, "role");
    Wt::Dbo::field(a, username, "username");
    Wt::Dbo::field(a, password, "password");
    Wt::Dbo::field(a, email, "email");
  }
};

#endif
