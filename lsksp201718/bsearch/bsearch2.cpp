#include<bits/stdc++.h>
using namespace std;

vector<int> polo;

bool check(int ind, int num) {
    int sum = 0;
    for (int i = 0; i < polo.size(); i++) {
        sum+=min(ind, polo[i]);
    }
    if (sum < num) {
        return(false);
    } else {
        return(true);
    }
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
    int n, x, suma, p, maxi;
    suma = 0;
    maxi = 0;
    cin>>n>>p;
    for(int i = 0; i < n; i++) {
        cin>>x;
        polo.push_back(x);
        suma+=x;
        maxi = max(x, maxi);
    }
    if (suma < p) {
        cout<<"Nic nedostanete\n";
        return(0);
    }
    cout<<bsearch(0,maxi, p)<<"\n";

}
