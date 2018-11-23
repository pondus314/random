#include<bits/stdc++.h>
using namespace std;

vector<int> otec;
vector<int> hlbka;
vector<vector<int> > synovia;
vector<vector<int> > skoky;
int n;

void hlbky(int dpt = 0, int v = 0) {
    hlbka[v] = dpt;
    for (int i = 0; i < synovia[v].size(); i++) {
        hlbky(dpt+1, synovia[v][i]);
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
        // cout<<"beee"<<endl;
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
            // cout<<"bdeeee"<<endl;
            return(lca(skoky[v1][i],skoky[v2][i]));
        }
    }
    // cout<<"baa"<<endl;
    while (hi > 0) {
        if (skoky[curr1][hi-1]==skoky[curr2][hi-1]) {
            hi--;
        } else {
            curr1 = skoky[curr1][hi-1];
            curr2 = skoky[curr2][hi-1];
            hi--;
        }
    }
    if (skoky[curr1][hi]!=skoky[curr2][hi]) {
        cout<<"waaaat "<<curr1<<" "<<curr2<<" "<<hi<<endl;
        return(-1);
    }
    return(skoky[curr1][hi]);
}

int main () {
    int n, q, x, y, dptdif;
    cin>>n;
    for (int i = 0; i < n; i++) {
        synovia.push_back(vector<int>());
        hlbka.push_back(0);
        skoky.push_back(vector<int>());
    }
    for (int i = 0; i < n; i++) {
        cin>>x;
        otec.push_back(x-1);
        synovia[x-1].push_back(i);
    }
    hlbky();
    skokan(n);

    // cout<<"otcovia"<<endl;
    // for (int i = 0; i < n; i++) {
    //     cout<<otec[i]<<" ";
    // }
    // cout<<endl<<"synovia"<<endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j =0; j < synovia[i].size(); j++) {
    //         cout<<synovia[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //
    // for (int i = 0; i < n; i++) {
    //     cout<<hlbka[i]<<" ";
    // }
    // cout<<endl<<"skoky"<<endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j =0; j < skoky[i].size(); j++) {
    //         cout<<skoky[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cin>>q;
    for (int i = 0; i < q; i++) {
        cin>>x>>y;
        x--;
        y--;
        if (hlbka[x] < hlbka[y]) {
            swap(x,y);
        }
        dptdif = hlbka[x]-hlbka[y];
        // cout<<dptdif<<endl;
        for (int i = 0; 1<< i <= dptdif; i++) {
            // cout<<x<<" "<<i<<" "<<dptdif<<endl;
            if ((1 << i) & dptdif) {
                x = skoky[x][i];
            }
            // cout<<x<<endl;
        }

        // if (hlbka[x]==hlbka[y]) {
        //     cout<<"yes"<<endl;
        // } else {
        //     cout<<"no"<<endl;
        // }
        if (x == y) {
            cout<<x+1<<endl;
        } else {
            cout<<lca(x,y)+1<<endl;
        }
    }

}
