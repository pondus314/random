#include<bits/stdc++.h>
using namespace std;

vector<long long> polo;
vector<bool> presli;

bool check(long long ind, long long num) {
    long long used = 0;
    for(long long i = 0; i < polo.size(); i++) {
        if (polo[i] <= ind) {
            continue;
        } else {
            if (num==1) {
                return(false);
            }
            // cout<<(polo[i]-ind+num-2)<<" "<<(num-1)<<"\n";
            used+=(polo[i]-ind+num-2)/(num-1);
        }
    }
    // cout<<ind<<" "<<used<<"  "<<num<<"\n";
    if (used > ind) {
        return(false);
    }
    return(true);
}

long long bsearch(long long lo, long long hi, long long num){
    while (lo != hi) {
        long long mid = (lo+hi)/2;
        if (check(mid, num)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return(lo);
}

int main() {
    long long n, x, r, maxi = 0;
    cin>>n;
    for(long long i = 0; i < n; i++) {
        cin>>x;
        polo.push_back(x);
        maxi = max(maxi, x);
    }
    cin>>r;
    cout<<bsearch(0,maxi, r)<<"\n";
}
