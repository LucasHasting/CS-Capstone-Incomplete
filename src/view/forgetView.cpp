#include "forgetView.h"
#include "navbar.h"
#include "verifyEmail.h"

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLink.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>
#include <string>
using namespace Wt;
using namespace std;

ForgetView ::ForgetView(WContainerWidget *parent) : WContainerWidget() {

  WApplication::instance()->useStyleSheet("style.css");

  WApplication::instance()->internalPathChanged().connect(
      this, &ForgetView::onInternalPathChange);

  container = addWidget(make_unique<WContainerWidget>());
  container->setStyleClass("vforget-background");
  createHeader();
  enterEmailView();
}

void ForgetView::onInternalPathChange() {

  if (WApplication::instance()->internalPath() ==
      "/forget-password/verify-email") {
    container->clear();
    showVerifyCode(textEr);
  } else {

    showForgetView();
  }
}

bool isAtPresent(string str) {
  for (int i = 0; i < str.size(); i++) {
    cout << "entered" << endl;
    cout << str[i] << endl;
    if (str[i] == '@') {
      cout << "@ is presnent" << endl;
      return true;
    }
  }
  cout << "@ not present" << endl;
  return false;
}

bool isDotPresent(string str) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '.') {
      return true;
      cout << ". is present" << endl;
    }
  }
  cout << "dot is not present" << endl;
  return false;
}

bool verifyEmail(WString str) {

  // auto wstr = static_cast<wstring>(str);
  // string email(wstr.begin(), wstr.end());
  string email = str.toUTF8();
  cout << "Email: hwq" << email << endl;
  int dot = -1, At = -1;
  cout << "Rmail " << str << endl;
  if (!isAtPresent(email))
    return false;
  if (!isDotPresent(email))
    return false;

  auto size = static_cast<int>(email.size());

  for (int i = 0; i < size; i++) {
    if (email[i] == '.')
      dot = i;
    else if (email[i] == '@')
      At = i;
  }

  if (At > dot)
    return false;
  cout << str << " is valid email" << endl;
  return true;
}

void ForgetView::enterEmailView() {

  auto card = container->addWidget(make_unique<WContainerWidget>());

  auto head1 = card->addWidget(make_unique<WContainerWidget>());
  auto verifyText = head1->addWidget(make_unique<WText>("Verify Email"));

  card->addWidget(make_unique<WBreak>());

  auto emailSection = card->addWidget(make_unique<WContainerWidget>());

  auto emailTxt = emailSection->addWidget(
      make_unique<WText>("Enter your registered email"));

  emailSection->addWidget(make_unique<WBreak>());

  email_ = emailSection->addWidget(make_unique<WLineEdit>());

  card->addWidget(make_unique<WBreak>());

  auto submitBox = card->addWidget(make_unique<WContainerWidget>());
  submit = submitBox->addWidget(make_unique<WPushButton>("Verify"));

  textEr = card->addWidget(make_unique<WContainerWidget>());

  submit->clicked().connect(this, [this] {
    WString emailText = email_->text();
    bool ans = verifyEmail(emailText);
    if (ans)
      submit->setLink(
          WLink(LinkType::InternalPath, "/forget-password/verify-email"));
    else {
      textEr->addWidget(make_unique<WText>("Email is Invalid! Try again.."));
    }
  });

  card->setStyleClass("vEmail");
  verifyText->setStyleClass("vText");
  head1->setStyleClass("vHead1");
  emailSection->setStyleClass("vEmailSection");
  email_->setStyleClass("vEmailEdit");
  emailTxt->setStyleClass("venterEmail");
  submitBox->setStyleClass("vsubmitCon");
  submit->setStyleClass("vSubmit");
  textEr->setStyleClass("verror");
}

WString ForgetView::getEmail() {}

void ForgetView::createHeader() { container->addWidget(make_unique<Navbar>()); }

void ForgetView::showVerifyCode(WContainerWidget *textEr) {

  WString emailText = email_->text();
  cout << "email text: " << emailText << endl;
  if (!emailText.empty()) {
    cout << "got in this condiiton" << endl;
    auto verifyEmail = make_unique<VerifyEmail>(nullptr, emailText);
    container->clear();
    container->addWidget(move(verifyEmail));
    cout << "Naivigate to verfiy email" << emailText << endl;
  } else {
    cout << "got in this two" << endl;
    // card->addWidget(make_unique<WText>("Invalid Email..."));
    auto color = textEr->addWidget(make_unique<WText>("Error"));
    color->setStyleClass("setError");
    cout << "addede text to error" << endl;
  }
}

void ForgetView::showForgetView() {
  cout << "everyhing is working till now" << endl;
  container->clear();
  createHeader();
  enterEmailView();
}
