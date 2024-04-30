#include "riskMatrix.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTable.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WPushButton.h>

using namespace std;
using namespace Wt;

RiskMatrix :: RiskMatrix(WContainerWidget* parent) : WContainerWidget(){

	auto app = WApplication::instance();
	app->useStyleSheet("table.css");

	container = addNew <WContainerWidget>();
	
	auto Mat = container->addWidget(make_unique<WContainerWidget>());
	auto But = container->addWidget(make_unique<WContainerWidget>());

	createMatrix(Mat);
	createButton(But);


	container->setStyleClass("MatContainer");
	But->setStyleClass("But");
	Mat->setStyleClass("Mat");
}

void RiskMatrix :: createMatrix(WContainerWidget* Mat){
	
	auto matrix = Mat->addWidget(make_unique<WContainerWidget>());

	auto table = matrix->addWidget(std::make_unique<WTable>());
	table->setHeaderCount(1,Orientation::Horizontal);
	
	for(int col = 1; col <= 7 ; col++){
		auto title = make_unique<WText>("X");
		table->elementAt(0,col)->addWidget(move(title));
	}

	for(int row = 1 ; row <= 7 ; row++){
		table->elementAt(row , 0)->addNew<WText>("Y");
	}

	
	for(int row = 1; row <= 7 ; row++){
		 for(int col = 1; col <= 7 ; col++){
	   	table->elementAt(row,col)->setStyleClass("set-border");
	   }
	}

	matrix->addWidget(make_unique<WText>("Overall X"));


	auto yLabelCon = make_unique<WContainerWidget>();
        auto yLabel = make_unique<WText>("over y");
	
	yLabelCon->addWidget(move(yLabel));	
	//yLabel->decorationStyle().setStyleProperty("transform" , "rotate(-90deg)");
	//matrix->addWidget(move(yLabelCon));	
	//yLabel->setStyleClass("yLabel");

	table->setStyleClass("mat-table");
	//Mat->setLayout(move(matrix));

}

void RiskMatrix :: createButton(WContainerWidget*But)
{
	auto butCon = But->addWidget(make_unique<WContainerWidget>());
	auto userTitle =  butCon->addWidget(make_unique<WContainerWidget>());

	auto txt = butCon->addWidget(make_unique<WText>("User Actions"));

	auto buttons = But->addWidget(make_unique<WContainerWidget>());

	auto editButton = buttons->addWidget(make_unique<WPushButton>("Edit"));
	auto addUser = buttons->addWidget(make_unique<WPushButton>("Add"));
	auto deleteUser = buttons->addWidget(make_unique<WPushButton>("Delete"));

	userTitle->setStyleClass("userCon");
}