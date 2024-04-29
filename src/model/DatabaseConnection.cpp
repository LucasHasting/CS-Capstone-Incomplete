#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/MySQL.h>
#include <Wt/Dbo/Exception.h>
#include "DatabaseConnection.h"
#include "User.h"

DatabaseConnection::DatabaseConnection(){
    connection = new Wt::Dbo::backend::MySQL("SRT_DB", "risk", 
    "niuco9Aish", "localhost", 3306, "/var/run/mysql/mysql.sock");
    
    session.setConnection(connection->clone()); 
    session.mapClass<User>("user");
    
    try{
        session.createTables();
    } catch (Wt::Dbo::Exception e) {

    }
}

bool DatabaseConnection::addUser(std::unique_ptr<User> user){
    try{
        Wt::Dbo::Transaction transaction1(session);
        Wt::Dbo::ptr<User> u = session.find<User>().where("username = ?").bind(user->getUsername());

        //only seems to work with this line so it stays until I figure out why 
        std::cout << "TEST" << u.modify()->getUsername() << std::endl;

        return false;
   } catch (Wt::Dbo::Exception e) { 
        try{
            Wt::Dbo::Transaction transaction2(session);
            session.add(std::move(user));
            connection->commitTransaction();
        } catch (Wt::Dbo::Exception e) { 
            std::cout << "error adding user" << std::endl;
            return false;
        }
   }

    return true;
}

std::unique_ptr<User> DatabaseConnection::authenticateUser(std::string username, std::string password){
    try {
        Wt::Dbo::Transaction transaction(session);
        Wt::Dbo::ptr<User> user = session.find<User>().where("username = ?").bind(username);
        Wt::Dbo::ptr<User> pass = session.find<User>().where("password = ?").bind(password);
    if(*user.modify() == *pass.modify())
        return CreateUserFromDB(user.modify());
    else
        return nullptr;
    } catch (Wt::Dbo::Exception e) {
        return nullptr;
    }
}

std::unique_ptr<User> DatabaseConnection::CreateUserFromDB(Wt::Dbo::ptr<User>::mutator u){
    return make_unique<User>(u->getRole(), u->getUsername(), u->getPassword(), u->getEmail());
}
