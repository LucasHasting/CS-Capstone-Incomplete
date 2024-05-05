#include "forgetView.h"
#include "navbar.h"
#include "verifyEmail.h"
#include "addUser.h"
/*
	#include "admin.h"
*/
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WLink.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WMessageBox.h>
#include <Wt/WComboBox.h>
#include <Wt/WLabel.h>

using namespace Wt;
using namespace std;

addUser::addUser(WContainerWidget* parent) : WContainerWidget()
{

	WApplication::instance()->useStyleSheet("table.css");

	//WApplication::instance()->internalPathChanged().connect(this, &addUser::onInternalPathChange);

	container = addWidget(make_unique<WContainerWidget>());
	container->setStyleClass("add-background");
	
	Role();
	UserName();
	Password();
	Email();
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
			auto messageBox = subMenu->addChild(make_unique<Wt::WMessageBox>("Role", Wt::WString::fromUTF8("Role"), Wt::Icon::Information, Wt::StandardButton::Ok));
	messageBox->show();
	messageBox->buttonClicked().connect([=] {
			subMenu->removeChild(messageBox);
			});
	});

	//card->setStyleClass("Add User");
	//headcon->setStyleClass("loginHead");


}
*/
void addUser::Role()
{

	auto card = container->addWidget(make_unique<WContainerWidget>());
	auto headcon = card->addWidget(make_unique<WContainerWidget>());

//	auto header = headcon->addWidget(make_unique<WText>("Add User"));
//	card->addWidget(make_unique<WBreak>());

	auto rbox = container->addWidget(make_unique<Wt::WContainerWidget>()); 
	auto cbRole = rbox->addWidget(make_unique<Wt::WComboBox>());
	cbRole->addItem("Role");
	cbRole->addItem("Admin");
	cbRole->addItem("Audit");
	cbRole->addItem("Track");

//	card->setStyleClass("addcard");
//	headcon->setStyleClass("addheadcon");
//	header->setStyleClass("");
	rbox->setStyleClass("addrbox");
	cbRole->setStyleClass("addrole");


}	

void addUser::UserName()
{
	auto card = container->addWidget(make_unique<WContainerWidget>());
	auto UserName = card->addWidget(make_unique<WLabel>("User Name"));
	card->addWidget(make_unique<WBreak>());
	auto edit_ = card->addWidget(make_unique<WLineEdit>());

	UserName->setBuddy(edit_);
	card->addWidget(make_unique<WBreak>());
	
	edit_->blurred().connect([=]{
		if(edit_->text().empty()) edit_->setText("username");
	});

	edit_->focussed().connect([=]{
		if(edit_->text() == "username") edit_->setText("");
	});


	//card->setStyleClass("loginHead");
	UserName->setStyleClass("nameMsg");
	edit_ ->setStyleClass("userEdit");

}


void addUser::Password()
{
	auto card = container->addWidget(make_unique<WContainerWidget>());
	auto Password = card->addWidget(make_unique<WLabel>("Password"));
	card->addWidget(make_unique<WBreak>());
	auto edit_ = card->addWidget(make_unique<WLineEdit>());

	Password->setBuddy(edit_);

	edit_->setEchoMode(Wt::EchoMode::Password);

	card->addWidget(make_unique<WBreak>());
	
	edit_->blurred().connect([=]{
		if(edit_->text().empty()) edit_->setText("password");
	});

	edit_->focussed().connect([=]{
		if(edit_->text() == "password") edit_->setText("");
	});


	//card->setStyleClass("loginHead");
	Password->setStyleClass("passwordUser");
	edit_ ->setStyleClass("passEdit");

}


void addUser::Email()
{
	auto card = container->addWidget(make_unique<WContainerWidget>());
	auto Email = card->addWidget(make_unique<WLabel>("Email"));
	card->addWidget(make_unique<WBreak>());
	auto edit_ = card->addWidget(make_unique<WLineEdit>());

	Email->setBuddy(edit_);

	card->addWidget(make_unique<WBreak>());
	
	edit_->blurred().connect([=]{
		if(edit_->text().empty()) edit_->setText("email");
	});

	edit_->focussed().connect([=]{
		if(edit_->text() == "email") edit_->setText("");
	});


	//card->setStyleClass("loginHead");
	Email->setStyleClass("userEmail");
	edit_ ->setStyleClass("emailEdit");
	
	auto submit = card->addWidget(make_unique<Wt::WPushButton>("Submit"));
	submit->setLink(WLink(LinkType::InternalPath, "loginpage"));

}



