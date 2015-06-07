CC = cc
CXX = c++

CFLAGS  = -g -Wall  -I/usr/local/include 

TARGET = getopt-bsdc 
#TARGET_CPP = getopt-c

all: $(TARGET) $(TARGET_CPP)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

$(TARGET_CPP): $(TARGET_CPP).cc
	$(CC) $(CFLAGS) -o $(TARGET_CPP) $(TARGET_CPP).cc

clean:
	$(RM) $(TARGET)