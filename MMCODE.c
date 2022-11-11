
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
char user[50]="bitm",pass[20]="123",expname[20][20],ename1[20],name[50];
long mi,temp;
int expamt[50],e=0,i=0,bamt=0;
void login();
void input();
void output();
void doc();
void main()
{
	int ch,amt,i;
	login();
ab:	printf(" Press 1 for Personal Use    \n");
	printf(" Press 2 for Busness or Organization Purpose : ");
	scanf(" %d",&i);
	if(i==1)
	{
		printf(" Enter Your Name : ");
		scanf(" %s",name);
	}
	if(i==2)
	{
		printf("'' Enter Your Busness or Organization Name : ");
		scanf(" %s",name);
	}
	if(i<1 || i>2)
	{
		printf(" Invalid Input !!\n");
		goto ab;
	}
	printf("Enter the monthly income ");
	scanf("%ld",&mi);
	temp=mi;
	do{		
		printf("\n\n*****************************************\n\n");
		printf(" 1. Inserting the Details of expenditure \n");
		printf(" 2. To display the Details of expenditure \n");
		printf(" 3. To Add the Bonus Amount \n");
		printf(" 4. To Make the Report of the Expenditure \n");
		printf(" 5. To Exit \n");
		printf(" Select the operation : ");
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1 : input();
					break;
			case 2 : output();
					break;
			case 3 : printf(" Enter the Bonus Amount : ");
	   				scanf("%d",&amt);
		 			mi = mi + amt;
		 			bamt = bamt + amt;
			 		break;
			case 4 : doc();
					break;
			case 5 : break;
			default: printf(" Invalid Input !!");
		}
	}while(ch!=5);
	printf("\n----- Thank You :) -------\n "); 
}
	// Login and password
void login()		
{
	char uname[50],password[50];
	int iu=0;
	time_t t;
    time(&t);
    en: printf(" Enter the UserName : ");
		scanf("%s",uname);
		printf(" Enter the Password : ");
		scanf("%s",password);
	if(((strcmp(user,uname)!=0) && iu<3) || ((strcmp(pass,password)!=0) && iu<3))
	{ 	
		if(iu==2 )
	{	
		printf("Sorry ! Too many Unsuccessful Attempts !! ");
		iu=1;
		exit(0);
	}
		printf("Invalid Username or Password Please Re-enter \n ");
		iu++;
		goto en;
	}	
	  system("cls");
    printf("\n- - - - - - - - - - - - Welcome To Money Management System - - - - - - - - - - - - - \n");
    printf("\n\n\t %s \n",ctime(&t));
	iu=0;
}
void input()
{
	int ch=0,j;
	long amt;
	if(i>0)
	{
		printf("\n The Existing Details are :\n");
		for(j=1;j<=i;j++)
		printf("\n %d . %s ",j,expname[j]);
	a:	printf("\n\n Select the Existing Expenditure else enter 0 to add new Expenditure: ");
		scanf(" %d",&ch);
		if(ch>i)
		{
			printf(" Invalid Choice !! \n");
			goto a;
		}
	}
	if(i>0 && ch>0)
	{	
		printf("\nEnter the amount spent in %s ",expname[ch]);
		scanf(" %ld",&amt);
		if(amt>mi)
		{
			printf(" Expenditure amount is larger than the Balance amount !! \n");
			return;
		}	
		expamt[ch]+=amt;
		mi -= amt;
	}
	if(ch==0)
	{	
		printf("\n Enter the Name of Expenditure ( Avoid the Space in between Name ) : \n");
		scanf(" %s",expname[++i]);
		printf("\n Enter the amount that is spent : ");
		scanf("%ld",&amt);
		if(amt>mi)
		{
			printf(" Expenditure amount is larger than the Balance amount !! \n");
			i--;
			return;
		}
		expamt[i] += amt ;
		mi -= amt;
	}
}
	//Displaying the details of Expenditure
void output()
{
	int j;
	if(i>0)
	{
		printf("\n The Details of Expenditue are : \n");
		for(j=1;j<=i;j++)
		printf("\n  Name of Expenditure : %s \n  Amount Spent is : %d \n",expname[j],expamt[j]);
		printf("\n Balance Amount is: %ld\n",mi);
		if(mi==0)
		{
			printf(" There is No Balance left !!\n");
		}
		else if(mi<(temp/4))
		{
			printf("\nX--------X--- Warning!! ---X----------X\n");
			printf("\n You have Left With %d Rs , Please avoid Useless Expenditure  !! \n",mi);
		}
	}
	else
	printf(" Please Enter atleast one Expenditure details \n");
}
void doc()
{
	FILE *fp;
	int j;
	time_t t;
	time(&t);
	char name[32];
	printf(" Enter the File name : ");
	scanf("%s",name);
	strcat(name,".csv");
	fp = fopen(name,"a+");
	fprintf(fp,"           Welcome %s \n                       %s\n",name,ctime(&t));
	fprintf(fp,"         Monthly Expenditure Amount   \n");
	fprintf(fp," Sl No , Expindeture Name , Expinditure Amount \n");
	for(j=1;j<=i;j++)  
	{
		fprintf(fp," %d , %s , %d Rs\n",j,expname[j],expamt[j]);
	}
	fprintf(fp,"----------------------------------------------------\n");
	fprintf(fp," Entered Income Amount :   %d Rs\n",temp);
	fprintf(fp," Total Bonus Amount    :   %d Rs\n",bamt);
	fprintf(fp," Total Amount Credited :   %d Rs\n",(temp+bamt));
	fprintf(fp," Total Expenditure     :   %d Rs\n",(temp+bamt-mi));
	fprintf(fp," Balance Amount        :   %d Rs\n",mi);
	fclose(fp);
}