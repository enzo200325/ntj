#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1e5; 
typedef pair<int,int> ii;

vector<vector<ii>> Adj(MAX); 
int D[MAX]; 
priority_queue<ii, vector<ii>, greater<ii>> pq; 

int main() {
    for (int i = 0; i < MAX; i++) {
        D[i] = INT_MAX; 
    } 

    int begin_from = 1;

    pq.push({0, begin_from}); 
    while(!pq.empty()) {
        int u = pq.top().second; 
        int w = pq.top().first; 
        pq.pop(); 
        if (w < D[u]) {
            D[u] = w;
            for (int i = 0; i < Adj[u].size(); i++) {
                pq.push({Adj[u][i].first + w, Adj[u][i].second}); 
            } 
        } 
    } 
} 
