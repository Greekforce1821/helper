/* Λειτουργικά Συστήματα | Επεισόδιο ΙΙI | Ομάδα Χρηστών ΙΙΙ | Παραλλαγή της sort μέσω pipelining  */

/* -------------------------------------------------------------- */

#include "program.h" 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    // Έλεγχος για τον σωστό αριθμό των ορισμάτων

    if (argc != 2) {
        fprintf(stderr, "Usage: %s file name\n", argv[0]);
        displayErrorMessage("Incorrect number of arguments.", ARGUMENT_ERROR);
        return ARGUMENT_ERROR;
    }

    // Δημιουργία ενός αγωγού για επικοινωνία μεταξύ διεργασιών

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        displayErrorMessage("Failure to create a pipe.", PIPE_CREATION_ERROR);
        return PIPE_CREATION_ERROR;
    }

    // Δημιουργία μιας παιδικής διεργασίας

    pid_t pid = fork();
    if (pid < 0) {
        displayErrorMessage("Failure to create a child process.", FORK_ERROR);
        return FORK_ERROR;
    }

    if (pid == 0) {

        // Παιδική διεργασία: εκτέλεση της εντολής ταξινόμησης

        executeSortCommand(pipefd, argv[1]);
        
    } else {

        // Γονική διεργασία: ανάγνωση και εκτύπωση των ταξινομημένων δεδομένων

        readAndPrintSortedData(pipefd);

        // Αναμονή για την ολοκλήρωση της παιδικής 
        
        int status;
        if (wait(&status) == -1) {
            displayErrorMessage("Failure of waiting.", WAIT_ERROR);
            return WAIT_ERROR;
        }

        // Έλεγχος της κατάστασης της παιδικής διεργασίας

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0 && exit_status != 1) {
                fprintf(stderr, "The child process exited with a non-zero status: %d\n", exit_status);
                displayErrorMessage("The child process exited with a non-zero status.", CHILD_EXIT_ERROR);
                return CHILD_EXIT_ERROR;
            }
        } else {
            displayErrorMessage("Failure of waiting.", WAIT_ERROR);
            return WAIT_ERROR;
        }
    }

    return EXIT_SUCCESS;
}

/* -------------------------------------------------------------- */

/* You reached the end of the following file :D 
   CHRISTOS - SPYRIDON KARYDIS & SPYRIDON - EFTYCHIOS KOKOTOS */
