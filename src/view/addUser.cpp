#include "addUser.h"
#include "../model/DatabaseConnection.h"
#include "../model/User.h"
#include "forgetView.h"
#include "navbar.h"
#include "verifyEmail.h"
/*
        #include "admin.h"
*/
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLabel.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLink.h>
#include <Wt/WMessageBox.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

addUser::addUser(WContainerWidget *parent) : WContainerWidget() {

  WApplication::instance()->useStyleSheet("view/table.css");

  // WApplication::instance()->internalPathChanged().connect(this,
  // &addUser::onInternalPathChange);

  container = addWidget(make_unique<WContainerWidget>());
  container->setStyleClass("add-background");

  Role();
  UserName();
  Email();
  Password();
}

void addUser::Submit() {
  unique_ptr<User> user =
      make_unique<User>(role->currentText().narrow(), userName->text().narrow(),
                        password->text().narrow(), email->text().narrow());
  connection.addUser(move(user));
}

/*
void addUser::onInternalPathChange()
{

        if(WApplication::instance()->internalPath() == "/loginpage")
        {
                showAdmin();
        }
        else {
                showAdmin();
        }


}

void addUser::subMenu()
{
        auto card = container->addWidget(make_unique<WContainerWidget>());
        auto headcon = card->addWidget(make_unique<WContainerWidget>());

        auto header = headcon->addWidget(make_unique<WText>("Add User"));
        card->addWidget(make_unique<WBreak>());


        auto subMenu = container->addWidget(make_unique<Wt::WPopupMenu>());
        subMenu->addItem("Add User")->triggered().connect([=] {
                        auto messageBox =
subMenu->addChild(make_unique<Wt::WMessageBox>("Role",
Wt::WString::fromUTF8("Role"), Wt::Icon::Information, Wt::StandardButton::Ok));
        messageBox->show();
        messageBox->buttonClicked().connect([=] {
                        subMenu->removeChild(messageBox);
                        });
        });

        //card->setStyleClass("Add User");
        //headcon->setStyleClass("loginHead");


}
*/
void addUser::Role() {

  auto card = container->addWidget(make_unique<WContainerWidget>());
  auto headcon = card->addWidget(make_unique<WContainerWidget>());

  //	auto header = headcon->addWidget(make_unique<WText>("Add User"));
  //	card->addWidget(make_unique<WBreak>());

  auto rbox = container->addWidget(make_unique<Wt::WContainerWidget>());
  auto cbRole = rbox->addWidget(make_unique<Wt::WComboBox>());
  cbRole->addItem("Audit");
  cbRole->addItem("Track");
  cbRole->addItem("Admin");

  rbox->setStyleClass("addrbox");
  cbRole->setStyleClass("addrole");
  this->role = cbRole;
}

void addUser::UserName() {
  auto card = container->addWidget(make_unique<WContainerWidget>());
  auto UserName = card->addWidget(make_unique<WLabel>("User Name"));
  card->addWidget(make_unique<WBreak>());
  auto user_edit_ = card->addWidget(make_unique<WLineEdit>());

  UserName->setBuddy(user_edit_);
  card->addWidget(make_unique<WBreak>());

  user_edit_->blurred().connect([=] {
    if (user_edit_->text().empty())
      user_edit_->setText("username");
  });

  user_edit_->focussed().connect([=] {
    if (user_edit_->text() == "username")
      user_edit_->setText("");
  });

  // card->setStyleClass("loginHead");
  UserName->setStyleClass("nameMsg");
  user_edit_->setStyleClass("userEdits");
  this->userName = user_edit_;
}

void addUser::Password() {
  auto card = container->addWidget(make_unique<WContainerWidget>());
  auto Password = card->addWidget(make_unique<WLabel>("Password"));
  card->addWidget(make_unique<WBreak>());
  auto pass_edit_ = card->addWidget(make_unique<WLineEdit>());

  Password->setBuddy(pass_edit_);

  pass_edit_->setEchoMode(Wt::EchoMode::Password);

  card->addWidget(make_unique<WBreak>());

  pass_edit_->blurred().connect([=] {
    if (pass_edit_->text().empty())
      pass_edit_->setText("password");
  });

  pass_edit_->focussed().connect([=] {
    if (pass_edit_->text() == "password")
      pass_edit_->setText("");
  });

  Password->setStyleClass("passwordUser");
  pass_edit_->setStyleClass("passEdits");
  this->password = pass_edit_;

  auto submit = card->addWidget(make_unique<WPushButton>("Submit"));
  submit->setLink(WLink(LinkType::InternalPath, "loginpage"));
  submit->setStyleClass("buttoni");
  submit->clicked().connect(this, &addUser::Submit);
}

void addUser::Email() {
  auto card = container->addWidget(make_unique<WContainerWidget>());
  auto Email = card->addWidget(make_unique<WLabel>("Email"));
  card->addWidget(make_unique<WBreak>());
  auto email_edit_ = card->addWidget(make_unique<WLineEdit>());

  Email->setBuddy(email_edit_);

  card->addWidget(make_unique<WBreak>());

  email_edit_->blurred().connect([=] {
    if (email_edit_->text().empty())
      email_edit_->setText("email");
  });

  email_edit_->focussed().connect([=] {
    if (email_edit_->text() == "email")
      email_edit_->setText("");
  });

  Email->setStyleClass("userEmail");
  email_edit_->setStyleClass("emailEdits");

  // auto submit = card->addWidget(make_unique<Wt::WPushButton>("Submit"));
  // submit->setLink(WLink(LinkType::InternalPath, "loginpage"));
  this->email = email_edit_;
  // submit->clicked().connect(this, &addUser::Submit);
}
