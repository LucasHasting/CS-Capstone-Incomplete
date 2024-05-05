#include <gtest/gtest.h>
#include <string>

#include "../model/Risk.h"

namespace {

	TEST(Risk, DefaultConstructor)
	{
		Risk risk("01", "short description", "long description", 2, 3,
				  "owner", "status", "notes", "openDate", "closeDate");

		EXPECT_EQ(risk.getID(), "01");
		EXPECT_EQ(risk.getShortDescription(), "short description");
		EXPECT_EQ(risk.getLongDescription(), "long description");
		EXPECT_EQ(risk.getLikelihoodRank(), 2);
		EXPECT_EQ(risk.getImpactRank(), 3);
		EXPECT_EQ(risk.getOwner(), "owner");
		EXPECT_EQ(risk.getStatus(), "status");
		EXPECT_EQ(risk.getNotes(), "notes");
		EXPECT_EQ(risk.getOpenDate(), "openDate");
		EXPECT_EQ(risk.getCloseDate(), "closeDate");
	}
	
	TEST(Risk, Setters)
	{
		Risk risk("01", "short description", "long description", 2, 3,
                    "owner", "status", "notes", "openDate", "closeDate");
		
		risk.setID("02");
		risk.setShortDescription("short_description");
		risk.setLongDescription("long_description");
		risk.setLikelihoodRank(3);
		risk.setImpactRank(4);
		risk.setOwner("owner");
		risk.setStatus("Status");
		risk.setNotes("Notes");
		risk.setOpenDate("openDate");
		risk.setCloseDate("closeDate");

		EXPECT_EQ(risk.getID(), "02");
        EXPECT_EQ(risk.getShortDescription(), "short_description");
        EXPECT_EQ(risk.getLongDescription(), "long_description");
        EXPECT_EQ(risk.getLikelihoodRank(), 3);
        EXPECT_EQ(risk.getImpactRank(), 4);
        EXPECT_EQ(risk.getOwner(), "owner");
        EXPECT_EQ(risk.getStatus(), "Status");
        EXPECT_EQ(risk.getNotes(), "Notes");
        EXPECT_EQ(risk.getOpenDate(), "openDate");
        EXPECT_EQ(risk.getCloseDate(), "closeDate");

	}

}
