#include "Risk.h"

// Constructor
Risk::Risk(std::string ID, std::string shortDescription,
           std::string longDescription, int likelihoodRank, int impactRank,
           std::string owner, std::string status, std::string notes,
           std::string openDate, std::string closeDate) {

  this->RID = ID;
  this->shortDescription = shortDescription;
  this->longDescription = longDescription;
  this->likelihoodRank = likelihoodRank;
  this->impactRank = impactRank;
  this->owner = owner;
  this->status = status;
  this->notes = notes;
  this->openDate = openDate;
  this->closeDate = closeDate;
}

Risk::Risk() {
  this->RID = "";
  this->shortDescription = "";
  this->longDescription = "";
  this->likelihoodRank = 0;
  this->impactRank = 0;
  this->owner = "";
  this->status = "";
  this->notes = "";
  this->openDate = "";
  this->closeDate = "";
}

/* getID() returns a string representing the assigned risk ID */
std::string Risk::getID() { return RID; }

/* getShortDescription returns a string representing the short description
 * for the risk */
std::string Risk::getShortDescription() { return shortDescription; }

/* getLongDescription() returns a string representing the long description
 * for the risk */
std::string Risk::getLongDescription() { return longDescription; }

/* getLikelihoodRank() returns an integer representing the likelihood
 * that the risk will occur */
int Risk::getLikelihoodRank() { return likelihoodRank; }

/* getImpactRank() returns an integer representing the impact the
 * risk will have if it occurs */
int Risk::getImpactRank() { return impactRank; }

/* getOwner() returns a string representing the owner of the risk */
std::string Risk::getOwner() { return owner; }

/* getStatus() returns a string representing the status of the risk */
std::string Risk::getStatus() { return status; }

/* getNotes() returns a string representing any notes made regarding
 * the risk */
std::string Risk::getNotes() { return notes; }

/* getOpenDate() returns a string representing the date the risk was opened */
std::string Risk::getOpenDate() { return openDate; }

/* getCloseDate() returns a string representing the date the risk was closed */
std::string Risk::getCloseDate() { return closeDate; }

/* setID() takes in a string parameter for the new ID and updates the risk ID */
void Risk::setID(std::string id) { RID = id; }

/* setCloseDate() takes in a string parameter for the new closeDate and updates
 * the risk closeDate */
void Risk::setCloseDate(std::string cd) { closeDate = cd; }

/* setOpenDate() takes in a string parameter for the new openDate and updates
 * the risk openDate */
void Risk::setOpenDate(std::string od) { openDate = od; }

/* setNotes() takes in a string parameter for the new notes and updates the risk
 * notes */
void Risk::setNotes(std::string n) { notes = n; }

/* setStatus() takes in a string parameter for the new status and updates the
 * risk status */
void Risk::setStatus(std::string s) { status = s; }

/* setOwner() takes in a string parameter for the new owner and updates the risk
 * owner */
void Risk::setOwner(std::string o) { owner = o; }

/* setLikelihoodRank() takes in a int parameter for the new likelihoodRank and
 * updates the risk likelihoodRank */
void Risk::setLikelihoodRank(int lr) { likelihoodRank = lr; }

/* setImpactRank() takes in a int parameter for the new impactRank and updates
 * the risk impactRank */
void Risk::setImpactRank(int ir) { impactRank = ir; }

/* setLongDescription() takes in a string parameter for the new longDescription
 * and updates the risk longDescription*/
void Risk::setLongDescription(std::string ld) { longDescription = ld; }

/* setShortDescription() takes in a string parameter for the new
 * shortDescription and updates the risk shortDescription */
void Risk::setShortDescription(std::string sd) { shortDescription = sd; }

/* validateID() fucntion checks for the ID entered by the user with the database
 * to see if it actually exists. */
bool Risk::validateID() { return !RID.empty(); }
