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

/* method will select all users from a database and store it into a vector
   it will return an empty vector if an error occurrs */
std::vector<std::unique_ptr<User>> DatabaseConnection::select_all() {
  try {
    Wt::Dbo::Transaction transaction(session);

    // get all the users
    Wt::Dbo::collection<Wt::Dbo::ptr<User>> Users = session.find<User>();

    // create vector of smart pointers
    std::vector<std::unique_ptr<User>> userCollection;

    // convert dbo smart pointer to user smart pointer and append to the vector
    for (auto it = Users.begin(); it != Users.end(); ++it) {
      Wt::Dbo::ptr<User> user = *it;
      userCollection.push_back(CreateUserFromDB(user.modify()));
    }

    // return the vector
    return userCollection;
  } catch (Wt::Dbo::Exception e) {
    // return an empty vector
    return {};
  }
}

/* addRisk will return false if a risk cannot be added, and true if it is
 * successfully added */
bool DatabaseConnection::addRisk(std::unique_ptr<Risk> risk) {
  try {
    // check to see if the risk exists
    Wt::Dbo::Transaction transaction1(session);
    Wt::Dbo::ptr<Risk> r =
        session.find<Risk>().where("riskID = ?").bind(risk->getID());

    // used to throw an exception if no risk is found
    r.modify()->getID();

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


bool DatabaseConnection::editRisk(std::string id, std::string cd,
                                  std::string od, std::string note,
                                  std::string stat, std::string own,
                                  std::string ld, std::string sd, int lr,
                                  int ir) {
  try {
    Wt::Dbo::Transaction transaction(session);

    // check if risk exists
    Wt::Dbo::ptr<Risk> r = session.find<Risk>().where("riskID = ?").bind(id);

    // update the database with the edited risk if the risk does't exist
    // then an exception will be thrown
    r.modify()->setCloseDate(cd);
    r.modify()->setOpenDate(od);
    r.modify()->setNotes(note);
    r.modify()->setStatus(stat);
    r.modify()->setOwner(own);
    r.modify()->setLikelihoodRank(lr);
    r.modify()->setImpactRank(ir);
    r.modify()->setLongDescription(ld);
    r.modify()->setShortDescription(sd);

  } catch (Wt::Dbo::Exception e) {
    // something went wrong editing the risk
    std::cout << "Error editing risk: " << e.what() << std::endl;
    return false;
  }

  return true;
}
