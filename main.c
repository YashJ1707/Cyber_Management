#include <stdio.h>
#include <time.h>
#include <string.h>
struct customer
{
    char name[20];
    char password[20];
    char adharno[15];
};
void login_data(struct customer *ptr);
void signup_data(struct customer *ptr);
int search_password(struct customer *ptr, char pass[]);
int search_username(struct customer *ptr, char user[]);
int customers;
struct customer *starting;
void setTimeout(int milliseconds)
{
    if (milliseconds <= 0)
    {
        fprintf(stderr, "COUNT MILLISECONDS FOR TIMEOUT IS LESS OR EQUAL TO 0\n");
        return;
    }
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    int end = milliseconds_since + milliseconds;
    do
    {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}
int time_remainging()
{
    int time, flag, cost;
recharge:
    printf("\t\t\t\t*CHOOSE A PLAN FROM THE FOLLOWING:\n");
    printf("\n\t\t\t\t\t*COST FOR 1HOUR IS RS.10\n");
    printf("\n\t\t\t*ENTER THE NUMBER OF HOURS YOU WANT TO TOP-UP: ");
    scanf("%d", &time);
    printf("\n\t\t\t*DO YOU WANT INTERNET FACILITY (Rs.5/hour)\n\t\t\t\t\t\t1.YES\t0.NO: ");
    scanf("%d", &flag);
    if (flag == 1)
    {
        cost = time * 15;
    }
    printf("\n\t\t\t\t\t\t*YOUR TOTAL BILL :%d\n\t\t\t\t\t*DO YOU WANT TO CONTINUE:\n\t\t\t\t\t\t1.YES\t0.GO BACK :", cost);
    scanf("%d", &flag);
    printf("\t\t\t\t\t========================================\n");
    printf("\n");
    if (flag == 0)
        goto recharge;
    return time;
}
struct customer customer_data[10];
int main()
{
    int login, flag, time;

    struct customer *ptr = NULL;
    ptr = customer_data;
    starting = ptr;
    printf("\t\t\t\t\t========================================\n");
    printf("\t\t\t\t\t\t*WELCOME TO CYBER CAFE*\n");
    printf("\t\t\t\t\t========================================\n\n");
menu:
    printf("\t\t\t\t\t\t1.NEW CUSTOMER LOGIN.\n\t\t\t\t\t\t2.EXISTING CUSTOMER LOGIN.\n\n\t\t\t\t\t\t*ENTER YOUR CHOICE :  ");

    scanf("%d", &login);
    printf("\n\t\t\t\t\t========================================");
    printf("\n");
    switch (login)
    {
    case 1:
        signup_data(customer_data);
        break;
    case 2:
        login_data(customer_data);
        break;
    default:
        printf("\nINVALID INPUT\n");
        goto menu;
    }
again:
    time = time_remainging();
    time *= 60;
    do
    {
        printf("\t\t\t\t\t\t\033[A%d minutes remainging\n", time);
        setTimeout(60000);
        time--;
    } while (time >= 0);
    printf("\t\t\t\t\t========================================\n");
    printf("YOUR TIME IS UP,Do YOU WANT TO TOP-UP MORE TIME ?\n1.YES\tENTER ANY NO. FOR QUIT : ");
    scanf("%d", &flag);
    printf("\t\t\t\t\t========================================\n");
    if (flag == 1)
    {
        goto again;
    }
    printf("YOU HAVE BEEN LOGGED OUT!\n THANKYOU FOR COMING\n");
    goto menu;
    return 0;
}
void login_data(struct customer *ptr)
{
    {
        printf("\n\t\t\t\t\t========================================\n");
        printf("\t\t\t\t\t\t*LOGIN IN YOUR ACCOUNT : \n");
        printf("\t\t\t\t\t========================================\n");
        printf("IF YOU DON'T HAVE ACCOUNT CREATE ONE BY PRESSING 1 IN USERNAME SECTION :  \n");
        char pass[20];
        char username[20];
    pass:
        printf("\n\t\t\t\t\t\t*Enter YOUR USERNAME: ");
        scanf("%s", username);
        if (username[0] == '1')
        {
            signup_data(customer_data);
        }
        //printf("\t\t\t\t\t\t\t\t\t****\n");
        printf("\t\t\t\t\t\t*ENTER YOUR PASSWORD: ");
        scanf("%s", pass);
        //printf("\t\t\t\t\t\t\t\t\t****\n");
        if ((search_password(customer_data, pass) && search_username(customer_data, username)) != 1)
        {
            printf("\n\t\t\t\t\t*USERNAME OR PASSWORD ERROR!!!\n");
            printf("ENTER PASSWORD AGAIN : OR CREATE A NEW ACCOUNT : \n");
            // printf("\t\t\t****\n");
            goto pass;
        }
        else
        {
            goto aadhar;
        }
    }

aadhar:
    //printf("\n\t\t\t\t\t\t\t\t\t****\n");
    printf("\t\t\t\t*ENTER YOUR ADHAR NO WITHOUT SPACES : ");
    scanf("%s", ptr->adharno);
    if (strlen(ptr->adharno) != 12)
    {
        printf("\n\t\t*ENTER CORRECT AADHAR NUMBER : \n");
        goto aadhar;
    }
    printf("\n\t\t\t\t\t========================================");
    printf("\n\t\t\t\t\t\t!YOUR LOGGED IN!\n");
    printf("\t\t\t\t\t\t****!!!!WELCOME!!!!****\n");
    printf("\t\t\t\t\t========================================\n");
}

void signup_data(struct customer *ptr)
{
    ptr = starting;
    ptr = ptr + customers;
    char pass[20];
    printf("\t\t\t\t\t\t*CREATE YOUR ACCOUNT :- \n");
    printf("\t\t\t\t\t========================================\n");
    printf("\n\t\t\t\t\t\t*ENTER YOUR USERNAME: ");
    scanf("%s", ptr->name);
    //printf("\t\t\t\t\t\t\t\t\t****\n");
pass:
    printf("\t\t\t\t\t\t*CREATE A PASSWORD  : ");
    scanf("%s", ptr->password);
    printf("\t\t\t\t\t\t*CONFIRM PASSWORD   : ");
    scanf("%s", pass);
    // printf("\t\t\t\t\t\t\t\t****\n");
    if (strcmp(pass, ptr->password) != 0)
    {
        printf("\t\t\t\tPASSWORD DO NOT MATCH !!\n \t\t\t\t!!PLEASE TRY AGAIN!!\n");
        goto pass;
    }
    //
    printf("\n\t\t\t\t\t\t****PASSWORD CONFIRMED****\n");
    // printf("\t\t\t\t\t========================================\n");
    printf("\n\t\t\t\t\t*YOUR ACCOUNT IS CREATED !!! PLEASE LOGIN : \n\n");
    login_data(customer_data);
    customers++;
}
int search_username(struct customer *ptr, char user[])
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(ptr->name, user) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int search_password(struct customer *ptr, char pass[])
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(ptr->password, pass) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
