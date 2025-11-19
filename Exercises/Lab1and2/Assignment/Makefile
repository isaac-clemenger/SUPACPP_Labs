CC=g++ # Name of our compiler
FLAGS= # Desired compiler flags 
SOURCES=AnalyseData.cxx CustomFunctions.cxx CartesianVector.cxx # Source files to compile
TARGET=AnalyseData # Name of the output file
OBJECTS=AnalyseData.o CustomFunctions.o CartesianVector.o # Object files needed to create the target

${TARGET}: ${OBJECTS} # Make targets from objects
	@echo "Linking..." 
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET} 
	@make clean 

# Create object files from source files
AnalyseData.o: AnalyseData.cxx 
	${CC} ${FLAGS} -c AnalyseData.cxx

CustomFunctions.o: CustomFunctions.cxx 
	${CC} ${FLAGS} -c CustomFunctions.cxx

CartesianVector.o: CartesianVector.cxx 
	${CC} ${FLAGS} -c CartesianVector.cxx

clean: # Clean up object files
	rm -f *.o *~ 

cleantarget: # Clean up target file
	rm -f ${TARGET} 