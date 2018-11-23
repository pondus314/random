#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > hrany, spatne;
vector<bool> prejdene;
vector<int> listy;
vector<vector<int> > usortene;
vector<int> dpt;

int hlbka(int index, int depth = 0) {
    if (dpt[index]!= -1) {
        return(dpt[index]);
    }
    if (depth > 30000) {
        return(-1);
    }
    int ans = 1;
    for(unsigned int i = 0; i < hrany[index].size(); i++) {
        int below = hlbka(hrany[index][i], depth+1);
        if (below==-1) {
            return(-1);
        }
        ans = max(ans, below+1);
    }
    dpt[index] = ans;
    return(ans);
}

int main() {
    int n, m, x, y;
    cin>>n>>m;
    hrany.resize(n);
    spatne.resize(n);
    dpt.resize(n, -1);
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        x--;
        y--;
        hrany[x].push_back(y);
        spatne[y].push_back(x);
    }

    usortene.push_back(vector<int> ());

    for(int i = 0; i < n; i++) {
        if (hrany[i].size()==0) {
            listy.push_back(i);
            dpt[i] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        if(hlbka(i)==-1) {
            cout<<-1<<"\n";
            return(0);
        }
        // cout<<i<<" "<<dpt[i]<<"\n";
        while(dpt[i] >= usortene.size()) {
            usortene.push_back(vector<int> ());
        }
        usortene[dpt[i]].push_back(i);
    }

    for(int i = usortene.size()-1; i > -1; i--) {
        for(int j = 0; j < usortene[i].size(); j++) {
            cout<<usortene[i][j]+1;
            if (j < usortene[i].size()-1 || i > 0) {
                cout<<" ";
            } else {
                cout<<"\n";
            }
        }
    }

}
