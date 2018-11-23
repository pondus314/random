#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, ans = 0;
    cin>>a;
    vector<int> hor, vert, diag1, diag2;
    vector<int> b(2,0);
    for (int i = 0; i < a; i++) {
        cin>>b[0]>>b[1];
        hor.push_back(b[0]);
        vert.push_back(b[1]);
        diag1.push_back(b[0]+b[1]);
        diag2.push_back(b[0]-b[1]);
    }
    sort(hor.begin(), hor.end());
    sort(vert.begin(), vert.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());
    for (int i = 1; i < a; i++) {
        if (hor[i]==hor[i-1])
            ans+=1;
        if (vert[i]==vert[i-1])
            ans+=1;
        if (diag1[i]==diag1[i-1])
            ans+=1;
        if (diag2[i]==diag2[i-1])
            ans+=1;
    }
    cout<<ans<<"\n";

}
