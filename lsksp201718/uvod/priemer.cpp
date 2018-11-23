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

    for (int i = a-1; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            cout<<cisla[j]+cisla[j+1];
            cisla[j] = cisla[j]+cisla[j+1];
            if (j < i-1) {
                cout<<" ";
            } else cout<<"\n";
        }
    }
    cout<<ans<<"\n";
}
