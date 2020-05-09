CC = gcc
CFLAGS = -O1 -g -Wall -std=c99 -pedantic -lm -lgsl -lgslcblas
SOURCE = hw12.c
OBJ = $(patsubst %.c, %.o, $(SOURCE))
EXE = hw12
EXERAND = genRand
VALGRIND = valgrind --tool=memcheck --leak-check=yes --track-origins=yes 
RESULTS = out.txt
MEMTXT = mem.txt
VERB = VERBOSE
GE0 = ge0.txt
GE1 = ge1.txt
GE2 = ge2.txt
GE3 = ge3.txt
GE4 = ge4.txt
GE5 = ge5.txt
GE6 = ge6.txt
GE7 = ge7.txt
GE8 = ge8.txt
GE9 = ge9.txt
GE10 = ge10.txt
GE11 = ge11.txt
GE12 = ge12.txt
RANDTXT = rand.txt

.SILENT:
all: $(EXE)

$(EXE): $(SOURCE)
	@echo "Compiling hw12.c"
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXE)

test: $(EXE) 
	@echo "Running tests"
	@echo "ge0.txt test" > $(RESULTS)
	-./$(EXE) -i $(GE0) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge1.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE1) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge2.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE2) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge3.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE3) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge4.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE4) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge5.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE5) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge6.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE6) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge7.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE7) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge8.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE8) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge9.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE9) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge10.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE10) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge11.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE11) >> $(RESULTS) 2>&1
	@echo " " >> $(RESULTS)
	@echo "ge12.txt test" >> $(RESULTS)
	-./$(EXE) -i $(GE12) >> $(RESULTS) 2>&1
	@echo "check out.txt for results"

.PHONY: mem clean test all help
mem: $(EXE)
	@echo "running valgrind with rand.txt"
	chmod +x $(EXERAND) 
	./$(EXERAND) > $(RANDTXT)
	$(VALGRIND) ./$(EXE) -i $(RANDTXT) > $(MEMTXT) 2>&1
	@echo "valgrind output in mem.txt"

memwhere: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE) -i $(RANDTXT)

clean: 
	-rm -f $(EXE) $(RESULTS) $(MEMTXT)

help:
	@echo "make options are: all, clean, mem, test"

