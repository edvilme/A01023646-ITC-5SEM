#include <bits/stdc++.h>
using namespace std;
// This assumes all ints are possitive
void countIndices(vector<int> A, int l, int r){
    int count = 0;
    int maxSize = A.size();
    for(size_t i = 0; i < maxSize-1; i++){
        // If element in A[i] is bigger than range, this is not a valid i
        if(A[i] > r) continue;
        for(size_t j = i+1; j < maxSize; j++){
            // If element in A[j] is bigger than range, this is not a valid j
            if(A[j] > r) continue;
            int sum = A[i]+A[j];
            if(l<=sum&&sum<=r) count++;
        }
    }
    cout<<count<<"\n";
}

// This assumes ordering is efficient enough
void countIndicesOrdered(vector<int> A, int l, int r){
    sort(A.begin(), A.end());
    int count = 0;
    int maxSize = A.size();
    int i = 0;
    int j = 0;
    while(i < A.size()-1 && j < A.size()){
        if(A[i] > r) break;
        if(A[])
    }

    for(size_t i = 0; i < maxSize-1; i++){
        if(A[i]>r) break;
        // if(A[i]<l) continue;
        for(size_t j = i+1; j < maxSize; j++){
            if(A[j]>r) break;
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
        countIndicesOrdered(A, l, r);
    }
    return 0;
}