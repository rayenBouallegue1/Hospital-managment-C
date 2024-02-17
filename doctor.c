#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ft_commun.h"
#include "Doctor.h"
#include "Authentification.h"





void intialisation_tableau( docteur *tableauDocteurs,int* nb_med_courant  )
{
     char *temp[9];
     FILE* f = fopen("docteur.txt", "r+");
    char line[350];
    while (fgets(line, sizeof(line), f) != NULL )
    {
         char *strToken = strtok(line, ",/");
         int i = 0;
         while (strToken != NULL && i < 9)
            {
                        temp[i] = strToken;
                        i++;
                        strToken = strtok(NULL, ",/");
            }
                strcpy(tableauDocteurs[*nb_med_courant].cin,temp[0]);

                strcpy(tableauDocteurs[*nb_med_courant].nom,temp[1]);
                strcpy(tableauDocteurs[*nb_med_courant].prenom,temp[2]);
                strcpy(tableauDocteurs[*nb_med_courant].specialite,temp[3]);
                strcpy(tableauDocteurs[*nb_med_courant].numtel,temp[4]);
                strcpy(tableauDocteurs[*nb_med_courant].adresse,temp[5]);
                tableauDocteurs[*nb_med_courant].date_naissance.day=atoi(temp[6]); //atoi sert à convertir une chaine en entier
                tableauDocteurs[*nb_med_courant].date_naissance.month=atoi(temp[7]);
                tableauDocteurs[*nb_med_courant].date_naissance.year=atoi(temp[8]);
                *nb_med_courant = *nb_med_courant + 1;



  }


    fclose(f);
}



int verification_chaine (char *chaine) // une chaine est un tableau le pointeur pointe vers 1 case
{   int verif=0 ,i=0;
    while (verif==0 && i<strlen(chaine))
    {
        if (isalpha(chaine[i])|| isspace(chaine[i])) i++;
        else verif=1;    }
       return verif;
}

int verification_num (char *chaine)
{   int verif=0 ,i=0;
    while (verif==0 && i<strlen(chaine))
    {
        if (isdigit(chaine[i])) i++;
        else verif=1;    }
       return verif;
}
int verification_date (date date_naiss )
{    if (date_naiss.year <1950 || date_naiss.year>2023) return 1;
     if (date_naiss.month< 1 || date_naiss.month>12) return 1;


     if (date_naiss.month==2) {   if ((date_naiss.year%4==0 && date_naiss.year%100!=0) || (date_naiss.year % 400 == 0))
                                             {
                                                if (date_naiss.day<1 || date_naiss.day>29) return 1;
                                             }
                                  else {

                                            if (date_naiss.day <1 || date_naiss.day > 28) return 1;
                                       }
                              }
    else if (date_naiss.month == 4 || date_naiss.month == 6 || date_naiss.month == 9 || date_naiss.month == 11)
                              {

                                  if (date_naiss.day<1 || date_naiss.day>30) return 1;

                              }
    else {
        if (date_naiss.day < 1 || date_naiss.day > 31) return 1;
         }

    return 0;
}

void fichierDocteur(docteur *tableauDocteurs, int* nb_med_courant) {
    FILE* f = fopen("docteur.txt","a");

        fprintf(f, "%s,%s,%s,%s,%s,%s,%02d/%02d/%04d\n",
                tableauDocteurs[*nb_med_courant].cin,
                tableauDocteurs[*nb_med_courant].nom,
                tableauDocteurs[*nb_med_courant].prenom,
                tableauDocteurs[*nb_med_courant].specialite,
                tableauDocteurs[*nb_med_courant].numtel,
                tableauDocteurs[*nb_med_courant].adresse,
                tableauDocteurs[*nb_med_courant].date_naissance.day,
                tableauDocteurs[*nb_med_courant].date_naissance.month,
                tableauDocteurs[*nb_med_courant].date_naissance.year);


    fclose(f);
}



position verif_cin (docteur *tableauDocteurs, int *nb_med_courant)
{  position verif;
       strcpy(verif.cin,"");
      do{
        printf("Entrer le CIN du docteur: ");
        scanf("%s",verif.cin);
        getchar();

       } while(strlen(verif.cin )!= 8 || verification_num(verif.cin)== 1);


   int i=0 ;
   verif.exist=0;

   while(i< *nb_med_courant && verif.exist==0)
   {   if (strcmp(verif.cin,tableauDocteurs[i].cin)==0) {verif.pos=i;
                                                         verif.exist=1;}
     else i++;

   }
   return verif ;
}

