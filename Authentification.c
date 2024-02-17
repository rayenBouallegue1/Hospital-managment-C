#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Authentification.h"

void CreerCompteUtilisateur()
{    compte cpt ;
     printf("Donner le nom de l'utiisateur : ") ;
     scanf("%s",cpt.nomutilisateur ) ;
     printf("Donner le password : ") ;
     scanf("%s",cpt.password) ;
     printf("Donner le role : ") ;
     scanf("%s",cpt.role) ;
     FILE * f = fopen("comptes.txt","a") ;
     fprintf(f, "%s , %s , %s",cpt.nomutilisateur , cpt.password , cpt.role);
     fprintf(f,"\n") ;
     fclose(f);
    printf("Creation de compte Realiser avec Succées ! ") ;
}

compte* SeConnecter()
{   compte *c ;
    c = (compte*)malloc(sizeof(compte)) ;

    char mdp [30],user[30] , role [30] ;
    char mdp_test [30],user_test[30] ;
    FILE * f = fopen("comptes.txt","r");
    printf("entrer Votre Nom d'utilisateur ! ") ;
    scanf("%s",user_test) ;
    printf("enrer Votre mot de passe : ") ;
    scanf("%s",mdp_test) ;
    while(fscanf(f, "%s , %s , %s", user , mdp , role)==3 )
    {   printf("hi") ;
        if (strcmp(user_test,user)==0 && strcmp(mdp_test,mdp)==0)
    {

        printf("Logged in !") ;
        strcpy(c->nomutilisateur,user) ;
        strcpy(c->password,mdp) ;
        strcpy(c->role,role) ;
        return c ;
    }
    }
    return NULL;
    }
void saveAccounts(FILE* f)
{ compte Accounts[200] ;
  int i ;
    while(!feof(f))
    {
        fscanf(f, "%s , %s , %s", Accounts[i].nomutilisateur , Accounts[i].password , Accounts[i].role ) ;
        i++ ;

    }
}

void ModifierPassword(compte c)
{   char mdpold[30] ;
   char mdpnew [30];
    printf("entrer Votre mot de passe actuel") ;
    scanf("%s",mdpold) ;
    if(strcmp(mdpold,c.password)!=0)
    {
        printf("mot de passe incorrecte SORRY ! ") ;
    }
    else {
        printf("entrer Votre nouveau mot de passe ") ;
        scanf("%s",mdpnew) ;
        strcpy(c.password,mdpnew) ;
    }
}


void WelcomingFunction(compte* c)
{          system("cls") ;
         printf("\n******************************************************************* \n") ;

        printf(" \n \t Bienvenue Cher(e) : %s \n",c->nomutilisateur) ;

        printf("\t Ravi de vous revoir, cher(e) %s \n",c->role) ;
    printf("\n******************************************************************* \n") ;
        sleep(3) ;

}
