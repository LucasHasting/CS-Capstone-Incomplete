class User {
private:
  string role;
  string username;
  string password;
  string email;
  DatabaseConnection connection;

public:
  string getRole();
  string getUsername();
  string getPassword();
  string getEmail();
  bool saveUser();
}
