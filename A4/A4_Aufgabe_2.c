// Technische Programmierung - A4 - Aufgabe 2
// 11.03.2021

/*
    // Technische Programmierung - A4 - Aufgabe 1
// 11.03.2021

/*
    Nachdem das Einbinden der Bibliothek funktioniert, erweitern Sie Ihr Programm, 
    sodass 
    + die Flags bitweise ausgegeben werden (nur die Flags bis einschließlich 
    Overflow-Flag inkl. deren Bedeutung), siehe Skript.
    + die Funktionsparameter als Variablen übergeben werden.
    + die Variablen und das Ergebnis bei der Ausgabe zunächst als SIGNED und 
    dann als UNSIGNED gecastet werden.
    Beispiel der Bildschirmausgabe:
    Flags:
    O D I T S Z A P C 
    0 0 1 0 1 0 0 0 0 1 1 0 
    Ergebnis und Operanden SIGNED:
    -32767 + 2 = -32765 
    Ergebnis und Operanden UNSIGNED:
    32769 + 2 = 32771

*/

#include <stdio.h>
#include "addsub.h"

int main(int argc, char const *argv[])
{
    int ergebnis;
    unsigned int flags = 0;

    printf("Hello\n");

    ergebnis = addsub16(1, 2, '+', &flags);

    printf("Ergebnis: %i | Flags: 0x%04x | CF = %i\n", ergebnis, flags, flags & 1);

    printf("Flags:\nO D I T S Z _ A _ P _ _ C\n");
    printf("%i %i %i %i %i %i %i %i %i %i %i %i %i", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, flags & 1);




    //   unsigned char mask;
    //   char string[] = "TEST";
    //   char *temp;
    
    //   temp = string;  
    //   while(*temp){
    //        mask = 0x80;
    //        while(mask){
    //       mask >>= 1;
    //       if(*temp & mask)
    //         printf("1");
    //       else
    //         printf("0");  
    //     }
    //     temp++;
    //   }

    return 0;
}
