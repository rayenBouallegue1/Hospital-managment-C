#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED
#include "ft_commun.h"

struct Employe {
    char cin[9];
    char nom[50];
    char prenom[50];
    char fonction[50];
    char departement[50];
    char numtel[9]; // neuvieme pour le /0
    char adresse[100];
    date  date_naissance;
    char date_recutement[20];
};

typedef struct Employe employe;

void intialisation_tableau_employe (employe *tableauEmploye,int* nb_employe_courant);
void fichierEmploye(employe *tableauEmploye,int* nb_employe_courant  ) ;
position verif_cin_staff (employe *tableauEmploye, int *nb_employe_courant);
void ajouter_staff(employe *tableauEmploye, int *nb_employe_courant);
void RechercheEmpCin(employe *tableauEmploye, int *nb_employe_courant);
void RechercheEmpFonction(employe *tableauEmploye, int *nb_employe_courant);
void RechercheEmpDepartement(employe *tableauEmploye, int *nb_employe_courant);
void RechercheEmpNomprenom(employe *tableauEmploye, int *nb_employe_courant);
void ModifierfichierStaff(int nb_employe_courant, employe * tableauEmploye);
void ModifieremployeCin (employe *tableauEmploye, int *nb_employe_courant);
void ModifieremployeNom (employe *tableauEmploye, int *nb_employe_courant);
void ModifieremployeFonction (employe *tableauEmploye, int *nb_employe_courant);
void ModifieremployeDepart(employe *tableauEmploye, int *nb_employe_courant);
void ModifieremployeAdresse (employe *tableauEmploye, int *nb_employe_courant);
void ModifieremployePrenom (employe *tableauEmploye, int *nb_employe_courant);
void Modifieremployetel (employe *tableauEmploye, int *nb_employe_courant);
void Modifieremployedate (employe *tableauEmploye, int *nb_employe_courant);
void SuppressionEmp (employe *tableauEmploye, int* nb_employe_courant);
void ModifierEmp(employe *tableauEmploye, int* nb_employe_courant);
void RechercheEmp (employe *tableauEmploye, int* nb_employe_courant);
void GestionEmploye();


#endif // STAFF_H_INCLUDED
