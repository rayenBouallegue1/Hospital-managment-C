#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ft_commun.h"
#include "staff.h"
// implementer une fonction / procedure






void intialisation_tableau_employe (employe *tableauEmploye,int* nb_employe_courant)
{
     char *temp[10];
     FILE* f = fopen("staff.txt", "r+");
    char line[350];
    while (fgets(line, sizeof(line), f) != NULL )
    {
         char *strToken = strtok(line, ",/");
         int i = 0;
         while (strToken != NULL && i < 10)
            {
                        temp[i] = strToken;
                        i++;
                        strToken = strtok(NULL, ",/");
            }
                strcpy(tableauEmploye[*nb_employe_courant].cin,temp[0]);

                strcpy(tableauEmploye[*nb_employe_courant].nom,temp[1]);
                strcpy(tableauEmploye[*nb_employe_courant].prenom,temp[2]);
                strcpy(tableauEmploye[*nb_employe_courant].fonction,temp[3]);
                strcpy(tableauEmploye[*nb_employe_courant].departement,temp[4]);
                strcpy(tableauEmploye[*nb_employe_courant].numtel,temp[5]);
                strcpy(tableauEmploye[*nb_employe_courant].adresse,temp[6]);
                tableauEmploye[*nb_employe_courant].date_naissance.day=atoi(temp[7]); //atoi sert à convertir une chaine en entier
                tableauEmploye[*nb_employe_courant].date_naissance.month=atoi(temp[8]);
                tableauEmploye[*nb_employe_courant].date_naissance.year=atoi(temp[9]);
                *nb_employe_courant = *nb_employe_courant + 1;




  }


    fclose(f);
}

void fichierEmploye(employe *tableauEmploye,int* nb_employe_courant  ) {
    FILE* f = fopen("staff.txt","a");

        fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%02d/%02d/%04d\n",
                tableauEmploye[*nb_employe_courant].cin,
                tableauEmploye[*nb_employe_courant].nom,
                tableauEmploye[*nb_employe_courant].prenom,
                tableauEmploye[*nb_employe_courant].fonction,
				tableauEmploye[*nb_employe_courant].departement,
                tableauEmploye[*nb_employe_courant].numtel,
                tableauEmploye[*nb_employe_courant].adresse,
                tableauEmploye[*nb_employe_courant].date_naissance.day,
                tableauEmploye[*nb_employe_courant].date_naissance.month,
                tableauEmploye[*nb_employe_courant].date_naissance.year);


    fclose(f);
}

position verif_cin_staff (employe *tableauEmploye, int *nb_employe_courant)
{  position verif;

      do{
        printf("Entrer le CIN de l'employe: ");
        scanf("%s",verif.cin);
        getchar();

       } while(strlen(verif.cin )!= 8 || verification_num(verif.cin)== 1);


   int i=0 ;
   verif.exist=0;


   while(i< *nb_employe_courant && verif.exist==0)
   {    printf("%d",i);
        if (strcmp(verif.cin,tableauEmploye[i].cin)==0) {verif.pos=i;
                                                         verif.exist=1;}
     else i++;

   }
   return verif ;
}

void ajouter_staff(employe *tableauEmploye, int *nb_employe_courant)
{
    position verif ;
    verif = verif_cin_staff(tableauEmploye,nb_employe_courant);
    if (verif.exist==0)
    {
    strcpy(tableauEmploye[*nb_employe_courant].cin,verif.cin);
    do{
    printf("Nom de l'employe : ");
    gets(tableauEmploye[*nb_employe_courant].nom);

    }while (verification_chaine(tableauEmploye[*nb_employe_courant].nom));

    do{
    printf("Prenom de l'employe : ");
    gets( tableauEmploye[*nb_employe_courant].prenom);

    }while (verification_chaine(tableauEmploye[*nb_employe_courant].prenom));

    do{
    printf("Fonction de l'employe : ");
    gets(tableauEmploye[*nb_employe_courant].fonction);

    }while (verification_chaine(tableauEmploye[*nb_employe_courant].fonction));


	do{
	printf("Departement de l'employe : ");
    gets(tableauEmploye[*nb_employe_courant].departement);
     }while (verification_chaine(tableauEmploye[*nb_employe_courant].departement));



   do {
        printf("Numero de telephone de l'employe : ");
        gets(tableauEmploye[*nb_employe_courant].numtel);

    } while (strlen(tableauEmploye[*nb_employe_courant].numtel) != 8 || verification_num(tableauEmploye[*nb_employe_courant].numtel)==1);

    do{
    printf("Adresse de l'employe : ");
    gets(tableauEmploye[*nb_employe_courant].adresse);
   }
    while (verification_chaine(tableauEmploye[*nb_employe_courant].adresse)==1);

  do{
        printf("Date de naissance de l'employe sous DD MM YYYY: ");
        scanf("%02d %02d %04d", &tableauEmploye[*nb_employe_courant].date_naissance.day,&tableauEmploye[*nb_employe_courant].date_naissance.month, &tableauEmploye[*nb_employe_courant].date_naissance.year);
        getchar();
     }while(verification_date(tableauEmploye[*nb_employe_courant].date_naissance) == 1);

    fichierEmploye(tableauEmploye, nb_employe_courant);


    *nb_employe_courant = *nb_employe_courant+1;

    }
    else { printf("La CIN existe deja \n "); }
}

