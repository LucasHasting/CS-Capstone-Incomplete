#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>


using namespace Wt;
using namespace std;


class AdminView : public WContainerWidget {
	
	public:
		AdminView(WContainerWidget *parent = nullptr);

};

#endif /*ADMINVIEW_H*/
