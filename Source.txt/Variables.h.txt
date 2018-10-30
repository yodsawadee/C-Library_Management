#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

//list of header files
#include<windows.h>                 //contains color functions,etc.
#include<stdio.h>                   //contains printf(),scanf(),etc.
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include<stdlib.h>                  //contains system(),,etc.
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc.
#include<ctype.h>                   //contains toupper(), tolower(),etc.
#include<dos.h>                     //contains _dos_getdate
#include<time.h>                    //contains clock, time

#define RETURNTIME 15

//function prototype for main program
void SelectionMode();
void Admin_Mode();
void User_Mode();

//function prototype for admin mode
void menuForAdmin();
void addBooks(void);
void deleteBooks();
void searchBooks();
void viewBooks(void);
void editBooks(void);
//void issueBooks(void);

int getData();
int checkID(int);
int t(void);
void searchByID();
void searchByName();
void add_window();
void creditNclose();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;

//list of global variable
char catagories[][15]={"Mathematics","Science","Social","English","Art","Computer"};
int s;
char findbook;
char password[10] = {"1234"};
int main_window = 1;  ///////////////////////

struct meroDate
{
    int mm,dd,yy;
};

struct Book
{
    int id;
    char stname[20];
    char name[50];
    char Author[50];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct Book book;

#endif // VARIABLES_H_INCLUDED
