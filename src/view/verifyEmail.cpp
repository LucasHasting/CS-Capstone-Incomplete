#include "verifyEmail.h"
#include "navbar.h"
#include "adminView.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WLink.h>

using namespace std;
using namespace Wt;

VerifyEmail :: VerifyEmail (WContainerWidget* parent) : WContainerWidget() {
	
	auto app = WApplication::instance();	
	app->useStyleSheet("style.csS");


	app->internalPathChanged().connect(this,&VerifyEmail::onInternalPathChange);

	container = addWidget(make_unique<WContainerWidget>());
	container->setStyleClass("verify");
	createHeader();
	verifyEmailCodeView();	
}


void VerifyEmail::onInternalPathChange(){

	if(WApplication::instance()->internalPath() == "/admin") {

		showAdmin();
	}
	else {
		showVerifyScreen();
	}

}

void VerifyEmail::verifyEmailCodeView(){

	auto card = container->addWidget(make_unique<WContainerWidget>());

	auto title = card->addWidget(make_unique<WContainerWidget>());
	
	auto subTitle = title->addWidget(make_unique<WText>("Verify Code"));

	card->addWidget(make_unique<WBreak>());

	auto codeSection = card->addWidget(make_unique<WContainerWidget>());
        auto codeTxt = codeSection->addWidget(make_unique<WText>("Enter the code you recived on your email "));	

	oneCode_ = codeSection->addWidget(make_unique<WLineEdit>());

	card->addWidget(make_unique<WBreak>());

	auto submitBox = card->addWidget(make_unique<WContainerWidget>());
	auto submit = submitBox->addWidget(make_unique<WPushButton>("Reset Password"));
	submit->setLink(WLink(LinkType::InternalPath,"/admin"));

	
	card->setStyleClass("vEmail");
	subTitle->setStyleClass("vText");
	title->setStyleClass("vHead1");
	codeSection->setStyleClass("vEmailSection");
	oneCode_->setStyleClass("vEmailEdit");
	codeTxt->setStyleClass("venterEmail");
	submitBox->setStyleClass("vsubmitCon");
	submit->setStyleClass("vSubmit");
}

void VerifyEmail::createHeader(){

	container->addWidget(make_unique<Navbar>());
}

void VerifyEmail::showAdmin(){

	container->clear();
	container->addWidget(make_unique<AdminView>());
}

void VerifyEmail::showVerifyScreen(){

	container->clear();
	createHeader();
	verifyEmailCodeView();
}	
