
/* ***** Code du BlackJack ****
*** - tirage aléatoire de 04 cartes.
*** - chaque carte tirée change leur valeur 0.
*** -  si la carte  tirée a la valeur 0, elle n'est pas affichée.
***
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int Numero, n, CarteSortie, Zero, NbreJoueur, Tour;
int Joueur1[10] ={0,0,0,0,0,0,0,0,0,0,};
int Joueur2[10] ={0,0,0,0,0,0,0,0,0,0,};
int ScoreJoueur1;
int ScoreJoueur2;
char reponse[10];

struct Carte
    {
        char NomCarte[30];
        int ValeurCarte;
    };

typedef struct Carte JeuDeCartes[52];
//struct Carte CopieJeuDeCartes[52];

JeuDeCartes JeuDeCartesOriginal =
   {
   {"AS de Trefle" , 11}, {"Roi de Trefle",  10}, {"Dame de Trefle", 10}, {"Valet de Trefle", 10}, {"Dix de Trefle", 10},
   {"Neuf de Trefle", 9}, {"Huit de Trefle", 8 }, {"Sept de Trefle" ,7 }, {"Six de Trefle", 6 }, {"Cinq de Trefle" , 5}, 
   {"Quatre de Trefle ", 4}, {"Trois de Trefle ", 3}, {"Deux de Trefle ", 2},{"AS de Pique" , 11}, {"Roi de Pique",  10}, 
   {"Dame de Pique", 10}, {"Valet de Pique", 10},{"Dix de Pique", 10}, {"Neuf de Pique", 9}, {"Huit de Pique", 8}, 
   {"Sept de Pique" ,7 }, {"Six de Pique", 6 }, {"Cinq de Pique" , 5},{"Quatre de Pique ", 4}, {"Trois de Pique ", 3}, 
   {"Deux de Pique ", 2}, {"AS de Coeur" , 11}, {"Roi de Coeur",  10}, {"Dame de Coeur",10}, {"Valet de Coeur", 10}, 
   {"Dix de Coeur", 10}, {"Neuf de Coeur", 9},{"Huit de Coeur", 8 }, {"Sept de Coeur" ,7 }, {"Six de Coeur", 6 },
   {"Cinq de Coeur" , 5}, {"Quatre de Coeur ", 4}, {"Trois de Coeur ", 3}, {"Deux de Coeur ", 2}, {"AS de Carreau" , 11}, 
   {"Roi de Carreau",  10},{"Dame de Carreau", 10}, {"Valet de Carreau", 10}, {"Dix de Carreau", 10}, {"Neuf de Carreau", 9}, 
   {"Huit de Carreau", 8 }, {"Sept de Carreau" ,7 }, {"Six de Carreau", 6 }, {"Cinq de Carreau" , 5}, 
   {"Quatre de Carreau ", 4},{"Trois de Carreau ", 3}, {"Deux de Carreau ", 2}
   };

JeuDeCartes CopieJeuDeCartesCreation;
JeuDeCartes Copie2JeudeCartes;

/***********************************************************************************************************************************************************************/
/* **** Declaration des fonctions
****** */

int Selection ();
int AffichageAleatoire();
int Creation ();
int Random();
int TirageCarte ();
int NeutralisationCarte ();
int PremierTour ();
int AffichageScore ();
int DemandeCarte ();

/***********************************************************************************************************************************************************************/
/* **** Implementation des fonctions ***********************************************************************************************************************************/
/********************************************************************************************************************************************************************* */

