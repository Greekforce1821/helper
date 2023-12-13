# Ορισμός μεταβλητών

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Ο στόχος που θα εκτελεστεί εξ' ορισμού

all: helper

# Ο στόχος helper εξαρτάται από τα αρχεία program.o και helper.o

helper: program.o helper.o
	$(CC) $(CFLAGS) -o helper program.o helper.o

# Το αρχείο program.o εξαρτάται από τα αρχεία program.c και program.h

program.o: program.c program.h
	$(CC) $(CFLAGS) -c program.c

# Το αρχείο main.o εξαρτάται από τα αρχεία helper.c και program.h

main.o: main.c program.h
	$(CC) $(CFLAGS) -c helper.c

# Στόχος για τον καθαρισμό: διαγράφει τα αρχεία .o και το εκτελέσιμο helper

clean:
	rm -f *.o helper
	
	
################################################################
#               Μήνυμα στο τέλος του Makefile                  #
# -------------------------------------------------------------#
#         You reached the end of the following file :D         #
#  CHRISTOS - SPYRIDON KARYDIS & SPYRIDON - EFTYCHIOS KOKOTOS  #
# -------------------------------------------------------------#
################################################################

