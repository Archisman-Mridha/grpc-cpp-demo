#include <iostream>
#include <grpcpp/grpcpp.h>
#include <string>
#include "./generated/main.grpc.pb.h"

using namespace std;
using namespace grpc;
using namespace grpc_cpp_test;

class GrpcCppTestService final : public GrpcCppTest::Service {
    private:
        Status TestGrpcServer(
            ServerContext* context, const TestGrpcServerRequest* request, TestGrpcServerResponse* response
        ) override
        {
            response->set_message("server is running");

            return Status::OK;
        }
};

int main( ) {
    string listeningAddress= "0.0.0.0:4000";

    ServerBuilder serverBuilder;
        serverBuilder.AddListeningPort(listeningAddress, InsecureServerCredentials( ));

    GrpcCppTestService grpcCppTestService;
    serverBuilder.RegisterService(&grpcCppTestService);

    unique_ptr<Server> server(serverBuilder.BuildAndStart( ));
    cout<<"starting gRPC server at port 4000"<<endl;
    server->Wait( );

    return 0;
}