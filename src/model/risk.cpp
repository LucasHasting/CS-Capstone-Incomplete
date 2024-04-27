#include "risk.h"
#include "DatabaseConnection.h"

// Constructor
risk::Riskt(std::string ID,std::string shortDescription,std::string longDescription, likelihoodRank, impactRank,std::string owner,std::string status,std::string notes,std::string openDate,std::string closeDate);
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

	this->connection = DatabaseConnection(/*ARGUMENTS*/)
}


//saveRisk() function that saves the risks to database added by the user
bool risk::saveRisk()
{
	if(connection.isConnected())
	{
		//will put the code here for saving
		std::cout << "Risk saved to database\n";
		return true;
	}

	else
	{
		std::cout << "Failed to save risk. Database connection might not be established. \n";
		return false;
	}
}


//validateID() fucntion checks for the ID entered by the user with th database to see if it actually exists.

bool risk::vaidateID()
{
	return !ID.empty();
}


//formatDate() function helps format the date entered

bool risk::formatDate()
{
	// code goes here
	std::cout << "Date formatted successfully\n";
	return true;
}
