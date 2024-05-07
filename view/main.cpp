#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WServer.h>
#include "Audit.h"

std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env)
{
    auto app = std::make_unique<Wt::WApplication>(env);
    app->setTitle("Risk Tracker");

    app->root()->addWidget(std::make_unique<Audit>());

    return app;
}

int main(int argc, char **argv)
{
    try {
        Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);

        // Specify the desired port number
        int desiredPort = 8081;

        std::string httpAddress = "0.0.0.0";
        std::string httpPort = std::to_string(desiredPort);

        server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(Wt::EntryPointType::Application, createApplication);

        server.run();
    } catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
