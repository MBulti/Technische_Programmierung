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
    int iArrayLaenge = 0;
    float fMittelwert = 0, fStandardabweichung = 0;
    float fWerte[100];

    iArrayLaenge = datEingabe(fWerte);
    fMittelwert = datMittelwert(fWerte, iArrayLaenge);
    fStandardabweichung = datStandard(fWerte, iArrayLaenge, fMittelwert);

    printf("\nAnzahl Sensorwerte: %i", iArrayLaenge);
    printf("\nMittelwert: %.2f", fMittelwert);
    printf("\nStandardabweichung: %.2f", fStandardabweichung);
    
    return 0;
}
//Rueckgabe: Anzahl der eingegebenen Werte
int datEingabe(float fWerte[])
{
    int iAnzahlEingebeneneWerte = 0;
    float tempSensor = 0;
    printf("** Sensorwerte auswerten **\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%.2i. Wert: ", i + 1);
        scanf("%f", &tempSensor);
        if(tempSensor <= 0)
            break;
        else
        {
            fWerte[i] = tempSensor;
            iAnzahlEingebeneneWerte++;
        }
    }
    return iAnzahlEingebeneneWerte;
}
//Rueckgabe: Mittelwert
float datMittelwert(float fWerte[], int iAnzahl)
{
    int fSumme = 0;
    for (int i = 0; i < iAnzahl; i++)
        fSumme += fWerte[i];
        
    return fSumme / iAnzahl;
}
//Rueckgabe: Standardabweichung
float datStandard(float fWerte[], int iAnzahl, float fMittel)
{
    float fVarianzSumme = 0;
    // Varianz
    for (int i = 0; i < iAnzahl; i++)
        fVarianzSumme += pow((fWerte[i] - fMittel), 2);

    float fVarianz = fVarianzSumme / iAnzahl;
    return sqrt(fVarianz);
}