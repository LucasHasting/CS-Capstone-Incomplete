#ifndef ADDUSER_H
#define ADDUSER_H

#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WMessageBox.h>
#include <Wt/WComboBox.h>


using namespace Wt;
using namespace std;

class addUser : public WContainerWidget{


	public:
		addUser(Wt::WContainerWidget *parent = nullptr);

	private: 
		void subMenu();
		WPushButton* submit;
		WContainerWidget* container;

		WComboBox* role;
		WLineEdit* userName;
		WLineEdit* password;
		WLineEdit* email;


		//void Head();
		void onInternalPathChange();
		void Role();
		void UserName();
		void Password();
		void Email();

};

#endif /*ADDUSER_H*/
