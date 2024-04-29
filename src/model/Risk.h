#include<string>
#include"DatabaseConnection.h"

class risk
{
	private:
		std::string ID;
		std::string closeDate;
		std::string openDate;
		std::string notes;
		std::string status;
		std::string owner;
		int likelihoodRank;
		int impactRank;
		std::string longDescription;
		std::string shortDescription;
		DatabaseConnection connection;
 
	public: 
		Risk(std::string ID,std::string shortDescription,std::string longDescription,int likelihoodRank,int impactRank,std::string owner,std::string status,std::string notes,std::string openDate,std::string closeDate);
		bool saveRisk();
		bool vaidateID();
		bool formatDate();
        
        template<class Action>
        void persist(Action& a);
}
