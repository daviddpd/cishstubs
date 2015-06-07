CC = cc
CXX = c++

CFLAGS  = -g -Wall  -I/usr/local/include 

TARGET = getopt-bsdc getopt_long-bsdc
#TARGET_CPP = getopt-c

all: $(TARGET) $(TARGET_CPP)

%: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

$(TARGET_CPP): $(TARGET_CPP).cc
	$(CC) $(CFLAGS) -o $(TARGET_CPP) $(TARGET_CPP).cc

clean:
	$(RM) $(TARGET)