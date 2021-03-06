#include<bits/stdc++.h>
using namespace std;

vector<int> otec;
vector<int> hlbka;
vector<vector<int> > synovia;
vector<vector<int> > skoky;
vector<int> distabs, distrel;

void hlbky(int dpt = 0, int v = 0, int distt = 0) {
    hlbka[v] = dpt;
    distabs[v] = distt+distrel[v];
    for (int i = 0; i < synovia[v].size(); i++) {
        hlbky(dpt+1, synovia[v][i], distabs[v]);
    }
}

void skokan(int k) {
    for (int i = 0; 1 << i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (hlbka[j]>= (1 << i)) {
                if (i == 0)  {
                    skoky[j].push_back(otec[j]);
                } else {
                    skoky[j].push_back(skoky[skoky[j][i-1]][i-1]);
                }
            }
        }
    }
}

int lca(int v1, int v2) {
    int hi, curr1, curr2;
    for (int i = 0; 1 << i <= hlbka[v1]; i++) {
        if (skoky[v1][i]==skoky[v2][i]) {
            if (i==0) {
                return(skoky[v1][i]);
            }
            hi = i-1;
            curr1 = skoky[v1][i-1];
            curr2 = skoky[v2][i-1];
            break;
        }
        if (1<<(i+1) > hlbka[v1]) {
            return(lca(skoky[v1][i],skoky[v2][i]));
        }
    }
    while (hi > 0) {
        if (skoky[curr1][hi-1]==skoky[curr2][hi-1]) {
            hi--;
        } else {
            curr1 = skoky[curr1][hi-1];
            curr2 = skoky[curr2][hi-1];
            hi--;
        }
    }
    return(skoky[curr1][hi]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, x, y, dptdif, k, anc, yn, xn;
    string typ;
    cin>>n;
    synovia.resize(n);
    hlbka.resize(n,0);
    skoky.resize(n);
    distabs.resize(n,0);

    distrel.push_back(0);
    otec.push_back(-1);
    for (int i = 0; i < n-1; i++) {
        cin>>x>>y;
        otec.push_back(x);
        synovia[x].push_back(i+1);
        distrel.push_back(y);
    }
    hlbky();
    skokan(n);

    cin>>q;
    for (int i = 0; i < q; i++) {
        cin>>typ>>x>>y;
        xn = x;
        yn = y;
        if (hlbka[xn] < hlbka[yn]) {
            swap(xn,yn);
        }
        dptdif = hlbka[xn]-hlbka[yn];
        for (int i = 0; 1<< i <= dptdif; i++) {
            if ((1 << i) & dptdif) {
                xn = skoky[xn][i];
            }
        }
        if (xn!=yn) {
            anc = lca(xn,yn);
        } else {
            anc = xn;
        }
        if (typ =="DST") {
            cout<<distabs[x]+distabs[y]-2*distabs[anc]<<"\n";
        } else if (typ == "KTH") {
            cin>>k;
            if (hlbka[x]-hlbka[anc] >= k) {
                xn = x;
                for (int i = 0; 1<< i <= k; i++) {
                    if ((1 << i) & k) {
                        xn = skoky[xn][i];
                    }
                }
                cout<<xn<<"\n";
            } else {
                yn = y;
                k = hlbka[x]+hlbka[y]-2*hlbka[anc] - k;
                for (int i = 0; 1<< i <= k; i++) {
                    if ((1 << i) & k) {
                        yn = skoky[yn][i];
                    }
                }
                cout<<yn<<"\n";
            }
        }
    }

}
