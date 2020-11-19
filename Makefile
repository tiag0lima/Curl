CXX_C=g++ -c
CXX_O=g++ -o
LIBS = -lcurl -ljsoncpp

all: curl.o test_post test_put test_get


test_post:
	$(CXX_O) test_post test_post.cpp Curl.o $(LIBS)

test_put:
	$(CXX_O) test_put test_put.cpp Curl.o $(LIBS)

test_get:
	$(CXX_O) test_get test_get.cpp Curl.o $(LIBS)

curl.o:
	$(CXX_C) Curl.cpp

clean: rm

rm:
	rm *\.o test_put test_get test_post
