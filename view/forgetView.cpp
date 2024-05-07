#include "forgetView.h"
#include "navbar.h"
//#include "verifyEmail.h"


#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WLink.h>
#include <Wt/WString.h>

using namespace Wt;
using namespace std;

ForgetView :: ForgetView(WContainerWidget* parent) : WContainerWidget(){


	WApplication::instance()->useStyleSheet("style.css");
	
        WApplication::instance()->internalPathChanged().connect(this,&ForgetView::onInternalPathChange);	
	
	container = addWidget(make_unique<WContainerWidget>());
	container->setStyleClass("vforget-background");
	createHeader();
	enterEmailView();
	

}



void ForgetView::onInternalPathChange(){
	
	if(WApplication::instance()->internalPath() == "/forget-password/verify-email"){
		container->clear();
		showVerifyCode(textEr);
	}
	else {
	
		showForgetView();

	}
}

	


void ForgetView:: enterEmailView(){

	auto card = container->addWidget(make_unique<WContainerWidget>());
	
	auto head1 = card->addWidget(make_unique<WContainerWidget>());
	auto verifyText = head1->addWidget(make_unique<WText>("Verify Email"));

	card->addWidget(make_unique<WBreak>());

	auto emailSection = card->addWidget(make_unique<WContainerWidget>());
	
	auto emailTxt = emailSection->addWidget(make_unique<WText>("Enter your registered email"));
	
	emailSection->addWidget(make_unique<WBreak>());
	
	email_ = emailSection->addWidget(make_unique<WLineEdit>());

	
	card->addWidget(make_unique<WBreak>());

	auto submitBox = card->addWidget(make_unique<WContainerWidget>());
	submit = submitBox->addWidget(make_unique<WPushButton>("Verify"));
	submit->setLink(WLink(LinkType::InternalPath,"/forget-password/verify-email"));

	
	textEr = card->addWidget(make_unique<WContainerWidget>());
        textEr->addWidget(make_unique<WText>("error"));	

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

WString ForgetView::getEmail(){

}

void ForgetView::createHeader(){

	container->addWidget(make_unique<Navbar>());
}

void ForgetView::showVerifyCode(WContainerWidget* textEr){


	WString emailText = email_->text();
	cout<<"email text: "<< emailText<<endl;
	if(!emailText.empty())
	{
//		cout<<"got in this condiiton"<<endl;
//		auto verifyEmail = make_unique<VerifyEmail>(nullptr,emailText);
//		container->clear();
//		container->addWidget(move(verifyEmail));
//		cout<<"Naivigate to verfiy email"<<emailText<<endl;
	}
	else{
		cout<<"got in this two"<<endl;
		//card->addWidget(make_unique<WText>("Invalid Email..."));
   		textEr->addWidget(make_unique<WText>("Error"));
		cout<<"addede text to error"<<endl;  
	}

}

void ForgetView:: showForgetView(){
	
	container->clear();
	createHeader();
	enterEmailView();

}
