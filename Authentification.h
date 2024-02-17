#ifndef AUTHENTIFICATION_H_INCLUDED
#define AUTHENTIFICATION_H_INCLUDED


typedef struct compte {
char nomutilisateur[50] ;
char password[50] ;
char role[50];
} compte;

void CreerCompteUtilisateur();
compte* SeConnecter();
void saveAccounts(FILE* f);
void ModifierPassword(compte c);
void WelcomingFunction(compte* c);

#endif // AUTHENTIFICATION_H_INCLUDED
