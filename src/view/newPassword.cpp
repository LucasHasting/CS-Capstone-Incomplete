#include "newPassword.h"
#include "loginpage.h"
#include "navbar.h"

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLink.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;

NewPassword::NewPassword(WContainerWidget *parent) : WContainerWidget() {

  container = addWidget(make_unique<WContainerWidget>());

  auto app = WApplication::instance();

  app->internalPathChanged().connect(this, &NewPassword::onInternalPathChange);
  app->useStyleSheet("view/style.css");
  createHeader();
  viewPasswordCard();
  container->setStyleClass("container");
}

void NewPassword::createHeader() {
  container->addWidget(make_unique<Navbar>());
}

void NewPassword::onInternalPathChange() {

  if (WApplication::instance()->internalPath() == "/login") {

    showLoginPage();
  }
}

void NewPassword::viewPasswordCard() {

  auto card = container->addWidget(make_unique<WContainerWidget>());

  auto headCon = card->addWidget(make_unique<WContainerWidget>());
  auto text = headCon->addWidget(make_unique<WText>(" Create a new password "));

  auto passwords = card->addWidget(make_unique<WContainerWidget>());

  auto label = passwords->addWidget(make_unique<WText>("Enter password"));
  passwords->addWidget(make_unique<WBreak>());

  auto passEdit = passwords->addWidget(make_unique<WLineEdit>());

  passwords->addWidget(make_unique<WBreak>());

  label = passwords->addWidget(make_unique<WText>("Confirm password"));

  passwords->addWidget(make_unique<WBreak>());
  auto passEdit1 = passwords->addWidget(make_unique<WLineEdit>());

  passwords->addWidget(make_unique<WBreak>());

  auto submit = passwords->addWidget(make_unique<WPushButton>("Set Password"));
  submit->setStyleClass("submitB");
  submit->setLink(WLink(LinkType::InternalPath, "/login"));
  card->setStyleClass("loginHead");
  headCon->setStyleClass("headContainer");
  text->setStyleClass("text");
  passwords->setStyleClass("userEdit");
  label->setStyleClass("label");
  passEdit->setStyleClass("userEdit");
  passEdit1->setStyleClass("userEdit");
}

void NewPassword::showLoginPage() {

  container->clear();
  // container->addWidget(make_unique<LoginPage>());
}
