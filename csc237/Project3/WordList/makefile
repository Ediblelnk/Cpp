COMPILER  = g++

DEBUG  = 

EXE  = app

HDRS  = WordData.h\
	WordDataList.h\
	WordList.h\

OBJS  = WordData.o\
	WordDataList.o\
	app.o\

SRC  = 	WordData.cpp\
	WordDataList.cpp\
	app.cpp\


##########################################################################
$(EXE): $(OBJS) $(HDRS) $(SRC)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

WordData.o:  WordData.cpp WordData.h 
	$(COMPILER) -c WordData.cpp $(DEBUG)

WordDataList.o:  WordData.h WordDataList.cpp WordDataList.h WordList.h 
	$(COMPILER) -c WordDataList.cpp $(DEBUG)

app.o:  WordDataList.h WordList.h app.cpp 
	$(COMPILER) -c app.cpp $(DEBUG)


clean:
	del *.o $(EXE)

