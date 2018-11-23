#include<bits/stdc++.h>
using namespace std;

vector<int> polo;

bool check(int ind, int num) {
    if (polo[ind]>=num) {
        return(true);
    }
    return(false);
}

int bsearch(int lo, int hi, int num){
    while (lo != hi) {
        int mid = (lo+hi)/2;
        if (check(mid, num)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if (polo[lo]==num) {
        return(lo);
    } else {
        return(-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, q;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>x;
        polo.push_back(x);
    }
    cin>>q;
    for(int i = 0; i < q; i++) {
        cin>>x;
        cout<<bsearch(0, n-1, x)<<endl;
    }
}
