#include "updateRisk.h"

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

UpdateRisk ::UpdateRisk(WContainerWidget *parent) : WContainerWidget() {

  container = addWidget(make_unique<WContainerWidget>());

  auto app = WApplication::instance();

  app->useStyleSheet("view/forget.css");

  auto widCon = container->addWidget(make_unique<WContainerWidget>());

  auto id = widCon->addWidget(make_unique<WLineEdit>());
  id->setPlaceholderText("Risk Id");
  auto openClose = widCon->addWidget(make_unique<WContainerWidget>());

  auto openDate = widCon->addWidget(make_unique<WLineEdit>());
  openDate->setPlaceholderText("Open Date");
  auto closeDate = widCon->addWidget(make_unique<WLineEdit>());
  closeDate->setPlaceholderText(" Close Date ");
  widCon->addWidget(make_unique<WBreak>());
  auto notes = widCon->addWidget(make_unique<WLineEdit>());
  notes->setPlaceholderText("Notes");
  widCon->addWidget(make_unique<WBreak>());

  auto statOwn = widCon->addWidget(make_unique<WContainerWidget>());

  auto status = statOwn->addWidget(make_unique<WComboBox>());
  status->addItem("started");
  status->addItem("InBetween");
  status->addItem("Complete");

  auto owner = statOwn->addWidget(make_unique<WLineEdit>());
  owner->setPlaceholderText("Owner");
  widCon->addWidget(make_unique<WBreak>());

  auto likeImp = widCon->addWidget(make_unique<WContainerWidget>());

  auto likeCombo = likeImp->addWidget(make_unique<WComboBox>());
  likeCombo->addItem("0");
  likeCombo->addItem("1");
  likeCombo->addItem("2");
  likeCombo->addItem("3");
  likeCombo->addItem("4");
  likeCombo->addItem("5");

  auto impactRank = likeImp->addWidget(make_unique<WComboBox>());
  impactRank->addItem("0");
  impactRank->addItem("1");
  impactRank->addItem("2");
  impactRank->addItem("3");
  impactRank->addItem("4");
  impactRank->addItem("5");

  widCon->addWidget(make_unique<WBreak>());

  shortDes = widCon->addWidget(make_unique<WLineEdit>());
  shortDes->setPlaceholderText("short Description");

  widCon->addWidget(make_unique<WBreak>());

  longDes = widCon->addWidget(make_unique<WLineEdit>());
  longDes->setPlaceholderText("Long Description");

  container->setStyleClass("updateContainer");
  widCon->setStyleClass("widCon");
  id->setStyleClass("id");
  openClose->setStyleClass("openClose");
  openDate->setStyleClass("openDate");
  closeDate->setStyleClass("closeDate");
  notes->setStyleClass("notes");
  statOwn->setStyleClass("statown");
  status->setStyleClass("status");
  owner->setStyleClass("owner");
  likeImp->setStyleClass("likeImp");
  likeCombo->setStyleClass("likeCombo");
  impactRank->setStyleClass("impactRank");
  shortDes->setStyleClass("shortDes");
  longDes->setStyleClass("longDes");
}
