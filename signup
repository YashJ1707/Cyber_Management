#include<stdio.h>
 struct customer{
   char name[20];
   char password[20];
   long int adharno;

};

void login_data(struct customer *ptr);
  void signup_data(struct customer *ptr);


int main()
{
int login;
struct customer customer_data[3];

struct customer *ptr = NULL;
ptr=customer_data;


printf("WELCOME TO CYBER CAFE\n");
menu:
printf("ARE YOU NEW CUSTOMER? (PRESS 1:YES & 0:NO):  ");
scanf("%d",&login);
printf("\n");

switch(login)
{
  case 0:
signup_data(customer_data);
break;
  case 1:
         login_data(customer_data);
         break;
default:
printf("\nINVALID INPUT\n");
goto menu;

}
}
void login_data(struct customer *ptr)
{
printf("Enter YOUR NAME: ");
scanf("%s",ptr->name);
printf("Enter PASSWORD: ");
scanf("%s",ptr->password);
printf("ENTER YOUR ADHAR NO: ");
scanf("%ld",&ptr->adharno);
printf("!!!!WELCOME!!!!");
}


void signup_data(struct customer *ptr)
{
 printf("Enter YOUR NAME: ");
scanf("%s",ptr->name);
printf("Enter PASSWORD: ");
scanf("%s",ptr->password);

printf("Welcome Back!!!!!\n");
}
