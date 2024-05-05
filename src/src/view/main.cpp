#include<memory>
#include"loginpage.h"
#include<Wt/WApplication.h>

int main(int argc , char** argv){

	return Wt::WRun(argc , argv , [](const Wt::WEnvironment &env){
			return std::make_unique<LoginPage>(env);
		       });
			
}

