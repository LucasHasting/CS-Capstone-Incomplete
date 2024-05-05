#ifndef ADDRISKVIEW_H
#define ADDRISKVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>
#include <Wt/WTextArea.h>
#include <Wt/WPushButton.h>
#include <Wt/WDateEdit.h>
#include <Wt/WString.h>
#include "Database.h"

class AddRiskView : public Wt::WContainerWidget {
private:
    Database& db;

    Wt::WLineEdit *idEdit;
    Wt::WDateEdit *openDateEdit;
    Wt::WDateEdit *closeDateEdit;
    Wt::WTextArea *notesEdit;
    Wt::WLineEdit *statusEdit;
    Wt::WLineEdit *ownerEdit;
    Wt::WComboBox *likelihoodRankCombo;
    Wt::WComboBox *impactRankCombo;
    Wt::WTextArea *shortDescriptionEdit;
    Wt::WTextArea *longDescriptionEdit;
    Wt::WPushButton *submitButton;

    void submit();

public:
    AddRiskView(Database& db, Wt::WContainerWidget *parent = nullptr);
};

#endif // ADDRISKVIEW_H

