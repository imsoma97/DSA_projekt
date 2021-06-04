
#include "fuggvenyek.h"

//dinamikus helyffoglalas, amikor menet kozbe kell lefoglalj, nem tudod elore

int main() {

    int darabSzam;
    lemezek *l;

    tree *t;


   t = beolvas("D:\\UNIVERSITY\\I_ev\\Projekt_S_G\\lemezek.txt");

    int option;  // menubol mit valasztunk
    int eloado;
    char eloadostr[100];
    bool repeat = true;   //ezze tudsz kilepni a while-bol
    while(repeat) {
        printf("Lehetseges muveletek:\n"
               "0. Kilepes\n"
               "1. Preorder\n"
               "2. Inorder\n"
               "3. Postorder\n"
               );


        printf("Valassz opciot: ");
        scanf("%i", &option);  // 0-9
        switch(option) {
            case 0:
                printf("Kilepes...");
                repeat = false;
                break;
            case 1:
                preorder(t);
                break;
            case 2:
                inorder(t);
                break;
            case 3:
                postorder(t);
                break;

            default:
                printf("Helytelen opcio. Probald ujra");
                break;
        }
    }


    return 0;
}
