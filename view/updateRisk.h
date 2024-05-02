#ifndef UPDATERISK_H
#define UPDATERISK_H

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>

using namespace std;
using namespace Wt;

class UpdateRisk : public WContainerWidget {

	puublic:
		UpdateRisk(WContainerWidget* parent = nullptr);

	private:
		WContainerWidget* container;

}



#endif  /* UPDATERISK_H */
