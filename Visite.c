#include "Visite.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Fonctions  DATE */

DATE lire_date()
{   DATE date ;
    do {
    printf("entrer jours :  ") ;
    scanf("%i",&date.jour) ;
    }while (date.jour<1 || date.jour > 31);
    do{
    printf("entrer mois :  ") ;
    scanf("%i",&date.mois) ;
    }while(date.mois<1||date.mois>12) ;
    do {
    printf("entrer annee :  ") ;
    scanf("%i",&date.annee) ;
    }while(date.annee<1900||date.annee>2030) ;
    return date ;
}
void affiche_Date(DATE d )
{
    printf("%i-%i-%i",d.jour,d.mois,d.annee) ;

}


/* Fin des fonctions date  */


/*---------- Fonction ordonnance  -------------------*/

ordonnance * Lire_ordonnance(char cin[9])
{
    ordonnance *ord ;
    ord = (ordonnance*)malloc(sizeof(ordonnance)) ;
    strcpy(ord->cin,cin) ;
    printf("entrer le nombre de medicament a donner : ") ;
    scanf("%i",&ord->nb_med) ;
    for(int i= 0 ; i<ord->nb_med;i++)
    {
        printf("entrer le medicament numero : %i ",(i+1)) ;
        scanf("%s",ord->liste_medicaments[i]) ;

    }
    return ord ;
}
void afficher_ordonnance(ordonnance* ord) {
    printf("ID Ordonnance:     %d\n", ord->id_ord);
    printf("ID Docteur: %d\n", ord->id_docteur);
    printf("Nombre de medicaments: %d\n", ord->nb_med);
    printf("Liste de medicaments:\n");
    for (int i = 0; i < ord->nb_med; i++) {
        printf(" -%s\n", ord->liste_medicaments[i]);
    }
}



/* Fin fonction des ordonnaces  */


/*-------------------- fonction visite ------------------*/

visite CreerVisite()
{   visite v ;

    v = (visite)malloc(sizeof(StructVisite)) ;
    v->ord = (ordonnance*)malloc(sizeof(ordonnance)) ;
    if (v)
        return v ;
    else  return NULL ;
}

visite Lire_Visite()
{
    visite v ;
    v= CreerVisite() ;
    v->date_visite=lire_date() ;
    printf("Entrer la CIN du Patient ") ;
    scanf("%s",v->cin) ;
    printf("ajouter une remarque : ") ;
    scanf(" %[^\n]", v->remarque) ;
    v->ord=Lire_ordonnance(v->cin) ;
    return  v ;
}


void afficheVisite(visite V) {
    printf("\n");
    printf("Date: ");
    affiche_Date(V->date_visite);
    printf("\n CIN Patient: %s\n", V->cin);
    printf("Ordonnance:\n");
    afficher_ordonnance(V->ord);
    printf("Remarques: %s\n", V->remarque);
}




/*-------------- Fin fonction Visite -----------------------*/

/*----------------- Fonction  cellule  --------------------*/

cellule creerCellule(visite v)
{   cellule c ;
    c = (cellule)malloc(sizeof(structCellule)) ;
    if(!c)
    {
        printf("creation d'une cellule impossible") ;
        return NULL ;
    }
    else
    {
        c->Visite = v ;
        c->suivant = NULL ;
        return c ;
    }


}

void afficherCellule(cellule c)
{
    afficheVisite(c->Visite) ;

}

/*--------- Fin fonction cellule -----------  */

/*------------- les fonctions liées au File --------------*/

File CreerFile()
{   File f ;
f = (File)malloc(sizeof(structureFile)) ;
if(!f)
{
    printf("Creation du file impossible ! probleme memoire ") ;
    return NULL ;
}
else
{   f->First= NULL ;
    f->last = NULL ;
    return f ;
}

}

int FileVide(File f)
{
    if(!f->First)  {

        return 1 ;
    }
    else {

        return 0 ;
    }

}

int enfiler (File f , cellule c)
{
    if (f == NULL || c == NULL)
    {   printf("probleme d'enregistrement d'une visite ! ") ;
        return 0  ;
    }
    else
    {
        if (FileVide(f))
            {
                f->First = c  ;
                f->last = c;
                f->First->suivant=NULL  ;
                f->last->suivant=NULL ;

            }
        else {

        f->last->suivant = c ;
        f->last = c  ;

            }
        return 1  ;
    }

}

cellule defiler (File f)
{   cellule c ;

    if(FileVide(f))
    {
        printf("\n erreur lors de l'enfilage d'une cellule  :  file vide \n ") ;
        return NULL ;
    }
    else {
        c = creerCellule(NULL) ;
        c = f->First ;
        f->First = f->First->suivant ;
        return c ;
    }

}


void afficheFile(File f)
{   cellule c ;
 c = creerCellule(NULL) ;
    if( FileVide(f) )
    {
     printf(" \n erreur lors de l'affichage des visites :  file vide \n ") ;

    }
    else {
        c = f->First ;
        while(c!=NULL)
        {
            afficherCellule(c) ;
            c = c->suivant ;

        }
    }
}
/*------------------ Fin Fonction File -----------*/

