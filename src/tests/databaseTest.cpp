#include "../model/User.h"
#include "../model/Risk.h"
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Exception.h>
#include <Wt/Dbo/backend/MySQL.h>
#include <gtest/gtest.h>

#define private public
#include "../model/DatabaseConnection.h"
#undef private

namespace {

	TEST(DatabaseConnection, DefaultConstructor)
	{
		DatabaseConnection db;
		
	}

	TEST(DatabaseConnection, AddUser)
	{
		DatabaseConnection db;
		std::unique_ptr<User> user = std::make_unique<User>("Test1", "Test1", "12345", "test1@una.com");
		std::unique_ptr<User> user2 = std::make_unique<User>("Test3", "Test3", "54321", "test3@una.edu");

		db.addUser(std::move(user));
		db.addUser(std::move(user2));
		
		EXPECT_NE(user, nullptr);
		EXPECT_NE(user2, nullptr);
		
	}

}
