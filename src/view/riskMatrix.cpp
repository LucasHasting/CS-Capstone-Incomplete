#include "riskMatrix.h"
#include "../model/DatabaseConnection.h"
#include "addUser.h"
#include "deleteUser.h"
#include "editUser.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WTable.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <string.h>
using namespace std;
using namespace Wt;

RiskMatrix ::RiskMatrix(WContainerWidget *parent) : WContainerWidget() {

  auto app = WApplication::instance();
  app->useStyleSheet("view/table.css");

  container = addNew<WContainerWidget>();

  auto Mat = container->addWidget(make_unique<WContainerWidget>());
  auto But = container->addWidget(make_unique<WContainerWidget>());

  createMatrix(Mat);
  createButton(But);

  container->setStyleClass("MatContainer");
  container->setWidth("100%");
  But->setStyleClass("But");
  Mat->setStyleClass("Mat");
}

void RiskMatrix ::createMatrix(WContainerWidget *Mat) {

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

  // matrix->addWidget(make_unique<WText>("Overall X"));

  auto yLabelCon = make_unique<WContainerWidget>();
  auto yLabel = make_unique<WText>("over y");

  yLabelCon->addWidget(move(yLabel));
  // yLabel->decorationStyle().setStyleProperty("transform" , "rotate(-90deg)");
  // matrix->addWidget(move(yLabelCon));
  // yLabel->setStyleClass("yLabel");

  table->setStyleClass("mat-table");
  // Mat->setLayout(move(matrix));

  auto inputsContainer = Mat->addWidget(make_unique<WContainerWidget>());

  inputEdit = inputsContainer->addWidget(make_unique<WLineEdit>());
  textBox = inputsContainer->addWidget(make_unique<WText>());

  auto button = inputsContainer->addWidget(make_unique<WPushButton>("Check"));
  button->clicked().connect(this, &RiskMatrix::Submit);

  inputEdit->setPlaceholderText("Risk Id");
  inputEdit->setStyleClass("riskInputMat");
  inputsContainer->setStyleClass("inputsCon");
  button->setStyleClass("buttos");
}

void RiskMatrix ::createButton(WContainerWidget *But) {
  auto butCon = But->addWidget(make_unique<WContainerWidget>());
  auto userTitle = butCon->addWidget(make_unique<WContainerWidget>());

  auto txt = userTitle->addWidget(make_unique<WText>("User Actions"));

  auto buttons = But->addWidget(make_unique<WContainerWidget>());

  auto editButton = buttons->addWidget(make_unique<WPushButton>("Edit"));

  editButton->clicked().connect([this, But] {
    if (!dialog) {
      cout << "Not Exist" << endl;
      dialog = make_unique<WDialog>("Edit User");
      auto editUser = make_unique<EditUser>();
      dialog->contents()->addWidget(move(editUser));

      auto closeButton = make_unique<WPushButton>("X");
      closeButton->clicked().connect(
          [dialog = dialog.get()] { dialog->accept(); });
      dialog->finished().connect([this] { dialog.reset(); });
      dialog->setStyleClass("golden");
      dialog->footer()->addWidget(move(closeButton));
      dialog->show();

    } else
      cout << "Not Exist" << endl;
  });

  auto addButton = buttons->addWidget(make_unique<WPushButton>("Add"));

  addButton->clicked().connect([this, But] {
    if (!dialog) {
      cout << "Not Exist" << endl;
      dialog = make_unique<WDialog>("Add User");
      auto adduser = make_unique<addUser>();
      dialog->contents()->addWidget(move(adduser));

      auto closeButton = make_unique<WPushButton>("X");
      closeButton->clicked().connect(
          [dialog = dialog.get()] { dialog->accept(); });
      dialog->finished().connect([this] { dialog.reset(); });
      dialog->footer()->addWidget(move(closeButton));
      dialog->show();
    } else
      cout << "Not Exist" << endl;
  });

  auto deleteButton = buttons->addWidget(make_unique<WPushButton>("Delete"));

  deleteButton->clicked().connect([this, But] {
    if (!dialog) {
      cout << "Not Exist" << endl;
      dialog = make_unique<WDialog>("Delete User");
      auto deleteuser = make_unique<deleteUser>();
      dialog->contents()->addWidget(move(deleteuser));

      auto closeButton = make_unique<WPushButton>("X");
      closeButton->clicked().connect(
          [dialog = dialog.get()] { dialog->accept(); });
      dialog->finished().connect([this] { dialog.reset(); });
      dialog->footer()->addWidget(move(closeButton));
      dialog->show();
    } else
      cout << "Not Exist" << endl;
  });

  editButton->setStyleClass("edit");
  addButton->setStyleClass("add");
  deleteButton->setStyleClass("delete");
  txt->setStyleClass("txt");
  buttons->setStyleClass("just-btn");
  userTitle->setStyleClass("userCon");
}

void RiskMatrix::Submit() {
  textBox->setText(
      to_string(connection.riskPriority(inputEdit->text().narrow())));
}
