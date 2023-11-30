/* Λειτουργικά Συστήματα | Επεισόδιο ΙΙ | Ομάδα Χρηστών ΙΙΙ | Παραλλαγή της cp γνωστή και ως mycp */

/* -------------------------------------------------------------- */

/* Τμήμα εισαγωγής βιβλιοθηκών εισόδου / εξόδου στην C */

#include <stdio.h>
#include <stdlib.h>
#include "error_handling.h"

/* Aξιοποιούνται οι: stdio.h η οποία περιλαμβάνει βασικές
   συναρτήσεις εισόδου / εξόδου όπως η fprintf(), scanf()
   fopen(), fclose(), κα. και η stdlib.h η οποία περιλαμβάνει διάφορες συναρτήσεις
   που σχετίζονται με την λειτουργία του εκάστοτε συστήματος όπως:
   malloc(), atoi(), exit(), system() κα. Επίσης, γίνεται χρήση των "error_handling.h", 
   "report_generator.h" και "file_operations.h" τα οποία είναι τα header αρχεία για τα αντίστοιχα 
   "error_handling.c", "report_generator.c" και "file_operations.c", όπου σε αυτά βρίσκονται οι 
   δηλώσεις μόνο των συναρτήσεων και των σταθερών που αξιοποιούνται στα αρχεία 
   που γίνονται include. Αυτά χειρίζονται τα σφάλματα, δημιουργούν το 
   report.out αρχείο και υλοποιούν όλες τις διεργασίες που θέλουμε για το αυγκεκριμένο
   πρόγραμμα, όπως το την αντιγραφή του αρχείου, το άνοιγμα ενός αρχείου κα. , αντίστοιχα*/

/* -------------------------------------------------------------- */

int main(int argc, char *argv[]) {

    /*  Δήλωση μεταβλητών  */




    /*  Έλεγχος ορθότητας ορισμάτων εισόδου  */

    if (validateArguments(argc, argv, &source_path) != SUCCESS) {
        return ERR_INSUFFICIENT_ARGS;
    }

    printf("Arguments validated.\n");

    /*  Άνοιγμα του πηγαίου αρχείου  */

    FILE *infile = openFile(source_path, "rb");
    if (infile == NULL) {
        fprintf(stderr, "The program exits with code 3!\n");
        return ERR_UNABLE_TO_OPEN_INFILE_FILE;
    }

    printf("Infile file opened successfully!\n");

}