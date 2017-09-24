#include <stdio.h>
#include <stdlib.h>
#define MEM_SIZE 1024
struct mblock{
    size_t size;
    struct mblock * next;
    struct mblock * prev;
};
char memory[MEM_SIZE];
void memory_init(){
    struct mblock *  mb = (struct mblock*)(&memory[0]);
    mb -> size = 0;
    mb -> next = NULL; //gleich wie *mb.next
    mb -> prev = NULL;

}
void* memory_allocate(){
    struct mblock * mbl = (struct mblock*)(&memory[16]);
    struct mblock * mblo = (struct mblock*)(&memory[128]);
     struct mblock *  mb = (struct mblock*)(&memory[0]);
        mb -> size = 0;
        mb -> next = mbl; //gleich wie *mb.next
        mb -> prev = NULL;
        mbl -> size = 26;
        mbl -> next = mblo;
        mbl -> prev = mb;
        mblo -> size = 8;
        mblo -> next = NULL;
        mblo -> prev = mbl;
}
void memory_print() {
    struct mblock *  mb = (struct mblock*)(&memory[0]);
    while (mb != NULL){
        printf("Die Size ist: %zu\n", mb -> size);
        char * nextmb;
        if (mb -> next == NULL){
            nextmb = &memory[MEM_SIZE-1];
        }
        else {
            nextmb = (char*)(mb -> next);
        }
        size_t free = nextmb - ((char*)(mb) + mb -> size + sizeof(struct mblock));
        printf ( "Soviel ist noch Frei!\n %zu\n", free );
        mb = mb -> next;
    }

}
int main(){
    memory_init();
    memory_allocate();
    memory_print();
    return EXIT_SUCCESS;
}

