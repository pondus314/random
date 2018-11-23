#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin>>n;
    vector<vector<int> > hrany(n);
    for(int i = 0; i < n-1; i++) {
        cin>>x>>y;
        hrany[x-1].push_back(y-1);
        hrany[y-1].push_back(x-1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (hrany[i].size()==1 && i!=0) {
            ans++;
        }
    }
    cout<<ans<<endl;
}
