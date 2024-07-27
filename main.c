#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ESTUDIANTES 100  // Ajusta este valor según el número máximo esperado de estudiantes por grado

// Prototipos de funciones
void ingresarPromedios(int[], int, const char*);
void ingresarEdades(int[], int, const char*);
void mostrarEdadesMayores(int[], int, const char*);
void mostrarEdadesMenores(int[], int, const char*);
void mostrarPromedioMayor(int[], int, const char*);
void mostrarMejoresPromedios(int[], int, const char*);
void mostrarEdadRepetida(int[], int, const char*);
float calcularPromedioGeneral(int[], int, const char*);
void mostrarGradoMejorRendimiento(float[], int);

int main() {
    int opcion;
    int n, m, k, x;
    int promedios1[MAX_ESTUDIANTES], promedios2[MAX_ESTUDIANTES];
    int promedios3[MAX_ESTUDIANTES], promedios4[MAX_ESTUDIANTES];
    int edades1[MAX_ESTUDIANTES], edades2[MAX_ESTUDIANTES];
    int edades3[MAX_ESTUDIANTES], edades4[MAX_ESTUDIANTES];
    float promediosGenerales[4];

    // Solicitar la cantidad de estudiantes por grado
    printf("Ingrese la cantidad de estudiantes de primer grado: ");
    scanf("%d", &n);
    printf("Ingrese la cantidad de estudiantes de segundo grado: ");
    scanf("%d", &m);
    printf("Ingrese la cantidad de estudiantes de tercer grado: ");
    scanf("%d", &k);
    printf("Ingrese la cantidad de estudiantes de cuarto grado: ");
    scanf("%d", &x);

    // Inicialización de promedios y edades a cero
    for(int i = 0; i < MAX_ESTUDIANTES; i++) {
        promedios1[i] = promedios2[i] = promedios3[i] = promedios4[i] = 0;
        edades1[i] = edades2[i] = edades3[i] = edades4[i] = 0;
    }

    // Menú
    do {
        printf("::....MENU:....::\n");
        printf("op1: ingresar promedios.\n");
        printf("op2: ingresar edades\n");
        printf("op3: mostrar edades mayores.\n");
        printf("op4: mostrar edades menores\n");
        printf("op5: mostrar mejores promedios.\n");
        printf("op6: mostrar los 3 mejores promedios\n");
        printf("op7: mostrar edades que más se repiten.\n");
        printf("op8: mostrar promedio general por grado.\n");
        printf("op9: mostrar grado con mejor rendimiento.\n");
        printf("op10: salir\n");
        printf("Ingrese una opcion: ");
        if(scanf("%d", &opcion) != 1) {
            // Si la entrada no es un entero, limpiar el buffer de entrada y continuar
            while(getchar() != '\n');
            printf("Opcion invalida! Por favor ingrese una opción válida.\n");
            continue;
        }

        switch(opcion) {
            case 1:
                // Ingresar promedios
                ingresarPromedios(promedios1, n, "primer grado");
                ingresarPromedios(promedios2, m, "segundo grado");
                ingresarPromedios(promedios3, k, "tercer grado");
                ingresarPromedios(promedios4, x, "cuarto grado");
                break;
            case 2:
                // Ingresar edades
                ingresarEdades(edades1, n, "primer grado");
                ingresarEdades(edades2, m, "segundo grado");
                ingresarEdades(edades3, k, "tercer grado");
                ingresarEdades(edades4, x, "cuarto grado");
                break;
            case 3:
                // Mostrar edades mayores
                mostrarEdadesMayores(edades1, n, "primer grado");
                mostrarEdadesMayores(edades2, m, "segundo grado");
                mostrarEdadesMayores(edades3, k, "tercer grado");
                mostrarEdadesMayores(edades4, x, "cuarto grado");
                break;
            case 4:
                // Mostrar edades menores
                mostrarEdadesMenores(edades1, n, "primer grado");
                mostrarEdadesMenores(edades2, m, "segundo grado");
                mostrarEdadesMenores(edades3, k, "tercer grado");
                mostrarEdadesMenores(edades4, x, "cuarto grado");
                break;
            case 5:
                // Mostrar mejores promedios
                mostrarPromedioMayor(promedios1, n, "primer grado");
                mostrarPromedioMayor(promedios2, m, "segundo grado");
                mostrarPromedioMayor(promedios3, k, "tercer grado");
                mostrarPromedioMayor(promedios4, x, "cuarto grado");
                break;
            case 6:
                // Mostrar los 3 mejores promedios
                mostrarMejoresPromedios(promedios1, n, "primer grado");
                mostrarMejoresPromedios(promedios2, m, "segundo grado");
                mostrarMejoresPromedios(promedios3, k, "tercer grado");
                mostrarMejoresPromedios(promedios4, x, "cuarto grado");
                break;
            case 7:
                // Mostrar edades que más se repiten
                mostrarEdadRepetida(edades1, n, "primer grado");
                mostrarEdadRepetida(edades2, m, "segundo grado");
                mostrarEdadRepetida(edades3, k, "tercer grado");
                mostrarEdadRepetida(edades4, x, "cuarto grado");
                break;
            case 8:
                // Mostrar promedio general por grado
                promediosGenerales[0] = calcularPromedioGeneral(promedios1, n, "primer grado");
                promediosGenerales[1] = calcularPromedioGeneral(promedios2, m, "segundo grado");
                promediosGenerales[2] = calcularPromedioGeneral(promedios3, k, "tercer grado");
                promediosGenerales[3] = calcularPromedioGeneral(promedios4, x, "cuarto grado");
                break;
            case 9:
                // Mostrar grado con mejor rendimiento
                mostrarGradoMejorRendimiento(promediosGenerales, 4);
                break;
            case 10:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida! Por favor ingrese una opción válida.\n");
        }
    } while(opcion != 10);

    return 0;
}

