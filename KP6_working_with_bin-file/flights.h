#include <string.h>
#ifndef flights_h
#define flights_h
#define N 10
#define SIZE 50

const char *names[N]={"Sername", "Initials", "Sex", "Baggage", "Air Company", "Flight", "Date", "Time", "From", "To"};
char* Air_company[SIZE];
char* Flight[SIZE];
char* Dates[SIZE];
char* Times[SIZE];
char* From[SIZE];
char* To[SIZE];

typedef struct flights{
    char sername[21];
    char initials[6];
    char sex[3];
    char baggage[5];
    char company[21];
    char flight[9];
    char date[10];
    char time[7];
    char from[21];
    char to[21];
} flights;

#endif