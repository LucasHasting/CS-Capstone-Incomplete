#include "riskReport.h"
#include "updateRisk.h"

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>
#include <Wt/WTableCell.h>
#include <Wt/WPushButton.h>
#include <Wt/WDialog.h>


using namespace std;
using namespace Wt;

namespace{

	struct Risk{
		string Uid;
		string risk;
		string longDesc;
		string shortDesc;
		string likelihood;
		int  impact;
		string status;

		Risk(const string& aUid , const string& aRisk , const string& alongDesc ,const string& ashortDesc ,const string& aLikelihood , const int& aimpact , const string& aStatus):Uid(aUid) , risk(aRisk) , longDesc(alongDesc) , shortDesc(ashortDesc) , likelihood(aLikelihood) , impact(aimpact) , status(aStatus){} 
	};

	Risk risks[] = {
		Risk("758943","Risk1" , "longsesc" , "shortdes" , "qwer" , 19 , "jdsklf" ),
		Risk("758943","Risk1" , "longsesc" , "shortdes" , "wert" , 19 , "jdsklf" ),
		Risk("758943","Risk1" , "longsesc" , "shortdes" , "wert" , 19 , "jdsklf" ),
		Risk("758943","Risk1" , "longsesc" , "shortdes" , "2w43" , 19 , "jdsklf" ),
		
	};

}

RiskReport::RiskReport(WContainerWidget* parent) : WContainerWidget()
{
	  auto app = WApplication::instance();
	  app->useStyleSheet("style.css");
	  
	  app->internalPathChanged().connect(this,&RiskReport::onInternalPathChange);
	  container = addWidget(make_unique<WContainerWidget>());
	  container->setStyleClass("riskReport");
	  
	  showRiskReport();
}

void RiskReport :: onInternalPathChange(){

}

void RiskReport::showRiskReport(){
	   

	//auto tableContainer = container->addWidget(make_unique<WContainerWidget>());

 	WPushButton* edit;
	WPushButton* delet;
	
	int length = sizeof(risks)/sizeof(risks[0]);
	auto table = container->addWidget(make_unique<WTable>());
	cout<<"Length -----------------------" << length<<endl; 
	if(length == 0) {
		std::cerr<<"IN the lenght = 0 " <<std::endl;
		table->setStyleClass("table table-striped table-hover table-bordered");
		table->setHeaderCount(1);
		table->setWidth(Wt::WLength("100%"));

	  	table->elementAt(0,0)->addNew<WText>("UID");
	  	table->elementAt(0,1)->addNew<WText>("Risk");
	  	table->elementAt(0,2)->addNew<WText>("Long Desc.");
	  	table->elementAt(0,3)->addNew<WText>("Show Details");
	  
	  	table->elementAt(0,4)->addNew<WText>("Likelihood");
	  	table->elementAt(0,5)->addNew<WText>("Impact");
	  	table->elementAt(0,6)->addNew<WText>("Status");
	  	table->elementAt(0,7)->addNew<WText>("Edit");
	  	table->elementAt(0,8)->addNew<WText>("Delete");

		auto txt = table->elementAt(1,0)->addWidget(make_unique<WText>("No Open Risks"));
		table->elementAt(1,4)->setColumnSpan(7);
		txt->setTextAlignment(AlignmentFlag::Center);
	}	
	else { 

	  table->setStyleClass("table table-striped table-hover table-bordered");
	  table->setHeaderCount(1);
	  table->setWidth(Wt::WLength("100%"));

	  table->elementAt(0,0)->addNew<WText>("UID");
	  table->elementAt(0,1)->addNew<WText>("Risk");
	  table->elementAt(0,2)->addNew<WText>("Long Desc.");
	  table->elementAt(0,3)->addNew<WText>("Show Details");
	  
	  table->elementAt(0,4)->addNew<WText>("Likelihood");
	  table->elementAt(0,5)->addNew<WText>("Impact");
	  table->elementAt(0,6)->addNew<WText>("Status");
	  table->elementAt(0,7)->addNew<WText>("Edit");
	  table->elementAt(0,8)->addNew<WText>("Delete");
	  


	  for(unsigned i = 0 ; i < 4; i++){
	  	const Risk& currentRisk = risks[i];
		int row = i + 1;

		table->elementAt(row , 0)->addNew<WText>(currentRisk.Uid);
		table->elementAt(row , 1)->addNew<WText>(currentRisk.risk);
		table->elementAt(row , 2)->addNew<WText>(currentRisk.longDesc);
		table->elementAt(row , 3)->addNew<WText>(currentRisk.shortDesc);
		table->elementAt(row , 4)->addNew<WText>(currentRisk.likelihood);
		table->elementAt(row , 5)->addNew<WText>(to_string(currentRisk.impact));
		table->elementAt(row , 6)->addNew<WText>(currentRisk.status);
		edit = table->elementAt(row , 7)->addNew<WPushButton>("edit");
	
		edit->clicked().connect(this,[this,currentRisk]{
			if(!dialog){
				cout<<"not exist"<<endl;
			dialog = make_unique<WDialog>("Update Risk");
			auto editRisk = make_unique<UpdateRisk>();
			dialog->contents()->addWidget(move(editRisk));
	
			auto closeButton = make_unique<WPushButton>("X");
			closeButton->clicked().connect([dialog = dialog.get()]{
				dialog->accept();				

			});
			dialog->finished().connect([this]{
				dialog.reset();		
			});		

			dialog->footer()->addWidget(move(closeButton));
		
		dialog->show();
		
		
		//container->addWidget(move(dialog));
		}
		else{
			cout<<"exist"<<endl;
		}
		});
		
	  	edit->setStyleClass("editButton");
		delet = table->elementAt(row , 8)->addNew<WPushButton>("Delete");
	  	delet->setStyleClass("deleteButton");
	  //table->elementAt(row , 7)->addNew<WText>(WString("{1}").arg(row));
		//table->elementAt(row , 8)->addNew<WText>(WString("{1}").arg(row));
	  }
	}
}
