#ifndef SETRISKID_H
#define SETRISKID_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include "../model/DatabaseConnection.h"

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
	    WLineEdit* password;
	    WLineEdit* password1;
	    WLineEdit* username;
        DatabaseConnection connection;
        void Submit();
};

#endif /*SETRISKID*/
