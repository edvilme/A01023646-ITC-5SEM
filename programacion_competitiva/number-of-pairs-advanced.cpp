#include <bits/stdc++.h>
using namespace std;



void countIndicesWithSumInRange(vector<int> &A, int &l, int &r){
    sort(A.begin(), A.end());
    int count = 0;
    int maxSize = A.size();
    for(int i = 0; A[i]<r && i < maxSize-1; i++){
        for(int j = i+1; A[j]<r && j < maxSize; j++){
            int sum = A[i] + A[j];
            if(l<=sum&&sum<=r) count++;
        }
    }
    cout<<count<<"\n";
}

int main(){
    int t;
    cin >> t;
    // Repeat for each test
    for(int i = 0; i < t; i++){
        // Receive params
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> A(n);
        for(int &elem : A) cin >> elem;
        countIndicesWithSumInRange(A, l, r);
    }
    return 0;
}