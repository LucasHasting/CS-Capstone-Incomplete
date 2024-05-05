#ifndef UPDATERISK_H
#define UPDATERISK_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>
#include <Wt/WPopupMenu.h>

using namespace std;
using namespace Wt;

class UpdateRisk : public WContainerWidget {

	public:
		UpdateRisk(WContainerWidget* parent = nullptr);

	private:
		WContainerWidget* container;
		WLineEdit*  id;
		WLineEdit*  openDate;
		WLineEdit*  closeDate;
		WLineEdit*  notes;
		WComboBox*  status;
		WLineEdit*  owner;
		WComboBox* likeComobo;
	        WComboBox* impactRank;
		WLineEdit*  shortDes;
		WLineEdit*  longDes;
};




#endif  /* UPDATERISK_H */
