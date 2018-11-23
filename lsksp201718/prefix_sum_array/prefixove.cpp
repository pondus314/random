#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, q;
    vector<int> prefixove;
    cin>>n;
    for (int i =0; i < n; i++) {
        cin>>y;
        if (i==0) {
            prefixove.push_back(0);
        }
        prefixove.push_back(prefixove[i]+y);
    }
    cin>>q;
    for (int i = 0; i < q; i++) {
        cin>>x>>y;
        cout<<prefixove[y]-prefixove[x-1]<<endl;
    }
}
