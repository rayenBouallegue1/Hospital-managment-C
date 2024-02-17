#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED


//structure patient
typedef struct
{
    char  Lname [40] ;
    char Fname [40] ;
    char CIN [9] ;
    char Tel [9] ;

}Patient ;


// structure Noeud pour la declaration du liste

typedef struct structNoeud {

Patient *patient ;
struct structNoeud *precedent ;
struct structNoeud *suivant;

}structNoeud, *NOEUD;


// declaration du liste
typedef  struct structListe
{
    NOEUD head ;
    NOEUD tail ;
    int length ;

}structListe, *List ;




int isNum(char s[])  ;
int isChar(char s[]) ;
Patient* PatientRead() ;
void PatientPrint(Patient p) ;
int enregistrerPatients(Patient *p) ;
int patientComparer(Patient *p1 , Patient *p2) ;
void PatientDestruction(Patient *p ) ;
NOEUD noeudCreer(Patient *p) ;
void  DestructionNoeud(NOEUD n ) ;
List ListCreate();
int EstVide(List l);
void ListeAfficher(List l);
int SupprListe(List l ,char Cin[] );
void listeDestruction(List l);
int ExistePat(Patient *p, List l );
NOEUD CherchCinPat(char Cin[9], List l );
NOEUD CherchPatient (Patient *p,List l);
int ModifCinPatient(char OldCin [9],char NewCin[9],List l );
void AffichePatientAvecCin(char cin[9] , List l );

void deleteAndCreateFilePatient();
int EnregistrerListeEnFichier(List l );
int AddPatient(Patient *p, List l);
void menuRecherchePatient();
void GestionPatient();


List LireFichier() ;





#endif // PATIENT_H_INCLUDED
