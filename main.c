#include <stdio.h>
#include <conio.h>
Void border();
Void main()
{ clrscr;
border();
    printf("This is where we will enter our code");
getch;
} 
void border()
{
int n;
 

 gotoxy(1,1);
 for(n=1;n<=33;n++)
 {
 printf("%c",177);
 }
 printf(" CYBER CAFE ");
 for(n=45;n<78;n++)
 {
 printf("%c",177);
 }
 gotoxy(70,1);
 for(n=1;n<=23;n++)
 {      printf("%c",177);
 printf("\n");

 }
  for(n=1;n<=78;n++)
  {
   printf("%c",177);
  }
    gotoxy(78,1);
   for(n=1;n<24;n++)
 { gotoxy(78,n);
  printf("%c",177);
 printf("\n");
 }
 


}
