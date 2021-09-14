#include <bits/stdc++.h>
using namespace std;

vector<int> getResults(vector<int> &M, vector<int> &P, int &k){
    vector<int> res;
    int M_index = 0;
    int P_index = 0;
    int maxSize = M.size()+P.size();
    for(int i = 0; i<maxSize; i++){
        if(M_index < M.size()){
            if(M[M_index] == 0){
                res.push_back(0);
                k++;
                M_index++;
            }
            else if(M[M_index] <= k){
                res.push_back(M[M_index]);
                M_index++;
            }
        }
        else if(P_index < P.size()){
            if(P[P_index] == 0){
                res.push_back(0);
                k++;
                P_index++;
            }
            else if(P[P_index] <= k){
                res.push_back(P[P_index]);
                P_index++;
            }
        }
        else return vector<int>(0);
    }
    return res;
}

int main(){
    // Read line with t test cases
    int t;
    cin >> t;
    // Iterate t times
    for(int i = 0; i < t; i++){
        // First line contains k, n, m
        int k, n, m;
        cin >> k >> n >> m;
        // Create vector 1
        vector<int> v1(n);
        for(int &item : v1) cin >> item;
        // Create vector 2
        vector<int> v2(m);
        for(int &item : v2) cin >> item;
        // Results
        vector<int> results = getResults(v2, v1, k);
        // Print
        if(results.size() == 0){
            cout << -1 << "\n";
        } else {
            for(int &item : results) cout << item << " ";
            cout << "\n";
        }
    }
    return 0;
}