#include <iostream>
#include "DatabaseConnection.h"
#include "User.h"

int main(){
    DatabaseConnection connection;
    std::unique_ptr<User> user = std::make_unique<User>("Admin", "Admin", "root", "admin@una.edu");
    connection.addUser(std::move(user));
    std::unique_ptr<User> user2 = std::make_unique<User>();
    user2 = connection.authenticateUser("Admin", "root");
    std::cout << "Authentication Finished" << std::endl;
    if(user2 == nullptr)
        std::cout << "nullptr" << std::endl;
    else
        std::cout << user2->getRole() << std::endl;
    return 0;
}

