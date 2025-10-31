

#include <iostream>
#include <locale>
using namespace std;

// --- Prototipos ---
// Sirve para poder hacer las funciones abajo del main
void mostrarMenuRecursivo();
void ejercicio1_secuenciaAlternativa();
void ejercicio3_mayorSumaConsecutiva3();

// --------------------
// Función principal
// --------------------
int main() {
    setlocale(LC_ALL, "spanish");
    mostrarMenuRecursivo(); // llamada inicial
    return 0;
}

// --------------------
// Menú recursivo principal
// --------------------
void mostrarMenuRecursivo() {
    cout << "==================== MENU PRINCIPAL ====================\n";
    cout << "Seleccione una opcion:\n";
    cout << "1. Secuencia Alternante de Máximos y Mínimos\n";
    cout << "2. Secuencia Autodescriptiva\n";
    cout << "3. Subarreglo de Suma Máxima\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
        ejercicio1_secuenciaAlternativa();
        break;
    case 2:

        break;
    case 3:
        ejercicio3_mayorSumaConsecutiva3();
        break;
    case 0:
        cout << "Saliendo... Gracias.\n";
        return; // finaliza la recursión
    default:
        cout << "Opcion no valida. Intente de nuevo.\n";
    }

   

    // Llamada recursiva al menú
    mostrarMenuRecursivo();
}

// --------------------
// Ejercicio 1: Secuencia Alternante de Máximos y Mínimos
// --------------------
void ejercicio1_secuenciaAlternativa() {
    const int TAM = 7;
    int arr[TAM];

    cout << "\n--- EJERCICIO 1:  (TAMANIO = 7) ---\n";
    cout << "Ingrese 7 numeros enteros:\n";

    for (int i = 0; i < TAM; ++i) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    };
   // int temp ;
    bool ordenado = false;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            }
            
        }
        
    }
    cout << TAM;
    

};


// --------------------
// Ejercicio 3: Subarreglo de Suma Máxima
// --------------------
void ejercicio3_mayorSumaConsecutiva3() {
    const int TAM = 7;
    int arr[TAM];

    cout << "\n--- EJERCICIO 3: Mayor suma consecutiva de 3 numeros (TAMANIO = 7, circular) ---\n";
    cout << "Ingrese 7 numeros enteros:\n";

    for (int i = 0; i < TAM; ++i) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    int mejorSuma = arr[0] + arr[1] + arr[2];
    int idxMejor = 0;

    // Recorre todos los posibles bloques de 3 (de forma circular)
    for (int i = 1; i < TAM; ++i) {
        int suma = arr[i] + arr[(i + 1) % TAM] + arr[(i + 2) % TAM];
        if (suma > mejorSuma) {
            mejorSuma = suma;
            idxMejor = i;
        }
    }

    int n1 = arr[idxMejor];
    int n2 = arr[(idxMejor + 1) % TAM];
    int n3 = arr[(idxMejor + 2) % TAM];

    cout << "\nBloque con mayor suma: [" << n1 << ", " << n2 << ", " << n3 << "]\n";
    cout << "Suma maxima: " << mejorSuma << endl;
}
