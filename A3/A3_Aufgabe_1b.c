// Technische Programmierung - A3 - Aufgabe 1b
// 25.02.2021

/*
Erweitern Sie Ihr Programm, sodass die Sensorwerte über die Konsole eingelesen
und auch die Varianz (mittlere quadratische Abweichung) berechnet und ausgegeben
wird. 
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    int iArrayLaenge = 6;
    float fMittelwert = 0;
    float fVarianz = 0;
    //float fWerte[]={5.2, 4.9, -1.0, 5.4, 5.0, 4.7};
    float fWerte[iArrayLaenge];

    // Einlesen
    for (i = 0; i < iArrayLaenge; i++)
    {
        printf("%i Messwert: ", i + 1);
        scanf("%f", &fWerte[i]);
    }
    
    // Mittelwert
    for (i = 0; i < iArrayLaenge; i++)
    {
        fMittelwert += fWerte[i];
    }
    fMittelwert = fMittelwert / iArrayLaenge;

    // Varianz
    for (i = 0; i < iArrayLaenge; i++)
    {
        fVarianz += pow((fWerte[i] - fMittelwert), 2);
    }
    fVarianz = fVarianz / iArrayLaenge;


    printf("\nMittelwert %f", fMittelwert);
    printf("\nVarianz %f", fVarianz);
    
    return 0;
}
