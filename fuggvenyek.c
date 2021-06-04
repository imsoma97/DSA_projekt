//
// Created by Gergo on 4/14/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include "fuggvenyek.h"
#include "string.h"

tree * beolvas(const char *filenev){

    FILE *f;
    lemezek *l;

    f = fopen(filenev, "r");

    int i,j,szam;


    fscanf(f,"%d", &szam);

    l = (lemezek*)calloc(szam,sizeof(lemezek));

    l->lemezszam = szam;



    for(i = 0; i < l->lemezszam; i++) {



        fscanf(f, "%s", (l + i)->lemezkod);

        fscanf(f, "%s", (l+i)->eloadonev);

        fscanf(f, "%s", (l+i)->albumnev);

        fscanf(f, "%d",&(l + i)->formatumkod);

        fscanf(f, "%d", &(l + i)->kiadasiev);

        fscanf(f, "%s", (l + i)->kiadasiorszag);

        fscanf(f, "%d", &(l + i)->db);

        (l + i)->szl = (szamlista *) calloc((l + i)->db, sizeof(szamlista));



        for (j = 0; j < (l + i)->db; j++) {
            fscanf(f, "%s", (l + i)->szl[j].sorszamkod);

            fscanf(f, "%s", (l + i)->szl[j].szamcim);

        }

        fscanf(f, "%d", &(l + i)->eladotdarabszam);


    }
    fclose(f);


    tree *root = create((l+0)); //Ricardo Villalobos
    tree *n1 = create((l+1)); // Dj_Discuopline
    tree *n2 = create((l+2)); // Cabanelas
    tree *n3 = create((l+3)); //Andrea
    tree *n4 = create((l+4));
    tree *n5 = create((l+5));
    tree *n6 = create((l+6));
    tree *n7 = create((l+7));
    tree *n8 = create((l+8));
    tree *n9 = create((l+9));
    tree *n10 = create((l+10));
    tree *n11 = create((l+11));
    tree *n12 = create((l+12));
    tree *n13 = create((l+13));

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->right = n5;
    n2->left = n6;

    n6->right = n7;
    n7->left = n8;

    n4->left = n9;
    n9->right = n10;

    n10->left = n11;
    n10->right = n12;

    n12->right =n13;

    return root;
}

void kiir(lemezek *l, int hossz) {

    int j,i;

    for(i = 0; i < hossz; i++) {


        printf("%s\n",(l + i)->lemezkod);

        printf("%s\n",(l+i)->eloadonev);

        printf("%s\n",(l+i)->albumnev);

        printf("%d ", (l + i)->formatumkod);


        printf( "%d ", (l + i)->kiadasiev);


        printf("%s ",(l + i)->kiadasiorszag);

        printf("%d\n", (l + i)->db);





        for (j = 0; j < (l + i)->db; j++) {

            printf("%s ",(l + i)->szl[j].sorszamkod);

            printf("%s\n",(l + i)->szl[j].szamcim);



        }

        printf("%d\n", (l + i)->eladotdarabszam);

    }

}

void legtobbetEladott(lemezek *l, int hossz){

    int i, j;
    int max = 0;

    for(i = 0; i < hossz; i++){


        if( (l+i)->eladotdarabszam > max){
            max = (l+i)->eladotdarabszam;
            j = i;
        }


    }

    printf("Legtobbet eladott lemez eloadoja = %s \n", (l+j)->eloadonev);
    printf("Legtobbet eladott album neve = %s \n", (l+j)->albumnev);
    printf("ez a lemez %d-szer volt eladva.\n", max);

}

void ketEzerElott(lemezek *l, int hossz){

    for(int i = 0; i < hossz; i++){
        if((l+i)->kiadasiev < 2000){
            printf("%s\n",(l+i)->eloadonev);
            printf("%s\n",(l+i)->albumnev);
            printf( "%d\n", (l + i)->kiadasiev);

        }
    }
}

void abcEloadok(lemezek *l, int hossz) {

    int i, j;
    char temp[100];

    for (i = 0; i < hossz - 1; i++) {
        for (j = 0; j < hossz - i - 1; j++) {
            if (strcmp((l + j)->eloadonev, (l + j + 1)->eloadonev) > 0) {
                strcpy(temp, (l + j)->eloadonev);
                strcpy((l + j)->eloadonev, (l + j + 1)->eloadonev);
                strcpy((l + j + 1)->eloadonev, temp);
            }
        }
    }

    for(i = 0; i < hossz; i++){
        printf("%s \n", (l+i)->eloadonev);
    }

}

void eloadoLemezei(lemezek *l,char eloado[], int hossz){

for(int i = 0; i < hossz; i++){
    if(strcmp(eloado, (l+i)->eloadonev) == 0){
        printf("%s\n",(l+i)->eloadonev);
        printf("%s\n",(l+i)->albumnev);
        printf( "%d\n", (l + i)->kiadasiev);

    }
}




}


tree * create(lemezek * a) {
    tree *t = (tree *) malloc(sizeof(tree));
    t->data = a;
    t->right = NULL;
    t->left = NULL;

    return t;
}

void printtab(int num){

    for(int i = 0; i < num; i++){
        printf("\t");
    }

}


void preorder_rec(tree *root, int level){  // node->left->right

    if(root == NULL){
        printtab(level);
        printf("----ures ag----\n");
        return;
    }

    printtab(level);
    printf("nev = %s\n", root->data->eloadonev);

    printtab(level);
    printf("left: \n");
    preorder_rec(root->left, level+1);


    printtab(level);
    printf("right: \n");
    preorder_rec(root->right, level+1);

    printtab(level);
    printf("----vege----\n");

}

void preorder(tree * root){
    preorder_rec(root,0);
}

void inorder_rec(tree *root, int level){  // left->node->right

    if(root == NULL){
        printtab(level);
        printf("----ures ag----\n");
        return;
    }


    printtab(level);
    printf("left: \n");
    inorder_rec(root->left, level+1);

    printtab(level);
    printf("nev = %s\n", root->data->eloadonev);

    printtab(level);
    printf("right: \n");
    inorder_rec(root->right, level+1);

    printtab(level);
    printf("----vege----\n");

}

void inorder(tree * root){
    inorder_rec(root,0);
}

void postorder_rec(tree *root, int level){  // left->right->node kiir

    if(root == NULL){
        printtab(level);
        printf("----ures ag----\n");
        return;
    }


    printtab(level);
    printf("left: \n");
    postorder_rec(root->left, level+1);

    printtab(level);
    printf("right: \n");
    postorder_rec(root->right, level+1);

    printtab(level);
    printf("nev = %s\n", root->data->eloadonev);

    printtab(level);
    printf("----vege----\n");

}

void postorder(tree * root){
    postorder_rec(root,0);
}
