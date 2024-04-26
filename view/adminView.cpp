#include "adminView.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

AdminView :: AdminView(WContainerWidget* parent) : WContainerWidget(){

	auto tex = addWidget(make_unique<WContainerWidget>());
	tex->addWidget(make_unique<WText>("Admin View "));

}
