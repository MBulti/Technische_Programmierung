// Technische Programmierung - A3 - Aufgabe 1a
// 25.02.2021

/*
Schreiben Sie ein C-Programm, welches die folgenden 6 Sensorwerte einer
Industrieanlage (z.B. Temperatur) auswertet, indem der Mittelwert berechnet und
ausgegeben wird. 
float fWerte[]={5.2, 4.9, -1.0, 5.4, 5.0, 4.7};
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float fGesamt = 0;
    float fWerte[]={5.2, 4.9, -1.0, 5.4, 5.0, 4.7};

    for (int i = 0; i < 6; i++)
    {
        // printf("\nAktueller Index %i", i);
        // printf("\nAktueller Wert %f", fWerte[i]);
        fGesamt += fWerte[i];
    }
    fGesamt = fGesamt / 6;
    printf("\nMittelwert %f", fGesamt);
    
    return 0;
}
