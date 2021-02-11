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

#define USMILE 1.6093
#define USGALLON 3.785

int main(void)
{
    float lastOdoMeter = 0, currentOdoMeter = 0, tankFillValue = 0;
    printf("Tachostand letzter Tankstop:\n");
    scanf("%f", &lastOdoMeter);

    printf("Tachostand aktueller Tankstop:\n");
    scanf("%f", &currentOdoMeter);

    printf("Wieviel Liter wurden getankt?\n");
    scanf("%f", &tankFillValue);

    float distance = currentOdoMeter - lastOdoMeter;
    float usage = tankFillValue / (distance / 100);
    printf("\nAktueller Verbrauch ist %f L/100km", usage);
    return 0;
}
