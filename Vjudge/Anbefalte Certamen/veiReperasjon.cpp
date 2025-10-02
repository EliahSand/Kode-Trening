#include <iostream>
#include <vector>
#include <ios>
#include <algorithm>
typedef long long ll;
using namespace std;


struct Edge {
    ll u, v, weight;
};

bool compare(Edge a, Edge b){
    // er a MINDRE enn b
    return a.weight < b.weight;
}

int findParent(ll node, vector<ll>& parent){
    if(node != parent[node]){
        parent[node] = findParent(parent[node], parent); // kompresjon
    }
    return parent[node];
}

void unionNodes(int u, int v, vector<ll>& parent, vector<ll>& rank){
    ll pu = findParent(u,parent);
    ll pv = findParent(v,parent);
    if(rank[pu] > rank[pv]){
        parent[pv] = pu;
    } else if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    } else{
        parent[pu] = pv; 
        ++ rank[pv];
    }
}

ll kruskal(ll n, vector<Edge>& edges ){
    sort(edges.begin(),edges.end(), compare);
    vector<ll> parent(n + 1), rank(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
    }
    ll mstWeight = 0, edgeCount = 0;
    for (auto& edge : edges){
        if(findParent(edge.u, parent) != findParent(edge.v,parent)){
            mstWeight += edge.weight;
            unionNodes(edge.u, edge.v, parent, rank);
            edgeCount++;
            if(edgeCount == n -1 ){
                break;
            }
        }
    }

    // Sjekk om grafen var sammenhengende
    if (edgeCount < n - 1) {
        return -1; // Indikerer at MST ikke kan opprettes
    }

    return mstWeight;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,a,b,c;
    /*
    n = antall byer
    m = antall veier
    a = by
    b = by
    c = repareringskost*/
    cin >> n >> m;

    vector<Edge> veiNett;
    Edge vei;
    //fyll ut veinett
    for(int i = 0; i < m;i++){
        cin >> a >> b >> c;
        vei.u = a;
        vei.v = b;
        vei.weight = c;
        veiNett.push_back(vei);
    }// ferdig her

    ll ans = kruskal(n,veiNett);
    if (ans < 0 ){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}