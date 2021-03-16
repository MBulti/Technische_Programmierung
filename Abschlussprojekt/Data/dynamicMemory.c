// Abschlussprojekt - Grundlagen technische Programmierung
/*
    Dynamische Speicherverwaltung mit malloc, calloc, realloc, free
*/

#include <stdio.h>
#include <stdlib.h>

int WaitForInput();

int main(int argc, char const *argv[])
{
    int *arr = (int*)malloc(100 * sizeof(int));
    if (arr != NULL)
    {
        for (int i = 0; i < 100; i++)
            arr[i] = 0;
    }


    int *brr = (int*)calloc(100, sizeof(int));
    if (brr != NULL)
    {

    }


    *arr = realloc(arr, 500);
    if (arr != NULL)
    {

    }


    free(arr);
    free(brr);


    WaitForInput();
    return 0;
}

int WaitForInput()
{
    printf("Bla");
    int a = 0;
    scanf("%i", &a);
    return 0;
}
