#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]){
    int Nzeilen =0;
    int Nzeichen = 0;
    int Nwoerter = 0;
    printf("%d %d %d\n", Nzeilen, Nzeichen, Nwoerter);
    if (argc!=2){
        printf("Genau 1 Parameter angeben\n");
        return EXIT_FAILURE;
    }

    FILE*  datei;

    datei = fopen(argv[1], "r");

    if (datei == NULL){
        printf("Datei nicht gefunden!\n");

        return EXIT_FAILURE;
    }
    else{
        char zeichen;
        while(zeichen!=EOF){
            if (zeichen==10){
                ++Nzeilen;
            }
            zeichen=fgetc(datei);
        }
    }
    printf("Zeilen: %d\nZeichen: %d\nWörter: %d\n",Nzeilen, Nzeichen, Nwoerter);
    fclose(datei);
    return EXIT_SUCCESS;
}
