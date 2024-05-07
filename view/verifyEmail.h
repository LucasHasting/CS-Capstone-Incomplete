#ifndef VERIFYEMAIL_H
#define VERIFYEMAIL_H

#include "forgetView.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>

using namespace std;
using namespace Wt;

class VerifyEmail : public WContainerWidget {
	

	public:
		VerifyEmail(WContainerWidget* parent = nullptr, const WString& email= "");
	
	private:
		WString email_;
		WLineEdit* oneCode_;
		WContainerWidget* container;
		void createHeader();
		void showSetNewPassword();
		void showVerifyScreen();
		void verifyEmailCodeView();
		void onInternalPathChange();
};


#endif /*VERIFYEMAIL_H*/
