/*
-------------------------------------
|    Developer   |  Parminder Singh |
|    Description |  Login Page      |
-------------------------------------
*/


#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WText.h>
#include <Wt/WLabel.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WLink.h>
#include <Wt/WStackedWidget.h>

#include "loginpage.h"
#include "navbar.h"
#include "forgetView.h"
#include "adminView.h"

using namespace Wt;
using namespace std;




/*
--------------------------------------------------------------------------
|    Function Name   |  Login Consturctor 			         |
|    Description     |  Make a container and then importing every thing  |
|                    |  as a component.					 |
--------------------------------------------------------------------------
 *
*/
LoginPage :: LoginPage(const WEnvironment& env) : WApplication(env){

	
	useStyleSheet("style.css");
	container = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	
	internalPathChanged().connect(this,&LoginPage::onInternalPathChange);
	

	container->setStyleClass("parent");
	createHeader();
	loginCard();
}


/*
-----------------------------------------------------------------------------
|    Function Name   |  create Header 			         	     |
|    Description     |  calls the header function and place it in conatainer |
------------------------------------------------------------------------------
 *
*/


void LoginPage::createHeader(){

	auto nav = std::make_unique<Navbar>();
	container->addWidget(move(nav));
}



/*
--------------------------------------------------------------------------
|    Function Name   |  Login card			                 |
|    Description     |  Make a Login form with a link to forget password |
|                    |  page					 	 |
--------------------------------------------------------------------------
 *
*/

void LoginPage::loginCard(){
	
	auto card = container->addWidget(make_unique<WContainerWidget>());


	auto logCon = card->addWidget(make_unique<WContainerWidget>());
	auto loginText = logCon->addWidget(make_unique<WText>("Login"));
	
	card->addWidget(make_unique<WBreak>());
	
	auto msg = card->addWidget(make_unique<WContainerWidget>());
	auto welMsg = msg->addWidget(make_unique<WText>("Hi! Welcome Back \U0001F44B "));
	
	
	card->addWidget(make_unique<WBreak>());

	auto userName = card->addWidget(make_unique<WLabel>("User Name"));
	card->addWidget(make_unique<WBreak>());
	auto edit_ = card->addWidget(make_unique<WLineEdit>());

	userName->setBuddy(edit_);

	card->addWidget(make_unique<WBreak>());
	
	edit_->blurred().connect([=]{
		if(edit_->text().empty()) edit_->setText("username");
	});

	edit_->focussed().connect([=]{
		if(edit_->text() == "username") edit_->setText("");
	});

	
	auto password = card->addWidget(make_unique<WLabel>("Password"));
	card->addWidget(make_unique<WBreak>());
	auto passEdit_ = card->addWidget(make_unique<WLineEdit>());
	password->setBuddy(passEdit_);
	passEdit_->setEchoMode(Wt::EchoMode::Password);
	
	card->addWidget(make_unique<WBreak>());
	
	passEdit_->blurred().connect([=]{
		if(passEdit_->text().empty()) passEdit_->setText("password");
	});

	passEdit_->focussed().connect([=]{
		if(passEdit_->text() == "password") passEdit_->setText("");
	});
	
	auto submit = card->addWidget(std::make_unique<Wt::WPushButton>("Login"));
	submit->setLink(WLink(LinkType::InternalPath,"/admin"));

	card->addWidget(make_unique<WBreak>());
	auto forContainer = card->addWidget(make_unique<WContainerWidget>());
	forContainer->addWidget(make_unique<WText>("Forgot Password? "));
	auto forget = forContainer->addWidget(std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::LinkType::InternalPath , "/forget-password"),"Click Here"));	
	//styling classes
	

	card->setStyleClass("loginHead");	
	logCon->setStyleClass("text");
	welMsg->setStyleClass("welcome");
	userName->setStyleClass("msg");
	edit_ ->setStyleClass("userEdit");
	passEdit_->setStyleClass("pasEdit");
	submit->setStyleClass("submit");
	forContainer->setStyleClass("forContainer");
	forget->setStyleClass("forget");

}


/*
--------------------------------------------------------------------------
|    Function Name   |  onInternalPathChange			         |
|    Description     |  Mantains the paths to the different pages. 	 |			 
--------------------------------------------------------------------------
 *
*/

void LoginPage::onInternalPathChange(){
	
	if(internalPath() == "/forget-password"){
		showForget();
	}
	else if(internalPath() == "/admin"){
		showAdmin();
	}
	else if(internalPath() == "/"){
		//container->clear();i
		showLogin();
	}

}


/*
--------------------------------------------------------------------------
|    Function Name   |  showForget 			         	 |
|    Description     |  calls to the forget password screen.		 |
--------------------------------------------------------------------------
 *
*/

void LoginPage::showForget(){
	
	 container->clear();
	 container->addWidget(make_unique<ForgetView>());
}

/*
--------------------------------------------------------------------------
|    Function Name   |  showLogin			         	 |
|    Description     |  Calls same login screen if the forget-passsword  |
|                    |  view is not available.			 	 |
--------------------------------------------------------------------------
 *
*/

void LoginPage::showLogin(){
	
	container->clear();
	createHeader();
	loginCard();

}	

/*
----------------------------------------------------------------------------
|    Function Name   |  showAdmin 			         	   |
|    Description     |  If user login succesfully call show the Admin View |	
--------------------------------------------------------------------------
 *
*/

void LoginPage::showAdmin(){

	container->clear();
	container->addWidget(make_unique<AdminView>());
}
