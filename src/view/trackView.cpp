#include "trackView.h"
#include "navbar.h"
#include "riskMatrix.h"
#include "riskMatrixSingle.h"
#include "riskReport.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLength.h> // Include WLength header for setting width
#include <Wt/WLink.h>
#include <Wt/WPushButton.h>
#include <Wt/WTable.h> // Include WTable header
#include <Wt/WTemplate.h>
#include <Wt/WText.h>
using namespace Wt;
using namespace std;

TrackView::TrackView(WContainerWidget *parent) : WContainerWidget() {
  auto app = WApplication::instance();
  app->useStyleSheet("view/style.css");
  app->useStyleSheet("https://cdnjs.cloudflare.com/ajax/libs/font-awesome/"
                     "6.5.2/css/all.min.css");
  container = addWidget(make_unique<WContainerWidget>());
  auto riskDetails = container->addWidget(make_unique<WContainerWidget>());

  app->internalPathChanged().connect(this, &TrackView::onInternalPathChange);
  createHeader();
  dashboardView(riskDetails);
}

void TrackView::onInternalPathChange() {}

void TrackView::dashboardView(WContainerWidget *riskDetails) {

  viewRiskMatrix(riskDetails);
  viewRiskReport(riskDetails);
  riskDetails->setStyleClass("riskContainer");
}

void TrackView::createHeader() { container->addWidget(make_unique<Navbar>()); }

void TrackView::viewRiskReport(WContainerWidget *riskDetails) {
  auto riskReport = riskDetails->addWidget(make_unique<WContainerWidget>());
  riskReport->addWidget(make_unique<RiskReport>());
  riskReport->setWidth(WLength("90%")); // Use WLength for setting width
  riskDetails->setStyleClass("riskDets");
}

void TrackView::viewRiskMatrix(WContainerWidget *riskDetails) {

  auto dashboardContainer =
      riskDetails->addWidget(make_unique<WContainerWidget>());
  // viewTotalComplete(dashboardContainer);

  auto buttonContainer =
      dashboardContainer->addWidget(make_unique<WContainerWidget>());

  auto tableContainer =
      buttonContainer->addWidget(make_unique<WContainerWidget>());
  // box
  auto table = tableContainer->addWidget(make_unique<WTable>());

  // Add rows and columns to the table
  table->elementAt(0, 0)->addWidget(make_unique<WText>("Total"));
  table->elementAt(0, 1)->addWidget(make_unique<WText>("Complete"));
  table->elementAt(1, 0)->addWidget(make_unique<WText>("."));
  table->elementAt(1, 1)->addWidget(make_unique<WText>("."));

  auto twoButton = buttonContainer->addWidget(make_unique<WContainerWidget>());

  auto button1 = twoButton->addWidget(make_unique<WPushButton>("Add Risk"));
  auto button2 = twoButton->addWidget(make_unique<WPushButton>("Sort"));

  // Matriix

  auto matrixContainer =
      dashboardContainer->addWidget(make_unique<WContainerWidget>());
  matrixContainer->addWidget(make_unique<RiskMatrixSingle>());

  dashboardContainer->setStyleClass("dashContain");
  matrixContainer->setStyleClass("risMat");
  buttonContainer->setStyleClass("tabl");
  twoButton->setStyleClass("butto");
  tableContainer->setStyleClass("total");
  button1->setStyleClass("addSort");
  button2->setStyleClass("addSort");
  table->setStyleClass("table");
}
