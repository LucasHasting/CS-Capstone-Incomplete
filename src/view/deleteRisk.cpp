#include "deleteRisk.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

deleteRisk::deleteRisk(WContainerWidget *parent) : WContainerWidget() {
  WApplication::instance()->useStyleSheet("view/table.css");

  auto container = addWidget(make_unique<WContainerWidget>());
  auto edit = container->addNew<WText>();
  edit->setText("<p>Are you Sure you want to delete this risk?</p>");

  auto container2 = container->addWidget(make_unique<WContainerWidget>());
  // auto submit1 = container2->addWidget(make_unique<WPushButton>("cancel"));

  auto submit2 = container2->addWidget(make_unique<WPushButton>("delete"));
  submit2->setLink(WLink(LinkType::InternalPath, "/admin"));
  // submit1->setStyleClass("sub3");
  submit2->setStyleClass("sub4");
  container2->setStyleClass("container2");
}
