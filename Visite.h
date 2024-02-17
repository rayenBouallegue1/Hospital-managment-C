#ifndef VISITE_H_INCLUDED
#define VISITE_H_INCLUDED

///-------DECLARATION DES STRUCTURES----------------------------------------------

typedef struct DATE
{
int jour ;
int mois ;
int annee ;
} DATE ;

typedef struct  ordonnance
{   int id_ord;
    char liste_medicaments [50][10] ;
    int nb_med ;
    char cin [9] ;
    int id_docteur ;
}ordonnance;

typedef struct StructVisite
{
    DATE date_visite ;
    char cin [9] ;
    char remarque [300] ;
    ordonnance *ord ;

}StructVisite , *visite ;

typedef struct structCellule {

visite Visite  ;
struct structCellule *suivant;

}structCellule, *cellule;

typedef struct structureFile
{
    cellule First ;
    cellule last ;
}structureFile , *File ;



///------- FIN DECLARATION DES STRUCTURES----------------------------------------------


DATE lire_date() ;
void affiche_Date(DATE d );
ordonnance * Lire_ordonnance();
void afficher_ordonnance(ordonnance* ord);
visite CreerVisite();
visite Lire_Visite();
void afficheVisite(visite V);
cellule creerCellule(visite v);
void afficherCellule(cellule c);
File CreerFile();
int FileVide(File f);
int enfiler (File f , cellule c);
cellule defiler (File f);
void afficheFile(File f);
void writeToFile(visite visit);
void readFromFileAndEnqueue(File f);
void deleteVisiteFromFile(visite visit);
int compareDates(DATE date1, DATE date2);
void displayVisitsInRange(File f, DATE DateDebut, DATE DateFin);
void GestionVisite();








#endif // VISITE_H_INCLUDED
