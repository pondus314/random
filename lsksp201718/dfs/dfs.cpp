#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > hrany;
vector<int> dfsnum;
vector<int> dfsmin;
vector<bool> visited;
int num = 0;

void dfs (int v, int f = -1) {
    dfsnum[v] = num++;
    dfsmin[v] = dfsnum[v];
    visited[v] = true;
    for (int i = 0; i < hrany[v].size(); i++) {
        int w = hrany[v][i];
        if (w==f) {
            continue;
        } else if (visited[w]) {
            // cout<<v<<" "<<w<<" "<<f<<"\n";
            dfsmin[v] = min(dfsmin[v],dfsnum[w]);
        } else {
            dfs(w,v);
            dfsmin[v] = min(dfsmin[v], dfsmin[w]);
        }
    }
}

int main() {
    int n, m, x, y;
    cin>>n>>m;
    hrany.resize(n);
    dfsnum.resize(n,n+1);
    dfsmin.resize(n,n+1);
    visited.resize(n, false);
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        hrany[x].push_back(y);
        hrany[y].push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (hrany[i].size()==1) {
            ans++;
        }
    }
    cout<<ans<<endl;

    dfs(0);
    for(int i = 0; i < n; i++) {
        cout<<dfsnum[i]<<" "<<dfsmin[i]<<"\n";
    }
}
