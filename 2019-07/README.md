## Slides
This is the publicly accessible [slide deck](https://docs.google.com/presentation/d/1skSQVbMKiybXHHjBqA7XOlxuzE9MXTKz7dCix0dLAH0/edit?usp=sharing).

## Steps to build
1. `export CPP_HOME=<some_dir>`
2. `cd ${CPP_HOME} && mkdir -p github.com/{ericniebler,google,knedlsepp,mrtazz}`
3. [Ubuntu] `sudo apt install libcurl4-openssl-dev libssl-dev libboost-dev libboost-system`
4. `git clone https://github.com/ericniebler/range-v3 github.com/ericniebler/range-v3`
5. `git clone https://github.com/knedlsepp/crow github.com/knedlsepp/crow`
6. `git clone https://github.com/mrtazz/restclient-cpp github.com/mrtazz/restclient-cpp`
7. `git clone https://github.com/google/flatbuffers github.com/google/flatbuffers`
8. `cd github.com/mrtazz/restclient-cpp && ./autogen.sh && ./configure && make && sudo make install`
9. `cd github.com/google/flatbuffers && cmake -DCMAKE_BUILD_TYPE=Release && make && sudo make install`
10. `git clone https://github.com/amukherj/cpp-meetup`
11. `cd cpp-meetup/2019-07  && cd lang && make && cd ../lib && make && cd third_party && make`
12. While running individual binaries, set the `LD_LIBRARY_PATH` correctly to ensure all library dependencies are correctly loaded.