/***********************************************************************************************************************************************************************/
/* **** Implementation de la fonction Main ().
****** */
int main (void)
{
    srand(time(NULL));
    Creation ();
//    AffichageAleatoire ();
//    Selection ();
    PremierTour ();

/****** Tours suivants */    

Tour= 1;
    while (((ScoreJoueur1 || ScoreJoueur2 ) >= 21) || (reponse != 0) || Tour == 6)
        {
        Tour++;
        ScoreJoueur1 = Joueur1[0] + Joueur1[1] + Joueur1[2] +Joueur1[3] +Joueur1[4] +Joueur1[4] +Joueur1[5] +Joueur1[6] +Joueur1[7] +Joueur1[8] +Joueur1[9];
        ScoreJoueur2 = Joueur2[0] + Joueur2[1] + Joueur2[2] +Joueur2[3] +Joueur2[4] +Joueur2[4] +Joueur2[5] +Joueur2[6] +Joueur2[7] +Joueur2[8] +Joueur2[9];
   
        if ((ScoreJoueur1 > 21) || (ScoreJoueur2  > 21)  || (Tour == 6)) {break;}
         // char reponse[10];  //Assez grand pour une petite réponse plus le '\n' et '\0'

        printf("\n\tJoueur1,  votre score est de : %i , Voulez-vous une autre carte (juste [Entrée] pour Oui, autre touche pour Non) ? ",ScoreJoueur1);

// Lire la ligne entière de l'entrée standard
// sizeof(reponse) garantit de ne pas dépasser la taille du buffer
        if (fgets(reponse, sizeof(reponse), stdin) != NULL) 
            {
    // Vérifier si la ligne est vide (contient seulement '\n')
    // Ou si elle contient "Oui" (si vous voulez être explicite)
            if (strcmp(reponse, "\n") == 0) 
                {
        // L'utilisateur a appuyé sur Entrée
        // Continuer la boucle (par exemple, rejouer = 1)
                printf("\n\tOkay Joueur 1, on tire une autre carte %i tour! ", Tour);
                TirageCarte ();
                printf ("\n\tCarte tirée Pour le Joueur 1 (index %i): %s, Valeur: %i\n", Numero, CopieJeuDeCartesCreation[Numero].NomCarte, CopieJeuDeCartesCreation[Numero].ValeurCarte);
                Joueur1 [Tour]=CopieJeuDeCartesCreation[Numero].ValeurCarte;
                
                printf ("\n\tScore Joueur 1: %i.\n",  ScoreJoueur1);
                } 
            else 
                {
        // L'utilisateur a tapé quelque chose d'autre
        // Sortir de la boucle (par exemple, rejouer = 0)
                printf("\n\tJoueur 1 servi, score: %i.\n", ScoreJoueur1);
                }
/*            else 
                {
    // Erreur de lecture (par exemple, fin de fichier)
                printf("\n\tErreur de lecture de l'entrée. Fin du tour.\n");
                }
*/          }
        



        printf("\n\tJoueur2,  votre score est de : %i , Voulez-vous une autre carte (juste [Entrée] pour Oui, autre touche pour Non) ? ",ScoreJoueur2);
// Lire la ligne entière de l'entrée standard
// sizeof(reponse) garantit de ne pas dépasser la taille du buffer
        if (fgets(reponse, sizeof(reponse), stdin) != NULL) 
            {
    // Vérifier si la ligne est vide (contient seulement '\n')
    // Ou si elle contient "Oui" (si vous voulez être explicite)
            if (strcmp(reponse, "\n") == 0) 
                {
        // L'utilisateur a appuyé sur Entrée
        // Continuer la boucle (par exemple, rejouer = 1)
                printf("\n\tOkay Joueur 2, on tire une autre carte %i tour! ", Tour);
                TirageCarte ();
                printf ("\n\tCarte tirée pour le Joueur 2 (index %i): %s, Valeur: %i \tScore Actuel Joueur2 : %i ", Numero, CopieJeuDeCartesCreation[Numero].NomCarte, CopieJeuDeCartesCreation[Numero].ValeurCarte, ScoreJoueur2);
                Joueur2 [Tour]=CopieJeuDeCartesCreation[Numero].ValeurCarte;

                printf ("\n\tScore Joueur 2: %i.\n",  ScoreJoueur2);
                } 
            else 
                {
        // L'utilisateur a tapé quelque chose d'autre
        // Sortir de la boucle (par exemple, rejouer = 0)
                printf("\n\tJoueur 2 servi, score: %i.\n", ScoreJoueur2);
                break;
                }
/*            else 
                {
    // Erreur de lecture (par exemple, fin de fichier)
                printf("\n\tErreur de lecture de l'entrée. Fin du tour.\n");
*/          }
        printf ("\n\t ***** Fini!!! tour %i *****\n",Tour);
//        AffichageScore ();
        }
    





/****** Fin des tours */

    AffichageScore ();
    printf("\n\n\t");
    return 1;
    exit;
}

