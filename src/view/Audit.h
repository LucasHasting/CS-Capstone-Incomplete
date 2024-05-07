#ifndef AUDIT_H
#define AUDIT_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTable.h>
#include <Wt/WPushButton.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WImage.h>
#include "riskMatrix.h"
#include "riskReport.h"

using namespace std;
using namespace Wt;

class Audit : public Wt::WContainerWidget
{
public:
    Audit(WContainerWidget* parent = nullptr);

private:
    WContainerWidget* container;
    void createHeader(WContainerWidget*);
    void createDashboard(WContainerWidget*);
    
};

#endif // AUDIT_H
