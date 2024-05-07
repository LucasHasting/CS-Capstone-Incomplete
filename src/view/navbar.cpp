#include "navbar.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;

Navbar ::Navbar(const WEnvironment *parent) : WContainerWidget() {

  createHeader();
}

void Navbar ::createHeader() {

  auto nav = addWidget(std::make_unique<Wt::WContainerWidget>());

  WApplication::instance()->useStyleSheet("view/style.css");

  nav->setStyleClass("navbar");

  auto sideL = nav->addWidget(std::make_unique<Wt::WText>("dashboard"));
  sideL->setStyleClass("side");
  auto txt = nav->addWidget(std::make_unique<Wt::WText>("Risk Manager"));
  txt->setStyleClass("title");
  // auto login = nav->addWidget(std::make_unique<Wt::WText>("login"));
  // login->setStyleClass("login");
  auto avatar = nav->addWidget(std::make_unique<Wt::WImage>("login_image.png"));
  avatar->resize(35, 35);
}
