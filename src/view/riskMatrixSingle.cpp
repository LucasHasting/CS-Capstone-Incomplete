
#include "riskMatrixSingle.h"
#include "editUser.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WTable.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;

RiskMatrixSingle ::RiskMatrixSingle(WContainerWidget *parent)
    : WContainerWidget() {

  auto app = WApplication::instance();
  app->useStyleSheet("view/table.css");

  container = addNew<WContainerWidget>();

  auto Mat = container->addWidget(make_unique<WContainerWidget>());
  auto But = container->addWidget(make_unique<WContainerWidget>());

  createMatrix(Mat);
  //	createButton(But);

  container->setStyleClass("MatContainer");
  container->setWidth("100%");
  //	But->setStyleClass("But");
  Mat->setStyleClass("Mat");
}

void RiskMatrixSingle ::createMatrix(WContainerWidget *Mat) {

  auto matrix = Mat->addWidget(make_unique<WContainerWidget>());

  auto table = matrix->addWidget(std::make_unique<WTable>());
  table->setHeaderCount(1, Orientation::Horizontal);

  for (int col = 1; col <= 5; col++) {
    auto title = make_unique<WText>(to_string(col));
    table->elementAt(0, col)->addWidget(move(title));
  }

  for (int row = 1; row <= 5; row++) {
    table->elementAt(row, 0)->addNew<WText>(to_string(6 - row));
  }

  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {

      int r = 6 - row;

      if (r * col <= 8 && r * col >= 1)
        table->elementAt(row, col)->setStyleClass("set-border green");
      else if (r * col > 8 && r * col <= 18)
        table->elementAt(row, col)->setStyleClass("set-border yellow");
      else if (r * col > 18 && r * col <= 25)
        table->elementAt(row, col)->setStyleClass("set-border red");
    }
  }

  auto yLabelCon = make_unique<WContainerWidget>();
  auto yLabel = make_unique<WText>("over y");

  yLabelCon->addWidget(move(yLabel));
  // yLabel->decorationStyle().setStyleProperty("transform" , "rotate(-90deg)");
  // matrix->addWidget(move(yLabelCon));
  // yLabel->setStyleClass("yLabel");

  table->setStyleClass("mat-table");
  // Mat->setLayout(move(matrix));
}
