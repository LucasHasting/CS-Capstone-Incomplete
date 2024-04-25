#ifndef FORGETVIEW_H
#define FORGETVIEW_H

#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>


using namespace Wt;
using namespace std;

class ForgetView : public WContainerWidget{

	public:
		ForgetView(Wt::WContainerWidget *parent = nullptr);

	private:
		void onInternalPathChange();
		void showVerifyCode();
		void createHeader();
		void showForgetView();
		WLineEdit* email_;
		void enterEmailView();
		WPushButton* submit;
		WContainerWidget *container;
};


#endif /*FORGETVIEW_H*/
