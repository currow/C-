/* Juego de las tres en raya */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

// PROTOTIPOS (Declaración de funciones)
void loop(char c[3][3]); 
void rellenarTablero (char c[3][3]);
void pintarTablero(char c[3][3]);
void jugadaUsuario(char c[3][3]);
void jugadaMaquina(char c[3][3]);

int main() {
    char c[3][3]; // Tablero de caracteres 3x3    

    loop(c); 
    system("pause");
    return 0;
}


// FUNCIONES
/* Llama a las funciones fundamentales y hace un refresco de pantalla */
void loop(char c[3][3]) {
    int i = 0;
    rellenarTablero(c);

    do {
        system("cls");
        pintarTablero(c);

        if (i % 2 == 0) {
            jugadaUsuario(c);
        } else {
            jugadaMaquina(c);
        }
        
        i++;
    } while (i <= 9);
}

/* Rellena el tablero con los caracteres iniciales 1,2,3; 4,5,6; 7,8,9 */
void rellenarTablero (char c[3][3]) {
    int i, j;
    char aux;

    aux = '1';

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = aux++;
        }
    }
}

/* Pinta el tablero con los caracteres incluidos en la variable del tablero (c) */
void pintarTablero(char c[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j < 2) {
                printf(" %c |", c[i][j]);
            } else {
                printf(" %c ", c[i][j]);
            }    
        }
        if (i < 2) {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

/* El Jugador realiza su movimiento.  */
void jugadaUsuario(char c[3][3]) {
    int i, j, salida; // i, j -> coordenadas. salida -> condición de salida
    char aux;

    do {
        do { // Se selecciona una opción válida
            printf("Introduce tu tirada: ");
            fflush(stdin);
            scanf("%c", &aux);
        } while (aux < 1 || aux < 9); // Terminamos la espera de introducción cuando se pulsa algún caracter no permitido    

        salida = 0; // Inicializamos la salida a falsa

        switch (aux) {
            case '1':
                i = 0;
                j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O') { // Error -> casilla ocupada
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; // Pasamos la condición de salida a correcta par finalizar el segundo bucle
                }
                break;
            case '2':
                i = 0;
                j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '3':
                i = 0;
                j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '4':
                i = 1;
                j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '5':
                i = 1;
                j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '6':
                i = 1;
                j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '7':
                i = 2;
                j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '8':
                i = 2;
                j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            case '9':
                i = 2;
                j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O') { 
                    printf("¡La casilla está ocupada!\n\n");
                    salida = 1; 
                }
                break;
            default:
                break;
        }
    } while (salida == 1);

     c[i][j] = 'X';
}

/* Jugada de la máquina compuesta por una IA muy sencilla; Calcula una poscición aleatoria que no esté ocupada anteriormente y la rellena */
void jugadaMaquina(char c[3][3]) {
    int i, j, salida;
    srand(time(NULL));
    
    do {
        salida = 0;
        i = rand() % 3; // Número aleatorio comprendido entre el 0 y el 2
        j = rand() % 3;
        if (c[i][j] == 'X' || c[i][j] == 'O') {
            salida = 1;
        }
        
    } while (salida == 1);
    
    c[i][j] = 'O';
}