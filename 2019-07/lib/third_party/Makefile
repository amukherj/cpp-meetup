CXX=g++
CXXFLAGS=-std=c++17 -I $(CPP_HOME)/github.com/knedlsepp/crow/include
BINARIES=01flatbuffers 02http_client 05crow_sample

all: $(BINARIES)

%_generated.h: %.fbs
	flatc --cpp --reflect-names $<

01flatbuffers: 01flatbuffers.cc 01address_generated.h
	$(CXX) -o $@ $(CXXFLAGS) $< -lflatbuffers

02http_server: 02http_server.cc
	$(CXX) -o $@ $(CXXFLAGS) $< -lnghttp2_asio -lboost_system -pthread -lssl -lcrypto

02http_client: 02http_client.cc
	$(CXX) -o $@ $(CXXFLAGS) $< -lrestclient-cpp -lcurl -pthread

05crow_sample: 05crow_sample.cc
	$(CXX) -o $@ $(CXXFLAGS) $< -lboost_system -pthread

clean:
	rm -f $(BINARIES)
