#include "core_functions.h"
#include "general_functions.h"

#ifndef USER_FUNCTIONS_H_INCLUDED
#define USER_FUNCTIONS_H_INCLUDED

void menuForUser()
{
    int k = 13;
    ClearConsoleToColors(0,k);
    while(1){
        system("cls");
        gotoxy(20,4);
        SetColorAndBackground(2,k);
        printf("\xDB\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 MENU \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xDB");
        SetColorAndBackground(4,k);
        gotoxy(20,6);
        printf("\xDB\xDB\xDB\xDB\xB2 1. Search Books");
        gotoxy(20,8);
        printf("\xDB\xDB\xDB\xDB\xB2 2. View Books");
        gotoxy(20,10);
        printf("\xDB\xDB\xDB\xDB\xB2 3. Close User Mode");
        gotoxy(20,12);
        SetColorAndBackground(2,k);
        printf("\xDB\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xDB");
        gotoxy(20,14);
        t(); //show Date and time
        gotoxy(20,19);
        SetColorAndBackground(0,k);
        printf("Enter your choice: ");
        switch(getch()){
            case '1': search_book(); break;
            case '2': view_book(); break;
            case '3': SelectionMode();
            default:
                gotoxy(12,21);
                SetColorAndBackground(12,k);
                printf("\aWrong Entry!! Please re-entered correct option");
                getch(); //holds the screen until a key is pressed
                fflush(stdin);
        }
    }
}

void search_book()
{
    ClearConsoleToColors(0,8);
    system("cls");
    gotoxy(15,2);
    SetColorAndBackground(4,8);
    printf("\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD SEARCH BOOK \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD");
    gotoxy(20,8);
    SetColorAndBackground(1,8);
    printf("-------\x0F  1) Search By ID");
    gotoxy(20,12);
    printf("-------\x0F  2) Search By Name");
    gotoxy(15,18);
    SetColorAndBackground(0,8);
    printf("Enter Your Choice: ");
    switch(getch())
    {
        case '1': searchByID_User(); break;
        case '2': searchByName_User(); break;
        default :
            SetColorAndBackground(12,8);
            gotoxy(17,20);
            printf("\aWrong Entry!! Please re-entered correct option");
            getch();
            search_book();
    }
}

void view_book(void) //show the list of book persists in library
{
    int j;
    FILE *fp;
    ClearConsoleToColors(0,7);
    system("cls");
    gotoxy(15,2);
    SetColorAndBackground(4,7);
    printf("\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD BOOK LIST \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD");
    gotoxy(2,4);
    SetColorAndBackground(1,7);
    printf("CATEGORY     ID    BOOK NAME      AUTHOR            QTY     PRICE     RackNo ");
    j=6;
    fp=fopen("Record.txt","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        SetColorAndBackground(0,7);
        gotoxy(2,j);
        printf("%s",book.cat);
        gotoxy(15,j);
        printf("%d",book.id);
        gotoxy(21,j);
        printf("%s",book.name);
        gotoxy(36,j);
        printf("%s",book.Author);
        gotoxy(55,j);
        printf("%d",book.quantity);
        gotoxy(62,j);
        printf("%.2f",book.Price);
        gotoxy(74,j);
        printf("%d",book.rackno);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    gotoxy(45,25);
    SetColorAndBackground(4,7);
    printf(" Press ENTER to return to menu");
    if(getch()==13) //allow only use of enter
        User_Mode();
    else
        view_book();
}

void searchByID_User(){
    ClearConsoleToColors(0,7);
    system("cls");
    int id; FILE *fp;
    gotoxy(14,2);
    SetColorAndBackground(4,7);
    printf("\x0F--------------- Search Books By ID ---------------\x0F");
    gotoxy(20,5);
    SetColorAndBackground(0,7);
    printf("Enter the book id: ");
    scanf("%d",&id);
    int findBook = 0;
    fp = fopen("Record.txt","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(book.id==id){
            Sleep(2);
            gotoxy(20,7);
            SetColorAndBackground(9,7);
            printf("The Book is available");
            gotoxy(20,8);
            SetColorAndBackground(2,7);
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            gotoxy(20,9);
            printf("\xBA ID: %d",book.id); gotoxy(54,9);printf("\xBA");
            gotoxy(20,10);
            printf("\xBA Name: %s",book.name); gotoxy(54,10);printf("\xBA");
            gotoxy(20,11);
            printf("\xBA Author: %s",book.Author); gotoxy(54,11);printf("\xBA");
            gotoxy(20,12);
            printf("\xBA Qantity: %d",book.quantity); gotoxy(54,12);printf("\xBA");
            gotoxy(20,13);
            printf("\xBA Price: Rs.%.2f",book.Price); gotoxy(54,13);printf("\xBA");
            gotoxy(20,14);
            printf("\xBA Rack No: %d ",book.rackno); gotoxy(54,14);printf("\xBA");
            gotoxy(20,15);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            findBook = 1;
        }
    }
    if(findBook == 0){  //checks whether conditiion enters inside loop or not
        gotoxy(20,8);
        SetColorAndBackground(12,7);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(20,17);
    SetColorAndBackground(0,7);
    printf("Try another search?(Y/N) ");
    if(getch()=='y')
        searchByID_User();
    else
        User_Mode();
}

void searchByName_User(){
    ClearConsoleToColors(0,7);
    system("cls");
    char s[15];
    int d=0;
    FILE *fp;
    gotoxy(14,2);
    SetColorAndBackground(4,7);
    printf("\x0F------------- Search Books By Name -------------\x0F");
    gotoxy(20,5);
    SetColorAndBackground(0,7);
    printf("Enter Book Name: ");
    scanf(" %[^\n]s", s);
    fp = fopen("Record.txt","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(strcmp(book.name,(s))==0){ //checks whether book.name is equal to s or not
            gotoxy(20,7);
            SetColorAndBackground(9,7);
            printf("The Book is available");
            gotoxy(20,8);
            SetColorAndBackground(2,7);
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            gotoxy(20,9);
            printf("\xBA ID: %d",book.id); gotoxy(54,9);printf("\xBA");
            gotoxy(20,10);
            printf("\xBA Name: %s",book.name); gotoxy(54,10);printf("\xBA");
            gotoxy(20,11);
            printf("\xBA Author: %s",book.Author); gotoxy(54,11);printf("\xBA");
            gotoxy(20,12);
            printf("\xBA Qantity: %d",book.quantity); gotoxy(54,12);printf("\xBA");
            gotoxy(20,13);
            printf("\xBA Price: Rs.%.2f",book.Price); gotoxy(54,13);printf("\xBA");
            gotoxy(20,14);
            printf("\xBA Rack No: %d ",book.rackno); gotoxy(54,14);printf("\xBA");
            gotoxy(20,15);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            d++;
        }
    }
    if(d==0){
        gotoxy(20,8);
        SetColorAndBackground(12,7);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(20,17);
    SetColorAndBackground(0,7);
    printf("Try another search?(Y/N) ");
    if(getch()=='y')
        searchByName_User();
    else
        User_Mode();
}

#endif // USER_FUNCTIONS_H_INCLUDED
