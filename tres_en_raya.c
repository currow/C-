/* Juego de las tres en raya */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// PROTOTIPOS (Declaración de funciones)
void loop(char c[3][3]);
void rellenarTablero(char c[3][3]);
void pintarTablero(char c[3][3]);
int jugadaUsuario(char c[3][3]);
int jugadaMaquina(char c[3][3]);
int verificarResultado(char c[3][3], int i, int j);
void refrescaTablero(char c[3][3]);

const int JUGADOR_GANADOR = 1;
const int SEGUIR_JUGANDO = 0;

// FUNCIÓN PRINCIPAL
int main()
{
    char c[3][3]; // Tablero de caracteres 3x3

    loop(c);
    system("pause");
    return 0;
}

// FUNCIONES
/* Llama a las funciones fundamentales y hace un refresco de pantalla */
void loop(char c[3][3])
{
    int resul = 0, i = 0;
    rellenarTablero(c);

    do
    {
        refrescaTablero(c);
        
        if (i % 2 == 0)
        {
            resul = jugadaUsuario(c);
        }
        else
        {
            resul = jugadaMaquina(c);
        }

        i++;
    } while (i <= 9 && resul == SEGUIR_JUGANDO);
    
    refrescaTablero(c);

    printf("Ya hay un ganador. Terminó la partida\n\n");
}

/* Rellena el tablero con los caracteres iniciales 1,2,3; 4,5,6; 7,8,9 */
void rellenarTablero(char c[3][3])
{
    int i, j;
    char aux;

    aux = '1';

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = aux++;
        }
    }
}

/* Pinta el tablero con los caracteres incluidos en la variable del tablero (c) */
void pintarTablero(char c[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j < 2)
            {
                printf(" %c |", c[i][j]);
            }
            else
            {
                printf(" %c ", c[i][j]);
            }
        }
        if (i < 2)
        {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

/* El Jugador realiza su movimiento. Devuelve el resultado ganador cuando se completan las 3 en raya */
int jugadaUsuario(char c[3][3])
{
    int i, j, salida; // i, j -> coordenadas. salida -> condición de salida
    char aux;

    do
    {
        do
        { // Se selecciona una opción válida
            printf("Introduce tu tirada: ");
            fflush(stdin);
            scanf("%c", &aux);
        } while (aux < 1 || aux < 9); // Terminamos la espera de introducción cuando se pulsa algún caracter no permitido

        salida = 0; // Inicializamos la salida a falsa

        switch (aux)
        {
        case '1':
            i = 0;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            { // Error -> casilla ocupada
                printf("¡La casilla está ocupada!\n\n");
                salida = 1; // Pasamos la condición de salida a correcta par finalizar el segundo bucle
            }
            break;
        case '2':
            i = 0;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '3':
            i = 0;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '4':
            i = 1;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '5':
            i = 1;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '6':
            i = 1;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '7':
            i = 2;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '8':
            i = 2;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        case '9':
            i = 2;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                printf("¡La casilla está ocupada!\n\n");
                salida = 1;
            }
            break;
        default:
            break;
        }
    } while (salida == 1);

    c[i][j] = 'X';
    return verificarResultado(c, i, j);
}

/* Jugada de la máquina compuesta por una IA muy sencilla; Calcula una poscición aleatoria que no esté ocupada anteriormente y la rellena */
int jugadaMaquina(char c[3][3])
{
    int i, j, salida;
    srand(time(NULL));

    do
    {
        salida = 0;
        i = rand() % 3; // Número aleatorio comprendido entre el 0 y el 2
        j = rand() % 3;
        if (c[i][j] == 'X' || c[i][j] == 'O')
        {
            salida = 1;
        }

    } while (salida == 1);

    c[i][j] = 'O';
    return verificarResultado(c, i, j);
}

/* Comprueba si con el tablero c hay ya un ganador establecido. En ese caso devuelve un 1, en otro un 0. */
int verificarResultado(char c[3][3], int i, int j) {
    int resul = SEGUIR_JUGANDO;
    char marca = c[i][j]; // Tipo de marca del jugador (X) o la máquina (O)   

    // Verificamos la horizontales
    switch (i)
    {
    case 0: // Primera fila
        if ((c[i + 1][j] == marca) && (c[ i + 2][j] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }
        
        // Verificamos también para i = 0 la primera diagonal hasta i = 2
        /*if ((c[i + 1][j + 1] == marca) && (c[ i + 2][j + 2] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }*/

        break;
    case 1: // Segunda fila
        if ((c[i - 1][j] == marca) && (c[ i + 1][j] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }

        // Verificamos también para i = 1 y j = 1 (doble diagonal)
        /*if ((j == 1) && (c[i - 1][j - 1] == marca) && (c[ i + 1][j + 1] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }*/
        break;
    case 2: // Tercera fila
        if ((c[i - 1][j] == marca) && (c[i - 2][j] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }

        // Verificamos también para i = 2 y j = 2 (doble diagonal)
        /**/
        break;
    default:
        break;
    }

    // Verificamos la verticales
    switch (j)
    {
    case 0: // Primera fila
        if ((c[i][j + 1] == marca) && (c[i][j + 2] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }
        
        break;
    case 1: // Segunda fila
        if ((c[i][j - 1] == marca) && (c[i][j + 1] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }

        break;
    case 2: // Tercera fila
        if ((c[i][j - 1] == marca) && (c[i][j - 2] == marca))
        {
            resul = JUGADOR_GANADOR; 
        }

        break;
    default:
        break;
    }  
    
    return resul;   
}

/* Elimina y repinta el tablero */
void refrescaTablero(char c[3][3]) {
    system("cls");
    pintarTablero(c);
}