/**
 * Problema 1: 
 * Dado un arreglo de números del 1 al 10, encontrar índices i y j que generen un conjuntos de 3 elementos que sumen x
 * Inputs:
 * suma, n, elementos...
 */

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> find(vector<int> arr, int x){
    // Guardar resultados en un vector de pares
    vector<pair<int, int>> results;
    // Iterar arreglo 
    for(int i = 0; i < arr.size(); i++){
        // Obtener la suma de arr[i] ... arr[i+2]
        int sum = arr[i] + arr[i+1] + arr[i+2];
        if(sum == x) results.push_back(pair<int, int> {i, i+2});
    }
    return results;
}

void receiveValuesFor(int &sum, int &n, vector<int> &arr){
    // Recibir valor de suma
    cin >> sum ;
    // Recibir valor de n
    cin >> n;
    // Inicializar arreglo de tamaño n
    arr = vector<int>(n);
    // cin para cada elemento
    for(int &elem : arr) cin >> elem;
}

int main(){
    int sum;
    int n;
    vector<int> arr;
    receiveValuesFor(sum, n, arr);
    vector<pair<int, int>> result = find(arr, sum);
    for(pair<int, int> &item : result){
        cout << item.first << ", " << item.second << endl;
    }
    return 0;
}