#include <iostream>
#include <ios>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;


void dfs(ll node, vector<vector<ll>>& graph, vector<bool>& visited, vector<ll>&component){
    visited[node] = true;
    component.push_back(node);
    for(ll neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(neighbor,graph,visited,component);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll cities,roads, city;
    cin >> cities >> roads;
    vector<vector<ll>> graph(cities + 1);
    for(int i = 0; i < roads; i++){
        ll u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited (cities +1, false);
    vector<ll> components;
    for(int i = 1; i <=cities; i++){
        if(!visited[i]){
            vector<ll>component;
            dfs(i,graph,visited,component);
            components.push_back(component[0]);
        }
    }

    ll k = components.size();
    cout << k - 1 << endl;
    for(int i = 0; i < k -1 ; i++){
        cout << components[i] << " " << components[i +1 ] <<  endl;
    }

    return 0;
}