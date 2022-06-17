#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define COLONNE 8
#define LIGNE 8
void placerpiece(char map[COLONNE][LIGNE]);

//Pour la generation de tableau
int Tableau[COLONNE][LIGNE];
int i, j, horizontal, vertical, choix_piece;
char c, piece;
int menu_choice;
FILE* fptr;

//Initialization de la couleur blanche
void white() {
    printf("\033[0;37m");
}

//Initialization de la couleur noire
void black() {
    printf("\033[0;30m");
}

void main()
{
    //Lecture et modification de fichier

    if ((fptr = fopen("C:\\Test\\Chess_Position.txt", "w")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    for (c = 'A'; c <= 'H'; ++c)
    {
        printf("%2c", c);
    }
    printf("\n");

    int i = 0;
    int marks[8] = { 1,2,3,4,5,6,7,8 };//alignement vertical    
     //generation du tableau vertical   
    for (i = 0; i < 8; i++) {
        printf("%d \n", marks[i]);
    }

    //Ont genere le tableau
    for (i = 0; i < LIGNE; i++)
    {
        
            for (j = 0; j < COLONNE; j++)
            { 
                white();
                printf("%2d", Tableau[i][j]);
            }
            printf("\n");
    }

    do {
        printf("\n");
        printf("Que voulez vous faire ?\n");
        printf("1. Ajouter une piece sur l'echequier\n");
        printf("2. Quitter\n");
        scanf("%d", &menu_choice);
        system("cls");

      
        switch (menu_choice)
        {
        case 1:
            //Ajouter une pièce
            printf("Quel piece voulez-vous ajouter ?\n1. Roi\n2. Reine\n3. Fou\n4. Cavalier\n5. Tour\n6. Pion\n");
            scanf("%d", &choix_piece);
            system("cls");

            printf("En quel position horizontal ?\n");
            scanf("%d", &horizontal);

            system("cls");

            printf("En quel position vertical ?\n");
            scanf("%d", &vertical);
            system("cls");

            fprintf(fptr,"Vous avez ajouter %d\n", &choix_piece);
            fprintf(fptr, "En position horizontal %d\n", &horizontal);
            fprintf(fptr, "Ainsi que la position vertical %d\n", &vertical);
            fclose(fptr);

            break;
        }
    } while (menu_choice != 2);
   
}