#include <stdio.h>
#include <windows.h>


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Cordenadas del cursor en la consola

int main() {

    char cuadrado[2][3] = {
        {'*', '*', '*'},
        {'*', '*', '*'},

        // Filas y columnas
    };
    int x = 56, y = 13;
    int direccion;
    int actual = 1;

    while (actual) {
       system("cls");

        for (int Fila = 0; Fila < 2; Fila++) {
            for (int Columna = 0; Columna < 3; Columna++) {
                gotoxy(x + Columna, y + Fila);
                //Acomodo de los asteriscos
                printf("%c ", cuadrado[Fila][Columna]);
            }
            //Imprime los asteriscos
        }
        
        direccion = getchar();

        switch (direccion)
        {        
            case 'a':
                x--;
                break;
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            case 'e':
                actual = 0;
                break;
        }
    }
    return 0;
}