/***********************************************************************************************************************************************************************/
/* ***** Implementation de la fonction Creation ().
******* */
int Creation()
{
    //JeuDeCartes CopieJeuDeCartes, Copie élément par élément
    int i;
    for (i = 0; i < 52; i++)
       {
            strcpy(CopieJeuDeCartesCreation[i].NomCarte , JeuDeCartesOriginal[i].NomCarte);     // copie de char
            (CopieJeuDeCartesCreation[i].ValeurCarte =  JeuDeCartesOriginal[i].ValeurCarte);    // Copie de int
        };
/*    printf ("\n\bQuel est le nombre de Joueur ? ");
    scanf ("%d",&NbreJoueur);

    for (int i=0; i++; i< NbreJoueur )
        {
            for (int j=0; j++; j<10)
            {            
                TableauJoueur [i][j]=0;
                printf ("\n\tRemplissage du TableauJoueur %i %i", i,j);
            }
        }
    for (int i=0;i++ ; i< NbreJoueur )
        {
            for (int j=0; j++; j<10)
            {
                printf ("\n\t%i", (TableauJoueur[i][j]));
            }
        }
*/    return 1;
}


int TirageCarte ()
{
    Random();
    Numero = n;
    while (CopieJeuDeCartesCreation[Numero].ValeurCarte == 0)
        {                
            printf ("\nLancement de la boucle anti zero");
            Random();
            Numero = n;
            Zero ++;
        }
}

int NeutralisationCarte ()
    {
//        printf ("\n\tCorrespondance du numéro %d est  %s dans la copie du jeu et a une valeur de %d.", Numero, CopieJeuDeCartesCreation[Numero].NomCarte ,CopieJeuDeCartesCreation[Numero].ValeurCarte);
        CopieJeuDeCartesCreation[Numero].ValeurCarte = 0;
        CarteSortie ++;        
}

int PremierTour ()
{

    TirageCarte ();
        printf ("\n\tCarte tirée pour le Joueur 1: (index %i): %s, Valeur: %i", Numero, CopieJeuDeCartesCreation[Numero].NomCarte, CopieJeuDeCartesCreation[Numero].ValeurCarte);
        Joueur1 [0]=CopieJeuDeCartesCreation[Numero].ValeurCarte;
    //    NeutralisationCarte;

    TirageCarte ();
        printf ("\n\tCarte tirée pour le Joueur 1: (index %i): %s, Valeur: %i", Numero, CopieJeuDeCartesCreation[Numero].NomCarte, CopieJeuDeCartesCreation[Numero].ValeurCarte);
        Joueur1 [1]=CopieJeuDeCartesCreation[Numero].ValeurCarte;
    //    NeutralisationCarte;

    TirageCarte ();
        printf ("\n\tCarte tirée pour le Joueur 2: (index %i): %s, Valeur: %i", Numero, CopieJeuDeCartesCreation[Numero].NomCarte, CopieJeuDeCartesCreation[Numero].ValeurCarte);
        Joueur2 [0]= CopieJeuDeCartesCreation[Numero].ValeurCarte;
    //    NeutralisationCarte;

    TirageCarte ();
        printf ("\n\tCarte tirée pour le Joueur 2: (index %i): %s, Valeur: %i", Numero, CopieJeuDeCartesCreation[Numero].NomCarte, CopieJeuDeCartesCreation[Numero].ValeurCarte);
        Joueur2 [1]= CopieJeuDeCartesCreation[Numero].ValeurCarte;
    //    NeutralisationCarte;


    printf("\n\n\t");
}




