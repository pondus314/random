#include<bits/stdc++.h>
using namespace std;

 int main() {
    int a, b, c, ans =0;
    vector<int> cisla;
    cin>>a;
    for (int i = 0; i < a; i++) {
        cin>>c;
        cisla.push_back(c);
    }
    cin>>b;
    for(int i = 0; i < a; i++) {
        if (cisla[i] < b) ans+=cisla[i];

    }
    cout<<ans<<"\n";
}
