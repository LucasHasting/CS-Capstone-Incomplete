#include "verifyEmail.h"
#include "adminView.h"
#include "navbar.h"
#include "newPassword.h"

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;

VerifyEmail ::VerifyEmail(WContainerWidget *parent, const WString &email)
    : WContainerWidget(), email_(email) {

  auto app = WApplication::instance();
  app->useStyleSheet("views/style.css");

  cout << "Recived " << email_ << endl;
  cout << "Got the value " << endl;
  app->internalPathChanged().connect(this, &VerifyEmail::onInternalPathChange);

  container = addWidget(make_unique<WContainerWidget>());
  container->setStyleClass("verify");
  createHeader();
  verifyEmailCodeView();
}

void VerifyEmail::onInternalPathChange() {

  cout << "Internal pah" << endl;
  if (WApplication::instance()->internalPath() == "/setpassword") {

    cerr << "Show set new screen" << endl;
    showSetNewPassword();
  } else {
    cerr << "verify screen" << endl;
    showVerifyScreen();
  }
}

void VerifyEmail::verifyEmailCodeView() {

  // auto emailText = getEmail();
  // cout<<"Email Text is :"<<emailText<<endl;
  auto card = container->addWidget(make_unique<WContainerWidget>());

  auto title = card->addWidget(make_unique<WContainerWidget>());

  auto subTitle = title->addWidget(make_unique<WText>("Verify Code"));

  card->addWidget(make_unique<WBreak>());

  auto codeSection = card->addWidget(make_unique<WContainerWidget>());

  auto texts = make_unique<WText>(email_);

  auto codeTxt = codeSection->addWidget(make_unique<WText>(
      "Enter the code you recived on your email at " + texts->text()));

  texts->setStyleClass("bld");
  oneCode_ = codeSection->addWidget(make_unique<WLineEdit>());

  card->addWidget(make_unique<WBreak>());

  auto submitBox = card->addWidget(make_unique<WContainerWidget>());
  auto submit =
      submitBox->addWidget(make_unique<WPushButton>("Reset Password"));
  submit->setLink(WLink(LinkType::InternalPath, "/setpassword"));

  card->setStyleClass("vEmail");
  subTitle->setStyleClass("vText");
  title->setStyleClass("vHead1");
  codeSection->setStyleClass("vEmailSection");
  oneCode_->setStyleClass("vEmailEdit");
  codeTxt->setStyleClass("venterEmail");
  submitBox->setStyleClass("vsubmitCon");
  submit->setStyleClass("vSubmit");
}

void VerifyEmail::createHeader() {

  container->addWidget(make_unique<Navbar>());
}

void VerifyEmail::showSetNewPassword() {

  container->clear();
  container->addWidget(make_unique<NewPassword>());
}

void VerifyEmail::showVerifyScreen() {

  container->clear();
  createHeader();
  verifyEmailCodeView();
}
