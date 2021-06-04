//
// Created by Gergo on 4/13/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <stdbool.h>

#ifndef PROJEKT_S_G_FUGGVENYEK_H
#define PROJEKT_S_G_FUGGVENYEK_H

typedef struct Szamlista{
    char sorszamkod[3];
    char szamcim[100];
}szamlista;

typedef struct lemezek {
    char lemezkod[100];
    int lemezszam;
    char eloadonev[100];
    char albumnev[100];
    int formatumkod; //hany inches
    int kiadasiev;
    char kiadasiorszag[25];
    int eladotdarabszam;
    int db;
    szamlista *szl;
}lemezek;

typedef struct tree{
    lemezek * data;
    struct tree *left, *right;
}tree;

tree * beolvas(const char *f);
void kiir(lemezek *l, int i);

tree * create(lemezek * a);

void legtobbetEladott(lemezek *l, int i);
void ketEzerElott(lemezek *l, int i);
void abcEloadok(lemezek *l, int i);
void eloadoLemezei(lemezek *l,char eloado[],int i);

void preorder(tree *root);
void inorder(tree *root);
void postorder(tree *root);
#endif //PROJEKT_S_G_FUGGVENYEK_H
