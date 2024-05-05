#include "../model/DatabaseConnection.h"
#include "../model/User.h"
#include "../model/Risk.h"
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Exception.h>
#include <Wt/Dbo/backend/MySQL.h>
#include <gtest/gtest.h>


namespace {

	TEST(DatabaseConnection, DefaultConstructor)
	{
		DatabaseConnection db;
		
		EXPECT_NE(db.session, nullptr);	
	}

	TEST(DatabaseConnection, AddUser)
	{
		DatabaseConnection db;
		User user("owner", "user1", "12345!", "test@test.com");

		EXPECT_EQ(db.addUser(user), true);

		
	}

}
