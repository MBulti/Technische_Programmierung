// Technische Programmierung - Abschlussprojekt - Imke Korte, Moritz Bulthaup

#include <stdio.h>      // printf/scanf/...
#include <stdlib.h>     // malloc/calloc/...
#include <math.h>       // pow/sqrt/...

int datEingabe(float fWerte[]);
int datEingabeAusDatei(float fWerte[], FILE *filePointer);
float datMittelwert(float fWerte[], int iAnzahl);
float datStandard(float fWerte[], int iAnzahl, float fMittel);

int main(void)
{
    int iArrayLaenge = 0, iBenutzerEingabe = 0;
    float fMittelwert = 0, fStandardabweichung = 0;

    float *fWerte = (float*)calloc(100, sizeof(float));
    if (fWerte == NULL)
    {
        printf("Speicher kann nicht zugewiesen werden. Programm wird beendet.");
        return -1;
    }

    // Arbeiten mit Datei
    FILE *filePointer;
    filePointer = fopen("Dateien/Sensorwerte.txt", "r"); // öffnen der Datei "Sensorwerte.txt im Lesemodus"
    if (filePointer == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden. Eingabe ueber Konsole.\n");
        iArrayLaenge = datEingabe(fWerte);
    }
    else
    {
        printf("Datei erfolgreich eingelesen.\n");
        iArrayLaenge = datEingabeAusDatei(fWerte, filePointer);
    }
    fclose(filePointer); // Die Datei muss wieder freigegeben werden

    fMittelwert = datMittelwert(fWerte, iArrayLaenge);
    fStandardabweichung = datStandard(fWerte, iArrayLaenge, fMittelwert);

    printf("\nAnzahl Sensorwerte: %i", iArrayLaenge);
    printf("\nMittelwert: %.2f", fMittelwert);
    printf("\nStandardabweichung: %.2f", fStandardabweichung);

    do
    {
        printf("\n\nWollen Sie das Ergebnis speichern? 0 = Nein, 1 = Ja\n");
        scanf("%i", &iBenutzerEingabe);
    } 
    while (!(iBenutzerEingabe == 0 || iBenutzerEingabe == 1));

    if (iBenutzerEingabe == 1)
    {
        filePointer = fopen("Dateien/Ergebnis.txt", "w"); // öffnen der Datei im Schreibmodus
        if (filePointer == NULL)
        {
            printf("Datei konnte nicht geoeffnet werden. Die Ergebnisse können nicht gespeichert werden. Das Programm wird beendet.\n");
            return -1;
        }
        else
        {
            fprintf(filePointer, "Mittelwert: %0.2f\n", fMittelwert);
            fprintf(filePointer, "Standartabweichung: %0.2f", fStandardabweichung);
            printf("Datei erfolgreich geschrieben.");
        }
        fclose(filePointer);
    }
    free(fWerte);
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
//Rueckgabe: Anzahl der eingegebenen Werte
int datEingabeAusDatei(float fWerte[], FILE *filePointer)
{
    int temp = 0, arrIndex = 0;
    float tempSensor = 0;
    // formatiertes auslesen
    while((temp = fscanf(filePointer, "%f", &tempSensor)) != EOF)
    {
        if (temp == 1) // Wert ist ein Float
        {
            printf("Eingelesen %.02f\n", tempSensor);
            fWerte[arrIndex++] = tempSensor;
        }
        else
            fgetc(filePointer); // den "ungültigen" char überspringen
    }
    return arrIndex;
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
    for (int i = 0; i < iAnzahl; i++)
        fVarianzSumme += pow((fWerte[i] - fMittel), 2);

    float fVarianz = fVarianzSumme / iAnzahl;
    return sqrt(fVarianz);
}