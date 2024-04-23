#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void balance_checker(char*);
void ACC_VIWER(char*);
void LOGin(void);

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct process {
	char user_name[50];
	char password[50];
	int date, month, year;
	char pnumber[15];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char typeaccount[20];
};

struct money {
	char userpersonfrom[50];
	char usernameto[50];
	long int money1;
};
void transfermoney(int,int);
void loginsu(void);
void ACC_created(void);
void account(void);
void logout(void);

// Driver Code
int main()
{
	system("COLOR 17");
	int i;
	int a;
	int b;
	int choice;
	int x=1;
	int passwordlength;
	gotoxy(20, 3);

	while(x){
		system("CLS");
		printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
		gotoxy(18, 5);
		printf("*********************************************************");
		gotoxy(30, 6);
		printf("DEVELOP BY JAWAD AND HAFEEZ");
		gotoxy(18, 7);
		printf("*********************************************************");
		gotoxy(20, 10);
		printf("1.... CREATE A BANK ACCOUNT");
		gotoxy(20, 12);
		printf("2.... ALREADY A USER? SIGN IN");
		gotoxy(20, 14);
		printf("3.... EXIT\n\n");
		printf("\n\nENTER YOUR CHOICE..");
		gotoxy(19, 18);
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			system("cls");
			printf("\n\n USERNAME 50 CHARACTERS MAX!!");
			printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
			account();
			break;
		case 2:
			LOGin();
			break;
		case 3:
			x=0;
			break;
			getch();
		}
	}
	return x;
}

void account(void)
{
	char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	int choice;
	FILE *fp, *fu;
	struct process u1;

	fp = fopen("username.txt", "ab");

	system("cls");
	printf("\n!!!!!CREATING ACCOUNT!!!!!");

	printf("\nFIRST NAME..: ");
	scanf("%s", &u1.fname);

	printf("\nLAST NAME..: ");
	scanf("%s", &u1.lname);
    fflush(stdin);
	printf("\nFATHER's NAME..: ");
	scanf("%[^\n]%*c", &u1.fathname);

	printf("\nMOTHER's NAME..: ");
	scanf("%[^\n]%*c", &u1.mothname);

	printf("\nADDRESS..: ");
	scanf("%[^\n]%*c", &u1.address);

	printf("\nACCOUNT TYPE::\n1:Minor Account\n2:Saving Account\n3:Buisness Account\nEnter The Choice::  ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		strcpy(u1.typeaccount,"Minor Account");
		break;
		case 2:
		strcpy(u1.typeaccount,"Saving Account");
		break;
		case 3:
		    strcpy(u1.typeaccount,"Buisness Account");
		    break;
	}

	printf("\nDATE OF BIRTH.. in this Form (DD/MM/YYYY)\n");
	scanf("%d/%d/%d", &u1.date,&u1.month,&u1.year);
fflush(stdin);
	printf("\nPHONE NUMBER : ");
	scanf("%[^\n]%*c",&u1.pnumber);

	printf("\nUSERNAME..:-");
	scanf("%[^\n]%*c", &u1.user_name);

	printf("\nPASSWORD..:-");

	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}
	strcpy(u1.password,password);
	fwrite(&u1, sizeof(u1), 1, fp);
	fclose(fp);

ACC_created();
}

void ACC_created(void)
                     {
	                    int i;
                          	char ch;
	                         system("cls");
                         	printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
                             	Sleep(100);
                                     	gotoxy(30, 10);
                              	printf("ACCOUNT CREATED SUCCESSFULLY....");
                              	gotoxy(0, 20);
                                	printf("Press enter to continue");
	getch();
}

void LOGin(void)
           {
            	system("cls");
 
              	    char username[50];
                	char password[50];

                   	int i, j, k, flag=1;
	                   char ch;
                                   	FILE *fp;
                                  	struct process u1;

	                         fp = fopen("username.txt","rb");

	                   if (fp == NULL) {
		                     printf("ERROR IN OPENING FILE");
	                                      }
	
	
                    	gotoxy(34, 2);
                               	printf(" ACCOUNT LOGIN ");
	    gotoxy(7, 5);
	                     printf("*******************************************************************************");
	      gotoxy(35, 10);
                        	printf("==== LOG IN ====");
	
	
	  gotoxy(35, 12);
                     	printf("USERNAME.. ");
	                    scanf("%s", &username);
	   gotoxy(35, 14);
                        	printf("PASSWORD..:-");

                       	for (i = 0; i < 50; i++) {
		                                          ch = getch();
		                                            if (ch != 13) {
		                                    	password[i] = ch;
                                         			ch = '*';
			                                   printf("%c", ch);
		                               }                           

	                  	else 
			                   break;
                           	}                        

	while (fread(&u1, sizeof(u1),1, fp)) {
		if (strcmp(username,u1.user_name) == 0 && strcmp(password,u1.password) == 0) {
			flag=1;
			loginsu();
			ACC_VIWER(username);
		}
		else flag=0;
	}
	
	if(flag==0) printf("\n\nIncorrect credentials / Account does not exist!!\n\n");
	printf("Press enter to continue...");
	getch();
	fclose(fp);
}

