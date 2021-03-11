// Technische Programmierung - A2 - Aufgabe 3b
// 11.02.2021

/* Aufgabe:
    - Die Ausgabe der berechneten Werte soll mit zwei Nachkommastellen erfolgen.
    - Vor der Verbrauchsberechnung soll abgefragt werden, ob die Eingabe in
    europäischen (km, l) oder US-amerikanischen Maßeinheiten (miles, gallon) erfolgt.
    - Berechnen Sie die zurückgelegte Distanz und den Verbrauch für die EU (l/km) und
    den US-Markt (miles/gallon).
    - Verwenden Sie für die Umrechnung in das angloamerikanische Maßsystem folgende
    symbolische Konstanten:
*/

#include <stdio.h>

#define USMILE 1.6093 // 1 mile = 1.6093 Km
#define USGALLON 3.785 // 1 gallon = 3.785 Liter

int main(void)
{
    float lastOdoMeter = 0, currentOdoMeter = 0, tankFillValue = 0;
    int unitOfMeasurement = 0;
    while (!(unitOfMeasurement == 1 || unitOfMeasurement == 2))
    {
        printf("Standort: 1. EU, 2. US\n");
        scanf("%i", &unitOfMeasurement);
    }

    printf("Tachostand letzter Tankstop (km oder miles): ");
    scanf("%f", &lastOdoMeter);

    printf("Tachostand aktueller Tankstop (km oder miles): ");
    scanf("%f", &currentOdoMeter);

    printf("Menge getanktes Benzin (l oder gal): ");
    scanf("%f", &tankFillValue);

    float distance = currentOdoMeter - lastOdoMeter;
    float secondDistance = 0, usage = 0, secondUsage = 0;

    if(unitOfMeasurement == 1) // EU werte, dann "zweite" sind US
    {
        usage = tankFillValue / distance * 100;                             // Liter / KM * 100
        secondDistance = distance / USMILE;                                 // KM / 1.6 = MILE
        secondUsage = secondDistance / (tankFillValue / USGALLON);          // MILE / GALLON

        printf("\nZurueckgelegte Distanz in KM: %.2f", distance);
        printf("\nZurueckgelegte Distanz in Meilen: %.2f", secondDistance);

        printf("\nAktueller Verbrauch in L/100 KM: %.2f", usage);
        printf("\nAktueller Verbrauch in MPG: %.2f", secondUsage);
    }
    else if(unitOfMeasurement == 2) // US werte, dann "zweite" sind EU
    {
        usage = distance / tankFillValue;                                   // MILES / GALLON
        secondDistance = distance * USMILE;                                 // MILE * 1.06 = KM
        secondUsage = (tankFillValue * USGALLON) / secondDistance * 100;    // (Gallon * 3.7) / KM * 100)

        printf("\nZurueckgelegte Distanz in KM: %.2f", secondDistance);
        printf("\nZurueckgelegte Distanz in Meilen: %.2f", distance);

        printf("\nAktueller Verbrauch in L/100 KM: %.2f", secondUsage);
        printf("\nAktueller Verbrauch in MPG: %.2f", usage);
    }
    return 0;
}