void Modifierfichier(int nb_med_courant, docteur * tableauDocteurs)
{   int i;
    FILE* copie = fopen("temp.txt","w");
        for (i=0;i<nb_med_courant;i++)
        {  fprintf(copie, "%s,%s,%s,%s,%s,%s,%02d/%02d/%04d\n",
                tableauDocteurs[i].cin,
                tableauDocteurs[i].nom,
                tableauDocteurs[i].prenom,
                tableauDocteurs[i].specialite,
                tableauDocteurs[i].numtel,
                tableauDocteurs[i].adresse,
                tableauDocteurs[i].date_naissance.day,
                tableauDocteurs[i].date_naissance.month,
                tableauDocteurs[i].date_naissance.year);

        }
        fclose(copie);
        remove("docteur.txt");
        rename("temp.txt", "docteur.txt");

}

void ajouter_medecin(docteur *tableauDocteurs, int *nb_med_courant)
{
    position verif ;
    verif = verif_cin(tableauDocteurs,nb_med_courant);
    if (verif.exist==0)
    {
    strcpy(tableauDocteurs[*nb_med_courant].cin,verif.cin);
    do{
    printf("Nom du docteur : ");
    gets(tableauDocteurs[*nb_med_courant].nom);

    }while (verification_chaine(tableauDocteurs[*nb_med_courant].nom));

    do{
    printf("Prenom du docteur : ");
    gets( tableauDocteurs[*nb_med_courant].prenom);

    }while (verification_chaine(tableauDocteurs[*nb_med_courant].prenom));

    do{
    printf("Specialite du docteur : ");
    gets(tableauDocteurs[*nb_med_courant].specialite);

    }while (verification_chaine(tableauDocteurs[*nb_med_courant].specialite));



   do {
        printf("Numero de telephone du docteur : ");
        gets(tableauDocteurs[*nb_med_courant].numtel);

    } while (strlen(tableauDocteurs[*nb_med_courant].numtel) != 8 || verification_num(tableauDocteurs[*nb_med_courant].numtel)==1);

    do{
    printf("Adresse du docteur : ");
    gets(tableauDocteurs[*nb_med_courant].adresse);
   }
    while (verification_chaine(tableauDocteurs[*nb_med_courant].adresse)==1);

  do{
        printf("Date de naissance du docteur sous DD MM YYYY: ");
        scanf("%02d %02d %04d", &tableauDocteurs[*nb_med_courant].date_naissance.day,&tableauDocteurs[*nb_med_courant].date_naissance.month, &tableauDocteurs[*nb_med_courant].date_naissance.year);
        getchar();
     }while(verification_date(tableauDocteurs[*nb_med_courant].date_naissance) == 1);

    fichierDocteur(tableauDocteurs, nb_med_courant);
    *nb_med_courant = *nb_med_courant + 1;

    }
    else { printf("La CIN existe deja \n "); }
}

void RechercheDocCin(docteur *tableauDocteurs, int *nb_med_courant)
{   position verif ;
    verif=verif_cin(tableauDocteurs,nb_med_courant);
    if (verif.exist == 1) {                         printf("CIN: %s\n", tableauDocteurs[verif.pos].cin);
                                                    printf("Nom: %s\n", tableauDocteurs[verif.pos].nom);
                                                    printf("Prenom: %s\n", tableauDocteurs[verif.pos].prenom);
                                                    printf("Specialite: %s\n", tableauDocteurs[verif.pos].specialite);
                                                    printf("Numéro de téléphone: %s\n", tableauDocteurs[verif.pos].numtel);
                                                    printf("Adresse: %s\n", tableauDocteurs[verif.pos].adresse);
                                                    printf("Date de naissance: %02d/%02d/%04d\n",tableauDocteurs[verif.pos].date_naissance.day,
                                                    tableauDocteurs[verif.pos].date_naissance.month,tableauDocteurs[verif.pos].date_naissance.year);
                                                    printf("\n");}
   else  printf("Le docteur est intouvable \n");
}
void RechercheDocSpecialite(docteur *tableauDocteurs, int *nb_med_courant)
{    char specialite[50];
     printf("Entrer la specialite du docteur: ");
     gets(specialite);
     int i=0 , exist=0;

      while( i < *nb_med_courant && exist==0 )
    {
         if (stricmp(tableauDocteurs[i].specialite,specialite) ==0) {exist=1;
                                                                   printf("%s %s %s %s %s %s %02d/%02d/%04d \n", tableauDocteurs[i].cin,tableauDocteurs[i].nom,tableauDocteurs[i].prenom
                                                                  ,tableauDocteurs[i].specialite,tableauDocteurs[i].numtel,tableauDocteurs[i].adresse,tableauDocteurs[i].date_naissance.day,tableauDocteurs[i].date_naissance.month,tableauDocteurs[i].date_naissance.year);
                                                    }
        else i++;
                                                     }
    if (exist == 0) printf("Le docteur est intouvable \n");
}
void RechercheDocNomprenom(docteur *tableauDocteurs, int *nb_med_courant)
{    char nom_prenom[100] , nom_prenom1[100]="\0";
     printf("Entrer le nom et le prenom du docteur: ");
     gets(nom_prenom);
     int i=0 , exist=0;

      while( i < *nb_med_courant )
    {    strcat(nom_prenom1,tableauDocteurs[i].nom);
         strcat(nom_prenom1," ");
         strcat(nom_prenom1,tableauDocteurs[i].prenom);
         if (stricmp(nom_prenom1,nom_prenom)==0 || stricmp(tableauDocteurs[i].nom,nom_prenom)==0 || stricmp(tableauDocteurs[i].prenom,nom_prenom)==0) {exist=1;
                                                printf("%s %s %s %s %s %s %02d/%02d/%04d \n", tableauDocteurs[i].cin,tableauDocteurs[i].nom,tableauDocteurs[i].prenom,tableauDocteurs[i].specialite,tableauDocteurs[i].numtel,tableauDocteurs[i].adresse,tableauDocteurs[i].date_naissance.day,tableauDocteurs[i].date_naissance.month,tableauDocteurs[i].date_naissance.year);
                                                    }
          i++;
                                                     }
    if (exist == 0) printf("Le docteur est introuvable \n");
}
void ModifierDocteurCin (docteur *tableauDocteurs, int *nb_med_courant)
{   position verif ;
    verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char cin[9];
        do {
        printf("Entrer le nouveau CIN: ");
        gets(cin);
        } while( strlen(cin) != 8 || verification_num(cin)==1);
        strcpy(tableauDocteurs[verif.pos].cin,cin);
        Modifierfichier(*nb_med_courant,tableauDocteurs);
        }


   }
