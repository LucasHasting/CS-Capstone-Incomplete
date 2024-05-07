#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "../model/DatabaseConnection.h"
#include "../model/User.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>



using namespace Wt;

class LoginPage : public WApplication{

	public:
		explicit LoginPage(const WEnvironment &env);

	private:
		void loginCard();
		void createHeader();
		void showForget();
		void showLogin();
		void showAdmin();
		void onInternalPathChange();
        void authenticate();
        void showTrack();
        void showAudit();
		Wt::WPushButton* submit;
		Wt::WLineEdit* edit_;
		Wt::WLineEdit* passEdit_;
        DatabaseConnection connection;
        std::unique_ptr<User> user;
		void showPassword();
		WContainerWidget* container;
		void createDialog(WContainerWidget*);
};


#endif /*LOGINPAGE_H*/
