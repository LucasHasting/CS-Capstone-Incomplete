#include "Audit.h"
#include "navbar.h"
#include "riskMatrixSingle.h"
#include "riskReport.h"

#include <Wt/WApplication.h>
#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLineEdit.h> // For WLineEdit
#include <Wt/WPopupMenu.h>
#include <Wt/WPushButton.h> // For WPushButton
#include <Wt/WTable.h>      // For WTable
#include <Wt/WTemplate.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
// For WPopupMenu
#include <memory> // For std::make_unique

using namespace std;
using namespace Wt;

Audit::Audit(WContainerWidget *parent) : Wt::WContainerWidget() {

  auto app = WApplication::instance();
  app->useStyleSheet("view/audit.css");

  container = addWidget(make_unique<WContainerWidget>());
  auto container1 = container->addWidget(make_unique<WContainerWidget>());
  auto container2 = container->addWidget(make_unique<WContainerWidget>());

  createHeader(container1);
  createDashboard(container2);
}

void Audit::createHeader(WContainerWidget *container1) {

  container1->addWidget(make_unique<Navbar>());
}

void Audit::createDashboard(WContainerWidget *container2) {

  auto reportMatrix = container2->addWidget(make_unique<WContainerWidget>());

  auto report = reportMatrix->addWidget(make_unique<WContainerWidget>());
  auto rep = report->addWidget(make_unique<RiskReport>());

  auto matrix = reportMatrix->addWidget(std::make_unique<WContainerWidget>());

  auto mat = matrix->addWidget(std::make_unique<RiskMatrixSingle>());

  auto btnContainer = matrix->addWidget(std::make_unique<WContainerWidget>());

  auto container5 =
      btnContainer->addWidget(std::make_unique<Wt::WContainerWidget>());

  auto btn1 = container5->addNew<Wt::WComboBox>();
  btn1->addItem("Heavy");
  btn1->addItem("Medium");
  btn1->addItem("Light");
  btn1->setCurrentIndex(1);
  btn1->setMargin(10, Wt::Side::Right);

  auto btn2 = btnContainer->addWidget(std::make_unique<WLineEdit>());
  btn2->setPlaceholderText("Input id");

  reportMatrix->setStyleClass("reportMatrix");

  report->setStyleClass("reportContainer");
  rep->setStyleClass("repot");

  matrix->setStyleClass("matricContainer");
  mat->setStyleClass("matr");

  btnContainer->setStyleClass("btncont");
  btn1->setStyleClass("butn1");
  btn2->setStyleClass("butn2");
}
