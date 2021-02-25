// Technische Programmierung - A3 - Aufgabe 2
// 25.02.2021

/*
+ Die Anzahl der Sensorwerte soll variabel sein, jedoch max. 100 betragen. Ist ein
Sensorwert <= 0, so ist die Eingabe beendet. Hinweis: Eine Schleife können Sie
vorzeitig mit break; verlassen.
+ Geben Sie als Ergebnis anstatt der Varianz die Standardabweichung aus. Verwenden
Sie hierzu die Funktion sqrt() der C Standard-Bibliothek, deklariert in math.h.
+ Verwenden Sie für die Eingabe und Auswertung der Daten einzelne Funktionen mit
folgenden Prototypen:

//Rueckgabe: Anzahl der eingegebenen Werte
int datEingabe(float fWerte[]);
//Rueckgabe: Mittelwert
float datMittelwert(float fWerte[], int iAnzahl);
//Rueckgabe: Standardabweichung
float datStandard(float fWerte[], int iAnzahl, float fMittel);
Beispiel zur Ausgabe:
** Sensorwerte auswerten **
 01. Wert: 2
 02. Wert: 4
 03. Wert: 15
 04. Wert: 3
 05. Wert: 5
 06. Wert: 0
Sensorwerte: Anzahl = 5 Mittelwert = 5.80 Standardabw. = 4.71
*/

#include <stdio.h>
#include <math.h>

int datEingabe(float fWerte[]);
float datMittelwert(float fWerte[], int iAnzahl);
float datStandard(float fWerte[], int iAnzahl, float fMittel);

int main(void)
{
    int i;
    int iArrayLaenge = 6;
    float fMittelwert = 0;
    float fVarianz = 0;
    //float fWerte[]={5.2, 4.9, -1.0, 5.4, 5.0, 4.7};
    float fWerte[iArrayLaenge];


    iArrayLaenge = datEingabe(fWerte);
    fMittelwert = datMittelwert(fWerte, iArrayLaenge);
    fVarianz = datStandard(fWerte, iArrayLaenge, fMittelwert);

    printf("\nMittelwert %f", fMittelwert);
    printf("\nVarianz %f", fVarianz);
    
    return 0;
}
//Rueckgabe: Anzahl der eingegebenen Werte
int datEingabe(float fWerte[])
{
    int i;
    // Einlesen
    for (i = 0; i < 6; i++)
    {
        printf("%i Messwert: ", i + 1);
        scanf("%f", &fWerte[i]);
    }
}
//Rueckgabe: Mittelwert
float datMittelwert(float fWerte[], int iAnzahl)
{
    int i;
    int fSumme = 0;
    // Mittelwert
    for (i = 0; i < iAnzahl; i++)
        fSumme += fWerte[i];
        
    return fSumme / iAnzahl;
}
//Rueckgabe: Standardabweichung
float datStandard(float fWerte[], int iAnzahl, float fMittel)
{
    int i;
    int fVarianz = 0;
    // Varianz
    for (i = 0; i < iAnzahl; i++)
        fVarianz += pow((fWerte[i] - fMittel), 2);

    return fVarianz / iAnzahl;
}