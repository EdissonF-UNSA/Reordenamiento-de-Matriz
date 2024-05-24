#include <iostream>
#include <cstdlib> // random
#include <ctime>   // acceso reloj del sistema

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

void cabecera() {
    std::system("cls");            // Comando para borrar todo el contenido de la pantalla
    std::cout << "\x1B[H";          // Codigo para colocar el cursor en el canto superior izquierdo

    std::cout << "\x1B[3;34m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"    
    std::cout << "/***************************************************/" << std::endl; 
    std::cout << "\x1B[m";             // Resetear color a valor por defecto
    std::cout << "\x1B[31;5;88mUniversidad Nacional de San Agustin \x1B[m" << std::endl; 
    std::cout << "\x1B[33;5;88mEscuela Profesional de Ingenieria de Sistemas\x1B[m" << std::endl; 
    std::cout << "Curso de C++ Intermedio" << std::endl; 
    std::cout << "\x1B[38;5;46mProf. D.Sc. Manuel Eduardo Loaiza Fernandez \x1B[m" << std::endl; 
    std::cout << "\x1B[37;5;46mAlumn. Edisson Franklin Checalla Soto \x1B[m" << std::endl;
	std::cout << "\x1B[37;5;46mAlumn. Michael Steve Hurtado Bejarano	 \x1B[m" << std::endl; 
    std::cout << "Arequipa 2024" << std::endl; 
    std::cout << "\x1B[3;34m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"    
    std::cout << "/***************************************************/" << std::endl;
    
    std::cout << "\x1B[m";             // Resetear color a valor por defecto 
}

// algoritmo quick sort
void quickSort(char arr[], int left, int right) {
	
	int i = left, j = right;
    char tmp;
    char pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };


    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
	
}

void ordenarMatriz(char **matriz, int n) {
    char *elementos = new char[n * n];
    int index = 0;
    //copiamos elementos de la matriz original a un arreglo unidimensional
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            elementos[index++] = matriz[i][j];
        }
    }
    // ordenamos el arreglo unidimensional
	quickSort(elementos, 0, n * n - 1);
	
    // Copiamos elementos ordenados de nuevo a la matriz original
    index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = elementos[index++];
        }
    }

    // Distribuir elementos en los arreglos adicionales
    char *minusculas = new char[n * n];
    char *numeros_0_4 = new char[n * n];
    char *numeros_5_9 = new char[n * n];
    char *mayusculas = new char[n * n];

    int count_minusculas = 0;
    int count_numeros_0_4 = 0;
    int count_numeros_5_9 = 0;
    int count_mayusculas = 0;

    for (int i = 0; i < n * n; ++i) {
        char elemento = elementos[i];
        if (elemento >= 'a' && elemento <= 'z') {
            minusculas[count_minusculas++] = elemento;
        } else if (elemento >= '0' && elemento <= '4') {
            numeros_0_4[count_numeros_0_4++] = elemento;
        } else if (elemento >= '5' && elemento <= '9') {
            numeros_5_9[count_numeros_5_9++] = elemento;
        } else if (elemento >= 'A' && elemento <= 'Z') {
            mayusculas[count_mayusculas++] = elemento;
        }
    }
/////////////////////////////////////////////////////////////////////
    // creamos nueva matriz para almacenar los cuadrantes
    char **nuevaMatriz = new char *[n];
    for (int i = 0; i < n; ++i) {
        nuevaMatriz[i] = new char[n];
    }

    // rellenamos cada cuadrante con los elementos correspondientes de los arreglos
    int index_minusculas = 0;
    int index_numeros_0_4 = 0;
    int index_numeros_5_9 = 0;
    int index_mayusculas = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < n / 2 && j < n / 2) { // Cuadrante 1 (letras minúsculas)
                if (index_minusculas < count_minusculas) {
                    nuevaMatriz[i][j] = minusculas[index_minusculas++];
                } else {
                    nuevaMatriz[i][j] = '-';
                }
            } else if (i < n / 2 && j >= n / 2) { // Cuadrante 2 (números de 0 a 4)
                if (index_numeros_0_4 < count_numeros_0_4) {
                    nuevaMatriz[i][j] = numeros_0_4[index_numeros_0_4++];
                } else {
                    nuevaMatriz[i][j] = '-';
                }
            } else if (i >= n / 2 && j < n / 2) { // Cuadrante 3 (números de 5 a 9)
                if (index_numeros_5_9 < count_numeros_5_9) {
                    nuevaMatriz[i][j] = numeros_5_9[index_numeros_5_9++];
                } else {
                    nuevaMatriz[i][j] = '-';
                }
            } else { // Cuadrante 4 (letras mayúsculas)
                if (index_mayusculas < count_mayusculas) {
                    nuevaMatriz[i][j] = mayusculas[index_mayusculas++];
                } else {
                    nuevaMatriz[i][j] = '-';
                }
            }
        }
    }
	
	// Mostramos la nueva matriz con los cuadrantes llenos hasta donde llegue
    std::cout << "\nNueva Matriz con Cuadrantes Semillenos:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << " " << nuevaMatriz[i][j];
        }
        std::cout << std::endl;
    }
	

    //distribuimos elementos excedentes en la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (nuevaMatriz[i][j] == '-') {
                if (index_minusculas < count_minusculas) {
                    nuevaMatriz[i][j] = minusculas[index_minusculas++];
                } else if (index_numeros_0_4 < count_numeros_0_4) {
                    nuevaMatriz[i][j] = numeros_0_4[index_numeros_0_4++];
                } else if (index_numeros_5_9 < count_numeros_5_9) {
                    nuevaMatriz[i][j] = numeros_5_9[index_numeros_5_9++];
                } else if (index_mayusculas < count_mayusculas) {
                    nuevaMatriz[i][j] = mayusculas[index_mayusculas++];
                }
            }
        }
    }

    // Mostramos la nueva matriz con los cuadrantes llenos
    std::cout << "\nNueva Matriz con Cuadrantes Llenos:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < n / 2) {
                if (j < n / 2) {
                    std::cout << RED;
                } else {
                    std::cout << GREEN;
                }
            } else {
                if (j < n / 2) {
                    std::cout << YELLOW;
                } else {
                    std::cout << BLUE;
                }
            }
			std::cout << " " << nuevaMatriz[i][j] << RESET;
        }
		std::cout << std::endl;
    }
	
	// Liberamos la memoria dinámica
	delete[] elementos;
	delete[] minusculas;
	delete[] numeros_0_4;
	delete[] numeros_5_9;
	delete[] mayusculas;
	 
	for (int i = 0; i < n; i++) {
		delete[] nuevaMatriz[i];
	}
	delete[] nuevaMatriz;

}

int main() {
	
	cabecera();
	
    int n = 10;

    // Crear matriz original
    char **miMatriz = new char *[n];
    for (int i = 0; i < n; ++i) {
        miMatriz[i] = new char[n];
    }

    // Llenar matriz original con valores aleatorios
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char miValor;
            int n_random = std::rand() % 3;
            if (n_random == 0) { // Mayúscula
                miValor = 65 + (std::rand() % 26);
            } else if (n_random == 1) { // Minúscula
                miValor = 97 + (std::rand() % 26);
            } else { // Número
                miValor = 48 + (std::rand() % 10);
            }
            miMatriz[i][j] = miValor;
        }
    }

    //mostrar matriz original
    std::cout << "Matriz Original:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << " " << miMatriz[i][j];
        }
        std::cout << std::endl;
    }

    //ordenar y distribuir los elementos de la matriz
    ordenarMatriz(miMatriz, n);

    return 0;
}
