#ifndef EDITUSER_H
#define EDITUSER_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>

using namespace std;
using namespace Wt;

class EditUser : public WContainerWidget{
	public:
		EditUser(WContainerWidget* parent = nullptr);
	private:
		WContainerWidget* container;
		WLineEdit* userName;
		WComboBox* role;
		WLineEdit* password;
		WLineEdit* email;
		WLineEdit* riskId;
};

#endif /*EDITUSER_H*/
