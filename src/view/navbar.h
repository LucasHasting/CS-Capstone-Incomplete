#ifndef NAVBAR_H
#define NAVBAR_H


#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>

#include "navbar.h"

using namespace Wt;
using namespace std;

class Navbar : public WContainerWidget {

 	public :
		Navbar(const WEnvironment *parent = nullptr);
		void createHeader();
	

};

#endif /*NAVBAR_H*/
