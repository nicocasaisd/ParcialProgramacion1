#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

int ordenarPorTipo(eVacuna vec[], int tam);

int reemplazarCaracteres(char cad[], char caracter1, char caracter2);

float aplicarAumento(float precio);

int main()
{
    printf("\n*** Ejercicio 1 ***\n");
    float precio1 = 10;
    float precioAumento;

    precioAumento = aplicarAumento(precio1);

    printf("Precio con aumento: %.2f\n\n", precioAumento);

    printf("\n*** Ejercicio 2 ***\n");

    char cadena[11] = "Mequetrefe";
    int cantidad;

    cantidad = reemplazarCaracteres(cadena, 'e', 'i');

    printf("Cadena: %s \n", cadena);
    printf("Cantidad: %d\n", cantidad);

    printf("\n*** Ejercicio 3 ***\n");
    eVacuna vacunas[4] = {
        {1, "Pfizer", 'a', 90},
        {2, "Sputnik", 'c', 93},
        {3, "AstraZeneca", 'c', 80},
        {4, "Moderna", 'a', 85}
    };

    ordenarPorTipo(vacunas, 4);

    for(int i=0; i<4; i++)
    {
        printf("Nombre: %s\t Efectividad: %.2f\n", vacunas[i].nombre, vacunas[i].efectividad);
    }


    return 0;
}

//1. Crear una función llamada aplicarAumento que reciba como parámetro el precio
// de un producto y devuelva el valor del producto con un aumento del 5%.
// Realizar la llamada desde el main.
float aplicarAumento(float precio)
{
    precio = precio * 1.05;

    return precio;
}

//2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de
//caracteres como primer parámetro, un carácter como segundo y otro carácter
//como tercero,  la misma deberá reemplazar cada ocurrencia del segundo parámetro
//por el tercero y devolver la cantidad de veces que se reemplazo ese carácter
//en la cadena
int reemplazarCaracteres(char cad[], char caracter1, char caracter2)
{
    int cantSwap = 0;
    int largoCadena;

    if(cad != NULL)
    {
        largoCadena = strlen(cad);

        for(int i=0; i < largoCadena; i++)
        {
            if(cad[i] == caracter1)
            {
                cad[i] = caracter2;
                cantSwap ++;
            }
        }
    }
    else
    {
        printf("La cadena apunta a una direccion nula!");
    }

    return cantSwap;
}

//3. Dada la siguiente estructura generar una función que permita ordenar un array
//de dicha estructura por tipo. Ante igualdad de tipo deberá ordenarse por
//efectividad creciente. Hardcodear datos y mostrarlos desde el main.
int ordenarPorTipo(eVacuna vec[], int tam)
{
    int todoOk = 0;
    eVacuna aux;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((vec[i].tipo == vec[j].tipo && vec[i].efectividad > vec[j].efectividad)
                || vec[i].tipo > vec[j].tipo)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
