#include "Admin_functions.h"
#include "User_functions.h"

int main()
{
    SetConsoleTitle("Library Management"); //set the console title to "Library Management"
    SelectionMode(); //invoke SelectionMode function
    return 0;
}

void SelectionMode()
{
    char ch;
    char str[25] = " SELECTION MODE "; //declare array str with have the size 25
    int j;
    ClearConsoleToColors(0,15); //0=letterColor, 15=backgroundColor
    while(1){
        system("cls"); //clear screen
        gotoxy(9,5); //move to the position x=9 and y=5
        SetColorAndBackground(10,15);
        for(j = 0; j < 11; j++){
            delay(50); //
            printf("\xC5 "); //printf("%c", 197); \x = hexa, C5 = hex of dec 197
        }
        SetColorAndBackground(4,15);
        for(j = 0; j < 16; j++){
            delay(50);
            printf("%c",str[j]); //
        }
        SetColorAndBackground(10,15);
        for(j = 0; j < 11; j++){
            delay(50);
            printf("\xC5 ");
        }
        while(1){
            gotoxy(30,10);
            if(main_window == 1) //go to this condition directly because of global variable initialization
                SetColorAndBackground(14,12);
            else
                SetColorAndBackground(21,15);
            printf("\xB1 USER MODE ");

            gotoxy(30,12);
            if(main_window == 2)
                SetColorAndBackground(14,12);
            else
                SetColorAndBackground(21,15);
            printf("\xB1 ADMINISTRATOR MODE ");

            gotoxy(30, 14);
            if(main_window == 3)
                SetColorAndBackground(14,12);
            else
                SetColorAndBackground(21,15);
            printf("\xB1 QUIT ");

            SetColorAndBackground(15,15);
            ch = getch();
            check_keyboard((int)ch);
            if((int)ch == 13){
                switch(main_window){
                    case 1: User_Mode(); break;
                    case 2: Admin_Mode(); break;
                    case 3: creditNclose();
                }
            }
        }
    }
}

void User_Mode() //for password option
{
    system("cls");
    menuForUser();
}

void Admin_Mode() //for password option
{
    system("cls");
    char str[25] = " ADMINISTRATOR MODE ";
    char ch = 0, pass[10];
    int i = 0, j;
    int k = 11; //for bg color parameterint k = 9; //for bg color parameter

    ClearConsoleToColors(0,k); // 0=letterColor, 15=backgroundColor
    gotoxy(10,4);
    SetColorAndBackground(5,k);
    for(j = 0; j < 10; j++){
        delay(50);
        printf("\x0F ");//printf("%c", 197);
    }
    SetColorAndBackground(2,k);
    for(j = 0; j < 20; j++){
        delay(50);
        printf("%c",str[j]);
    }
    SetColorAndBackground(5,k);
    for(j = 0; j < 10; j++){
        delay(50);
        printf("\x0F ");//printf("%c", 197);
    }

    SetColorAndBackground(0,k);
    gotoxy(15,10);
    printf("Enter Administrator Password: ");

    while(ch!=13){  //13 = Enter
        ch = getch();
        if(ch!=13 && ch!=8){
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0){
        gotoxy(15,15);
        SetColorAndBackground(9,k);
        printf("Password Correct");
        gotoxy(17,17);
        printf("Press any key to countinue.....");
        getch();
        menuForAdmin();
    }
    else{
        gotoxy(12,17);
        SetColorAndBackground(12,k);
        printf("\aWarning!! Incorrect Password");
        getch();
        Admin_Mode();
    }
}
