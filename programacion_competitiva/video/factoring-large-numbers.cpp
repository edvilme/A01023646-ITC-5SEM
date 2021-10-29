#include <bits/stdc++.h>
using namespace std;

// Usamos números grandes, conviene usar un alias
using llint = long long int;

// Necesitamos un lugar donde guardar los resultados
// Un mapa de vectores es rápido, pero toma mucho espacio y tiene muchas repeticiones
// Se guarda [n, n/i] donde i es el factor más pequeño
// Se itera para recorrer todos los factores
map<llint, llint> previousFactorsMap;

// Función para leer el mapa
void getFactorsFromMap(llint n){
    // Caso base cuando n sea menor o igual a 2
    if(n<=2) return;
    // Encontrar valor con llave n
    // Asumimos que siempre existe (lo implementaremos en la otra función)
    llint biggestFactor = previousFactorsMap.find(n)->second;
    // Despejamos para obtener i 
    llint smallestFactor = n/biggestFactor;
    // Si el factor más pequeño es 1, terminar, es primo
    if(smallestFactor == 1){
        cout << "    " << n << endl;
        return;
    }
    // Imprimir factor más pequeño
    cout << "    " << smallestFactor << endl;
    // Obtener los factores a partir del más grande
    return getFactorsFromMap(biggestFactor);
}


// Función para obtener los factores
void getFactors(llint n, llint previousFactor){
    // Todo número es divisible entre sí mismo y entre 1
    // Un número es divisible entre i si n%i == 0
    // Puede hacerse recursivamente con getFactors(n/i) hasta que n = 1
    // Todos los valores regresados serán primos 
    // Todos los valores regresados serán iguales o mayores que el anterior
    // Necesitamos saber el último valor anterior
    // i debe ir en incrementos del último factor para evitar múltiplos de factores anteriores ya conocidos
    // Funciona bien, pero toma mucho tiempo, especialmente si se ejecuta varias veces
    if(n == 1) return;
    // Determinar si n existe en el mapa
    if(previousFactorsMap.find(n) != previousFactorsMap.end()){
        return getFactorsFromMap(n);
    }
    for(llint i = previousFactor; i < n; i += previousFactor - 1){
        if(n%i == 0){
            // Agregar al mapa
            previousFactorsMap.insert({n, n/i});
            cout << "    " << i << endl;
            return getFactors(n/i, i);
        }
    }
    // Imprimir si es primo (no tiene otros factores)
    cout << "    " << n << endl;
    // También agregar al mapa
    previousFactorsMap.insert({n, n});
}

int main(int argc, char **argv){
    // Recibir valores siempre que sean mayor a 0
    llint currentNumber;
    while(true){
        cin >> currentNumber;
        if(currentNumber < 0) return 0;
        // Obtener factores
        getFactors(currentNumber, 2);
        cout<<endl;
    }
    return 0;
}