/**
* author: asif_102
* created: 2023-02-24 23:30:42
**/
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "DEBUG/debug.h"
#else
#define debug(x...) 42
#endif

int C(int n, int r){
    if(r > n){
        return 0;
    }
    if(r == 0 or n == r){
        return 1;
    }
    return C(n-1, r-1) + C(n-1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    cout << C(n, r);
    return 0;
}