// Implementaciones de funciones
void ingresarPromedios(int promedios[], int n, const char* grado) {
    for(int i = 0; i < n; i++) {
        printf("Ingrese promedio del alumno %d de %s: ", i+1, grado);
        scanf("%d", &promedios[i]);
    }
}

void ingresarEdades(int edades[], int n, const char* grado) {
    for(int i = 0; i < n; i++) {
        printf("Ingrese edad del alumno %d de %s: ", i+1, grado);
        scanf("%d", &edades[i]);
    }
}

void mostrarEdadesMayores(int edades[], int n, const char* grado) {
    int maxEdad = edades[0];
    for(int i = 1; i < n; i++) {
        if(edades[i] > maxEdad) {
            maxEdad = edades[i];
        }
    }
    printf("La edad mayor de %s es: %d\n", grado, maxEdad);
}

void mostrarEdadesMenores(int edades[], int n, const char* grado) {
    int minEdad = edades[0];
    for(int i = 1; i < n; i++) {
        if(edades[i] < minEdad) {
            minEdad = edades[i];
        }
    }
    printf("La edad menor de %s es: %d\n", grado, minEdad);
}

void mostrarPromedioMayor(int promedios[], int n, const char* grado) {
    int maxPromedio = promedios[0];
    for(int i = 1; i < n; i++) {
        if(promedios[i] > maxPromedio) {
            maxPromedio = promedios[i];
        }
    }
    printf("El promedio mayor de %s es: %d\n", grado, maxPromedio);
}

void mostrarMejoresPromedios(int promedios[], int n, const char* grado) {
    // Ordenar y mostrar los 3 mejores promedios
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (promedios[i] < promedios[j]) {
                int temp = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = temp;
            }
        }
    }
    printf("Los 3 mejores promedios de %s son: %d, %d, %d\n", grado, promedios[0], promedios[1], promedios[2]);
}

void mostrarEdadRepetida(int edades[], int n, const char* grado) {
    int maxRepetida = 0, edadRepetida = 0;
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(edades[j] == edades[i]) {
                count++;
            }
        }
        if(count > maxRepetida) {
            maxRepetida = count;
            edadRepetida = edades[i];
        }
    }
    printf("La edad que más se repite en %s es: %d (se repite %d veces)\n", grado, edadRepetida, maxRepetida);
}

float calcularPromedioGeneral(int promedios[], int n, const char* grado) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += promedios[i];
    }
    float promedioGeneral = (float)sum/n;
    printf("El promedio general de %s es: %.2f\n", grado, promedioGeneral);
    return promedioGeneral;
}

void mostrarGradoMejorRendimiento(float promediosGenerales[], int n) {
    float maxPromedio = promediosGenerales[0];
    int mejorGrado = 1;
    for(int i = 1; i < n; i++) {
        if(promediosGenerales[i] > maxPromedio) {
            maxPromedio = promediosGenerales[i];
            mejorGrado = i + 1;
        }
    }
    printf("El grado con mejor rendimiento es: %d con un promedio de %.2f\n", mejorGrado, maxPromedio);
}
