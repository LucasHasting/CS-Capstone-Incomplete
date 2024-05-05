#include "DatabaseConnection.h"
#include "User.h"
#include <iostream>

int main() {
  DatabaseConnection connection;
  std::unique_ptr<User> user =
      std::make_unique<User>("Admin", "Admin", "root", "admin@una.edu");
  std::unique_ptr<User> user3 =
      std::make_unique<User>("Track", "Track", "roout", "track@una.edu");
  std::unique_ptr<User> user4 =
      std::make_unique<User>("Track", "Admin", "tooor", "track@una.edu");
  std::unique_ptr<User> user5 =
      std::make_unique<User>("Track", "Ad", "root", "track@una.edu");

  connection.addUser(std::move(user));
  connection.addUser(std::move(user3));
  connection.addUser(std::move(user4));
  connection.addUser(std::move(user5));

  if (user4 == nullptr)
    std::cout << "passed" << std::endl;
  if (user5 == nullptr)
    std::cout << "passed" << std::endl;

  std::unique_ptr<User> user2 = std::make_unique<User>();
  user2 = connection.authenticateUser("Admin", "root");
  std::cout << "Authentication Finished" << std::endl;
  if (user2 == nullptr)
    std::cout << "nullptr" << std::endl;
  else
    std::cout << user2->getRole() << std::endl;

  std::vector<std::unique_ptr<User>> users = connection.select_all();

  for (auto it = users.begin(); it != users.end(); ++it) {
    std::cout << "NAME: " << (*it)->getUsername()
              << "\t Password: " << (*it)->getPassword() << std::endl;
  }
  return 0;
}
