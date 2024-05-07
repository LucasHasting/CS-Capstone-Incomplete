#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>


using namespace Wt;
using namespace std;


class AdminView : public WContainerWidget {
	
	public:
		AdminView(WContainerWidget *parent = nullptr);
	private:
		WContainerWidget* container;
		void createHeader();
		void onInternalPathChange();
		void dashboardView(WContainerWidget*);
		void viewRiskReport(WContainerWidget*);
		void viewRiskMatrix(WContainerWidget*);
		void createButtons(WContainerWidget*);
		unique_ptr<WDialog> dialog;
};

#endif /*ADMINVIEW_H*/
