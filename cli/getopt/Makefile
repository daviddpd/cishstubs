CC = cc
CXX = c++

CFLAGS  = -g -Wall  -I/usr/local/include 

TARGET = getopt-bsdc getopt_long-bsdc
#TARGET_CPP = getopt-c

all: $(TARGET) $(TARGET_CPP)

%: %.c 
	$(CC) -o $@ $< $(CFLAGS)

#%: %.cc 
#	$(CXX) $(CXXFLAGS) -o $@ $<
