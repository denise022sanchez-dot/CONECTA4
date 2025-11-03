# CONECTA4

Este proyecto es una implementación del clásico juego de mesa Conecta 4 (también conocido como "Cuatro en Línea") en C++. El juego se ejecuta en la consola y permite a dos jugadores turnarse para intentar alinear cuatro de sus fichas horizontal, vertical o diagonalmente.

Características

Juego por Turnos: Dos jugadores, 'X' y 'O'.
Tablero Estándar: Utiliza el tamaño tradicional de 6 filas por 7 columnas.
Detección de Victoria: Verifica automáticamente las 4 en raya en cualquier dirección (horizontal, vertical, y ambas diagonales).
Detección de Empate: Identifica cuando el tablero está completamente lleno sin un ganador.
Manejo de Errores: Valida la entrada del usuario para asegurar que la columna sea válida y no esté llena.

Cómo Jugar

El juego se ejecuta completamente en la terminal o consola.
Ejecutar el Programa: Compila y ejecuta el archivo fuente .cpp
Turno: El programa indicará de quién es el turno Jugador X o Jugador O.
Ingresar Columna: El jugador debe ingresar el número de columna del 1 al 7 donde desea dejar caer su ficha.
Movimiento: La ficha caerá automáticamente a la posición vacía más baja de esa columna.
Fin del Juego: El juego finaliza cuando un jugador logra conectar cuatro fichas o cuando el tablero se llena empate.

