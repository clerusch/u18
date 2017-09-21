#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]){
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
            printf("%c",zeichen);
            zeichen=fgetc(datei);
        }
    }
    printf("\n");
    fclose(datei);
    return EXIT_SUCCESS;
}
