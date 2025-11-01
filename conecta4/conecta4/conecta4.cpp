// conecta4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma execution_charecter_set("utf-8")
#include <iostream>
#include <vector>
using namespace std;


const int FILAS = 6;
const int COLUMNAS = 7;

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

int main() {



        }