void ModifierDocteurNom (docteur *tableauDocteurs, int *nb_med_courant)
{   position verif ;
    verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char nom[50];
        do {
        printf("Entrer le nouveau nom: ");
        gets(nom);
        } while (verification_chaine(nom));
        strcpy(tableauDocteurs[verif.pos].nom,nom);
        Modifierfichier(*nb_med_courant,tableauDocteurs);
        }


   }
void ModifierDocteurSpecialite (docteur *tableauDocteurs, int *nb_med_courant)
{    position verif ;
     verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char specialite[50];
        do {
        printf("Entrer la nouvelle specialite: ");
        gets(specialite);
        } while (verification_chaine(specialite));
        strcpy(tableauDocteurs[verif.pos].specialite,specialite);
        Modifierfichier(*nb_med_courant,tableauDocteurs);
        }


   }
void ModifierDocteurAdresse (docteur *tableauDocteurs, int *nb_med_courant)
{    position verif ;
     verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char adresse[100];
        do {
        printf("Entrer la nouvelle adresse: ");
        gets(adresse);
        } while (verification_chaine(adresse));
        strcpy(tableauDocteurs[verif.pos].adresse,adresse);
        Modifierfichier(*nb_med_courant,tableauDocteurs);
        }


   }


void ModifierDocteurPrenom (docteur *tableauDocteurs, int *nb_med_courant)
{    position verif;
     verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char prenom[50];
        do {
        printf("Entrer le nouveau prenom: ");
        gets(prenom);
        } while (verification_chaine(tableauDocteurs[*nb_med_courant].prenom));
        strcpy(tableauDocteurs[verif.pos].prenom,prenom);
        Modifierfichier(*nb_med_courant,tableauDocteurs);
        }

   }

void ModifierDocteurtel (docteur *tableauDocteurs, int *nb_med_courant)
{    position verif;
     verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char num[9];
        do {
        printf("Entrer le nouveau numero de telephone: ");
        gets(num);
        } while (verification_num(num) || strlen(num)!=8 );
        strcpy(tableauDocteurs[verif.pos].numtel,num);
        Modifierfichier(*nb_med_courant,tableauDocteurs);
        }
}

void ModifierDocteurdate (docteur *tableauDocteurs, int *nb_med_courant)
{    position verif;
     verif=verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        date datenaiss;
        do{
        printf("Date de naissance du docteur sous DD MM YYYY: ");
        scanf("%02d %02d %04d",&datenaiss.day,&datenaiss.month,&datenaiss.year);
        getchar();
         }while(verification_date(datenaiss) == 1);
        tableauDocteurs[verif.pos].date_naissance=datenaiss;
        }
}


