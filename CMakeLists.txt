cmake_minimum_required(VERSION 3.15)
project(grpc-cpp-demo CXX)

# protobuf and gRPC libraries should be present
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main gRPC::grpc++_unsecure)