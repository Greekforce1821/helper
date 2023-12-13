/* Λειτουργικά Συστήματα | Επεισόδιο ΙΙI | Ομάδα Χρηστών ΙΙΙ | Παραλλαγή της sort μέσω pipelining  */

/* -------------------------------------------------------------- */


#include "program.h" // Συμπερίληψη του αρχείου κεφαλίδας του προγράμματος
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Συνάρτηση που εμφανίζει μήνυμα σφάλματος και εξάγει το πρόγραμμα με κατάσταση σφάλματος

void displayErrorMessage(const char *message, int code) {
    fprintf(stderr, "Error: %s\nThe program terminates with a code %d!\n", message, code);
}

// Συνάρτηση που εκτελεί την εντολή ταξινόμησης και αντικαθιστά την έξοδο με την έξοδο του αγωγού

void executeSortCommand(int pipefd[], char *filename) {
    close(pipefd[0]);

    FILE *file = fopen(filename, "r");
    if (file) {
        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0) {
            displayErrorMessage("An empty file was provided", EMPTY_FILE_ERROR);
            exit(EMPTY_FILE_ERROR);
        }
        fclose(file);
    }

    if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
        displayErrorMessage("Failure to duplicate the file descriptor.", DUP_ERROR);
        exit(DUP_ERROR);
    }

    execlp("sort", "sort", "-n", filename, NULL);
    displayErrorMessage("Failure of execlp", EXEC_ERROR);
    exit(EXEC_ERROR);
}

// Συνάρτηση που διαβάζει και εκτυπώνει τα ταξινομημένα δεδομένα από τον αγωγό

void readAndPrintSortedData(int pipefd[]) {
    close(pipefd[1]);
    
    char buffer;
    char message[] = "Data received through pipe ";
    int flag = 1;

    while (read(pipefd[0], &buffer, sizeof(buffer)) > 0) {
        if (flag == 1) {
            if (write(STDOUT_FILENO, message, sizeof(message) - 1) == -1) {
                displayErrorMessage("Write Failure.", WRITE_ERROR);
                exit(WRITE_ERROR);
            }
            flag = 0;
        }

        if (write(STDOUT_FILENO, &buffer, 1) == -1) {
            displayErrorMessage("Write Failure.", WRITE_ERROR);
            exit(WRITE_ERROR);
        }

        if (buffer == '\n') {
            flag = 1;
        }
    }
}

/* -------------------------------------------------------------- */

/* You reached the end of the following file :D 
   CHRISTOS - SPYRIDON KARYDIS & SPYRIDON - EFTYCHIOS KOKOTOS */
