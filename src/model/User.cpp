#include "User.h"
#include <string>

User::User() {
  role = "";
  username = "";
  password = "";
  email = "";
}

User::User(std::string role, std::string username, std::string password,
           std::string email) {
  this->role = role;
  this->username = username;
  this->password = password;
  this->email = email;
}

/*
 * getRole() is a function that returns a string representing the role assigned
 * to the user by the admin.
 */
std::string User::getRole() { return role; }

/*
 * getUsername() is a function that returns a string representing the username
 * associated with the user account which is accessing the system.
 */
std::string User::getUsername() { return username; }

/*
 * getPassword() is a function that returns a string representing the password
 * associated with the specific user account.
 */
std::string User::getPassword() { return password; }

/*
 * getEmail() is a function that returns a string representing the the email
 * address associated with the user account.
 */
std::string User::getEmail() { return email; }

void User::setPassword(std::string pass) { password = pass; }

bool User::operator==(User user) {
  return (password == user.getPassword() && username == user.getUsername());
}
