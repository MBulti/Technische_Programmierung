// Abschlussprojekt - Grundlagen technische Programmierung
/*
    Arbeiten mit Dateien
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int temp = 0;

    fp = fopen("test.txt", "r");

    if(fp == NULL) 
    {
        printf("Datei konnte NICHT geoeffnet werden.\n");
    }
    else 
    {
        printf("Datei konnte geoeffnet werden.\n");
        while((temp = fgetc(fp)) != -1) 
        {
            printf("%c", temp);
        }
        fclose(fp);
    }

    return 0;
}
