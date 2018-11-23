#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long r, c, a, b, d,q;
    vector<vector<long long> >prefixove;
    vector<vector<long long> >pole;
    cin>>r>>c;
    pole.resize(r);
    prefixove.resize(r);
    for (long long i = 0; i < r; i++) {
        for (long long j =0; j < c; j++) {
            cin>>a;
            pole[i].push_back(a);
            if (i==0) {
                if (j==0) {
                    prefixove[i].push_back(pole[i][j]);
                } else {
                    prefixove[i].push_back(pole[i][j]+prefixove[i][j-1]);
                }
            } else if (j == 0) {
                prefixove[i].push_back(pole[i][j]+prefixove[i-1][j]);
            } else {
                prefixove[i].push_back(pole[i][j]+prefixove[i-1][j]+prefixove[i][j-1]-prefixove[i-1][j-1]);
            }
        }
    }

    // for(long long i = 0; i < r; i++) {
    //     for(long long j =0; j < c; j++) {
    //         cout<<prefixove[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cin>>q;
    long long ans =0;
    for (long long i = 0; i < q; i++) {
        ans = 0;
        cin>>a>>b>>c>>d;
        ans+=prefixove[c-1][d-1];
        // cout<<ans<<"\n";
        if (a > 1) {
            ans-=prefixove[a-2][d-1];
        }
        // cout<<ans<<"\n";

        if (b > 1) {
            ans-=prefixove[c-1][b-2];
        }
        // cout<<ans<<"\n";

        if (a > 1 && b > 1) {
            ans+=prefixove[a-2][b-2];
        }
        cout<<ans<<"\n";
    }
}
