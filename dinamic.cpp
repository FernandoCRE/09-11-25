#include <iostream>
#include <cstdlib>
using namespace std;

bool movimientovalido(int* posicion, int* b, int n, char m) {
    int idx = posicion - b;
    int r = idx / n ;
    int c = idx % n;

    if (m == 'w' && r == 0)         
        return false;
    if (m == 'a' && c == 0)         
        return false;
    if (m == 's' && r == n - 1)     
        return false;
    if (m == 'd' && c == n - 1)     
        return false;
    return true;
}

void movimientos(int* posicion, char m, int n) {
    int* q = posicion;
    if (m == 'w') q = posicion - n;
    if (m == 'a') q = posicion - 1;
    if (m == 's') q = posicion + n;
    if (m == 'd') q = posicion + 1;

    int temp = *posicion;
    *posicion = *q;
    *q = temp;
}

int main() {
    int n;
    cout << "Ingresa n (tablero n x n): ";
    cin >> n;

    
    int* B = new int[n * n];

    // llenar tablero
    for (int i = 0; i < n * n - 1; i++)
        B[i] = i + 1;
    B[n * n - 1] = 0;

    // numeros desordenados
    for (int k = 0; k < n * n * 5; k++) {
        int i = rand() % (n * n - 1); // no mover el 0
        int j = rand() % (n * n - 1);
        int temp = B[i];
        B[i] = B[j];
        B[j] = temp;
    }

    char mov = 'w';

    while (true) {
        //imp tablero
        for (int* p = B; p < B + n * n; p++) {
            cout << *p << " ";
            if ((p - B + 1) % n == 0)
                cout << endl;
        }

        
        for (int* p = B; p < B + n * n; p++) {
            if (*p == 0) {
                cout << "Movimiento (w=arriba, a=izq, s=abajo, d=der): ";
                cin >> mov;

                if (movimientovalido(p, B, n, mov)) {
                    movimientos(p, mov, n);
                }
                else {
                    cout << "movimiento ilegal" << endl;
                }
                break;
            }
        }
    }

    delete[] B;
    return 0;
}
