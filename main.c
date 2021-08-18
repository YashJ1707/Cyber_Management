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
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
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
    printf("Choose a plan from the following\n");
    printf("Cost for one hour is Rs.10\n");
    printf("Enter the number of hours you want to top-up\n");
    scanf("%d", &time);
    printf("Do you want to use internet facility? (Rs.5/hour)\n1.Yes\t0.No\n");
    scanf("%d", &flag);
    if (flag == 1)
    {
        cost = time * 15;
    }
    printf("Your total bill amount is %d\nDo you want to continue\n1.Yes\t0.Go back\n", cost);
    scanf("%d", &flag);
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
    printf("WELCOME TO CYBER CAFE\n");
menu:
    printf("1.NEW CUSTOMER LOGIN\n\n2.EXISTING CUSTOMER LOGIN\n");
    scanf("%d", &login);
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
    printf("You are logged in\n");
again:
    time = time_remainging();
    time *= 60;
    do
    {
        printf("\033[A%d minutes remainging\n", time);
        setTimeout(60000);
        time--;
    } while (time >= 0);
    printf("Your time is up, do you want to top-up more time?\n1.YES\tEnter any number to quit");
    scanf("%d", &flag);
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
        printf("If you dont have account create one by pressing 1 in user name section\n");
        char pass[20];
        char username[20];
    pass:
        printf("Enter YOUR USERNAME: ");
        scanf("%s", username);
        if (username[0] == '1')
        {
            signup_data(customer_data);
        }
        printf("Enter YOUR PASSWORD: ");
        scanf("%s", pass);
        if ((search_password(customer_data, pass) && search_username(customer_data, username)) != 1)
        {
            printf("Username or password error!!!\n");
            printf("Enter password again or create a new account\n");
        }
        else
        {
            goto aadhar;
        }
    }

aadhar:
    printf("ENTER YOUR ADHAR NO WITHOUT SPACES: ");
    scanf("%s", ptr->adharno);
    if (strlen(ptr->adharno) != 12)
    {
        printf("ENTER CORRECT AADHAR NUMBER\n");
        goto aadhar;
    }
    printf("!!!!WELCOME!!!!\n");
}

void signup_data(struct customer *ptr)
{
    ptr = starting;
    ptr = ptr + customers;
    char pass[20];
    printf("CREATE YOU ACCOUNT\n\n");
    printf("ENTER YOUR USERNAME: ");
    scanf("%s", ptr->name);
pass:
    printf("CREATE A PASSWORD: ");
    scanf("%s", ptr->password);
    printf("CONFIRM PASSWORD: ");
    scanf("%s", pass);
    printf("%s\n", pass);
    printf("%s", ptr->password);
    if (strcmp(pass, ptr->password) != 0)
    {
        printf("passwords do not match\nPlease try again\n");
        goto pass;
    }

    printf("\nYour account is created please login to continue\n");
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
