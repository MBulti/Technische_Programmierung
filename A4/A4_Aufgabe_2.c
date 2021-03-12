// Technische Programmierung - A4 - Aufgabe 2
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
    O D I T S Z   A   P   C 
    0 0 1 0 1 0 0 0 0 1 1 0 
    Ergebnis und Operanden SIGNED:
    -32767 + 2 = -32765 
    Ergebnis und Operanden UNSIGNED:
    32769 + 2 = 32771

*/

#include <stdio.h>
#include <stdlib.h>
#include "addsub.h"

int main(int argc, char const *argv[])
{
    int ergebnis;
    unsigned int flags = 0;

    int first = 1;
    int second = 2;
    char operator = '-';

    if(argc >= 4)
    {
        first = atoi(argv[1]);
        second = atoi(argv[3]);
        operator = *argv[2];
    }

    ergebnis = addsub16(first, second, operator, &flags);

    printf("Ergebnis: %i | Flags: 0x%04x | CF = %i\n", ergebnis, flags, flags & 1);

    printf("Flags:\nO D I T S Z _ A _ P _ C\n");
    printf("%i %i %i %i %i %i %i %i %i %i %i %i", 
        flags & 0b100000000000 ? 1 : 0, flags & 0b010000000000 ? 1 : 0, flags & 0b001000000000 ? 1 : 0, 
        flags & 0b000100000000 ? 1 : 0, flags & 0b10000000 ? 1 : 0, flags & 0b01000000 ? 1 : 0, flags & 0b00100000 ? 1 : 0, 
        flags & 0b00010000 ? 1 : 0, flags & 0b00001000 ? 1 : 0,  flags & 0b00000100 ? 1 : 0, flags & 0b00000010 ? 1 : 0, 
        flags & 1);


    printf("\n");
    unsigned int mask = 0b100000000000; //starter mask
    while(mask)
    {
        if(flags & mask)
            printf("1 ");
        else
            printf("0 "); 
        mask >>= 1;
    }


    // flags & 2 ? 1 : 0
    // if(flags & 2)
    //      return 1;
    // else 
    //      return 0;

    return 0;
}