void loginsu(void)
{
                           	int i;
                        	FILE* fp;
	                              system("cls");
                    	printf("Fetching account details.....\n");
                     	Sleep(100);
	                              gotoxy(30, 10);
	                    printf("LOGIN SUCCESSFUL....");
	                            gotoxy(0, 20);
                                      	printf("Press enter to continue");
                        	getch();
}

void ACC_VIWER(char username1[])
{
                        	system("cls");
                               	FILE* fp;
                             	int choice;
                                   	int z;
                             	fp = fopen("username.txt", "rb");
                    	struct process user;

	                  if (fp == NULL) {
                      		printf("error in opening file");
	                                    }       

	                          while (fread(&user, sizeof(user),1, fp)) {
                                     		if (strcmp(username1,user.user_name)== 0) {
		                        	gotoxy(30, 1);
			printf("WELCOME, %s %s",user.fname, user.lname);
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME..%s %s", user.fname,user.lname);

			gotoxy(55, 12);
			printf("FATHER's NAME..%s",user.fathname);

			gotoxy(55, 14);
			printf("MOTHER's NAME..%s",user.mothname);

			gotoxy(55, 16);

			gotoxy(55, 18);
			printf("MOBILE NUMBER..%s",user.pnumber);
			gotoxy(55, 20);
			printf("DATE OF BIRTH.. %d-%d-%d",user.date, user.month, user.year);

			gotoxy(55, 22);
			printf("ADDRESS..%s", user.address);

			gotoxy(55, 24);
			printf("ACCOUNT TYPE..%s",user.typeaccount);
			if(strcmp(user.typeaccount,"Minor Account")==0){
				z=1;
			}else if(strcmp(user.typeaccount,"Saving Account")==0){
				z=2;
			}else if(strcmp(user.typeaccount,"Buisness Account")==0){
				z=3;
			}
		}
	}

	fclose(fp);

	gotoxy(0, 6);

	printf(" HOME ");
	gotoxy(0, 7);
	printf("******");
	gotoxy(0, 9);
	printf(" 1....CHECK BALANCE OR HISTORY OF TRANSACTION");
	gotoxy(0, 11);
	printf(" 2....TRANSFER MONEY");
	gotoxy(0, 13);
	printf(" 3....DEPOSIT AMOUNT\n\n");
    gotoxy(0, 15);
	printf(" 4....CASH ACCOUNT\n\n");
	gotoxy(0, 17);
	printf(" 5....LOG OUT\n\n");

	printf(" ENTER YOUR CHOICES..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		balance_checker(username1);
		break;

	case 2:
		transfermoney(choice,z);
		break;

	case 3:
		transfermoney(choice,z);
		break;

	case 4:
		transfermoney(choice,z);
		break;
	case 5:
	logout();
	break;	
	}
}

