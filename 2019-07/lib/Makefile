CXX=clang++
CXXFLAGS=-std=c++17 -I $(CPP_HOME)/github.com/ericniebler/range-v3/include
LDFLAGS=-pthread
BINARIES=01variant 02try_range 03scoped_lock 04string_views 05shared_mutex

all: $(BINARIES)

clean:
	rm -f $(BINARIES)
