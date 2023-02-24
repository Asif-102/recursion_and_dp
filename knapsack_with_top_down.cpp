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
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 101; j++){
            if(i == 0 or j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(v[i-1].first <= j){
                dp[i][j] = max(v[i-1].second + dp[i-1][j-v[i-1].first], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w];
    return 0;
}
