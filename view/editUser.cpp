#include "editUser.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WLineEdit.h>


using namespace std;
using namespace Wt;

EditUser :: EditUser(WContainerWidget* parent) : WContainerWidget(){

	container = addWidget(make_unique<WContainerWidget>());

	auto app = WApplication::instance();
	app->useStyleSheet("table.css");

	auto card = container->addWidget(make_unique<WContainerWidget>());

	riskId = card->addWidget(make_unique<WLineEdit>());
	card->addWidget(make_unique<WBreak>());
	userName = card->addWidget(make_unique<WLineEdit>());

	card->addWidget(make_unique<WBreak>());
	role = card->addWidget(make_unique<WComboBox>());
	role->setPlaceholderText("Status");
	role->addItem("Admin");
	role->addItem("Audit");
	role->addItem("Track");

	card->addWidget(make_unique<WBreak>());
	

	email = card->addWidget(make_unique<WLineEdit>());
	email->setPlaceholderText("Email");
	
	card->addWidget(make_unique<WBreak>());

	password = card->addWidget(make_unique<WLineEdit>());
	password->setPlaceholderText("Password");
	password->setEchoMode(Wt::EchoMode::Password);

	card->addWidget(make_unique<WBreak>());
	
	auto submit = card->addWidget(make_unique<WPushButton>("Update"));
	submit->clicked().connect(this,[this]{
			container->clear();
	});
	
	card->setStyleClass("card-container");
	riskId->setStyleClass("riskid");
	userName->setStyleClass("username");
	role->setStyleClass("role");
	email->setStyleClass("emails");
	password->setStyleClass("passwords");
	submit->setStyleClass("subButton");
}
