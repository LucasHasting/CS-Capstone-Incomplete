#ifndef SETRISKID_H
#define SETRISKID_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>

using namespace std;
using namespace Wt;

class SetRiskId : public WContainerWidget{

	public:
		SetRiskId(WContainerWidget* parent = nullptr);
	private:
		WContainerWidget* container;
		void onInternalPathChange();
		void showRiskView();
		void createInput(WContainerWidget*); 
		void setRiskIdContainer(WContainerWidget*);
};

#endif /*SETRISKID*/
