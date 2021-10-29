#include <bits/stdc++.h>
using namespace std;
// Abreviar para mas velocidad
using v_int = vector<int>;

v_int getResults(v_int &M, v_int &P, int &k){
    v_int res;
    // Crear indices para cada usuario
    int M_index = 0, 
        P_index = 0;
    // Recorrer el archivo sin excederse del número de lineas
    int maxSize = M.size() + P.size();
    for(int i = 0; i < maxSize; i++){
        // El índice no puede excederse del tamaño del vector de usuario
        if(M_index < M.size()){
            // Cuando es 0, se agrega una nueva linea, y cambia el valor de k
            if(M[M_index] == 0){
                res.push_back(0);
                k++;
                M_index++;
            } 
            else if(M[M_index] <= k){
            // De lo contrario, solo se agrega el cambio al vector e incrementa el índice
                res.push_back(M[M_index]);
                M_index++;
            }
            // Se repite el mismo procedimiento para P
        } else if (P_index < P.size()){
            // Cuando es 0, se agrega una nueva linea, y cambia el valor de k
            if(P[P_index] == 0){
                res.push_back(0);
                k++;
                P_index++;
            } 
            else if(P[P_index] <= k){
            // De lo contrario, solo se agrega el cambio al vector e incrementa el índice
                res.push_back(P[P_index]);
                P_index++;
            }
        }
        // DE lo contrario no existe una solución
        else return v_int(0);
    }
    return res;
}

int main(){
    // Leer linea con t casos de prueba
    int t;
    cin >> t;
    // Iterar t veces
    while(t--){
        // La primera linea contiene k, n, m
        int k, n, m;
        cin >> k >> n >> m;
        // Crear v1
        v_int v1(n);
        // Llenar con elementos
        for(int &element : v1) cin >> element;
        // Repetir para v2
        // Crear v2
        v_int v2(n);
        // Llenar con elementos
        for(int &element : v2) cin >> element;
        // Los resultados se guardan en un vector
        v_int results = getResults(v2, v1, k);
        // Imprimir
        if(results.size() == 0){
            cout<<-1<<endl;
        } else {
            for(int &element : results) cout << element << endl;
            cout << endl;
        }
    }
    return 0;
}