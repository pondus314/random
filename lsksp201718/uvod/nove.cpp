#include<bits/stdc++.h>
using namespace std;

 int main() {
    int a, b, c;
    vector<vector<int> > cisla;
    cin>>a;
    b = a;
    cisla.resize(a);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin>>c;
            cisla[i].push_back(c);
        }
    }

    for (int i = a; i > 0; i--) {
        for (int j = 0; j < b; j++) {
            cout<<cisla[i][j];
            if (j < b-1) {
                cout<<" ";
            } else cout<<endl;
        }
    }

}
