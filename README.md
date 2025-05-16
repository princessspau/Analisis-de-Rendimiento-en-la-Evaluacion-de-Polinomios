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

## 1. Clonar el repositorio
```bash
git clone https://github.com/princessspau/Analisis-de-rendimiento-en-la-evaluacion-de-polinomios.git
```
## 2. Entrar al directorio del proyecto

```bash
cd Analisis-de-rendimiento-en-la-evaluacion-de-polinomios
```
### 3. Compilar el código
```bash
g++ -o evaluador evaluacion_de_polinomios.cpp -O3
```

### 4. Ejecutar el experimento
```bash
./evaluador
```
### Descripción de los Algoritmos de Evaluación Polinomial
Método Estándar (Evaluación Directa)
Este método evalúa el polinomio calculando cada término de forma independiente y sumando los resultados. Para un polinomio P(x) = aₙxⁿ + aₙ₋₁xⁿ⁻¹ + ... + a₁x + a₀:

Calcula cada potencia xⁱ desde cero para cada término

Multiplica cada potencia por su coeficiente correspondiente aᵢ

Suma todos los términos calculados

Características clave:

Implementación sencilla y directa

Requiere recalcular potencias para cada término

Complejidad computacional: O(n²) operaciones

Ideal para entender el concepto básico de evaluación polinomial

Ineficiente para polinomios de alto grado

### Método de Horner (Evaluación Anidada)
Este método optimizado reorganiza el polinomio para minimizar las operaciones:

P(x) = (...((aₙx + aₙ₋₁)x + aₙ₋₂)x + ... + a₁)x + a₀

Características clave:

Evita el recálculo redundante de potencias

Solo requiere n multiplicaciones y n sumas (O(n) operaciones)

Más eficiente en tiempo de ejecución

Mejor estabilidad numérica

Forma óptima para evaluar polinomios en aplicaciones reales

Recomendado para polinomios de cualquier grado, especialmente altos

## Ventaja principal:
El método de Horner reduce significativamente el número de operaciones necesarias, lo que se traduce en un mejor rendimiento, como demuestran los resultados experimentales en este proyecto.

