#ifndef FORGETVIEW_H
#define FORGETVIEW_H

#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>

using namespace Wt;
using namespace std;

class ForgetView : public  WContainerWidget{

	public:
		ForgetView(Wt::WContainerWidget *parent = nullptr);
		WString getEmail();
	private:
		void onInternalPathChange();
		void showVerifyCode(WContainerWidget*);
		void createHeader();
		void showForgetView();
		void enterEmailView();
		
		WContainerWidget* textEr;	
		WPushButton* submit;
		WContainerWidget* container;
		WLineEdit* email_ ;
		
};


#endif /*FORGETVIEW_H*/
