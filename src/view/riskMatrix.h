#ifndef RISKMATRIX_H
#define RISKMATRIX_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WDialog.h>
#include "../model/DatabaseConnection.h"
using namespace std;
using namespace Wt;

class RiskMatrix : public WContainerWidget {
	
	public:
		RiskMatrix(WContainerWidget* parent = nullptr);
	private:
		WContainerWidget* container;
		void createMatrix(WContainerWidget*);
		void createButton(WContainerWidget*);
		unique_ptr<WDialog> dialog;
	    WText* textBox;
	    WLineEdit* inputEdit;
        DatabaseConnection connection;
        void Submit();
};

#endif /* RISKMATRIX_H */
