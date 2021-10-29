#include <bits/stdc++.h>
using namespace std;

int countMovements(int smallest_index, int biggest_index, int size){
    int count = 0;
    int middle = size/2;
    // If both are accessed from the left
    if(smallest_index < middle && biggest_index < middle){
        return max(smallest_index, biggest_index);
    }
    // If both are accessed from the right
    if(smallest_index >= middle && biggest_index >= middle){
        return max(size - smallest_index, size - biggest_index);
    }
    return 0;
    // return max(smallest_index, biggest_index) + max(size - smallest_index, size - biggest_index);
    // If one is from the right and the other is from the left
}

int countMovements(vector<int> stones){
    int count = 0;
    // Encontrar índices de piedra más grande y piedra más pequeña (i, j)
    vector<int>::iterator smallest_element = min_element(stones.begin(), stones.end());
    vector<int>::iterator biggest_element = max_element(stones.begin(), stones.end());

    int smallest_element_index = smallest_element - stones.begin() + 1;
    int biggest_element_index = biggest_element - stones.begin() + 1;

    cout << "Smallest element is ["<<smallest_element_index<<"] = "<<*smallest_element<<endl;
    cout << "Biggest element is ["<<biggest_element_index<<"] = "<<*biggest_element<<endl;


    return countMovements(smallest_element_index, biggest_element_index, stones.size());
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> stones(n);
        for(int &item : stones) cin >> item;
        cout << countMovements(stones) << endl;
    }

    // vector<int> test{1, 5, 4, 3, 2};

    // cout << countMovements(test) << endl;

    return 0;
}