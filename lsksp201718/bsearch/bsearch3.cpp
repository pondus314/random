#include<bits/stdc++.h>
using namespace std;

vector<int> polo;

bool check(int ind, int num) {
    if (polo[ind]>=num) {
        return(true);
    }
    return(false);
}

bool bsearch(int lo, int hi, int num){
    while (lo != hi) {
        int mid = (lo+hi)/2;
        if (check(mid, num)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if (polo[lo]==num) {
        return(true);
    } else {
        return(false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, q, d;
    bool pl, mi;
    cin>>n;
    d = 0;
    for(int i = 0; i < n; i++) {
        cin>>x;
        polo.push_back(x);
        if (not d and x > 0) {
            d = i;
        }
    }
    cin>>q;
    for(int i = 0; i < q; i++) {
        cin>>x;
        pl = bsearch(d, n, x);
        mi = bsearch(0, d-1, -x);
        if (pl || mi) {
            cout<<"A\n";
        } else {
            cout<<"N\n";
        }
    }
}
