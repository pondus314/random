#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, f, ans, suc;
    ans = -1;
    cin>>n>>f;
    vector<int> kravy(n);
    vector<int> priemery(n-f+1);
    for (int i = 0; i < n; i++) {
        cin>>kravy[i];
    }
    for (int i = 0; i < n-f+1; i++) {
        if (i==0) {
            suc = 0;
            for (int j = 0; j < f; j++) {
                suc+=kravy[j];
            }
        }
        else {
            suc-=kravy[i-1];
            suc+=kravy[i+f-1];
        }
        priemery[i] = suc;
        ans = max(suc, ans);
        // cout<<suc<<endl;
    }
    cout<<1000*ans/f<<endl;

}
