// Technische Programmierung - A4 - Aufgabe 1
// 11.03.2021

/*
    Die Funktion zur Ausgabe der Flags mit dem Namen addsub16() ist in der Bibliothek 
    addsub16.o enthalten und als Prototyp in der Header-Datei addsub.h deklariert:
    int addsub16(int op1, int op2, char what, unsigned int *flags)
    Erstellen Sie nun in CodeBlocks ein neues C-Projekt für die Konsole und fügen Sie 
    die Biblithek addsub16.o hinzu, sodass der Linker sie bei der Erstellung des 
    Programms finden und einbinden kann. Als Test kann folgender Funktionsaufruf 
    dienen:
    int ergebnis; unsigned int flags=0;
    ergebnis = addsub16(1, 2, ’+’, &flags);
    Testen Sie die Ausgabe der Funktion mit unterschiedlichen Eingabewerten und geben 
    Sie sowohl das Rechenergebnis als auch die Flags in geeigneter Weise mittels 
    printf() aus.

*/
#include <stdio.h>
#include "addsub.h"

int main(int argc, char const *argv[])
{
    int ergebnis;
    unsigned int flags = 0;
    printf("Hello world\n");

    ergebnis = addsub16(1, 2, '+', &flags);

    printf("Ergebnis: %i | Flags: 0x%04x | CF = %i\n", ergebnis, flags, flags & 1);

    return 0;
}
