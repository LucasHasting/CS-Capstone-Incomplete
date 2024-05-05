#include "AddRiskView.h"
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WMessageBox.h>
#include <Wt/WVBoxLayout.h>

AddRiskView::AddRiskView(Database& db, Wt::WContainerWidget *parent)
    : Wt::WContainerWidget(parent), db(db) {
    
    auto *layout = new Wt::WVBoxLayout(this);
    this->setLayout(layout);

    Wt::WText *title = new Wt::WText("Add Risk Details");
    layout->addWidget(title);

    idEdit = new Wt::WLineEdit();
    idEdit->setPlaceholderText("ID");
    layout->addWidget(idEdit);

    openDateEdit = new Wt::WDateEdit();
    openDateEdit->setPlaceholderText("Open Date");
    layout->addWidget(openDateEdit);

    closeDateEdit = new Wt::WDateEdit();
    closeDateEdit->setPlaceholderText("Close Date");
    layout->addWidget(closeDateEdit);

    notesEdit = new Wt::WTextArea();
    notesEdit->setPlaceholderText("Notes");
    layout->addWidget(notesEdit);

    statusEdit = new Wt::WLineEdit();
    statusEdit->setPlaceholderText("Status");
    layout->addWidget(statusEdit);

    ownerEdit = new Wt::WLineEdit();
    ownerEdit->setPlaceholderText("Owner");
    layout->addWidget(ownerEdit);

    likelihoodRankCombo = new Wt::WComboBox();
    likelihoodRankCombo->addItem("Select Likelihood Rank");
    // Populate the combo box with appropriate rank options
    layout->addWidget(likelihoodRankCombo);

    impactRankCombo = new Wt::WComboBox();
    impactRankCombo->addItem("Select Impact Rank");
    // Populate the combo box with appropriate rank options
    layout->addWidget(impactRankCombo);

    shortDescriptionEdit = new Wt::WTextArea();
    shortDescriptionEdit->setPlaceholderText("Short Description");
    layout->addWidget(shortDescriptionEdit);

    longDescriptionEdit = new Wt::WTextArea();
    longDescriptionEdit->setPlaceholderText("Long Description");
    layout->addWidget(longDescriptionEdit);

    submitButton = new Wt::WPushButton("Add Risk");
    layout->addWidget(submitButton);

    submitButton->clicked().connect(this, &AddRiskView::submit);
}

void AddRiskView::submit() {
    int id = std::stoi(idEdit->text().toUTF8());
    Wt::WDate openDate = openDateEdit->date();
    Wt::WDate closeDate = closeDateEdit->date();
    std::string notes = notesEdit->text().toUTF8();
    std::string status = statusEdit->text().toUTF8();
    std::string owner = ownerEdit->text().toUTF8();
    int likelihoodRank = likelihoodRankCombo->currentIndex(); // assuming the first index is the placeholder
    int impactRank = impactRankCombo->currentIndex(); // assuming the first index is the placeholder
    std::string shortDescription = shortDescriptionEdit->text().toUTF8();
    std::string longDescription = longDescriptionEdit->text().toUTF8();

    // Simple validation example
    if (id <= 0) {
        Wt::WMessageBox::show("Error", "Please enter a valid ID.", Wt::StandardButton::Ok);
        return;
    }
    if (!openDate.isValid()) {
        Wt::WMessageBox::show("Error", "Please enter a valid open date.", Wt::StandardButton::Ok);
        return;
    }
    if (!closeDate.isValid()) {
        Wt::WMessageBox::show("Error", "Please enter a valid close date.", Wt::StandardButton::Ok);
        return;
    }
    if (likelihoodRank == 0 || impactRank == 0) {
        Wt::WMessageBox::show("Error", "Please select valid ranks for likelihood and impact.", Wt::StandardButton::Ok);
        return;
    }

    // If all validations pass, then proceed to interact with the database
    if (db.doesRiskExist(id)) {
        Wt::WMessageBox::show("Error", "Risk with this ID already exists.", Wt::StandardButton::Ok);
    } else {
        // Constructing a Risk object, which should be defined elsewhere
        Risk risk(id, openDate.toString("yyyy-MM-dd").toUTF8(),
                  closeDate.toString("yyyy-MM-dd").toUTF8(),
                  notes, status, owner, likelihoodRank, impactRank,
                  shortDescription, longDescription);

        if (risk.saveRisk(db)) {
            Wt::WMessageBox::show("Success", "Risk has been added successfully.", Wt::StandardButton::Ok);
            // Clear the form or perform other actions as necessary
        } else {
            Wt::WMessageBox::show("Error", "Failed to add risk to the database.", Wt::StandardButton::Ok);
        }
    }
}

