#include "adminView.h"
#include "navbar.h"
#include "riskReport.h"
#include "riskMatrix.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLink.h>
#include <Wt/WTemplate.h>

using namespace Wt;
using namespace std;
AdminView :: AdminView(WContainerWidget* parent) : WContainerWidget(){

	auto app = WApplication::instance();
	app->useStyleSheet("style.css");
	app->useStyleSheet("https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css");	
	container = addWidget(make_unique<WContainerWidget>());
	auto riskDetails = container->addWidget(make_unique<WContainerWidget>());


	app->internalPathChanged().connect(this,&AdminView::onInternalPathChange);
	createHeader();
	dashboardView(riskDetails);
	
}


void AdminView :: onInternalPathChange() {

}



void AdminView :: dashboardView(WContainerWidget* riskDetails){

	createButtons(riskDetails);
	viewRiskReport(riskDetails);
	viewRiskMatrix(riskDetails);
	riskDetails->setStyleClass("riskContainer");

}
void AdminView :: createHeader(){

	container->addWidget(make_unique<Navbar>());
}

void AdminView :: viewRiskReport(WContainerWidget* riskDetails) {
	auto riskReport = riskDetails->addWidget(make_unique<WContainerWidget>());
	riskReport->addWidget(make_unique<RiskReport>());
	riskReport->setWidth(Wt::WLength("90%"));
	riskDetails->setStyleClass("riskDets");
}

void AdminView :: viewRiskMatrix(WContainerWidget* riskDetails) {
	auto riskMatrix = container->addWidget(make_unique<WContainerWidget>());
	riskMatrix->addWidget(make_unique<RiskMatrix>());
	riskMatrix->setStyleClass("risMat");
}

void AdminView :: createButtons(WContainerWidget* riskDetails){

	auto buttons = riskDetails->addWidget(make_unique<WContainerWidget>());
	auto leftButtons = buttons->addWidget(make_unique<WContainerWidget>());
	
	auto result = make_unique<WTemplate>(WString::tr("appendedDropdownButton-template"));

	auto popup = make_unique<WPopupMenu>();
	popup->addItem("Author Name");
	popup->addItem("Rank");
	popup->addItem("Date Added");

	auto sortButton = leftButtons->addWidget(make_unique<WPushButton>());
	sortButton->setMenu(move(popup));
	auto inputId = leftButtons->addWidget(make_unique<WLineEdit>());
	inputId->setPlaceholderText("Search Risk by ID");
	
	auto rightButton = buttons->addWidget(make_unique<WPushButton>("Add"));
	rightButton->setLink(WLink(LinkType::InternalPath,"/add-user"));
	buttons->setStyleClass("abtnContainer");
	leftButtons->setStyleClass("left-btn");
	sortButton->setStyleClass("asortBtn");
	inputId->setStyleClass("ainputId");
	rightButton->setStyleClass("arghtbtn");
	

}


