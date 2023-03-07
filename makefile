install:
	cd ./build && \
		conan install ..

run:
	cd ./build && \
		cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release && \
		cmake --build . --config Release && \
		./main

protoc-generate:
	chmod +x ./tools/protoc-3.21.4.0
	./tools/protoc-3.21.4.0 \
		--plugin=protoc-gen-grpc=./tools/grpc_cpp_plugin \
		--cpp_out=./generated --grpc_out=./generated \
		-I . main.proto