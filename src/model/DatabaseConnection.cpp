#include "DatabaseConnection.h"
#include "Risk.h"
#include "User.h"
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Exception.h>
#include <Wt/Dbo/backend/MySQL.h>

/* Constructor initializes the connection to the database */
DatabaseConnection::DatabaseConnection() {
  // get the connection to the database
  connection =
      new Wt::Dbo::backend::MySQL("SRT_DB", "risk", "niuco9Aish", "localhost",
                                  3306, "/var/run/mysql/mysql.sock");

  // set the connection to the current session
  session.setConnection(connection->clone());

  // mapt the User class to the user table in the database
  session.mapClass<User>("user");

  // if the table does not exist make it
  try {
    session.createTables();
  } catch (Wt::Dbo::Exception e) {
  }
}

/* addUser will return false if a user cannot be added, and true if it is
 * successfully added */
bool DatabaseConnection::addUser(std::unique_ptr<User> user) {
  try {
    // check to see if the user exists
    Wt::Dbo::Transaction transaction1(session);
    Wt::Dbo::ptr<User> u =
        session.find<User>().where("username = ?").bind(user->getUsername());

    // used to throw an exception if no user is found
    u.modify()->getUsername();

    return false;
  } catch (Wt::Dbo::Exception e) {
    try {
      // add the user
      Wt::Dbo::Transaction transaction2(session);
      session.add(std::move(user));
    } catch (Wt::Dbo::Exception e) {
      // something went wrong adding the user
      std::cout << "error adding user" << std::endl;
      return false;
    }
  }

  return true;
}

/* authenticateUser takes in a username and password, if authentication is
 * successful it will return a User smart pointer, otherwise it will be nullptr
 */
std::unique_ptr<User>
DatabaseConnection::authenticateUser(std::string username,
                                     std::string password) {
  try {
    // check to see if the username and password exists
    Wt::Dbo::Transaction transaction(session);
    Wt::Dbo::ptr<User> user =
        session.find<User>().where("username = ?").bind(username);
    Wt::Dbo::ptr<User> pass =
        session.find<User>().where("password = ?").bind(password);

    // check to see if the users are the same person
    if (*user.modify() == *pass.modify())
      return CreateUserFromDB(user.modify());
    else
      return nullptr;
  } catch (Wt::Dbo::Exception e) {
    return nullptr;
  }
}

/* method used to convert a User dbo smart pointer to a User smart pointer */
std::unique_ptr<User>
DatabaseConnection::CreateUserFromDB(Wt::Dbo::ptr<User>::mutator u) {
  return make_unique<User>(u->getRole(), u->getUsername(), u->getPassword(),
                           u->getEmail());
}

/* addRisk will return false if a risk cannot be added, and true if it is
 * successfully added */
bool DatabaseConnection::addRisk(std::unique_ptr<Risk> risk) {
  try {
    // check to see if the risk exists
    Wt::Dbo::Transaction transaction1(session);
    Wt::Dbo::ptr<Risk> r =
        session.find<Risk>().where("riskID = ?").bind(risk->validateID());

    // used to throw an exception if no risk is found
    r.modify()->validateID();

    return false;
  } catch (Wt::Dbo::Exception e) {
    try {
      // add the risk
      Wt::Dbo::Transaction transaction2(session);
      session.add(std::move(risk));
    } catch (Wt::Dbo::Exception e) {
      // something went wrong adding the risk
      std::cout << "error adding risk" << std::endl;
      return false;
    }
  }

  return true;
}