/* --------- fonction du fichier text ------- */


/// fonciton d'ecriture dans un fichier

void writeToFile(visite visit) {
    FILE* file = fopen("visite.txt", "a");

    if (file == NULL) {
        printf("Error opening file for writing");

    }

    fprintf(file, "%d/%d/%d , %s , %s , %d , %d , %d ",
        visit->date_visite.jour, visit->date_visite.mois, visit->date_visite.annee,
        visit->cin, visit->remarque,
        visit->ord->id_ord,visit->ord->id_docteur ,visit->ord->nb_med)  ;

    for (int j = 0; j < visit->ord->nb_med; ++j) {
        fprintf(file, "%s ,", visit->ord->liste_medicaments[j]);
    }
    fprintf(file,"\n") ;
    fclose(file) ;
}


/// fonction lecture d'un fichier

void readFromFileAndEnqueue(File f) {
    FILE* file = fopen("visite.txt", "r");
    visite visit;
    cellule c ;
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
    }
    while (!feof(file)) {
          visit = CreerVisite() ;

        int result = fscanf(file, "%d/%d/%d , %8s , %299[^,] , %d , %d , %d ,",
                            &visit->date_visite.jour, &visit->date_visite.mois, &visit->date_visite.annee,
                            visit->cin, visit->remarque,
                            &visit->ord->id_ord, &visit->ord->id_docteur, &visit->ord->nb_med);
        if (result != 8) {
            break;
        }

        for (int j = 0; j < visit->ord->nb_med; ++j) {
            fscanf(file, " %20[^,] ,", visit->ord->liste_medicaments[j]);
        }

        fscanf(file, "\n");

        c = creerCellule(visit);
        enfiler(f, c);

    }

    fclose(file);
}



///fonction qui supprime une ligne d'un fichier
void deleteVisiteFromFile(visite visit) {
    FILE* file = fopen("visite.txt", "r");
    FILE* tempFile = fopen("tempfile.txt", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file for reading or writing");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    char lineToDelete[1024];

    snprintf(lineToDelete, sizeof(lineToDelete), "%d/%d/%d , %s , %s , %d , %d , %d ",
        visit->date_visite.jour, visit->date_visite.mois, visit->date_visite.annee,
        visit->cin, visit->remarque,
        visit->ord->id_ord, visit->ord->id_docteur, visit->ord->nb_med);

    for (int j = 0; j < visit->ord->nb_med; ++j) {
        snprintf(buffer, sizeof(buffer), "%s ,", visit->ord->liste_medicaments[j]);
        strcat(lineToDelete, buffer);
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, lineToDelete) == NULL) {
            fputs(buffer, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    if (remove("visite.txt") != 0) {
    perror("Error removing the original file");
    exit(EXIT_FAILURE);
}
    rename("tempfile.txt","visite.txt") ;
}
/*fin fonction fichier */



/* Debut fonction recherche avencé  */


int compareDates(DATE date1, DATE date2) {
    if (date1.annee < date2.annee) return -1;
    if (date1.annee > date2.annee) return 1;

    if (date1.mois < date2.mois) return -1;
    if (date1.mois > date2.mois) return 1;

    if (date1.jour < date2.jour) return -1;
    if (date1.jour > date2.jour) return 1;

    return 0;  // Les deux date sont egeaux
}

void displayVisitsInRange(File f, DATE DateDebut, DATE DateFin) {

    cellule c ;
    c = creerCellule(NULL) ;
    c = f->First ;
    system("cls") ;
    while (c) {
        if ((compareDates(c->Visite->date_visite, DateDebut) >= 0) &&
            (compareDates(c->Visite->date_visite, DateFin) <= 0)) {
            afficherCellule(c) ;

        }

        c = c->suivant;



    }

}


/* Fin Fonction recherche avencé  */


///Menu Generale pour al gestion de visite !


void GestionVisite()
{
    int choice ;
    File f ;
    visite v ;
    cellule c ;
    DATE d1 ;
    DATE d2 ;
    f = CreerFile() ;

    readFromFileAndEnqueue(f) ;

    do{
        printf("\n******* Gestion des Visites *******\n");
    printf("\n 1. Ajouter une visite \n");
    printf("\n2. Afficher tous les visites  \n");
    printf("\n3.afficher les visites selon un filtre \n") ;
    printf("\n4. Exit\n") ;
    scanf("%i",&choice) ;
    switch(choice){
    case 1 :

        v = CreerVisite() ;
        v = Lire_Visite() ;
        c = creerCellule(v) ;

        enfiler(f,c) ;
        writeToFile(v) ;
        break ;
    case 2 :
        afficheFile(f) ;
        break ;
    case 3 :

        d1 = lire_date() ;
        d2= lire_date() ;
        displayVisitsInRange(f,d1,d2) ;
    default :
        printf("\n Choix invalide ! \n") ;
        break ;
    }
    }while(choice!=4) ;


}
