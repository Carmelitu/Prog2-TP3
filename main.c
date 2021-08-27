#include <stdio.h>
#include <stdlib.h>

char nombreArchivo[] = "archi.txt";

// Proto
unsigned long long factorial (int num);
int potencia(int num, int pot);
void mostrarArreglo (int a[], int v, int i);
void mostrarArregloInvertido (int a[], int v, int i);
int capicua (int a[], int inic, int fin);
int suma (int a[], int v, int i);
int buscarMenor (int a[], int v, int i);
void cargarArchivo (int numero, char nombreArc[]);
void mostrarContenido(char nombreArc[]);
int contarRegistros (char nombreArc[]);
int buscarElemento (int a[], int v, int i, int elem);
int buscarMenorPpal(char nombreArchivo[]);
int buscarMenorAux(FILE * pBuffer);
int invertirPpal (char nombreArchivo[]);
void invertirAux (FILE * pBuffer, int i, int u);
void mostrarArchivoInvertido (char nombreArchivo[]);
void mostrarPosicionRecursiva(FILE * pBuffer, char nombreArchivo[], int pos);
void ingresarYMostrarInvertido ();

int main()
{
    /*unsigned long long fac = factorial(20);
    printf("Factorial: %llu", fac);
    int pochi = potencia(2,6);
    printf("Potencia 2^6 : %i", pochi);
*/
    /// 3
    /*
    int validos = 4;
    int arreglo[] = {2,4,6,8};
    mostrarArreglo(arreglo,validos,0);
    */

    /// 4
    /*
    int validos = 5;
    int arreglo[] = {1,2,3,4,5};
    mostrarArregloInvertido(arreglo,validos,0);
    */

    /// 5
    /*
    int arreglo[] = {1,2,3,2,1};
    int c = capicua(arreglo,0,4);
    if (c == 1){
        printf("Es capicua.");
    }
    else if (c == 0){
        printf("No es capicua.");
    }
    */

    /// 6
    /*
    int validos = 4;
    int arreglo[] = {2,4,6,8};
    int res = suma(arreglo,validos,0);
    printf("Suma: %i", res);
    */

    /// 7
    /*
    int validos = 4;
    int arreglo[] = {30,27,33,22};
    int m = buscarMenor(arreglo,validos,0);
    printf("Menor del Arreglo: %i", m);
    */

    /// 8
    /*
    int num;
    char control = 's';

    while (control == 's')
    {
        printf("\n>Ingrese un numero al archivo: ");
        scanf("%i", &num);
        cargarArchivo(num,nombreArchivo);
        printf("\n>Continuar? ");
        fflush(stdin);
        scanf("%c", &control);
    }

    int cdadReg = contarRegistros(nombreArchivo);
    printf("Hay %i registros.", cdadReg);

    int m = buscarMenorPpal(nombreArchivo);
    printf("\nEl menor del archivo es: %i", m);
    */

    /// 9
    /*int num;
    char control = 's';

    while (control == 's')
    {
        printf("\n>Ingrese un numero al archivo: ");
        scanf("%i", &num);
        cargarArchivo(num,nombreArchivo);
        printf("\n>Continuar? ");
        fflush(stdin);
        scanf("%c", &control);
    }*/

    printf("\nArchivo original:\n");
    mostrarContenido(nombreArchivo);

    /// 9
    /*
    printf("\nArchivo invertido:\n");
    invertirPpal(nombreArchivo);
    mostrarContenido(nombreArchivo);*/

    /// 10
    printf("\nArchivo invertido:\n");
    mostrarArchivoInvertido(nombreArchivo);




    /// 11
    /*
    ingresarYMostrarInvertido();
    */

    /// 12
    /*
    int validos = 4;
    int arreglo[] = {12,15,18,21};
    char control = 's';
    int num;
    int busq;

    printf("\nNumero a buscar -> ");
    scanf("%i", &num);

    busq = buscarElemento(arreglo,validos,0,num);

    if (busq == 1)
    {
        printf("Se encontro el elemento.\n");
    }
    else if (busq == 0)
    {
        printf("El elemento no esta en el arreglo.\n");
    }
    */

    return 0;
}

/* 1. Calcular el factorial de un número en forma recursiva. */

unsigned long long factorial (int num){
    // Si hemos llegado a 1, detenemos la recursión
    if (num <= 1)
    {
        return 1;
    }
    return num * factorial(num - 1); // Restar 1
}

/* 2. Calcular la potencia de un número en forma recursiva. */

int potencia(int num, int pot){

    if (pot <= 0)
    {
        return 1;
    }
    return num * potencia(num, (pot - 1)); // Restar 1
}

/* 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva*/

void mostrarArreglo (int a[], int v, int i)
{

    if (i == v)
    {
        printf("\nNo hay mas elementos por mostrar.\n");

    }
    else
    {
        printf("| %i ", a[i]);
        mostrarArreglo(a,v,i+1);
    }
}


// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).
void mostrarArregloInvertido (int a[], int v, int i)
{
    if (i < v)
    {
        mostrarArregloInvertido(a,v,i+1);
        printf("| %i ", a[i]);

    }
}


// 5. Determinar en forma recursiva si un arreglo es capicúa.
int capicua (int a[], int i, int u)
{
    int rta;

    if (i < u)
    {
        if (a[i] == a[u])
        {
            rta = capicua(a, i+1, u-1);
        }
        else
        {
            rta = 0;
        }
    }
    else
    {
        rta = 1;
    }

    return rta;
}

// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
int suma (int a[], int v, int i)
{
    int rta;

    if (i == v)
    {
        rta = 0;
    }
    else
    {
        rta = a[i] + suma(a,v,i+1);
    }

    return rta;
}

// 7. Buscar el menor elemento de un arreglo en forma recursiva.
int buscarMenor (int a[], int v, int i)
{
    int menor;
    if (i == v - 1)
    {
        menor = a[i];
    }
    else
    {
        menor = buscarMenor(a,v,i+1);

        if (menor > a[i])
        {
            menor = a[i];
        }
    }

    return menor;
}

// Cargo el archivo
void cargarArchivo (int numero, char nombreArc[])
{
    FILE * pBuffer;

    pBuffer = fopen (nombreArc, "ab");

    if (pBuffer != NULL)
    {
        fwrite (&numero, sizeof(int), 1, pBuffer);
        fclose(pBuffer);
    }
    else
    {
        printf("Error o el archivo no existe.");
    }
}

// Muestro el archivo
void mostrarContenido (char nombreArc[])
{
    FILE * pBuffer;
    int aux;

    pBuffer = fopen(nombreArc, "rb");
    if (pBuffer)
    {
        while(fread(&aux, sizeof(int), 1, pBuffer) > 0) // retorno de fread > 0 ---> encontró datos
        {
            printf("%i | ", aux);
        }
        fclose(pBuffer);
    }
}

// Cuento los registros (para tener un límite)
int contarRegistros (char nombreArc[])
{
    FILE * pBuffer;
    pBuffer = fopen(nombreArc, "rb");
    long int cantidad;

    if(pBuffer != NULL)
    {
        fseek(pBuffer, 0, SEEK_END);
        cantidad = ftell(pBuffer) / sizeof(int);
        fclose(pBuffer);
    }
    return cantidad;
}


/// NO funciona bien pero está escrita tal cual la hizo la profe xdn't
// 8. Buscar el menor elemento de un archivo de números enteros de forma recursiva.
int buscarMenorPpal(char nombreArchivo[])
{
    int menor;

    FILE * pBuffer = fopen(nombreArchivo, "rb");
    if (pBuffer)
    {
        menor = buscarMenorAux(pBuffer);
        fclose(pBuffer);
    }
    return menor;
}

int buscarMenorAux(FILE * pBuffer)
{
    int aux;
    int menor;

    if (fread(&aux, sizeof(int), 1, pBuffer) == 0)
    {
        fseek(pBuffer, sizeof(int)*-1, SEEK_END);
        fread(&menor, sizeof(int), 1, pBuffer);
    }
    else
    {
        menor = buscarMenorAux(pBuffer);
        if (menor > aux)
        {
            menor = aux;
        }
    }

    return menor;
}

// 9. Invertir los elementos de un archivo de números enteros de forma recursiva.
int invertirPpal (char nombreArchivo[])
{
    FILE * pBuffer = fopen(nombreArchivo,"r+b");
    if (pBuffer)
    {
        int u =  contarRegistros(nombreArchivo);
        invertirAux(pBuffer,0,u);
        fclose(pBuffer);
    }
}

void invertirAux (FILE * pBuffer, int i, int u)
{
    int ini = 0;
    int fin = 0;

    if (i < u)
    {
        fseek(pBuffer, sizeof(int)*(i), 0);
        fread(&ini, sizeof(int), 1, pBuffer);
        printf("\n Ini: %i", ini);

        rewind(pBuffer);

        fseek(pBuffer, sizeof(int)*(u-1), 0);
        fread(&fin, sizeof(int), 1, pBuffer);
        printf("\n Fin: %i\n", fin);

        // Reescribir
        rewind(pBuffer);

        fseek(pBuffer, sizeof(int)*i, 0);
        fwrite(&fin, sizeof(int), 1, pBuffer);

        rewind(pBuffer);

        fseek(pBuffer, sizeof(int)*(-(i+1)), 2);
        fwrite(&ini, sizeof(int), 1, pBuffer);

        rewind(pBuffer);

        invertirAux(pBuffer, i+1, u-1);
    }
}

// 10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
void mostrarArchivoInvertido (char nombreArchivo[])
{
    FILE * pBuffer;
    pBuffer = fopen(nombreArchivo, "rb");

    if (pBuffer)
    {
        int u =  contarRegistros(nombreArchivo);
        mostrarPosicionRecursiva(pBuffer, nombreArchivo, u-1);
        fclose(pBuffer);
    }
}

void mostrarPosicionRecursiva(FILE * pBuffer, char nombreArchivo[], int pos)
{
    int aux = 0;
    if (pos >= 0)
    {
        fseek(pBuffer, sizeof(int)*(pos), 0);
        fread(&aux, sizeof(int), 1, pBuffer);
        printf("%i | ", aux);

        mostrarPosicionRecursiva(pBuffer, nombreArchivo, pos-1);
    }
}


// 11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’)
// de forma recursiva. NO usar arreglos.
void ingresarYMostrarInvertido ()
{
    char valor;
    printf("La carga finaliza con *. Ingrese valor: ");
    fflush(stdin);
    scanf("%c", &valor);

    if (valor == '*')
    {
        printf("\n");
    }
    else
    {
        ingresarYMostrarInvertido();
        printf("%c |", valor);
    }

}


// 12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.
int buscarElemento (int a[], int v, int i, int elem)
{
    int flag = 0;

    if (i == v - 1)
    {
        if (elem == a[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    else
    {
        flag = buscarElemento(a,v,i+1,elem);

        if (elem == a[i])
        {
            flag = 1;
        }
    }

    return flag;
}
