#include <gtest/gtest.h>
#include <string>
#include "../model/User.h"

namespace {
	TEST(User, DefaultConstructor)
	{
		User* user = new User("Admin", "User", "123", "test@test.com");
	
		std::string uRole = user->getRole();
		std::string uName = user->getUsername();
		std::string uPass = user->getPassword();
		std::string uEmail = user->getEmail();
	
		EXPECT_EQ(uRole, "Admin");
		EXPECT_EQ(uName, "User");
		EXPECT_EQ(uPass, "123");
		EXPECT_EQ(uEmail, "test@test.com");

	}
}
