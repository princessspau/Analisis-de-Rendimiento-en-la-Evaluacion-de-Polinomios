#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Método de Horner
long double EvaluarPolinomioHorner(long double* cof, int grado, long double x) {
    long double valor = cof[0];  // coef[0] es el de x^grado
    for (int i = 1; i <= grado; ++i) {
        valor = valor * x + cof[i];
    }
    return valor;
}

// Método estándar término a término
long double EvaluarPolinomioTerminoATermino(long double* cof, int grado, long double x) {
    long double poliVal = cof[grado];
    long double term;

    for (int i = 1; i <= grado; ++i) {
        term = cof[grado - i];
        for (int j = 1; j <= i; ++j) {
            term = term * x;
        }
        poliVal = poliVal + term;
    }
    return poliVal;
}

// Generación de coeficientes
void GenerarCoeficientes(long double* cof, int grado) {
    for (int i = 0; i <= grado; ++i) {
        cof[i] = rand() % 21 - 10; // [-10, 10]
    }
}

int main() {
    srand(time(NULL));
    const int repeticiones = 1000;
    const int inicio_grado = 10;
    const int fin_grado = 1000;
    const int paso_grado = 10;

    std::ofstream archivo("resultados_nano.csv");
    archivo << "grado,tiempo_estandar_ns,tiempo_horner_ns\n";

    for (int grado = inicio_grado; grado <= fin_grado; grado += paso_grado) {
        long double* coeficientes = new long double[grado + 1];
        GenerarCoeficientes(coeficientes, grado);

        long double x;
        do {
            x = (rand() % 2001 - 1000) / 100.0L;
        } while (x == 0.0L);

        long double tiempo_total_estandar = 0;
        long double tiempo_total_horner = 0;

        for (int i = 0; i < repeticiones; ++i) {
            // Medición del método estándar
            auto inicio = std::chrono::high_resolution_clock::now();
            EvaluarPolinomioTerminoATermino(coeficientes, grado, x);
            auto fin = std::chrono::high_resolution_clock::now();
            tiempo_total_estandar += std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();

            // Medición del método de Horner
            inicio = std::chrono::high_resolution_clock::now();
            EvaluarPolinomioHorner(coeficientes, grado, x);
            fin = std::chrono::high_resolution_clock::now();
            tiempo_total_horner += std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();
        }

        long double tiempo_promedio_estandar = tiempo_total_estandar / repeticiones;
        long double tiempo_promedio_horner = tiempo_total_horner / repeticiones;

        archivo << grado << "," << tiempo_promedio_estandar << "," << tiempo_promedio_horner << "\n";
        delete[] coeficientes;

        if (grado % 100 == 0) {
            std::cout << "Procesado grado: " << grado << std::endl;
        }
    }

    archivo.close();
    std::cout << "Resultados guardados en 'resultados_nano.csv' (tiempos en nanosegundos).\n";
    return 0;
}
