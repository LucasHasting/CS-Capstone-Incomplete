#ifndef NEWPASSWORD_H
#define NEWPASSWORD_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>

using namespace std;
using namespace Wt;

class NewPassword : public WContainerWidget
{
	public :
		NewPassword(WContainerWidget* parent = nullptr);
	private:
		void onInternalPathChange();
		WContainerWidget* container;
		void createHeader();
		void viewPasswordCard();
		void showLoginPage();
	
};

#endif /* NEWPASSWORD_H */
