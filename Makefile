CC = gcc
GCC_OPTIONS = -g -ansi -pedantic -std=c99 -Wall
SRC_FILES =  main.c functions.c
OUT_EXE = registration

build: $(OUT_EXE)

$(OUT_EXE): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(SRC_FILES)

clean:
	rm -f $(OUT_EXE) *.o core *~

rebuild: clean build 
   