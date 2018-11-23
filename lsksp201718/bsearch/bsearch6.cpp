#include<bits/stdc++.h>
#include<climits>
using namespace std;

bool check(int ind, int num) {
    int sum = 0;
    for (int i = 5; i <= ind; i*=5) {
        sum+= ind/i;
    }
    // cout<<ind<<" "<<sum<<"\n";
    if (sum < num) {
        return(false);
    }
    return(true);
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
    return(lo);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    cout<<bsearch(0,INT_MAX, k)<<"\n";
}
