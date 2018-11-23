#include<bits/stdc++.h>
using namespace std;

vector<int> polo;

bool check(int ind, int num) {
    if (ind == 0) {
        return(true);
    }
    int sum = 0;
    for (int i = 0; i < polo.size(); i++) {
        sum+=polo[i]/ind;
    }
    // cout<<ind<<" "<<sum<<" "<<num<<"\n";
    if (sum>=num) {
        return(true);
    }
    return(false);
}

int bsearch(int lo, int hi, int num){
    while (lo != hi) {
        int mid = (lo+hi)/2+1;
        if (not check(mid, num)) {
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    return(lo);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, k;
    cin>>n>>k;
    for(int i = 0; i < k; i++) {
        cin>>x;
        polo.push_back(x);
    }
    cout<<bsearch(0, n, n)<<"\n";

}
