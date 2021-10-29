#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n; 
    long long p; 
    long long q; 
    long long r; 
    long long num[100];
    long long m1 = -1000; 
    long long m2 = -1000;
    long long m3 = -1000; 
    scanf("%d%lld%lld%lld", &n, &p, &q, &r);
    for(int i = 0; i<n; i++){
        scanf("%lld", &num[i]);
        m1 = max(m1, p*num[i]);
        m2 = max(m2, m1+q*num[i]);
        m3 = max(m3, m2+r*num[i]);
    }
    printf("%lld\n", m3);
	return 0;
}