/***********************************************************************************************************************************************************************/
/* ***** La fonction aleatoire
******* */
int AffichageAleatoire ()//(*Numero, *CopieJeuDeCartesCreation)
{
    Numero = 0;
    for (int i = 0; i < 4; i++)  //tirage des 4 premières cartes
        {
            Random();
            Numero = n;
            while (CopieJeuDeCartesCreation[Numero].ValeurCarte == 0)
            {                
                printf ("\nLancement de la boucle anti zero");
                Random();
                Numero = n;
                Zero ++;
            }

            printf ("\n\tCorrespondance du numéro %d est  %s dans la copie du jeu et a une valeur de %d.", Numero, CopieJeuDeCartesCreation[Numero].NomCarte ,CopieJeuDeCartesCreation[Numero].ValeurCarte);
            CopieJeuDeCartesCreation[Numero].ValeurCarte = 0;
            CarteSortie ++;
        }
/*    for (int j=0;j<52; j++)
        {  
            printf ("\n\tNouvelle correspondance du numéro %d est %s dans la copie du jeu et a une valeur de %d.", j, CopieJeuDeCartesCreation[j].NomCarte ,CopieJeuDeCartesCreation[j].ValeurCarte);
        }
*/    printf ("\n\n\tFin de boucle: Nombre de Cartes sorties: %i  %i boucles antizero.",CarteSortie, Zero);
    return 0;
}

/***********************************************************************************************************************************************************************/
/* **** Fonction par Selection.
****** */
int Selection ( )
{
         printf ("\n\tEntrez un numéro: ");
         scanf("%d", &Numero);

         printf ("\n\tCorrespondance du numéro %d est  %s et a une valeur de %d.\n\n", Numero, JeuDeCartesOriginal[Numero].NomCarte, JeuDeCartesOriginal[Numero].ValeurCarte);
          return Numero;
}

/***********************************************************************************************************************************************************************/
/* **** La fonction random.
****** */
int Random()
{
    n = rand() % 52;
    return n;
}

int AffichageScore ()
{
    ScoreJoueur1 = Joueur1[0] + Joueur1[1] + Joueur1[2] +Joueur1[3] +Joueur1[4] +Joueur1[4] +Joueur1[5] +Joueur1[6] +Joueur1[7] +Joueur1[8] +Joueur1[9];
    ScoreJoueur2 = Joueur2[0] + Joueur2[1] + Joueur2[2] +Joueur2[3] +Joueur2[4] +Joueur2[4] +Joueur2[5] +Joueur2[6] +Joueur2[7] +Joueur2[8] +Joueur2[9];
   
    printf ("\n\tScore Joueur 1: %i, \t\t détails: Tour 1: %i, Tour 2: %i, Tour 3: %i, Tour 4: %i, Tour 5: %i, Tour 6: %i, Tour 7: %i, Tour 8: %i, Tour 9: %i. ", ScoreJoueur1,Joueur1[0], Joueur1[1], Joueur1[2], Joueur1[3], Joueur1[4], Joueur1[4], Joueur1[5], Joueur1[6], Joueur1[7], Joueur1[8], Joueur1[9]);
    printf ("\n\tScore Joueur 2: %i, \t\t détails: Tour 1: %i, Tour 2: %i, Tour 3: %i, Tour 4: %i, Tour 5: %i, Tour 6: %i, Tour 7: %i, Tour 8: %i, Tour 9: %i. ", ScoreJoueur2,Joueur2[0], Joueur2[1], Joueur2[2], Joueur2[3], Joueur2[4], Joueur2[4], Joueur2[5], Joueur2[6], Joueur2[7], Joueur2[8], Joueur2[9]);

    if (ScoreJoueur1 > 21)
        {
            printf ("\n\t Joueur 1 disclifié\n");
        }

    if (ScoreJoueur2 > 21)
        {
            printf ("\n\t Joueur 2 disclifié\n");
        }
    if (ScoreJoueur1> ScoreJoueur2)
        {
            printf ("\n\n\t Joueur 1 gagnant !!!\n");
        }
        else
        {
            printf ("\n\n\t Joueur 1 gagnant !!!\n");
        }
}
