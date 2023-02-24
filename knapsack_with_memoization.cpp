/**
* author: asif_102
* created: 2023-02-25 01:32:32
**/
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "DEBUG/debug.h"
#else
#define debug(x...) 42
#endif

int dp[21][101];

int knapsack(vector<pair<int, int>>&v, int w, int sz){
    if(sz == 0 or w == 0){
        return 0;
    }
    if(dp[sz][w] != -1){
        return dp[sz][w];
    }
    if(v[sz-1].first <= w){
        return dp[sz][w] = max(v[sz-1].second + knapsack(v, w-v[sz-1].first, sz-1), knapsack(v, w, sz-1));
    }
    return dp[sz][w] = knapsack(v, w, sz-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int weight, value;
        cin >> weight >> value;
        v.push_back({weight, value});
    }
    memset(dp, -1, sizeof dp);
    cout << knapsack(v, w, n);
    return 0;
}
