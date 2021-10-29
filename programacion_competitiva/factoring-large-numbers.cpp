#include <bits/stdc++.h>
using namespace std;
using llint = long long int;

map<llint, llint> previous_min_factor;

void getFactorsFromMap(llint n){
    if(n <= 2) return;
    llint newVal = previous_min_factor.find(n)->second;
    if(n/newVal == 1){
        cout << "   " << n << endl;
        return;
    }
    cout << "   " << n/newVal << endl;
    return getFactorsFromMap(newVal);
}

void getFactorsMoreEfficently(llint n, llint previous_prime){
    if(n == 1) return;
    if(previous_min_factor.find(n) != previous_min_factor.end()){
        getFactorsFromMap(n);
        return;
    }
    for(llint i = previous_prime; i < n; i+=previous_prime-1){
        if(n%i == 0){
            previous_min_factor.insert({n, n/i});
            // cout<<"["<<n<<"]="<<n/i<<endl;
            cout<<"    "<<i<<endl;
            return getFactorsMoreEfficently(n/i, i);
        }
    }
    cout << "    " << n  << endl;
    // cout<<"["<<n<<"]="<<n<<endl;
    previous_min_factor.insert({n, n});
}



int main(){
    llint current_number;
    while(true){
        llint initial = 1;
        cin >> current_number;
        if(current_number < 0) return 0;
        getFactorsMoreEfficently(current_number, 2);
        // getFactorsFromMap(current_number);
        cout<<endl;
    }
    // getFactorsMoreEfficently(12745267386521023, 1);
    return 0;
}