void RechercheEmpCin(employe *tableauEmploye, int *nb_employe_courant)
{   position verif ;
    verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
    if (verif.exist == 1) {                         printf("CIN: %s\n", tableauEmploye[verif.pos].cin);
                                                    printf("Nom: %s\n", tableauEmploye[verif.pos].nom);
                                                    printf("Prenom: %s\n", tableauEmploye[verif.pos].prenom);
                                                    printf("fonction: %s\n", tableauEmploye[verif.pos].fonction);
													printf("Departement: %s\n", tableauEmploye[verif.pos].departement);
                                                    printf("Numéro de telephone: %s\n", tableauEmploye[verif.pos].numtel);
                                                    printf("Adresse: %s\n", tableauEmploye[verif.pos].adresse);
                                                    printf("Date de naissance: %02d/%02d/%04d\n",tableauEmploye[verif.pos].date_naissance.day,
                                                    tableauEmploye[verif.pos].date_naissance.month,tableauEmploye[verif.pos].date_naissance.year);
                                                    printf("\n");}
else  printf("Le employe est intouvable \n");}

void RechercheEmpFonction(employe *tableauEmploye, int *nb_employe_courant)
{    char fonction[50];
     printf("Entrer la fonction de l'employe: ");
     gets(fonction);
     int i=0 , exist=0;

      while( i < *nb_employe_courant && exist==0 )
    {
         if (stricmp(tableauEmploye[i].fonction,fonction) ==0) {exist=1;
                                                                   printf("%s %s %s %s %s %s %s %02d/%02d/%04d \n", tableauEmploye[i].cin,tableauEmploye[i].nom,tableauEmploye[i].prenom
                                                                  ,tableauEmploye[i].fonction,tableauEmploye[i].departement,tableauEmploye[i].numtel,tableauEmploye[i].adresse,tableauEmploye[i].date_naissance.day,tableauEmploye[i].date_naissance.month,tableauEmploye[i].date_naissance.year);
                                                    }
        else i++;
                                                     }
    if (exist == 0) printf("Le employe est intouvable \n");
}
void RechercheEmpDepartement(employe *tableauEmploye, int *nb_employe_courant)
{    char departement[50];
     printf("Entrer le departement de l'employe: ");
     gets(departement);
     int i=0 , exist=0;

      while( i < *nb_employe_courant && exist==0 )
    {
         if (stricmp(tableauEmploye[i].departement,departement) ==0) {exist=1;
                                                                   printf("%s %s %s %s %s %s %s %02d/%02d/%04d \n", tableauEmploye[i].cin,tableauEmploye[i].nom,tableauEmploye[i].prenom
                                                                  ,tableauEmploye[i].fonction,tableauEmploye[i].departement,tableauEmploye[i].numtel,tableauEmploye[i].adresse,tableauEmploye[i].date_naissance.day,tableauEmploye[i].date_naissance.month,tableauEmploye[i].date_naissance.year);
                                                    }
        else i++;
                                                     }
    if (exist == 0) printf("Le employe est intouvable \n");
}
void RechercheEmpNomprenom(employe *tableauEmploye, int *nb_employe_courant)
{    char nom_prenom[100] , nom_prenom1[100]="\0";
     printf("Entrer le nom et le prenom de l'employe: ");
     gets(nom_prenom);
     int i=0 , exist=0;

      while( i < *nb_employe_courant )
    {    strcat(nom_prenom1,tableauEmploye[i].nom);
         strcat(nom_prenom1," ");
         strcat(nom_prenom1,tableauEmploye[i].prenom);
         if (stricmp(nom_prenom1,nom_prenom)==0 || stricmp(tableauEmploye[i].nom,nom_prenom)==0 || stricmp(tableauEmploye[i].prenom,nom_prenom)==0) {exist=1;
                                               printf("%s %s %s %s %s %s %s %02d/%02d/%04d \n", tableauEmploye[i].cin,tableauEmploye[i].nom,tableauEmploye[i].prenom
                                                                  ,tableauEmploye[i].fonction,tableauEmploye[i].departement,tableauEmploye[i].numtel,tableauEmploye[i].adresse,tableauEmploye[i].date_naissance.day,tableauEmploye[i].date_naissance.month,tableauEmploye[i].date_naissance.year);
                                                    }
          i++;
                                                     }
    if (exist == 0) printf("Le employe est introuvable \n");
}
void ModifierfichierStaff(int nb_employe_courant, employe * tableauEmploye)
{   int i;
    FILE* copie = fopen("temp.txt","w");
        for (i=0;i<nb_employe_courant;i++)
        {  fprintf(copie, "%s,%s,%s,%s,%s,%s,%s,%02d/%02d/%04d\n",
                tableauEmploye[i].cin,
                tableauEmploye[i].nom,
                tableauEmploye[i].prenom,
                tableauEmploye[i].fonction,
				tableauEmploye[i].departement,
                tableauEmploye[i].numtel,
                tableauEmploye[i].adresse,
                tableauEmploye[i].date_naissance.day,
                tableauEmploye[i].date_naissance.month,
                tableauEmploye[i].date_naissance.year);

        }
        fclose(copie);
        remove("staff.txt");
        rename("temp.txt", "staff.txt");

}

