// Technische Programmierung - A2 - Aufgabe 4
// 18.02.2021

/* Aufgabe:
    Es ist ein C-Programm zu erstellen, mit dem ein variabler Ausschnitt aus der
    ASCII-Tabelle im Terminal ausgegeben wird. Die ASCII-Tabelle besteht aus
    druckbaren Zeichen (32 <= Code < 127) und nicht druckbaren Steuerzeichen. Anstelle
    der nicht druckbaren Steuerzeichen soll in der Ausgabe jeweils ein "." erscheinen.
    Beispiel zur Ausgabe:
    ** ASCII-Tabelle **
    Bereich eingeben (START ENDE): 64 80
    Dez Hex Zeichen
    064 0x40 @
    065 0x41 A
    066 0x42 B
    067 0x43 C
    068 0x44 D
    069 0x45 E
    070 0x46 F
    071 0x47 G
    072 0x48 H
    073 0x49 I
    074 0x4a J
    075 0x4b K
    076 0x4c L
    077 0x4d M
    078 0x4e N
    079 0x4f O
    080 0x50 P
    
    Mittels scanf(" %i %i"...); können Sie den Wertebereich abfragen und mit printf("
    ... %c", Code); das jeweilige Zeichen selbst ausgeben.
*/