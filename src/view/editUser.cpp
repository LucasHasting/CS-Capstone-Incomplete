#include "editUser.h"
#include "../model/DatabaseConnection.h"
#include "../model/User.h"
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

using namespace std;
using namespace Wt;

EditUser ::EditUser(WContainerWidget *parent) : WContainerWidget() {

  container = addWidget(make_unique<WContainerWidget>());

  auto app = WApplication::instance();
  app->useStyleSheet("view/table.css");

  auto card = container->addWidget(make_unique<WContainerWidget>());

  oldUserName = card->addWidget(make_unique<WLineEdit>());
  oldUserName->setPlaceholderText("Old Username");
  card->addWidget(make_unique<WBreak>());

  newUserName = card->addWidget(make_unique<WLineEdit>());
  newUserName->setPlaceholderText("New Username");

  card->addWidget(make_unique<WBreak>());
  role = card->addWidget(make_unique<WComboBox>());
  role->setPlaceholderText("Status");
  role->addItem("Audit");
  role->addItem("Track");
  role->addItem("Admin");

  card->addWidget(make_unique<WBreak>());
  email = card->addWidget(make_unique<WLineEdit>());
  email->setPlaceholderText("Email");

  card->addWidget(make_unique<WBreak>());
  card->addWidget(make_unique<WBreak>());
  password = card->addWidget(make_unique<WLineEdit>());
  password->setPlaceholderText("Password");
  password->setEchoMode(Wt::EchoMode::Password);

  card->addWidget(make_unique<WBreak>());
  auto submit = card->addWidget(make_unique<WPushButton>("Update"));
  submit->clicked().connect(this, &EditUser::Submit);

  card->setStyleClass("card-container");
  oldUserName->setStyleClass("riskid");
  newUserName->setStyleClass("username");
  role->setStyleClass("role");
  email->setStyleClass("emails");
  password->setStyleClass("passwordss");
  submit->setStyleClass("subButton");
}

void EditUser::Submit() {
  unique_ptr<User> user = make_unique<User>(
      role->currentText().narrow(), newUserName->text().narrow(),
      password->text().narrow(), email->text().narrow());
  connection.removeUser(oldUserName->text().narrow());
  connection.addUser(move(user));
}
