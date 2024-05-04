#include "deleteUser.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>


using namespace Wt;
using namespace std;

deleteUser::deleteUser(WContainerWidget* parent) : WContainerWidget()
{
	WApplication::instance()->useStyleSheet("table.css");

	auto container = addWidget(make_unique<WContainerWidget>());
	auto edit = container->addNew<WText>();
	edit->setText("<p>Are you Sure you want to delete this user?</p>");

	auto submit1 = container->addWidget(make_unique<WPushButton>("cancel"));

	auto submit2 = container->addWidget(make_unique<WPushButton>("delete"));
	
	submit1->setStyleClass("sub1");	
	submit2->setStyleClass("sub2");

}

