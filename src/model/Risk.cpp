#include "Risk.h"

// Constructor
Risk::Risk(std::string ID, std::string shortDescription,
            std::string longDescription, int likelihoodRank, int impactRank,
            std::string owner, std::string status, std::string notes,
            std::string openDate, std::string closeDate)
{

  this->ID = ID;
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

// validateID() fucntion checks for the ID entered by the user with the database
// to see if it actually exists.

bool Risk::validateID() { return !ID.empty(); }
