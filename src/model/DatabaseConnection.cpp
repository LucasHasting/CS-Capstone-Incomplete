#include "DatabaseConnection.h"
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
  bool throw_exception = false;
  try {
    Wt::Dbo::Transaction transaction1(session);

    // account for duplicate usernames, passwords, and emails
    try {
      Wt::Dbo::Transaction transaction1(session);
      session.find<User>().where("username = ?").bind(user->getUsername());
    } catch (Wt::Dbo::Exception e) {
      throw_exception = true;
    }

    try {
      Wt::Dbo::Transaction transaction1(session);
      session.find<User>().where("password = ?").bind(user->getPassword());
    } catch (Wt::Dbo::Exception e) {
      throw_exception = true;
    }

    try {
      Wt::Dbo::Transaction transaction1(session);
      session.find<User>().where("email = ?").bind(user->getEmail());
    } catch (Wt::Dbo::Exception e) {
      throw_exception = true;
    }

    if (throw_exception)
      throw Wt::Dbo::Exception("Too many users with the same credentials");

    // check to see if the username, password, or email exists
    Wt::Dbo::ptr<User> u =
        session.find<User>().where("username = ?").bind(user->getUsername());
    Wt::Dbo::ptr<User> p =
        session.find<User>().where("password = ?").bind(user->getPassword());
    Wt::Dbo::ptr<User> e =
        session.find<User>().where("email = ?").bind(user->getEmail());

    // check to see if every filed is empty
    int throw_exception_sum = 0;

    try {
      u.modify()->getUsername();
    } catch (Wt::Dbo::Exception e) {
      ++throw_exception_sum;
    }

    try {
      p.modify()->getPassword();
    } catch (Wt::Dbo::Exception e) {
      ++throw_exception_sum;
    }

    try {
      e.modify()->getEmail();
    } catch (Wt::Dbo::Exception e) {
      ++throw_exception_sum;
    }

    // throw an exception to add a user
    if (throw_exception_sum == 3)
      throw Wt::Dbo::Exception("A User can be added");

    // a user cannot be added
    return false;
  } catch (Wt::Dbo::Exception e) {
    try {
      // hash the password before adding the user
      std::string plain_text = user->getPassword();
      user->setPassword(hashFunction.compute(plain_text, "ABC"));

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

/*
editUser
*/
bool DatabaseConnection::editUser(std::string username, std::unique_ptr<User> updatedUser ){
  try{
    Wt::Dbo::Transaction transaction(session);
    Wt::Dbo::ptr<User> user = session.find<User>().where("username = ?").bind(username);

    user.modify()->setRole(updatedUser->getRole());
    user.modify()->setUsername(updatedUser->getUsername());
    user.modify()->setPassword(updatedUser->getPassword());
    user.modify()->setEmail(updatedUser->getEmail());

    return true;

  } catch (Wt::Dbo::Exception e){
    return false;
  }
}


/*
removeUser
*/
bool DatabaseConnection::removeUser(std::string username){
  try{
    Wt::Dbo::Transaction transaction(session);
    Wt::Dbo::ptr<User> user == session.find<User>().where("username = ?").bind(username);

    session.remove(user);
    
    return true;
  } catch (Wt::Dbo::Exception e){
    return false;
  }
}


/* authenticateUser takes in a username and password, if authentication is
 * successful it will return a User smart pointer, otherwise it will be
 * nullptr
 */
std::unique_ptr<User>
DatabaseConnection::authenticateUser(std::string username,
                                     std::string password) {
  try {
    std::string plain_text = password;
    password = hashFunction.compute(plain_text, "ABC");

    // check to see if the username and password exists
    Wt::Dbo::Transaction transaction(session);
    Wt::Dbo::ptr<User> user =
        session.find<User>().where("username = ?").bind(username);
    Wt::Dbo::ptr<User> pass =
        session.find<User>().where("password = ?").bind(password);

    // check to see if the users are the same person
    if (*user.modify() == *pass.modify())
      return CreateUserFromDB(user.modify(), true, plain_text);
    else
      return nullptr;
  } catch (Wt::Dbo::Exception e) {
    return nullptr;
  }
}

/* method used to convert a User dbo smart pointer to a User smart pointer
 */
std::unique_ptr<User>
DatabaseConnection::CreateUserFromDB(Wt::Dbo::ptr<User>::mutator u,
                                     bool plain = false,
                                     std::string plain_text = "") {

  // get the password
  std::string password = u->getPassword();

  // if the password is in plain text, change it
  if (plain) {
    password = plain_text;
  }

  // return the smart pointer
  return make_unique<User>(u->getRole(), u->getUsername(), password,
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
