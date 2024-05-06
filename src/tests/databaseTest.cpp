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
		
	}

}
