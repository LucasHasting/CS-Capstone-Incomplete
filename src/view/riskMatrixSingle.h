
#ifndef RISKMATRIXSINGLE_H
#define RISKMATRIXSINGLE_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WDialog.h>
using namespace std;
using namespace Wt;

class RiskMatrixSingle : public WContainerWidget {
	
	public:
		RiskMatrixSingle(WContainerWidget* parent = nullptr);
	private:
		WContainerWidget* container;
		void createMatrix(WContainerWidget*);
//		void createButton(WContainerWidget*);
		unique_ptr<WDialog> dialog;
};

#endif /* RISKMATRIXSINGLE_H */