void ModifieremployeCin (employe *tableauEmploye, int *nb_employe_courant)
{   position verif ;
    verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char cin[9];
        do {
        printf("Entrer le nouveau CIN: ");
        gets(cin);
        } while( strlen(cin) != 8 || verification_num(cin)==1);
        strcpy(tableauEmploye[verif.pos].cin,cin);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }


   }
void ModifieremployeNom (employe *tableauEmploye, int *nb_employe_courant)
{   position verif ;
    verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char nom[50];
        do {
        printf("Entrer le nouveau nom: ");
        gets(nom);
        } while (verification_chaine(nom));
        strcpy(tableauEmploye[verif.pos].nom,nom);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }


   }
void ModifieremployeFonction (employe *tableauEmploye, int *nb_employe_courant)
{    position verif ;
     verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char fonction[50];
        do {
        printf("Entrer la nouvelle fonction: ");
        gets(fonction);
        } while (verification_chaine(fonction));
        strcpy(tableauEmploye[verif.pos].fonction,fonction);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }


   }
void ModifieremployeDepart(employe *tableauEmploye, int *nb_employe_courant)
{    position verif ;
     verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char depart[50];
        do {
        printf("Entrer le nouveau departement: ");
        gets(depart);
        } while (verification_chaine(depart));
        strcpy(tableauEmploye[verif.pos].departement,depart);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }


   }
void ModifieremployeAdresse (employe *tableauEmploye, int *nb_employe_courant)
{    position verif ;
     verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char adresse[100];
        do {
        printf("Entrer la nouvelle adresse: ");
        gets(adresse);
        } while (verification_chaine(adresse));
        strcpy(tableauEmploye[verif.pos].adresse,adresse);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }


   }


void ModifieremployePrenom (employe *tableauEmploye, int *nb_employe_courant)
{    position verif;
     verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char prenom[50];
        do {
        printf("Entrer le nouveau prenom: ");
        gets(prenom);
        } while (verification_chaine(tableauEmploye[*nb_employe_courant].prenom));
        strcpy(tableauEmploye[verif.pos].prenom,prenom);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }

   }

void Modifieremployetel (employe *tableauEmploye, int *nb_employe_courant)
{    position verif;
     verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        char num[9];
        do {
        printf("Entrer le nouveau numero de telephone: ");
        gets(num);
        } while (verification_num(num) || strlen(num)!=8 );
        strcpy(tableauEmploye[verif.pos].numtel,num);
        ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }
}

void Modifieremployedate (employe *tableauEmploye, int *nb_employe_courant)
{    position verif;
     verif=verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
      else {
        date datenaiss;
        do{
        printf("Date de naissance de l'employe sous DD MM YYYY: ");
        scanf("%02d %02d %04d",&datenaiss.day,&datenaiss.month,&datenaiss.year);
        getchar();
         }while(verification_date(datenaiss) == 1);
        tableauEmploye[verif.pos].date_naissance=datenaiss;
		ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
        }
}


