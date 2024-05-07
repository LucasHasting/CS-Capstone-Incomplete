#ifndef RISKREPORT_H
#define RISKREPORT_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>


using namespace Wt;
using namespace std;

class RiskReport : public WContainerWidget {

    public:
        RiskReport(WContainerWidget* parent = nullptr);

    private:
        WContainerWidget* container;
        void onInternalPathChange();
            void showRiskReport();
};



#endif /*RISKREPORT_H*/
