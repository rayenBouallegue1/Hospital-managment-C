#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED
#include "ft_commun.h"
typedef struct Date date ;

struct Docteur {
    char cin[9];
    char nom[50];
    char prenom[50];
    char specialite[50];
    char numtel[9]; // neuvieme pour le /0
    char adresse[100];
    date  date_naissance;
    char date_recutement[20];
};

typedef struct Docteur docteur;

void intialisation_tableau( docteur *tableauDocteurs,int* nb_med_courant  );
int verification_chaine (char *chaine) ;// une chaine est un tableau le pointeur pointe vers 1 case
int verification_num (char *chaine);
int verification_date (date date_naiss );
void fichierDocteur(docteur *tableauDocteurs, int* nb_med_courant) ;
position verif_cin (docteur *tableauDocteurs, int *nb_med_courant);
void Modifierfichier(int nb_med_courant, docteur * tableauDocteurs);
void ajouter_medecin(docteur *tableauDocteurs, int *nb_med_courant);
void RechercheDocCin(docteur *tableauDocteurs, int *nb_med_courant);
void RechercheDocSpecialite(docteur *tableauDocteurs, int *nb_med_courant);
void RechercheDocNomprenom(docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurCin (docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurNom (docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurSpecialite (docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurAdresse (docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurPrenom (docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurtel (docteur *tableauDocteurs, int *nb_med_courant);
void ModifierDocteurdate (docteur *tableauDocteurs, int *nb_med_courant);
void SuppressionDoc (docteur *tableauDocteurs, int* nb_med_courant);
void ModifierDoc (docteur *tableauDocteurs, int* nb_med_courant);
void RechercheDoc (docteur *tableauDocteurs, int* nb_med_courant);
void GestionDocteur();

#endif // DOCTOR_H_INCLUDED
