CC=g++
FLAGS=-std=c++20 -w
TARGET=AnalyseData
OBJECTS=AnalyseData.o CustomFunctions.o #Intermediate object files


#First target in Makefile is what gets made by default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..." 
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}
	@make clean 

AnalyseData.o : AnalyseData.cxx CustomFunctions.h
	${CC} ${FLAGS} -c AnalyseData.cxx

CustomFunctions.o : CustomFunctions.cxx CustomFunctions.h
	${CC} ${FLAGS} -c CustomFunctions.cxx

clean: #No targets, just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: 
	@rm -f ${TARGET}