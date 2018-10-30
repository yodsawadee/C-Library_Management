#ifndef CORE_FUNCTIONS_H_INCLUDED
#define CORE_FUNCTIONS_H_INCLUDED

int getdata(int choice){
	int bookID;
	ClearConsoleToColors(2,7);
	gotoxy(20,3);printf("Enter the Information");
	SetColorAndBackground(4,7);
	gotoxy(20,4);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
	gotoxy(20,5);
	printf("\xBA");gotoxy(55,5);printf("\xBA");
	gotoxy(20,6);
	printf("\xBA");gotoxy(55,6);printf("\xBA");
	gotoxy(20,7);
	printf("\xBA");gotoxy(55,7);printf("\xBA");
	gotoxy(20,8);
	printf("\xBA");gotoxy(55,8);printf("\xBA");
	gotoxy(20,9);
	printf("\xBA");gotoxy(55,9);printf("\xBA");
	gotoxy(20,10);
	printf("\xBA");gotoxy(55,10);printf("\xBA");
	gotoxy(20,11);
	printf("\xBA");gotoxy(55,11);printf("\xBA");
	gotoxy(20,12);
	printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");

	SetColorAndBackground(0,7);
	gotoxy(22,5);
	printf("Category: ");
	printf("%s",catagories[choice-1]);
	gotoxy(22,6);
	printf("Book ID: ");
	scanf("%d",&bookID);
	if(checkID(bookID) == 0)
	{
		gotoxy(22,13);
		SetColorAndBackground(12,7);
		printf("The book id already exists");
		getch();
		addBooks();
		return 0;
	}
	book.id = bookID;
	gotoxy(22,7);
	printf("Book Name: ");
	scanf(" %[^\n]s", book.name);
	gotoxy(22,8);
	printf("Author: ");
	scanf(" %[^\n]s", book.Author);
	gotoxy(22,9);
	printf("Quantity: ");
	scanf("%d",&book.quantity);
	gotoxy(22,10);
	printf("Price: ");
	scanf("%f",&book.Price);
	gotoxy(22,11);
	printf("Rack No: ");
	scanf("%d",&book.rackno);
	return 1;
}


int checkID(int t){  //check whether the book is exist in library or not
    FILE *temp;
	temp = fopen("Record.txt","rb+");
	while(fread(&book,sizeof(book),1,temp)==1)
        if(book.id == t){
            fclose(temp);
            return 0;
        }
        fclose(temp);
        return 1;
}

void searchByID(){
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
        searchByID();
    else
        menuForAdmin();
}

void searchByName(){
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
        searchByName();
    else
        menuForAdmin();
}

void add_window(){
    gotoxy(20,2);
    SetColorAndBackground(4,8);
	printf("\xDB\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE CATEGORIES \xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xDB");
	gotoxy(20,4);
	SetColorAndBackground(1,8);
	printf("-----\x0F  1) Mathematics");
	gotoxy(20,6);
	printf("-----\x0F  2) Science");
	gotoxy(20,8);
	printf("-----\x0F  3) Social");
	gotoxy(20,10);
	printf("-----\x0F  4) English");
	gotoxy(20,12);
	printf("-----\x0F  5) Art");
	gotoxy(20,14);
	printf("-----\x0F  6) Computer");
	gotoxy(20,16);
	printf("-----\x0F  7) Back to menu");
	gotoxy(20,18);
	SetColorAndBackground(4,8);
	printf("\xDB\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xDB");

}

void creditNclose(){
    system("cls");
    ClearConsoleToColors(9,15);
    gotoxy(16,3);
    printf("Name: Library Management Program");
    gotoxy(16,6);
    printf("Yodsawadee Sornda");
    gotoxy(16,8);
    printf("ID: 58090032");
    gotoxy(16,10);
    printf("E-mail: jan.yodsawadee@outlook.com");
    gotoxy(16,12);
    printf("Department of Software Enginnering");
    gotoxy(16,13);
    printf("King Mongkut's Institute of Technology Ladkrabang");
    gotoxy(10,17);
    printf("Exiting in 3 second---------->");
    Sleep(3000);
    SetColorAndBackground(15,15);
    exit(0);
}

#endif // CORE_FUNCTIONS_H_INCLUDED
