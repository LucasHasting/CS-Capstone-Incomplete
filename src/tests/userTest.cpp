#include <gtest/gtest.h>
#include <string>
#include "../model/User.h"

namespace {
	TEST(User, DefaultConstructor)
	{
		User user("Admin", "User1", "123", "test@test.com");
		
		std::cout << user.getUsername() << std::endl;
	}
}
