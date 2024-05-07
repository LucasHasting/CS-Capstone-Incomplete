#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <Wt/WContainerWidget.h>

class TrackView : public Wt::WContainerWidget {
public:
    TrackView(Wt::WContainerWidget *parent = nullptr);

private:
    Wt::WContainerWidget* container;

    void createHeader();
    void onInternalPathChange();
    void dashboardView(Wt::WContainerWidget*);
    void viewRiskReport(Wt::WContainerWidget*);
    void viewRiskMatrix(Wt::WContainerWidget*);
 //   void viewTotalComplete(WContainerWidget*);
};

#endif // TRACKVIEW_H

