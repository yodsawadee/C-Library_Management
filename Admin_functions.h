#include "general_functions.h"
#include "core_functions.h"

#ifndef ADMIN_FUNCTIONS_H_INCLUDED
#define ADMIN_FUNCTIONS_H_INCLUDED

void menuForAdmin()
{
    int k = 13;
    ClearConsoleToColors(0,k);
    while(1){
        system("cls");
        gotoxy(20,2);
        SetColorAndBackground(2,k);
        printf("\xDB\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 MENU \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xDB");
        gotoxy(20,4);
        SetColorAndBackground(4,k);
        printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books");
        gotoxy(20,6);
        printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
        gotoxy(20,8);
        printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
        gotoxy(20,10);
        printf("\xDB\xDB\xDB\xDB\xB2 4. View Book list");
        gotoxy(20,12);
        printf("\xDB\xDB\xDB\xDB\xB2 5. Edit Book's Record");
        gotoxy(20,14);
        printf("\xDB\xDB\xDB\xDB\xB2 6. Close Administrator Mode");
        gotoxy(20,16);
        SetColorAndBackground(2,k);
        printf("\xDB\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xDB");
        gotoxy(20,18);
        t(); //show Date and time
        gotoxy(20,21);
        SetColorAndBackground(0,k);
        printf("Enter your choice: ");
        switch(getch()){
            case '1': addBooks(); break;
            case '2': deleteBooks(); break;
            case '3': searchBooks(); break;
            case '4': viewBooks(); break;
            case '5': editBooks(); break;
            case '6': SelectionMode();
            default:
                gotoxy(15,23);
                SetColorAndBackground(12,k);
                printf("\aWrong Entry!! Please re-entered correct option");
                getch(); //holds the screen until a key is pressed
        }
    }
}

void addBooks(void) //funtion that add books to file Record.txt
{
	system("cls");
	FILE *fp;
	int i, choice;
	ClearConsoleToColors(0,8);
	add_window();
	gotoxy(20,21);
	SetColorAndBackground(0,8);
	printf("Enter your choice: ");
	scanf("%d", &choice);
	if(choice<1 || choice>7){
        gotoxy(15,23);
        SetColorAndBackground(12,8);
        printf("\aWrong Entry!! Please re-entered correct option");
        getch();
        fflush(stdin); //for buffer
        addBooks();
    }
	else if(choice==7)
        menuForAdmin() ;

	system("cls");
	ClearConsoleToColors(0,7);
	fp = fopen("Record.txt","ab+");
	if(getdata(choice) == 1){
        book.cat=catagories[choice-1];
        fseek(fp,0,SEEK_END);
        fwrite(&book,sizeof(book),1,fp);
        fclose(fp);
        gotoxy(22,14);
        SetColorAndBackground(9,7);
        printf("The record is sucessfully saved");
        gotoxy(22,16);
        SetColorAndBackground(0,7);
        printf("Save any more?(Y / N): ");
        if(getch()=='n')
            menuForAdmin();
        else
            addBooks();
    }
    fclose(fp);
}

void deleteBooks() //function that delete items from file Record.txt
{
    FILE *ft,*fp;
    int d, findBook = 0;
    ClearConsoleToColors(0,7);
    system("cls");
    gotoxy(15,2);
    SetColorAndBackground(4,7);
    printf("\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD DELETE BOOK \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD");
    gotoxy(10,6);
    SetColorAndBackground(0,7);
    printf("Enter the Book ID to delete: ");
    scanf("%d",&d);
    fp = fopen("Record.txt","rb+");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(book.id==d){
            gotoxy(10,8);
            SetColorAndBackground(9,7);
            printf("The book record is available");
            gotoxy(12,9);
            printf("Book name is %s",book.name);
            gotoxy(12,10);
            printf("Rack No. is %d",book.rackno);
            findBook = 1;
            gotoxy(10,11);
            SetColorAndBackground(0,7);
            printf("Do you want to delete it?(Y/N): ");
            if(getch()=='y'){
                ft=fopen("test.txt","wb");  //temporary file for delete
                rewind(fp);
                while(fread(&book,sizeof(book),1,fp)==1){
                    if(book.id!=d){
                        fwrite(&book,sizeof(book),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(fp);
                fclose(ft);
                remove("Record.txt");
                rename("test.txt","Record.txt"); //copy all item from temporary file to fp except that
                                        //we want to delete
                gotoxy(10,12);
                SetColorAndBackground(9,7);
                printf("The record is sucessfully deleted");
            }
        }
    }
    if(findBook == 0){
        gotoxy(10,9);
        SetColorAndBackground(12,7);
        printf("No record is found");
        fflush(stdin);
    }
    gotoxy(10,14);
    SetColorAndBackground(0,7);
    printf("Delete another record?(Y/N): ");
    if(getch()=='n')
        menuForAdmin();
    else
        deleteBooks();
}

void searchBooks()
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
        case '1': searchByID(); break;
        case '2': searchByName(); break;
        default :
            SetColorAndBackground(12,8);
            gotoxy(17,20);
            printf("\aWrong Entry!! Please re-entered correct option");
            getch();
            searchBooks();
    }
}

void viewBooks(void) //show the list of book persists in library
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
        menuForAdmin();
    else
        viewBooks();
}

void editBooks(void) //edit information about book
{
	FILE *fp;
	int c = 0,d;
	ClearConsoleToColors(0,7);
	system("cls");
	gotoxy(15,2);
    SetColorAndBackground(4,7);
    printf("\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD EDIT BOOK \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD");
    gotoxy(15,6);
    SetColorAndBackground(0,7);
    printf("Enter Book Id to be edited: ");
    scanf("%d",&d);
    fp=fopen("Record.txt","rb+");
    while(fread(&book,sizeof(book),1,fp)==1)
    {
        if(checkID(d)==0)
        {
            gotoxy(15,7);
            SetColorAndBackground(9,7);
            printf("The book is availble");
            gotoxy(17,8);
            printf("The Book ID: %d",book.id);
            gotoxy(17,9);
            printf("The Book Name: %s",book.name);
            gotoxy(15,11);
            SetColorAndBackground(0,7);
            printf("Enter new name: ");
            scanf(" %[^\n]s",book.name);
            gotoxy(15,12);
            printf("Enter new Author: ");
            scanf(" %[^\n]s",book.Author);
            gotoxy(15,13);
            printf("Enter new quantity: ");
            scanf("%d",&book.quantity);
            gotoxy(15,14);
            printf("Enter new price: ");
            scanf("%f",&book.Price);
            gotoxy(15,15);
            printf("Enter new rackno: ");
            scanf("%d",&book.rackno);
            gotoxy(15,17);
            SetColorAndBackground(9,7);
            printf("The record is modified");
            //fseek(fp,ftell(fp)-sizeof(book),0);
            fseek(fp,ftell(fp)-sizeof(book),SEEK_CUR);
            //rewind(fp);
            fwrite(&book,sizeof(book),1,fp);
            fclose(fp);
            c=1;
        }
        if(c==0)
        {
            gotoxy(15,9);
            SetColorAndBackground(12,7);
            printf("No record found");
        }
    }
    gotoxy(15,19);
    SetColorAndBackground(0,7);
    printf("Modify another Record?(Y/N) ");
    fflush(stdin);
    if(getch()=='n')
        menuForAdmin();
    else
        editBooks();
}

#endif // ADMIN_FUNCTIONS_H_INCLUDED
