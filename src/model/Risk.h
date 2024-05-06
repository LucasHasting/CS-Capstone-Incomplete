#include <Wt/Dbo/Dbo.h>
#include <string>

#ifndef RISK
#define RISK

class Risk {
private:
  std::string RID;
  std::string closeDate;
  std::string openDate;
  std::string notes;
  std::string status;
  std::string owner;
  int likelihoodRank;
  int impactRank;
  std::string longDescription;
  std::string shortDescription;

public:
  Risk(std::string ID, std::string shortDescription,
       std::string longDescription, int likelihoodRank, int impactRank,
       std::string owner, std::string status, std::string notes,
       std::string openDate, std::string closeDate);
  Risk();
  bool validateID();
  bool formatDate();
  std::string getID();
  std::string getCloseDate();
  std::string getOpenDate();
  std::string getNotes();
  std::string getStatus();
  std::string getOwner();
  int getLikelihoodRank();
  int getImpactRank();
  std::string getLongDescription();
  std::string getShortDescription();
  void setID(std::string);
  void setCloseDate(std::string);
  void setOpenDate(std::string);
  void setNotes(std::string);
  void setStatus(std::string);
  void setOwner(std::string);
  void setLikelihoodRank(int);
  void setImpactRank(int);
  void setLongDescription(std::string);
  void setShortDescription(std::string);


  template <class Action> void persist(Action &a) {
    Wt::Dbo::field(a, RID, "RID");
    Wt::Dbo::field(a, closeDate, "closeDate");
    Wt::Dbo::field(a, openDate, "openDate");
    Wt::Dbo::field(a, notes, "notes");
    Wt::Dbo::field(a, status, "status");
    Wt::Dbo::field(a, owner, "owner");
    Wt::Dbo::field(a, likelihoodRank, "likelihoodRank");
    Wt::Dbo::field(a, impactRank, "impactRank");
    Wt::Dbo::field(a, longDescription, "longDescription");
    Wt::Dbo::field(a, shortDescription, "shortDescription");
  }
};

#endif
