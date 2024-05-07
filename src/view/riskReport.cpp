#include "riskReport.h"
#include "../model/DatabaseConnection.h"
#include "../model/Risk.h"
#include "deleteRisk.h"
#include "updateRisk.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>
#include <Wt/WPushButton.h>
#include <Wt/WTable.h>
#include <Wt/WTableCell.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;

RiskReport::RiskReport(WContainerWidget *parent) : WContainerWidget() {
  auto app = WApplication::instance();
  app->useStyleSheet("style.css");

  app->internalPathChanged().connect(this, &RiskReport::onInternalPathChange);
  container = addWidget(make_unique<WContainerWidget>());
  container->setStyleClass("view/riskReport");

  showRiskReport();
}

void RiskReport ::onInternalPathChange() {}

void RiskReport::showRiskReport() {

  // auto tableContainer =
  // container->addWidget(make_unique<WContainerWidget>());

  vector<unique_ptr<Risk>> risks = connection.selectAllRisk();
  WPushButton *edit;
  WPushButton *delet;

  auto table = container->addWidget(make_unique<WTable>());
  if (risks.empty()) {
    table->setStyleClass("table table-striped table-hover table-bordered");
    table->setHeaderCount(1);
    table->setWidth(Wt::WLength("100%"));

    table->elementAt(0, 0)->addNew<WText>("RID");
    table->elementAt(0, 1)->addNew<WText>("Long Desc.");
    table->elementAt(0, 2)->addNew<WText>("Short Description");
    table->elementAt(0, 3)->addNew<WText>("Likelihood");
    table->elementAt(0, 4)->addNew<WText>("Impact");
    table->elementAt(0, 5)->addNew<WText>("Status");
    table->elementAt(0, 6)->addNew<WText>("Open Date");
    table->elementAt(0, 7)->addNew<WText>("Close Date");
    table->elementAt(0, 8)->addNew<WText>("Notes");
    table->elementAt(0, 9)->addNew<WText>("Owner");
    table->elementAt(0, 10)->addNew<WText>("Edit");
    table->elementAt(0, 11)->addNew<WText>("Delete");

    auto txt =
        table->elementAt(1, 0)->addWidget(make_unique<WText>("No Open Risks"));
    table->elementAt(1, 4)->setColumnSpan(7);
    txt->setTextAlignment(AlignmentFlag::Center);
  } else {

    table->setStyleClass("table table-striped table-hover table-bordered");
    table->setHeaderCount(1);
    table->setWidth(Wt::WLength("100%"));

    table->elementAt(0, 0)->addNew<WText>("RID");
    table->elementAt(0, 1)->addNew<WText>("Long Desc.");
    table->elementAt(0, 2)->addNew<WText>("Short Description");
    table->elementAt(0, 3)->addNew<WText>("Likelihood");
    table->elementAt(0, 4)->addNew<WText>("Impact");
    table->elementAt(0, 5)->addNew<WText>("Status");
    table->elementAt(0, 6)->addNew<WText>("Open Date");
    table->elementAt(0, 7)->addNew<WText>("Close Date");
    table->elementAt(0, 8)->addNew<WText>("Notes");
    table->elementAt(0, 9)->addNew<WText>("Owner");
    table->elementAt(0, 10)->addNew<WText>("Edit");
    table->elementAt(0, 11)->addNew<WText>("Delete");

    for (unsigned i = 0; i < risks.size(); i++) {

      unique_ptr<Risk> currentRisk = move(risks[i]);
      int row = i + 1;

      table->elementAt(row, 0)->addNew<WText>(currentRisk->getID());
      table->elementAt(row, 1)->addNew<WText>(
          currentRisk->getLongDescription());
      table->elementAt(row, 2)->addNew<WText>(
          currentRisk->getShortDescription());
      table->elementAt(row, 3)->addNew<WText>(
          to_string(currentRisk->getLikelihoodRank()));
      table->elementAt(row, 4)->addNew<WText>(
          to_string(currentRisk->getImpactRank()));
      table->elementAt(row, 5)->addNew<WText>(currentRisk->getStatus());
      table->elementAt(row, 6)->addNew<WText>(currentRisk->getOpenDate());
      table->elementAt(row, 7)->addNew<WText>(currentRisk->getCloseDate());
      table->elementAt(row, 8)->addNew<WText>(currentRisk->getNotes());
      table->elementAt(row, 9)->addNew<WText>(currentRisk->getOwner());
      edit = table->elementAt(row, 10)->addNew<WPushButton>("edit");

      edit->clicked().connect([=] {
        if (!dialog) {
          cout << "not exist" << endl;
          dialog = make_unique<WDialog>("Update Risk");
          auto editRisk = make_unique<UpdateRisk>();
          dialog->contents()->addWidget(move(editRisk));

          auto closeButton = make_unique<WPushButton>("X");
          closeButton->clicked().connect([dialog = dialog.get()] {
            dialog->accept();
          });
          dialog->finished().connect([this] { dialog.reset(); });

          dialog->footer()->addWidget(move(closeButton));

          dialog->show();

          // container->addWidget(move(dialog));
        } else {
          cout << "exist" << endl;
        }
      });

      edit->setStyleClass("editButton");
      delet = table->elementAt(row, 11)->addNew<WPushButton>("Delete");
      delet->setStyleClass("deleteButton");

      // auto deleteButton =
      // buttons->addWidget(make_unique<WPushButton>("Delete"));

      // auto butCon = But->addWidget(make_unique<WContainerWidget>());
      delet->clicked().connect([=] {
        if (!dialog) {
          cout << "Not Exist" << endl;
          dialog = make_unique<WDialog>("Delete Risk");
          auto deleterisk = make_unique<deleteRisk>();
          dialog->contents()->addWidget(move(deleterisk));

          auto closeButton = make_unique<WPushButton>("X");
          closeButton->clicked().connect(
              [dialog = dialog.get()] { dialog->accept(); });
          dialog->finished().connect([this] { dialog.reset(); });
          dialog->footer()->addWidget(move(closeButton));
          dialog->show();
        } else
          cout << "Not Exist" << endl;
      });

      // table->elementAt(row , 7)->addNew<WText>(WString("{1}").arg(row));
      // table->elementAt(row , 8)->addNew<WText>(WString("{1}").arg(row));
    }
  }
}
