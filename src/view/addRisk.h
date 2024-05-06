#ifndef ADDRISK_H
#define ADDRISK_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>

using namespace Wt;
using namespace std;

class AddRiskView : public WContainerWidget {
public:
    explicit AddRiskView();

private:
    WContainerWidget* container;
    WLineEdit* id;
    WLineEdit* openDate;
    WLineEdit* closeDate;
    WLineEdit* notes;
    WComboBox* status;
    WLineEdit* owner;
    WComboBox* likelihoodRank;
    WComboBox* impactRank;
    WLineEdit* shortDes;
    WLineEdit* longDes;
};

#endif /* ADDRISK_H */

