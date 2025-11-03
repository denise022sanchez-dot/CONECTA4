#pragma execution_charecter_set("utf-8")
#include <iostream>
#include <vector>
using namespace std;


const int FILAS = 6;   //Cantidad fija de filas
const int COLUMNAS = 7;  //Cantidad fijas de columnas

//Funcion para imprimir tablero

void imprimirTablero(const vector<vector<char>>& tablero) {
    cout << "\n  ";
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

bool colocarFicha(vector<vector<char>>& tablero, int columna, char jugador) {
    for (int f = FILAS - 1; f >= 0; f--) {
        if (tablero[f][columna] == '.') {
            tablero[f][columna] = jugador;
            return true;
        }
    }
    return false;
}

bool verificarGanador(const vector<vector<char>>& t, char j) {


    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS - 3; c++) {
            if (t[f][c] == j && t[f][c + 1] == j &&
                t[f][c + 2] == j && t[f][c + 3] == j) {
                return true;
            }
        }
    }

    for (int f = 0; f < FILAS - 3; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            if (t[f][c] == j && t[f + 1][c] == j &&
                t[f + 2][c] == j && t[f + 3][c] == j) {
                return true;
            }
        }
    }

    for (int f = 3; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS - 3; c++) {
            if (t[f][c] == j && t[f - 1][c + 1] == j &&
                t[f - 2][c + 2] == j && t[f - 3][c + 3] == j) {
                return true;
            }
        }
    }

    for (int f = 0; f < FILAS - 3; f++) {
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

    for (int c = 0; c < COLUMNAS; c++) {
        if (tablero[0][c] == '.') {
            return false;
        }
    }
    return true;
}






int main() {



        }
