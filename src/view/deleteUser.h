#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WMenuItem.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPushButton.h>
#include <Wt/WMessageBox.h>

using namespace Wt;
using namespace std;


class deleteUser : public WContainerWidget {
	
	public:
		deleteUser(WContainerWidget *parent = nullptr);
		WPushButton *button;
		


};

#endif /*DELETEUSER_H*/

