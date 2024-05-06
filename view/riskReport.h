#ifndef RISKREPORT_H
#define RISKREPORT_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>

using namespace Wt;
using namespace std;

class RiskReport : public WContainerWidget {

	public: 
		RiskReport(WContainerWidget* parent = nullptr);

	private:
		WContainerWidget* container;
		unique_ptr<WDialog> dialog;
		void onInternalPathChange();
	        void showRiskReport();
		void showAdmin();	
};



#endif /*RISKREPORT_H*/
