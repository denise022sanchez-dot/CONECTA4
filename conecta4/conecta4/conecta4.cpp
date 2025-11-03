#pragma execution_charecter_set("utf-8")
#include <iostream>
#include <vector>
using namespace std;


const int FILAS = 6;   //Cantidad fija de filas
const int COLUMNAS = 7;  //Cantidad fijas de columnas

//Funcion para imprimir tablero

void imprimirTablero(const vector<vector<char>>& tablero) {  // Función que muestra el tablero en
    cout << "\n  ";                                      //pantalla y lo muestra constantemente en pantalla  
    // Para recorrer las columnas (1 al 7)
    for (int c = 0; c < COLUMNAS; c++) {
        cout << c + 1 << " ";  //Para mostrar los numeros de la columna
    }
    cout << "\n";


    //Para recorrer todas las filas
    for (int f = 0; f < FILAS; f++) {
        cout << "| ";
        for (int c = 0; c < COLUMNAS; c++) {
            cout << tablero[f][c] << " ";  /*Ciclo for anidado para mostrar en pantalla
            el contenido de cada celda ".", "X", "O"*/

        }
        cout << "|\n";
    }
    cout << "-----------------\n";
}


// Función para colocar una ficha. Devuelve 'true' si se pudo colocar, 
// 'false' si la columna está llena.
bool colocarFicha(vector<vector<char>>& tablero, int columna, char jugador) {
    for (int f = FILAS - 1; f >= 0; f--) {
        if (tablero[f][columna] == '.') {
            tablero[f][columna] = jugador;
            return true;
        }
    }
    return false;
}

// Función para verificar si el jugador j ganó 4 en raya
bool verificarGanador(const vector<vector<char>>& t, char j) {


    for (int f = 0; f < FILAS; f++) {      //Bucle para verificar si se gano en horizontal
        for (int c = 0; c < COLUMNAS - 3; c++) {
            if (t[f][c] == j && t[f][c + 1] == j &&   //Comprueba si se colocó  4 celdas seguidas a la derecha.
                t[f][c + 2] == j && t[f][c + 3] == j) {
                return true;
            }
        }
    }

    for (int f = 0; f < FILAS - 3; f++) {  //Bucle para verificar si se gano en vertical
        for (int c = 0; c < COLUMNAS; c++) {
            if (t[f][c] == j && t[f + 1][c] == j &&  //Condicional para verificar 
                t[f + 2][c] == j && t[f + 3][c] == j) {  //si se coloco 4 fichas seguidas en vertical
                return true;
            }
        }
    }

    for (int f = 3; f < FILAS; f++) {   //Bucle para verificar si se gano en diagonal ascendente
        for (int c = 0; c < COLUMNAS - 3; c++) {
            if (t[f][c] == j && t[f - 1][c + 1] == j &&
                t[f - 2][c + 2] == j && t[f - 3][c + 3] == j) {
                return true;
            }
        }
    }

    for (int f = 0; f < FILAS - 3; f++) {   //Bucle para verificar si se gano en diagonal descendente
        for (int c = 0; c < COLUMNAS - 3; c++) {
            if (t[f][c] == j && t[f + 1][c + 1] == j &&
                t[f + 2][c + 2] == j && t[f + 3][c + 3] == j) {
                return true;
            }
        }
    }

    return false;
}


bool tableroLleno(const vector<vector<char>>& tablero) {

    for (int c = 0; c < COLUMNAS; c++) {  // Función para verificar si el tablero está lleno, o sea hay empate
        if (tablero[0][c] == '.') {
            return false;
        }
    }
    return true;
}


int main() {

    vector<vector<char>> tablero(FILAS, vector<char>(COLUMNAS, '.'));  //Se inicializa el tablero como una matriz 6x7, llenando todas las celdas con el carácter vacío
    char jugadorActual = 'X';   //Se inicializa el jugador actual
    bool juegoTerminado = false; //bandera que me determinara el bucle del juego

    cout << "=== JUEGO CONECTA 4 ===\n";  
    cout << "Jugador 1: X   |   Jugador 2: O\n";

    while (!juegoTerminado) {   //Bucle while principal del juego que se repetirá hasta que haya ganador o empate
        imprimirTablero(tablero);  //llama a la funcion que muestra el tablero

        int columna;
        cout << "\nTurno del jugador " << jugadorActual << ". Ingresa una columna (1-7): ";
        cin >> columna;

        if (cin.fail() || columna < 1 || columna > 7) {  //Validacion de entrada
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida. Intenta de nuevo.\n";
            continue;
        }

        if (!colocarFicha(tablero, columna - 1, jugadorActual)) {  //Para colocar ficha
            cout << "Columna llena. Elige otra.\n";
            continue;
        }

        if (verificarGanador(tablero, jugadorActual)) {   //Para verificar si hay ganador
            imprimirTablero(tablero);
            cout << "\nJugador " << jugadorActual << " gana\n";
            juegoTerminado = true;
        }

        else if (tableroLleno(tablero)) {   //Para verificar si el tablero esta lleno, hay empate
            imprimirTablero(tablero);
            cout << "\nEmpate El tablero esta lleno.\n";
            juegoTerminado = true;
        }
        else {

            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';  // Si no hay ganador ni empate, cambia el turno al otro jugador
        }
    }

    cout << "\nFin del juego  Gracias por jugar\n";
    return 0;





        }
