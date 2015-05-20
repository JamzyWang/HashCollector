
COMPILER      = -c++
OPTIONS       = -ansi -pedantic -Wall -o
OPTIONS_LIBS  = -ansi -pedantic -Wall -c

all: HashFunctions.o HashTest

HashFunctions.o: HashFunctions.cpp HashFunctions.h
	$(COMPILER) $(OPTIONS_LIBS) HashFunctions.cpp

HashTest: HashFunctions.cpp HashTest.cpp
	$(COMPILER) $(OPTIONS) HashTest HashTest.cpp HashFunctions.o


clean:
	rm -f core *.o *.bak *stackdump *#
  
#
# The End !
#