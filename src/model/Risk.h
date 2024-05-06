#include <string>
#include<Wt/Dbo/Dbo.h>

#ifndef RISK_H
#define RISK_H


class Risk {
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
  Risk(std::string ID, std::string shortDescription,
       std::string longDescription, int likelihoodRank, int impactRank,
       std::string owner, std::string status, std::string notes,
       std::string openDate, std::string closeDate);
  bool saveRisk();
  bool vaidateID();
  bool formatDate();

  bool operator==(Risk);
  template <class Action> void persist(Action &a){
	Wt::Dbo::field(a,ID,"ID");
	Wt::Dbo::field(a,closeDate,"closeDate");
	Wt::Dbo::field(a,openDate,"openDate");
	Wt::Dbo::field(a,notes,"notes");
	Wt::Dbo::field(a,status,"status");
	Wt::Dbo::field(a,owner,"owner");
	Wt::Dbo::field(a,likelihood,"likelihood");
	Wt::Dbo::field(a,impactRank,"impactRank");
	Wt::Dbo::field(a,longDescription,"longDescription");
	Wt::Dbo::field(a,shortDescription,"shortDescription");
}
};