void SuppressionDoc (docteur *tableauDocteurs, int* nb_med_courant)
{    int i;
     position verif;
     verif= verif_cin(tableauDocteurs,nb_med_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
     else {
        if (verif.pos==*nb_med_courant) *nb_med_courant=*nb_med_courant-1;
        else {
           for(i=verif.pos; i<*nb_med_courant ;i++) {tableauDocteurs[i]=tableauDocteurs[i+1] ;}
           *nb_med_courant=*nb_med_courant-1;
           Modifierfichier(*nb_med_courant,tableauDocteurs);
           printf("Docteur supprime avec succes \n");
             }

          }

}
void ModifierDoc (docteur *tableauDocteurs, int* nb_med_courant)
{   int choix;
    do {
     printf("\n *********** MODIFIER DOCTEUR *********** \n ");
            printf("\n 1- Modifier le CIN \n");
            printf("\n 2- Modifier le Nom \n");
            printf("\n 3- Modifier le Prenom \n");
            printf("\n 4- Modifier la Specialite \n");
            printf("\n 5- Modifier le Numero de Telephone \n");
            printf("\n 6- Modifier l'Adresse \n");
            printf("\n 7- Modifier la Date de Naissance \n");
            printf("\n 8- Quitter le menu de modification \n");

            printf("\n Entrer un choix entre 1 et 8: ");
            scanf("%d", &choix);
            getchar();

            switch (choix) {
                case 1:
                    system("cls");
                    ModifierDocteurCin(tableauDocteurs, nb_med_courant);
                    break;
                case 2:
                    system("cls");
                    ModifierDocteurNom(tableauDocteurs, nb_med_courant);
                    break;
                case 3:
                    system("cls");
                    ModifierDocteurPrenom(tableauDocteurs, nb_med_courant);
                    break;
                case 4:
                    system("cls");
                    ModifierDocteurSpecialite(tableauDocteurs, nb_med_courant);
                    break;
                case 5:
                    system("cls");
                    ModifierDocteurtel(tableauDocteurs, nb_med_courant);
                    break;
                case 6:
                    system("cls");
                    ModifierDocteurAdresse(tableauDocteurs, nb_med_courant);
                    break;
                case 7:
                    system("cls");
                    ModifierDocteurdate(tableauDocteurs, nb_med_courant);
                    break;
                case 8:
                    break;

            }
        } while (choix != 8);  // Quitter le menu de modification lorsque l'utilisateur choisit l'option 8
    }


void RechercheDoc (docteur *tableauDocteurs, int* nb_med_courant)
{    int choix;
  do{
     printf("\n *********** RECHERCHE DOCTEUR *********** \n ");
     printf("\n 1- Recherche par CIN \n");
     printf("\n 2- Recherche par nom et/ou prenom \n");
     printf("\n 3- Recherche par specialite \n");
     printf("\n 4- Quitter le menu recherche \n");

     do{
     printf(" \n Entrer un choix entre 1 et 4: ");
     scanf("%d",&choix);
     getchar();
       }
     while (choix<0||choix>4);
     switch(choix)
  { case 1: system("cls");
            RechercheDocCin(tableauDocteurs,nb_med_courant);
            break;
    case 2: system("cls");
            RechercheDocNomprenom(tableauDocteurs,nb_med_courant);
            break;
    case 3: system("cls");
            RechercheDocSpecialite(tableauDocteurs,nb_med_courant);
            break;
    case 4: system("cls");
            break;
    }

    } while (choix != 4);

}

void GestionDocteur(compte* c)
{    int nb_med_courant=0 ;
     docteur *tableauDocteurs = (docteur *)malloc(100 * sizeof(docteur));
     intialisation_tableau(tableauDocteurs,&nb_med_courant);
    int choix;
    do {
    printf("\n *********** GESTION DOCTEUR *********** \n ");
    printf("\n 1- Ajouter un docteur \n");
    printf("\n 2- Modifier un docteur \n");
    printf("\n 3- Supprimer un docteur \n");
    printf("\n 4- Rechercher un docteur \n");
    printf("\n 5- Quitter la gestion des docteurs \n");

  do{
  printf(" \n Entrer un choix entre 1 et 5: ");
  scanf("%d",&choix);
  }
  while (choix<0||choix>5);

  switch(choix)
  { case 1: system("cls");
            if(strcmp(c->role,"admin")==0)
            {
                 ajouter_medecin(tableauDocteurs,&nb_med_courant);

            }

            break;
    case 2: system("cls");
            ModifierDoc(tableauDocteurs,&nb_med_courant);
        break;
    case 3: system("cls");
            SuppressionDoc(tableauDocteurs,&nb_med_courant);
            break;
    case 4: system("cls");
            RechercheDoc(tableauDocteurs,&nb_med_courant);
            break;
 }}
 while(choix != 5) ;

}
