#ifndef LOGINPAGE_H
#define LOGINPAGE_H

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
		WContainerWidget* container;

};


#endif /*LOGINPAGE_H*/
