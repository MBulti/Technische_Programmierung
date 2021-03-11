// Technische Programmierung - A2 - Aufgabe 3a
// 11.02.2021

/* Aufgabe:
    Schreiben Sie ein neues Programm, das den Benzinverbrauch eines Autos in Litern
    je 100 gefahrene Kilometer errechnet. Um die gefahrene Distanz zu berechnen,
    benötigt das Programm als Eingabe den Tachostand vom aktuellen und vom letzten
    Tankstop. Nach Eingabe der getankten Menge Benzin soll der Verbrauch errechnet und
    auf der Konsole ausgegeben werden.
*/

#include <stdio.h>

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
    float usage = tankFillValue / distance * 100;
    printf("\nAktueller Verbrauch ist %f L/100km", usage);
    return 0;
}
