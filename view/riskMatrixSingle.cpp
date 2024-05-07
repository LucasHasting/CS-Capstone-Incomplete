#include "RiskMatrixSingle.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTable.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WPushButton.h>

using namespace std;
using namespace Wt;

RiskMatrixSingle :: RiskMatrixSingle(WContainerWidget* parent) : WContainerWidget(){

    auto app = WApplication::instance();
    app->useStyleSheet("table.css");

    container = addNew <WContainerWidget>();
    
    auto Mat = container->addWidget(make_unique<WContainerWidget>());
   
    createMatrix(Mat);


    container->setStyleClass("MatContainer");
    container->setWidth("100%");
    Mat->setStyleClass("Mat");
}

void RiskMatrixSingle :: createMatrix(WContainerWidget* Mat){
    
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


