#include "setRiskId.h"

#include "../model/DatabaseConnection.h"
#include "../model/Risk.h"
#include "../model/User.h"
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;

SetRiskId ::SetRiskId(WContainerWidget *parent) : WContainerWidget() {

  addWidget(make_unique<WText>("Text is working"));
  container = addWidget(make_unique<WContainerWidget>());

  auto app = WApplication::instance();
  app->useStyleSheet("view/riskId.css");

  container->setStyleClass("contain");

  auto riskId = container->addWidget(make_unique<WContainerWidget>());

  riskId->setStyleClass("riskid");

  auto navi = riskId->addWidget(make_unique<WContainerWidget>());
  auto txti = navi->addWidget(make_unique<WText>(" Register Yourself"));

  riskId->addWidget(make_unique<WBreak>());
  navi->setStyleClass("navi");

  auto editContainer = riskId->addWidget(make_unique<WContainerWidget>());
  editContainer->setStyleClass("editConti");

  auto userN = editContainer->addWidget(make_unique<WContainerWidget>());
  userN->setStyleClass("userN");
  // User Name
  auto userLabel = userN->addWidget(make_unique<WText>("Enter Username"));
  userN->addWidget(make_unique<WBreak>());
  auto userEdit = userN->addWidget(make_unique<WLineEdit>());
  userEdit->setPlaceholderText("username");
  userEdit->setStyleClass("userEd");
  username = userEdit;
  editContainer->addWidget(make_unique<WBreak>());

  // User Password
  auto userPassword = editContainer->addWidget(make_unique<WContainerWidget>());
  userPassword->setStyleClass("userPasswords");
  auto passwordLabel =
      userPassword->addWidget(make_unique<WText>("Enter Password"));
  userPassword->addWidget(make_unique<WBreak>());

  // password1
  auto passEdit = userPassword->addWidget(make_unique<WLineEdit>());
  passEdit->setPlaceholderText("enter password");
  passEdit->setEchoMode(EchoMode::Password);
  passEdit->setStyleClass("userEd");
  userPassword->addWidget(make_unique<WBreak>());
  password = passEdit;

  auto passwordLabel1 =
      userPassword->addWidget(make_unique<WText>("confirm Password"));
  userPassword->addWidget(make_unique<WBreak>());

  // password2
  auto passEdit1 = userPassword->addWidget(make_unique<WLineEdit>());
  passEdit1->setPlaceholderText("enter confirm password");
  passEdit1->setEchoMode(EchoMode::Password);
  passEdit1->setStyleClass("userEd");
  editContainer->addWidget(make_unique<WBreak>());
  password1 = passEdit1;

  // setRiskIdContainer(editContainer);

  auto setId = editContainer->addWidget(make_unique<WContainerWidget>());
  setId->setStyleClass("setId");
  auto rules = setId->addWidget(
      make_unique<WText>(" Rules \n @ - \t Alphabets \n ! - \t Special "
                         "Characters \n #- \t Numbers "));
  rules->setStyleClass("rules");
  setId->addWidget(make_unique<WBreak>());
  auto ruleEdit = setId->addWidget(make_unique<WLineEdit>());
  ruleEdit->setStyleClass("userEd");
  // ruleEdit->setPlaceholderText>("Enter Sequence");

  editContainer->addWidget(make_unique<WBreak>());
  auto submitButton =
      editContainer->addWidget(make_unique<WPushButton>("Create"));
  submitButton->clicked().connect(this, &SetRiskId::Submit);

  submitButton->setStyleClass("sub");
  // nav->setStyleClass("nav");
  // txt->setStyleClass("txt");
}

void SetRiskId::Submit() {
  if (password->text().narrow() == password1->text().narrow()) {
    unique_ptr<Risk> risk =
        make_unique<Risk>("format", "", "", 0, 0, "", "", "", "", "");
    unique_ptr<User> user =
        make_unique<User>("Admin", username->text().narrow(),
                          password->text().narrow(), "default@email.com");

    connection.addUser(move(user));
    connection.addRisk(move(risk));
  }
}

// void SetRiskId :: showRiskView(){

// auto riskId = container->addWidget(make_unique<WContainerWidget>());

//	riskId->setStyleClass("riskid");
//	auto nav = riskId->addWidget(make_unique<WContainerWidget>());
//	auto txt = nav->addWidget(make_unique<WText>(" Register Yourself"));

//	riskId->setAttributeValue("style", "color: red; border: 1px solid
//black;"); 	auto editContainer =
//riskId->addWidget(make_unique<WContainerWidget>());

//	createInput(editContainer);
//
//	setRiskIdContainer(editContainer);

//	auto submitButton =
//editContainer->addWidget(make_unique<WPushButton>("Create"));

//	nav->setStyleClass("nav");
//	txt->setStyleClass("txt");
//}

/* void SetRiskId :: createInput(WContainerWidget* editContainer){

        auto userN = editContainer->addWidget(make_unique<WContainerWidget>());

        //User Name
        auto userLabel = userN->addWidget(make_unique<WText>("Enter Username"));
        userN->addWidget(make_unique<WBreak>());
        auto userEdit = userN->addWidget(make_unique<WLineEdit>());
        userEdit->setPlaceholderText("username");

        editContainer->addWidget(make_unique<WBreak>());

        //User Password
        auto userPassword =
editContainer->addWidget(make_unique<WContainerWidget>());

        auto passwordLabel = userPassword->addWidget(make_unique<WText>("Enter
Password")); userPassword->addWidget(make_unique<WBreak>());

        //password1
        auto passEdit = userPassword->addWidget(make_unique<WLineEdit>());
        passEdit->setPlaceholderText("enter password");
        passEdit->setEchoMode(EchoMode::Password);

        userPassword->addWidget(make_unique<WBreak>());

        auto passwordLabel1 =
userPassword->addWidget(make_unique<WText>("confirm Password"));
        userPassword->addWidget(make_unique<WBreak>());

        //password2
        auto passEdit1 = userPassword->addWidget(make_unique<WLineEdit>());
        passEdit1->setPlaceholderText("enter confirm password");
        passEdit1->setEchoMode(EchoMode::Password);

        editContainer->addWidget(make_unique<WBreak>());

}*/

/* void  SetRiskId:: setRiskIdContainer(WContainerWidget* editContainer){

        auto setId = editContainer->addWidget(make_unique<WContainerWidget>());
        auto rules = setId->addWidget(make_unique<WText>(" Rules \n @ - \t
Alphabets \n ! - \t Special Characters \n #- \t Numbers "));
        setId->addWidget(make_unique<WBreak>());
        auto ruleEdit = setId->addWidget(make_unique<WLineEdit>());
        //ruleEdit->setPlaceholderText>("Enter Sequence");

        editContainer->addWidget(make_unique<WBreak>());
} */
