// Technische Programmierung - A2 - Aufgabe 2
// 11.02.2021

#include <stdio.h>

int main(void)
{
    int a = 0, b = 0;

    printf("Hallo Lingen! \n");
    printf("Eingabe Zahl a: ");
    scanf("%i", &a);

    printf("Eingabe Zahl b: ");
    scanf("%i", &b);

    printf("\t %i + %i = %i\n",a,b,a+b);
    printf("\t %i / %i = %i\n",a,b,a/b);
    printf("\t %i %% %i = %i\n",a,b,a%b);
    printf("\t %x * 5 - %x = %x\n",b,a,b*5-a);


    return(0);
}
