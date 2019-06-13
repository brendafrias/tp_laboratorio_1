#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef input_H_INCLUDED
#define input_H_INCLUDED

#include "input.h"

#endif // Input_H_INCLUDED

// BIBLIOTECAS INPUT, POR LUCHETTINNI-DEV ( VERSION 4.0 )

void input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    printf(message);
    scanf("%d", input);

    while (*input < lowLimit || *input > hiLimit)
    {
        printf(eMessage);
        printf(message);
        scanf("%d", input);
    }
}

void input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    printf(message);
    scanf("%f", input);

    while (*input < lowLimit || *input > hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);
        scanf("%f", input);
    }
}

void input_getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    printf(message);

    scanf("%c", input);
    fflush(stdin);

    *input = tolower(*input);

    while (*input < lowLimit || *input > hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);

        scanf("%c", input);
        fflush(stdin);
        *input = tolower(*input);
    }
}

void input_getCharGenero(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    fflush(stdin);
    printf(message);
    scanf("%c", input);
    fflush(stdin);

    *input = tolower(*input);

    while (*input != lowLimit && *input != hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);

        scanf("%c", input);
        fflush(stdin);
        *input = tolower(*input);
    }
}

void input_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    fflush(stdin);
    printf(message);

    gets(input);
    input = strlwr(input);

    while (strlen(input) < lowLimit || strlen(input) > hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);
        gets(input);
        input = strlwr(input);
    }
}

void input_getAnswer (char* respuesta, char mensaje[])
{
    printf(mensaje);
    *respuesta = getche();
    *respuesta = tolower(*respuesta);

    while(*respuesta != 's' && *respuesta != 'n')
    {
        printf("\n\nEsa respuesta es invalida intente nuevamente...\n\n");
        printf(mensaje);
        *respuesta = getche();
        *respuesta = tolower(*respuesta);
    }
}

void input_getName(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    fflush(stdin);
    printf(message);

    scanf("%s", input);
    input = strlwr(input);
    input[0] = toupper(input[0]);

    while (strlen(input) < lowLimit || strlen(input) > hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);

        scanf("%s", input);
        input = strlwr(input);
        input[0] = toupper(input[0]);
    }
}
