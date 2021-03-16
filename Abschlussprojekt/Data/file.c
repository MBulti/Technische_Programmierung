// Abschlussprojekt - Grundlagen technische Programmierung
/*
    Arbeiten mit Dateien
*/

#include <stdio.h>

int readFile();
int writeFile();

int main(int argc, char const *argv[])
{
    int benutzerEingabe = 0;
    do
    {
        printf("Lesen = 1, Schreiben = 2.\n");
        scanf("%i", &benutzerEingabe);
    } 
    while (!(benutzerEingabe == 1 || benutzerEingabe == 2));
  
    benutzerEingabe == 1 ? readFile() : writeFile();
    return 0;
}
int readFile()
{
    FILE *fp;
    int temp = 0;
    fp = fopen("test.txt", "r");
    fp = fopen("test.txt", "w");
    
    if(fp == NULL) 
    {
        printf("Keine Datei geoeffnet.\n");
    }
    else 
    {
        printf("Datei wurde geoeffnet.\n");
        while((temp = fgetc(fp)) != EOF) 
        {
            printf("%c", temp);
        }
        fclose(fp);
    }
}
int writeFile()
{
    FILE *fp;
    int temp = 0;   
    fp = fopen("test.txt", "w");

    if(fp == NULL) 
    {
        printf("Keine Datei geoeffnet.\n");
    }
    else 
    {
        printf("Datei wurde geoeffnet.\n");
        for (int i = 0; i < 20; i++)
        {
            fputc('A', fp);
        }
        fclose(fp);
    }
}
