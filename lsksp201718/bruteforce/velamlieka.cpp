#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, x, vol, temp, ans = 2100000000000;
    vector<long long> vols;
    cin>>vol>>n;
    for(int i = 0; i < n; i++) {
        cin>>x;
        vols.push_back(x);
    }
    for(int i = 0; i < 1 << n; i++) {
        temp = 0;
        for(int j = 0; j < n; j++) {
            if(i & 1<<j) {
                temp+=vols[j];
            }
        }
        // cout<<i<<" "<<temp<<"\n";
        if (temp>=vol) {
            ans = min(ans,temp);
        }
    }
    cout<<ans<<"\n";
}
