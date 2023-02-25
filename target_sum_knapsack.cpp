/**
* author: asif_102
* created: 2023-02-25 19:04:29
**/
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "DEBUG/debug.h"
#else
#define debug(x...) 42
#endif

bool targetSum(vector<int>&v, int idx, int k, int sum){
    if(sum == k and idx == v.size()){
        return true;
    }
    if(idx == v.size()){
        return false;
    }
    return targetSum(v, idx + 1, k, sum + v[idx]) or targetSum(v, idx + 1, k, sum - v[idx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &it: v){
        cin >> it;
    }
    if(targetSum(v, 1, k, v[0])){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
