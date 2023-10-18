CC = gcc

all: proj

proj: midtermProject.o TrueFalse.o MultipleChoice.o FillBlank.o
	$(CC) midtermProject.o TrueFalse.o MultipleChoice.o FillBlank.o -o proj

MidtermProject.o: midtermProject.c
	$(CC) -c midtermProject.c

TrueFalse.o: TrueFalse.c
	$(CC) -c TrueFalse.c

MultipleChoice.o: MultipleChoice.c
	$(CC) -c MultipleChoice.c

FillBlank.o: FillBlank.c
	$(CC) -c FillBlank.c

clean:
	rm -f *.o proj