void logout(void)
{
	int ii ;
	int jj;
	system("cls");
	printf("please wait, logging out");
	for (ii = 0; ii < 10; ii++) {
		for (jj = 0; jj < 25000000; jj++) {
			ii++;
			ii--;
		}
		printf(":-");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}

void balance_checker(char username2[])
{
	system("cls");
	FILE* fm;
	struct money mmm;
	int i = 1, s_money = 0;

	fm = fopen("mon.txt", "rb");

	int kkk = 5; 
	int lll = 10;
	int mm = 30; 
	int nnn = 10;
	int uuu = 60;
	int v = 10;

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("***************************");
	gotoxy(kkk, lll);
	printf("S no.");
	gotoxy(mm, nnn);
	printf("TRANSACTION ID");
	gotoxy(uuu, v);
	printf("AMOUNT");

	while (fread(&mmm, sizeof(mmm),1, fm)) {
		if (strcmp(username2,mmm.usernameto)== 0) {
			gotoxy(kkk, ++lll);
			printf("%d", i);
			i++;
			gotoxy(mm, ++nnn);
			printf("%s", mmm.userpersonfrom);

			gotoxy(uuu, ++v);
			printf("%d", mmm.money1);
			// Adding and
			// finding total money
			s_money = s_money + mmm.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");
	gotoxy(80, 12);
	printf("%d", s_money);
	getch();

	fclose(fm);
	ACC_VIWER(username2);
}

void transfermoney(int k,int z)
{
	int i, j,x,p=1,a=0;
	FILE *fm, *fp;
	struct process u1;
	struct money m1;
	struct process u2;
	struct money m2;
	char user_to[20];
	char ab[20];
	char usernamep[20];
	system("cls");

	fp = fopen("username.txt", "rb");
	fm = fopen("mon.txt", "ab");

	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(34, 11);
	printf("(YOUR USERNAME)..   ");
	scanf("%s", &user_to);
	strcpy(ab,user_to);
     if(k==3){
     	gotoxy(31, 13);
	printf("AGAIN ENTER YOUR USERNAME.. ");
	 }else if(k==4){
     	gotoxy(31, 13);
	printf("AGAIN ENTER YOUR USER NAME..");
	 }else{
	gotoxy(31, 13);
	printf(" TO (username of person)..");}
	scanf("%s", &usernamep);
	
	
	while (fread(&u1, sizeof(u1),1, fp))
	{
		if (strcmp(usernamep,u1.user_name)== 0) {
			a=1;
			strcpy(m1.usernameto,u1.user_name);
			strcpy(m1.userpersonfrom,user_to);
		}
	}
	// Taking amount input
	while(p){
		system("cls");
	gotoxy(0, 0);
	if(z==1){
	printf("Your Account Is Minor You would not Deposit, With drawing And Transfarming amount less than 1500 and Greater than 5000\n");
	gotoxy(33,5);
	printf("ENTER THE AMOUNT  ");
	scanf("%d", &m1.money1);
	if(m1.money1<1500||m1.money1>5000){
	           system("cls");
	           gotoxy(33, 5);
	           printf("PLEASE ENTER THE AMOUNT IN RANGE\n");
	           gotoxy(36, 6);
	           printf("ENTER THE ANY KEY TO CONTINUE ");
	           getch();
	           continue;
			             }}
	if(z==2){
	printf("Your Account Is Saving You would not Deposit, With drawing And Transfarming amount less than 5000 and Greater than 50000\n");
	gotoxy(33,5);
	printf("ENTER THE AMOUNT  ");
	scanf("%d", &m1.money1);
	if(m1.money1<5000||m1.money1>50000){
	           system("cls");
	            gotoxy(33, 5);
	           printf("PLEASE ENTER THE AMOUNT IN RANGE\n");
	           gotoxy(33,6);
	           printf("ENTER THE ANY KEY TO CONTINUE ");
	           getch();
	           continue;
			             }}
	if(z==3){
	printf("Your Account Is BUSINESS You would not Deposit, With drawing And Transfarming amount less than 15000 and Greater than 150000\n");
	gotoxy(33,5);
	printf("ENTER THE AMOUNT  ");
	scanf("%d", &m1.money1);
	if(m1.money1<15000||m1.money1>150000){
	           system("cls");
 gotoxy(33, 5);
	           printf("PLEASE ENTER THE AMOUNT IN RANGE\n");
	           gotoxy(33, 6);
	           printf("ENTER THE ANY KEY TO CONTINUE  ");
	           getch();
	           continue;
			             }}
		p=0;				 					 		             
	}
	
	x=m1.money1;
	if(k==4){
		m1.money1=m1.money1*(-1);
		x=m1.money1;
	}else if(k==2)
	x=x*(-1);
	
	// Writing to the file
	fwrite(&m1, sizeof(m1),1, fm);
	fclose(fp);
	fclose(fm);
	fp = fopen("username.txt", "rb");
	            fm = fopen("mon.txt", "ab");
	if(strcmp(ab,usernamep)!=0){ 
	 	strcpy(usernamep,ab);
	          	while (fread(&u2, sizeof(u2),1, fp))
	        {
	               	if (strcmp(usernamep,u2.user_name)== 0) {
			           strcpy(m2.usernameto,u2.user_name);
			              strcpy(m2.userpersonfrom,user_to);
		                  }     
	} m2.money1=x;
		fwrite(&m2, sizeof(m2),1, fm);
	fclose(fp);
	fclose(fm);
	}else
	{   fclose(fp);
	fclose(fm);
	}
	gotoxy(0, 12);
	printf("----------------------------------------------------------------------------------------------");
	gotoxy(0, 14);
	printf("----------------------------------------------------------------------------------------------");
	gotoxy(0, 16);
	printf("transferring amount, Please wait..");
	gotoxy(10, 13);
	for (i = 0; i < 70; i++) {
		Sleep(20);
		printf("*");
	}
	gotoxy(33, 20);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();
	fclose(fp);
	fclose(fm);
	ACC_VIWER(user_to);
}

