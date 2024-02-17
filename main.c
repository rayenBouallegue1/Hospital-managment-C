#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Patient.h"
#include "Visite.h"
#include "Doctor.h"
#include "staff.h"
#include "Pharmacie.h"
#include "Authentification.h"

int MenuPrincipaleApplication()
{
    int choix ;
    system("cls") ;
    printf("\n******************************************************************* \n") ;
    printf("*Bienvenu dans l'application de gestion de l'hopital Mahmoud Matri* \n") ;
    printf("******************************************************************* \n\n") ;
    printf("Choisir votre Module ! \n") ;
    printf("1.Gestion des Docteurs. \n \n") ;
    printf("2.Gestion des Patients.\n \n") ;
    printf("3.Gestion Staff .\n \n") ;
    printf("4.Gestion des visites.\n \n") ;
    printf("5.Gestion de Pharmacie .\n") ;
    printf("6.se Deconnecter . \n") ;
    printf("7.Quitter l'application .\n") ;
    scanf("%i",&choix) ;
    return choix ;

}
int MenuPrincipaleApplicationAdmin()
{
    int choix ;
    system("cls") ;
    printf("\n******************************************************************* \n") ;
    printf("*Bienvenu dans l'application de gestion de l'hopital Mahmoud Matri* \n") ;
    printf("******************************************************************* \n\n") ;
    printf("Choisir votre Module ! \n") ;
    printf("1.Gestion des Docteurs. \n \n") ;
    printf("2.Gestion des Patients.\n \n") ;
    printf("3.Gestion Staff .\n \n") ;
    printf("4.Gestion des visites.\n \n") ;
    printf("5.Gestion de Pharmacie .\n\n") ;
    printf("6.Creer un Compte utilisateur .\n\n") ;
    printf("7.Se deconnecter . \n\n");
    printf("8.Quitter l'application \n\n") ;

    scanf("%i",&choix) ;
    return choix ;

}


int main()
{ int choice ;

compte* c ;
 deconnecter :
    do {
         system("cls") ;
         c = SeConnecter() ;
    }while(!c) ;
    WelcomingFunction(c);
if(strcmp(c->role,"admin")==0)
{
        do {
choice = MenuPrincipaleApplicationAdmin();
        switch(choice)
        {

            case 1 :
                GestionDocteur(c) ;
                break ;
            case 2 :
                GestionPatient() ;
                break ;
            case 3 :
                GestionEmploye() ;
                break ;
            case 4 :
                GestionVisite();
                break ;
            case 5 :
                GestionPharmacie();
                break ;
            case 6 :
                    CreerCompteUtilisateur() ;
                break ;
            case 7 :
                goto deconnecter ;

        }
        }while(choice!=8);


}
else {
        do {
            choice = MenuPrincipaleApplication();
        switch(choice)
        {

            case 1 :
                GestionDocteur(c) ;
                break ;
            case 2 :
                GestionPatient() ;
                break ;
            case 3 :
                GestionEmploye() ;
                break ;
            case 4 :
                GestionVisite();
                break ;
            case 5 :
                GestionPharmacie();
                break ;
            case 6 :
                goto deconnecter ;
        }
        }while(choice!=7) ;

}
    return 0 ;
}