void SuppressionEmp (employe *tableauEmploye, int* nb_employe_courant)
{    int i;
     position verif;
     verif= verif_cin_staff(tableauEmploye,nb_employe_courant);
     if (verif.exist==0) printf("Le CIN est introuvable");
     else {
        if (verif.pos==*nb_employe_courant) *nb_employe_courant=*nb_employe_courant-1;
        else {
           for(i=verif.pos; i<*nb_employe_courant ;i++) {tableauEmploye[i]=tableauEmploye[i+1] ;}
           *nb_employe_courant=*nb_employe_courant-1;
           ModifierfichierStaff(*nb_employe_courant,tableauEmploye);
           printf("Employe supprime avec succes \n");
             }

          }

}
void ModifierEmp(employe *tableauEmploye, int* nb_employe_courant)
{   int choix;
    do {
     printf("\n *********** MODIFIER EMPLOYE *********** \n ");
            printf("\n 1- Modifier le CIN \n");
            printf("\n 2- Modifier le Nom \n");
            printf("\n 3- Modifier le Prenom \n");
            printf("\n 4- Modifier la Fonction  \n");
            printf("\n 4- Modifier le Departement\n");
            printf("\n 5- Modifier le Numero de Telephone \n");
            printf("\n 6- Modifier l'Adresse \n");
            printf("\n 7- Modifier la Date de Naissance \n");
            printf("\n 8- Quitter le menu de modification \n");
            do {
            printf("\n Entrer un choix entre 1 et 9: ");
            scanf("%d", &choix);
            getchar();
			}while (choix<0||choix>9);

            switch (choix) {
                case 1:
                    system("cls");
                    ModifieremployeCin(tableauEmploye, nb_employe_courant);
                    break;
                case 2:
                    system("cls");
                    ModifieremployeNom(tableauEmploye, nb_employe_courant);
                    break;
                case 3:
                    system("cls");
                    ModifieremployePrenom(tableauEmploye, nb_employe_courant);
                    break;
                case 4:
                    system("cls");
                    ModifieremployeFonction(tableauEmploye, nb_employe_courant);
                    break;
                case 5:
                    system("cls");
                    ModifieremployeDepart(tableauEmploye, nb_employe_courant);
                    break;
				case 6 :
                    system("cls");
                    Modifieremployetel(tableauEmploye, nb_employe_courant);
                    break;
                case 7:
                    system("cls");
                    ModifieremployeAdresse(tableauEmploye, nb_employe_courant);
                    break;
                case 8:
                    system("cls");
                    Modifieremployedate(tableauEmploye, nb_employe_courant);
                    break;
                case 9:
                    break;

            }
        } while (choix != 9);  // Quitter le menu de modification lorsque l'utilisateur choisit l'option 8
    }

void RechercheEmp (employe *tableauEmploye, int* nb_employe_courant)
{    int choix;
  do{
     printf("\n *********** RECHERCHE employe *********** \n ");
     printf("\n 1- Recherche par CIN \n");
     printf("\n 2- Recherche par nom et/ou prenom \n");
     printf("\n 3- Recherche par fonction \n");
	      printf("\n 4- Recherche par departement \n");
     printf("\n 5- Quitter le menu recherche \n");

     do{
     printf(" \n Entrer un choix entre 1 et 5: ");
     scanf("%d",&choix);
     getchar();
       }
     while (choix<0||choix>5);
     switch(choix)
  { case 1: system("cls");
            RechercheEmpCin(tableauEmploye,nb_employe_courant);
            break;
    case 2: system("cls");
            RechercheEmpNomprenom(tableauEmploye,nb_employe_courant);
            break;
    case 3: system("cls");
            RechercheEmpFonction(tableauEmploye,nb_employe_courant);
            break;
    case 4: system("cls");
	RechercheEmpDepartement(tableauEmploye,nb_employe_courant);
            break;
	case 5: system("cls");
            break;
    }

    } while (choix != 5);

}
void GestionEmploye()
{    int nb_employe_courant=0 ;
     employe *tableauEmploye = (employe *)malloc(100 * sizeof(employe));
     intialisation_tableau_employe(tableauEmploye,&nb_employe_courant);
    int choix;
    do {
    printf("\n *********** GESTION DES EMPLOYES *********** \n ");
    printf("\n 1- Ajouter un employe \n");
    printf("\n 2- Modifier un employe \n");
    printf("\n 3- Supprimer un employe \n");
    printf("\n 4- Rechercher un employe \n");
    printf("\n 5- Quitter la gestion des employes \n");

  do{
  printf(" \n Entrer un choix entre 1 et 5: ");
  scanf("%d",&choix);
  }
  while (choix<0||choix>5);

  switch(choix)
  { case 1: system("cls");
            ajouter_staff(tableauEmploye,&nb_employe_courant);
            break;
	  case 2: system("cls");
            ModifierEmp(tableauEmploye,&nb_employe_courant);
        break;
    case 3: system("cls");
            SuppressionEmp(tableauEmploye,&nb_employe_courant);
            break;
    case 4: system("cls");
            RechercheEmp(tableauEmploye,&nb_employe_courant);
            break;

 }}
 while(choix != 5) ;

}
