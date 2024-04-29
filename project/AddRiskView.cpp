#include "AddRiskView.h"
#include "Risk.h"
#include <iostream>
#include <string>

using namespace std;

AddRiskView::AddRiskView(Database& db) : db(db) {}

void AddRiskView::submit() {
    int id;
    string openDate;
    string closeDate;
    string notes;
    string status;
    string owner;
    int likelihoodRank;
    int impactRank;
    string shortDescription;
    string longDescription;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

    cout << "Enter Open Date: ";
    getline(cin, openDate);

    cout << "Enter Close Date: ";
    getline(cin, closeDate);

    cout << "Enter Notes: ";
    getline(cin, notes);

    cout << "Enter Status: ";
    getline(cin, status);

    cout << "Enter Owner: ";
    getline(cin, owner);

    cout << "Enter Likelihood Rank (number): ";
    cin >> likelihoodRank;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

    cout << "Enter Impact Rank (number): ";
    cin >> impactRank;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

    cout << "Enter Short Description: ";
    getline(cin, shortDescription);

    cout << "Enter Long Description: ";
    getline(cin, longDescription);

    if (db.doesRiskExist(id)) {
        cout << "Risk already exists with ID: " << id << endl;
    } else {
        Risk risk(id, openDate, closeDate, notes, status, owner, likelihoodRank, impactRank, shortDescription, longDescription);
        if (risk.saveRisk(db)) {
            cout << "Risk added successfully." << endl;
        } else {
            cout << "Failed to add risk." << endl;
        }
    }
}

