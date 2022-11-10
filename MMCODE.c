#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
char user[50]="bitm",pass[20]="123",expname[20][20],ename1[20];
long mi;
int expamt[50],e=0,i=0;
void login();
void input();
void main()
{
	login();
	input();
}
void login()
{
	char uname[50],password[50];
	int iu=0;
    en: printf(" Enter the UserName : ");
		scanf("%s",uname);
		printf(" Enter the Password : ");
		scanf("%s",password);
	if(((strcmp(user,uname)!=0) && iu<3) || ((strcmp(pass,password)!=0) && iu<3))
	{ 	
		if(iu==2 )
	{
		printf("Sorry ! Too many Unsuccessful Attempts :(  ");
		iu=1;
		exit(0);
	}
		printf("Invalid Username or Password Please Re-enter \n ");
		iu++;
		goto en;
	}
	  system("cls");
    printf("\n_______Welcome To Money Management System  :) ________________\n");
	iu=0;
}
void input()
{
	int ch,j;
	long amt;
	printf(" Enter the monthly income ");
	scanf("%ld",&mi);
	strcpy(expname[++i]," BILLS ");
	strcpy(expname[++i]," MEDICINES ");
	strcpy(expname[++i]," SHOPPINGS ");
	strcpy(expname[++i]," FOOD ");
	printf("\n***************************************************************** \n");
	printf(" 1. BillS   \n");
	printf(" 2. Medicines \n");
	printf(" 3. Shoppings \n");
	printf(" 4. Food \n");
	if(i>=4)
	{
		for( j=5;j<=i;j++)
		printf(" %d. %s\n",j,expname[j]);
	}
	printf(" 15. Other Expenditures \n");
	printf(" Choose Your Option : ");
	scanf("%d",&ch);
	if(ch==15)
	{
		printf(" Enter the Name of Expenditure : ");
		scanf("%s",expname[++i]);
		printf(" Enter the amount that is spent : ");
		scanf("%ld",&amt);
		expamt[i] = expamt[i] + amt ;
		mi = mi-amt;
	}
	else if (ch>0 && ch<15)
	{
		printf(" Enter the amount that is spent in %s : ",expname[ch]);
		scanf("%ld",&amt);
		expamt[ch]=expamt[ch]+amt;
		mi = mi-amt;
	}
	else printf(" Invalid input !! ");	
}
