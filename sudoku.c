/*******************/ 
/* BUREL DYLAN 1D2 */
/*******************/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3

#define TAILLE N*N

const int MINI=1;

const char PLUS[2] = "+";
const char COLONNE[2] = "|";
const char LIGNE[10] = "---------";
const char ESPACE[2] = " ";


typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille);
void afficherGrille(tGrille);
void saisir(int*);
bool possible(tGrille,int,int,int);
bool fini(tGrille);

int main(){
    tGrille g;
    tGrille grille1={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int numLigne;
    int numColonne;
    int val;

   /* chargerGrille(g);*/
   
    while(fini(grille1)==0){
        afficherGrille(grille1);
        printf("Indices (ligne puis colonne) de la case ? ");
        saisir(&numLigne);
        saisir(&numColonne);
    if (grille1[numLigne - 1][numColonne - 1] !=0){
            printf("IMPOSSIBLE, la case n'est pas libre.");
        }
        else{
            printf("Valeur à insérer ? ");
            saisir(&val);
            if (possible(grille1, numLigne, numColonne, val))
            {
                grille1[numLigne - 1][numColonne - 1] = val;
            }
        }
    }
    printf("Félicitations");
    return EXIT_SUCCESS;
}




void chargerGrille(tGrille g)
{
    char nomFichier[30];
    FILE *f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f == NULL)
    {
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    }
    else
    {
        fread(g, sizeof(int), TAILLE * TAILLE, f);
    }
    fclose(f);
}


void afficherGrille(tGrille grille1)
{
    int ligne;
    int colonne;
    int cmpt1;
    int cmpt2;
    char cara;
    cmpt1 = 1;
    printf("\n");
    printf("   ");
    for (ligne = 0; ligne < TAILLE; ligne++)
    {
        if ((ligne == N) || (ligne == N+N) || (ligne == TAILLE))
        {
            printf(" ");
        }

        printf(" %d ", ligne + 1);
    }
    printf("\n");
    printf("  ");
    for (cmpt2 = 0; cmpt2 < N; cmpt2++)
    {
        printf(PLUS);
        printf(LIGNE);
    }
    printf(PLUS);
    printf("\n");
    for (ligne = 0; ligne < TAILLE; ligne++)
    {
        for (colonne = 0; colonne < TAILLE; colonne++)
        {
            if (grille1[ligne][colonne] == 0)
            {
                cara = '.';
            }
            else
            {
                cara = '0' + grille1[ligne][colonne];
            }
            if (colonne == 0)
            {
                printf("%d | %c ", cmpt1, cara);
                cmpt1 = cmpt1+1;
            }
            else
            {
                printf(" %c ", cara);
            }
            if ((colonne == 2) || (colonne == 5) || (colonne == TAILLE))
            {
                printf(COLONNE);
            }
        }
        printf("|");
        if ((ligne == 2) || (ligne == 5) || (ligne == TAILLE))
        {
            printf("\n");
            printf("  ");
            for (cmpt2 = 0; cmpt2 < N; cmpt2++)
            {
                printf(PLUS);
                printf(LIGNE);
            }
            printf(PLUS);
        }
        printf("\n");
    }
    printf("  ");
    for (cmpt2 = 0; cmpt2 < N; cmpt2++)
    {
        printf(PLUS);
        printf(LIGNE);
    }
    printf(PLUS);
    printf("\n");
}



void saisir(int *val)
{
    char carac[20];
    scanf("%s",carac);
    if (sscanf(carac, "%d", &(*val)) !=0){
        if ((*val > TAILLE) && (*val < MINI))
        {
            printf("erreur, la valeur n'est pas entre 1 et 9 veuillez de nouveau saisir : ");
            saisir( &(*val));
            printf("\n");
        }
    }
    else{
        printf("Valeur incorrecte\n");
        printf("Veuillez saisir une valeur :");
        saisir( &(*val));
    }
     
}




bool possible(tGrille grille1, int ligne, int colonne, int valeur)
{
    bool result=true;
    int k=0;
    int l=0;
    

    for (int j = 0; j < TAILLE; j++)
    {
        if (grille1[ligne - 1][j] == valeur)
        {
            printf("Erreur, La valeur %d est déjà présente sur la même ligne.\n", valeur);
            result = false;
        }
    }

    for (int i = 0; i < TAILLE; i++)
    {
        if (grille1[i][colonne - 1] == valeur)
        {
            printf("Erreur, La valeur %d est déjà présente sur la même colonne.\n", valeur);
            result = false;
        }
    }
    if (ligne < N-MINI){
        if (colonne < N-MINI){
            for ( k=0;k<N;k++){
                for ( l=0;l<N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        }
        else if (colonne <= ((N+N)-MINI)){
            for ( k=0;k<N;k++){
                for ( l=0;l<(N+N);l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        }
         else{
            for ( k=0;k<N-MINI;k++){
                for ( k=0;k<(N*N);k++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        } 
    }
    if (ligne < ((N+N)-MINI)){
        if (colonne < N-MINI){
            for (int k=0;k<N;k++){
                for (int l=0;l<N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        }
        else if (colonne <= ((N+N)-MINI)){
            for ( k=0;k<(N+N);k++){
                for ( l=0;l<N+N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        }
         else{
            for ( k=0;k<((N+N)-MINI);k++){
                for ( l=0;l<N*N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        } 
    }
    if (ligne < ((N*N)-MINI)){
        if (colonne < N){
            for (int k=0;k<N;k++){
                for (int l=0;l<N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        }
        else if (colonne <= ((N*N)-MINI)){
            for ( k=0;k<(N+N);k++){
                for ( l=0;l<N+N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        }
         else{
            for ( k=0;k<((N*N)-MINI);k++){
                for ( l=0;l<N*N;l++){
                    if (grille1[k][l]==valeur){
                        result=false;
                        printf("Valeur déjà présente dans le carré");
                    }
                }
            }
        } 
    }
    
    
    return result;
}



bool fini(tGrille grille1)
{
    bool result=true;
    
    for (int i = 0; i < TAILLE; ++i)
    {
        for (int j = 0; j < TAILLE; ++j)
        {
            if (grille1[i][j] == 0)
            {
                result = false;
            }
        }
    }
    return result;
}