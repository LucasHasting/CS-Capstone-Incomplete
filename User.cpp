#include "User.h"
#include "DatabaseConnection.h"

/*
 * getRole() is a function that returns a string representing the role assigned
 * to the user by the admin.
 */
string User::getRole() { return role; }

/*
 * getUsername() is a function that returns a string representing the username
 * associated with the user account which is accessing the system.
 */
string User::getUsername() { return username; }

/*
 * getPassword() is a function that returns a string representing the password
 * associated with the specific user account.
 */
string User::getPassword() { return password; }

/*
 * getEmail() is a function that returns a string representing the the email
 * address associated with the user account.
 */
string User::getEmail() { return email; }

/*
 * saveUser() is a function that saves the user date into the database using
 * the DatabaseConnection class.
 */
bool User::saveUser() {
  // Check to see if data could be successfully saved.
  //  !! This connection will need to be updated !!
  if (connection.makeQuery())
    return true;

  return false;
}
