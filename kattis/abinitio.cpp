#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void printAM(vector<vector<int>> &AM, int edge, bool transpose) {
    cout << " ";
    for (int i = 0; i<AM.size(); i++) cout << " " << i;
    cout << endl;
    for (int i = 0; i<AM.size(); i++) {
        cout << i;
        for (int j=0; j<AM.size(); j++) {
            int e = transpose ? AM[j][i] : AM[i][j];
            e = e == edge;
            cout << " " << e;
        }
        cout << endl;
    }
}

void getEdgeList(int e, vector<ii> &EL) {
    while (e--) {
        int a,b; cin>>a>>b;
        EL.push_back({a,b});
    }
}

void getAdjacencyMatrix(vector<ii> &EL, vector<vector<int>> &AM, int v) {
    AM = vector<vector<int>>(v, vector<int>(v, 0));
    for (auto edge : EL) {
        AM[edge.first][edge.second] = 1;
    }
}

void deleteAllEdges(vector<vector<int>> &AM, int x, int edge) {
    fill(AM[x].begin(), AM[x].end(), !edge);
    for (int u=0; u<AM.size(); u++) {
        AM[u][x] = !edge;
    }
}

void flipEdge(vector<vector<int>> &AM, int u, int v, bool transpose) {
    int s = transpose ? v : u;
    int t = transpose ? u : v;

    AM[s][t] = !AM[s][t];
}

void addNewVertex(vector<vector<int>> &AM, int edge) {
    int v = AM.size();
    for (int i=0; i<v; i++) {
        AM[i].push_back(!edge);
    }
    AM.push_back(vector<int>(v+1, !edge));
}

void handleQueries(vector<vector<int>> &AM, int &edge, bool &transpose, int q) {
    while (q--) {
        int command; cin >> command;
        int x,y;
        switch (command) {
            case 1: // add a new vertex lableled V to G, size(G)++
                addNewVertex(AM, edge);
                break;
            case 2: // add a new edge X->Y to G, guaranteed does not exists (flip edge)
            case 4: // remove edge X->Y to G, guaranteed does exists (flip edge)
                cin>>x>>y;
                flipEdge(AM, x, y, transpose);
                break;
            case 3: // delete all incoming and outgoing edges of X
                cin >> x;
                deleteAllEdges(AM, x, edge);
                break;
            case 5: // replace G with its transpose G'
                transpose = !transpose;
                break;
            case 6: // replace G with its complement
                edge = !edge;
                break;
        }
    }
}

void getAdjacencyList(vector<vector<int>> &AM, int &edge, bool &transpose, vector<vector<int>> &AL) {
    AL = vector<vector<int>>(AM.size(), vector<int>());
    for (int i=0; i<AM.size(); i++) {
        for (int j=0; j<AM.size(); j++) {
            if (i == j || AM[i][j] != edge) continue;
            if (transpose) {
                AL[j].push_back(i);
            } else {
                AL[i].push_back(j);
            }
        }
    }
}

vector<ll> getHashedExponents(int base, int length, ll modulo) {
    vector<ll> res(length, 0);
    res[0] = 1;
    for (int i=1; i<length; i++) {
        res[i] = (res[i-1] * base) % modulo;
    }
    return res;
}

ll getHash(vector<int> &vertex, vector<ll> &hashedExponents, ll modulo) {
    ll hash = 0;
    for (int i=0; i<vertex.size(); i++) {
        ll v = (hashedExponents[i] * vertex[i]) % modulo;
        hash = (hash + v) % modulo;
    }
    return hash;
}

void printOutput(vector<vector<int>> &AL) {
    printf("%ld\n", AL.size());
    ll modulo = pow(10, 9) + 7;
    vector<ll> hashedExponents = getHashedExponents(7, AL.size(), modulo);
    for (int i=0; i<AL.size(); i++) {
        int d = AL[i].size();
        ll h = getHash(AL[i], hashedExponents, modulo);
        printf("%d %lld\n", d, h);
    }
}

int main() {
    int v,e,q; cin>>v>>e>>q;
    vector<ii> EL; 
    vector<vector<int>> AM, AL;
    int edge = 1; // value in AM representing an edge
    bool transpose = false; // whether or not the graph is transposed;

    getEdgeList(e, EL);
    getAdjacencyMatrix(EL, AM, v);
    handleQueries(AM, edge, transpose, q);
    getAdjacencyList(AM, edge, transpose, AL);
    printOutput(AL);
}
