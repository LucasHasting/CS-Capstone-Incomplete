#include "addRisk.h"
#include "../model/DatabaseConnection.h"
#include "../model/Risk.h"
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

AddRiskView::AddRiskView() : WContainerWidget() {
  container = addWidget(std::make_unique<WContainerWidget>());
  auto app = WApplication::instance();
  app->useStyleSheet("view/addRisk.css");

  // auto heading = container->addWidget(make_unique<WText>("Add Risk
  // Details")); heading->setStyleClass("formHeading");

  auto widCon = container->addWidget(std::make_unique<WContainerWidget>());
  widCon->setStyleClass("formContainer");

  id = widCon->addWidget(std::make_unique<WLineEdit>());
  id->setPlaceholderText("ID");

  id->setStyleClass("inputriskid");
  auto datesContainer = widCon->addWidget(std::make_unique<WContainerWidget>());
  datesContainer->setStyleClass("datesContainer");

  openDate = datesContainer->addWidget(std::make_unique<WLineEdit>());
  openDate->setPlaceholderText("Open Date");
  closeDate = datesContainer->addWidget(std::make_unique<WLineEdit>());
  closeDate->setPlaceholderText("Close Date");

  openDate->setStyleClass("openDates");
  closeDate->setStyleClass("closeDates");
  notes = widCon->addWidget(std::make_unique<WLineEdit>());
  notes->setPlaceholderText("Notes");

  notes->setStyleClass("notes");
  auto statOwnerContainer =
      widCon->addWidget(std::make_unique<WContainerWidget>());
  statOwnerContainer->setStyleClass("statOwnerContainer");

  status = statOwnerContainer->addWidget(std::make_unique<WComboBox>());
  status->addItem("Select status");
  status->addItem("Started");
  status->addItem("In Progress");
  status->addItem("Completed");

  owner = statOwnerContainer->addWidget(std::make_unique<WLineEdit>());
  owner->setPlaceholderText("Owner");

  owner->setStyleClass("ownerisk");
  status->setStyleClass("statuss");
  auto ranksContainer = widCon->addWidget(std::make_unique<WContainerWidget>());
  ranksContainer->setStyleClass("ranksContainer");

  likelihoodRank = ranksContainer->addWidget(std::make_unique<WComboBox>());
  likelihoodRank->addItem("Select likelihood");
  for (int i = 0; i <= 5; ++i) {
    likelihoodRank->addItem(std::to_string(i));
  }

  impactRank = ranksContainer->addWidget(std::make_unique<WComboBox>());
  impactRank->addItem("Select impact");
  for (int i = 0; i <= 5; ++i) {
    impactRank->addItem(std::to_string(i));
  }

  likelihoodRank->setStyleClass("liklihood");
  impactRank->setStyleClass("impRank");
  shortDes = widCon->addWidget(std::make_unique<WLineEdit>());
  shortDes->setPlaceholderText("Short Description");

  widCon->addWidget(make_unique<WBreak>());
  longDes = widCon->addWidget(std::make_unique<WLineEdit>());
  longDes->setPlaceholderText("Long Description");

  shortDes->setStyleClass("shortD");
  longDes->setStyleClass("longD");
  auto addButton = widCon->addWidget(std::make_unique<WPushButton>("Add Risk"));

  addButton->setStyleClass("addButtons");
  addButton->clicked().connect(this, &AddRiskView::Submit);
}

void AddRiskView::Submit() {
  unique_ptr<Risk> risk = make_unique<Risk>(
      id->text().narrow(), shortDes->text().narrow(), longDes->text().narrow(),
      stoi(likelihoodRank->currentText().narrow()),
      stoi(impactRank->currentText().narrow()), owner->text().narrow(),
      status->currentText().narrow(), notes->text().narrow(),
      openDate->text().narrow(), closeDate->text().narrow());
  connection.addRisk(move(risk));
}
