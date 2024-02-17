#ifndef FT_COMMUN_H_INCLUDED
#define FT_COMMUN_H_INCLUDED
struct Date {
    int year ;
    int month ;
    int day;
};
struct Position {
    int pos ;
    int exist;
    char cin[9];
};

typedef struct Position position;
typedef struct Date date ;
int verification_chaine (char *chaine);
int verification_num (char *chaine);
int verification_date (date date_naiss );





#endif // FT_COMMUN_H_INCLUDED
