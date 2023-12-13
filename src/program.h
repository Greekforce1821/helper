/* Λειτουργικά Συστήματα | Επεισόδιο ΙΙI | Ομάδα Χρηστών ΙΙΙ | Παραλλαγή της sort μέσω pipelining  */

/* -------------------------------------------------------------- */

/* Τμήμα εισαγωγής βιβλιοθηκών εισόδου / εξόδου στην C*/

#ifndef PROGRAM_H_ 
#define PROGRAM_H_

/* Ορισμός των σταθέρων στους αριθμούς που αντιστοιχεί στον κωδικό σφάλματος που επιθυμούμε*/

#define EMPTY_FILE_ERROR 1
#define ARGUMENT_ERROR 2
#define PIPE_CREATION_ERROR 3
#define FORK_ERROR 4
#define DUP_ERROR 5
#define EXEC_ERROR 6
#define READ_ERROR 7
#define WRITE_ERROR 8
#define CHILD_EXIT_ERROR 9
#define WAIT_ERROR 10

// Πρότυπα συναρτήσεων που υπάρχουν στο πρόγραμμα

void displayErrorMessage(const char *message, int code);
void executeSortCommand(int pipefd[], char *filename);
void readAndPrintSortedData(int pipefd[]);

#endif /* PROGRAM_H_ */

/* -------------------------------------------------------------- */

/* You reached the end of the following file :D 
   CHRISTOS - SPYRIDON KARYDIS & SPYRIDON - EFTYCHIOS KOKOTOS */
