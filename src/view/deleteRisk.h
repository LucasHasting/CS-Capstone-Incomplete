#ifndef DELETERISK_H
#define DELETERISK_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WMenuItem.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPushButton.h>
#include <Wt/WMessageBox.h>

using namespace Wt;
using namespace std;


class deleteRisk : public WContainerWidget {
	
	public:
		deleteRisk(WContainerWidget *parent = nullptr);
		WPushButton *button;
		


};

#endif /*DELETERISK_H*/
