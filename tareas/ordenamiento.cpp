#include <iostream>
using namespace std;

// ===== BURBUJA =====
void burbuja(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool intercambiado = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                intercambiado = true;
            }
        }

        if (!intercambiado) break;
    }
}

// ===== SELECCIÓN =====
void seleccion(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = lista[i];
            lista[i] = lista[min_idx];
            lista[min_idx] = temp;
        }
    }
}

// ===== MERGE =====
void merge(int lista[], int left, int mid, int right) {
    int temp[100];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (lista[i] <= lista[j]) {
            temp[k++] = lista[i++];
        } else {
            temp[k++] = lista[j++];
        }
    }

    while (i <= mid) temp[k++] = lista[i++];
    while (j <= right) temp[k++] = lista[j++];

    for (int x = left; x <= right; x++) {
        lista[x] = temp[x];
    }
}

void mergesort(int lista[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergesort(lista, left, mid);
    mergesort(lista, mid + 1, right);
    merge(lista, left, mid, right);
}

// ===== MAIN =====
int main() {
    string algoritmo;
    int n;

    cin >> algoritmo; // 🔥 IMPORTANTE
    cin >> n;

    int lista[100];

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    if (algoritmo == "burbuja") {
        burbuja(lista, n);
    } 
    else if (algoritmo == "seleccion") {
        seleccion(lista, n);
    } 
    else if (algoritmo == "mergesort") {
        mergesort(lista, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        cout << lista[i];
        if (i < n - 1) cout << " ";
    }

    return 0;
}
