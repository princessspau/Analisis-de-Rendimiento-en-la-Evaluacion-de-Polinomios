# Análisis de Rendimiento en la Evaluación de Polinomios

## Descripción
Este proyecto compara experimentalmente la eficiencia computacional de dos algoritmos para evaluar polinomios:

- **Método Estándar**: Evalúa el polinomio término a término, calculando cada potencia de \(x\) de forma explícita.
- **Método de Horner**: Optimiza la evaluación mediante una forma anidada que reduce considerablemente la cantidad de operaciones aritméticas requeridas.

Se realizaron pruebas para polinomios de grado entre 10 y 1000, generando coeficientes aleatorios y evaluando los polinomios en un punto \(x \neq 0\). Los tiempos de ejecución promedio se almacenaron para análisis posterior.

---

## Autor(a)
Paulina Bojorquez Trujillo

---

## Requisitos del sistema
- Compilador C++ (recomendado: **g++ versión 9.4.0** o superior).
- Sistema compatible con C++11 o posterior.
- No se requieren bibliotecas externas adicionales.

---

## Instrucciones de compilación y ejecución

### 1. Clonar el repositorio
```bash
git clone https://github.com/princessspau/Eficiencia-Polinomios-Horner.git


