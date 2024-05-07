#include "deleteUser.h"
#include "../model/DatabaseConnection.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

deleteUser::deleteUser(WContainerWidget *parent) : WContainerWidget() {
  WApplication::instance()->useStyleSheet("view/table.css");

  auto container = addWidget(make_unique<WContainerWidget>());

  auto userID = container->addWidget(make_unique<WLineEdit>());
  userID->setPlaceholderText("Usernames");
  username = userID;

  container->addWidget(make_unique<WBreak>());

  auto edit =
      container->addNew<WText>("Are you Sure you want to delete this user?");

  auto container1 = container->addWidget(make_unique<WContainerWidget>());
  // auto submit1 = container1->addWidget(make_unique<WPushButton>("cancel"));

  auto submit2 = container1->addWidget(make_unique<WPushButton>("delete"));

  container->setStyleClass("deleteBackground");
  userID->setStyleClass("IDu");
  // submit1->setStyleClass("sub1");
  submit2->setStyleClass("sub2");
  container1->setStyleClass("container1");
  submit2->clicked().connect(this, &deleteUser::Submit);
}

void deleteUser::Submit() { connection.removeUser(username->text().narrow()); }
