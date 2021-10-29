#include <bits/stdc++.h>
using namespace std;
using v_char = vector<char>;
using vv_char = vector<v_char>;

int getPrice(vv_char square, int x, int y){
    int price = 0;
    // Focus on prices!!
    bool areBigTilesCheaper = 2*x>y;
    for(v_char &square_row : square){
        int i = 0;
        while(i < square_row.size()){
            int o_i = i;
            if(areBigTilesCheaper && i<square_row.size() -1 && square_row[i] == '.' && square_row[i+1] == '.'){
                price+=y;
                i+=2;
            } else {
                if(square_row[i] == '.') price+=x;
                i++;
            }
        }
        // cout<<endl;
    }    
    return price;
}

int main(){
    int t;
    cin >> t;
    // iterate t times
    for(int i = 0; i < t; i++){
        // Receive values in first row
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vv_char square(n, v_char(m));
        // Pass values to square
        for(v_char &square_row : square){
            string string_row;
            cin >> string_row;
            for(int j = 0; j<square_row.size(); j++){
                square_row[j] = string_row[j];
            }
        }
        // Call function
        int price = getPrice(square, x, y);
        cout << price << "\n";
    }
    return 0;
}


/* 
int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vv_char square(n, v_char(m));
    for(v_char &square_row : square){
        for(char &square_tile : square_row ){
            cin >> square_tile;
        }
    }
    return 0;
} */