#include <gtest/gtest.h>
#include <string>

#include "../model/Risk.h"

namespace {

	TEST(Risk, DefaultConstructor){
		Risk risk("01", "short description", "long description", 2, 3,
				  "owner", "status", "notes", "openDate", "closteDate");

		bool formattedDate = risk.formatDate();

		EXPECT_EQ(formattedDate, true);

	}

}
