#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long> > mergesortpairs(vector<pair<long long, long long> > polo) {
    vector<pair<long long, long long> > polo1, polo2, novepolo;
    for (long long i = 0; i < polo.size(); i++) {
        if (i < polo.size()/2) {
            polo1.push_back(polo[i]);
        } else {
            polo2.push_back(polo[i]);
        }
    }
    if (polo1.size()>1){
        polo1 = mergesortpairs(polo1);
    }
    if (polo2.size()>1) {
        polo2 = mergesortpairs(polo2);
    }

    long long i = 0;
    long long j = 0;
    while(i+j < polo1.size()+polo2.size()) {
        if (i<polo1.size() and j < polo2.size()) {
            if (polo1[i] < polo2[j]) {
                novepolo.push_back(polo1[i]);
                i++;
            } else {
                novepolo.push_back(polo2[j]);
                j++;
            }
        } else if (i==polo1.size()) {
            novepolo.push_back(polo2[j]);
            j++;
        } else {
            novepolo.push_back(polo1[i]);
            i++;
        }
    }
    return(novepolo);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k, y, ans, count;
    ans = 0;
    vector<long long> prefixove;
    vector<pair<long long, long long> > pole;
    cin>>n>>k;
    for (long long i = 0; i < n; i++) {
        cin>>y;
        if (i==0) {
            prefixove.push_back(0);
        }
        prefixove.push_back(prefixove[i]+y);
        pole.push_back(make_pair(prefixove[i]+y, i));
    }
    // for (long long i = 0; i < n; i++) {
    //     cout<<pole[i].first<<" "<<pole[i].second<<"\n";
    // }
    pole.push_back(make_pair(0,-1));
    pole = mergesortpairs(pole);
    // sort(pole.begin(), pole.end());
    // for (long long i = 0; i < n+1; i++) {
    //     cout<<pole[i].first<<" "<<pole[i].second<<"\n";
    // }
    long long j = 0;
    count=0;
    for (long long i = 1; i < n+1; i++) {
        if (j ==i) {
            continue;
        }
        // cout<<i<<" "<<j<<" "<<count<<"\n";
        if (pole[i].first!=pole[j].first) {
            // cout<<"a"<<"\n";
            ans+=count;
            count = 0;
            if (j < i-1) {
                j++;
                i-=2;
            }   else {
                j = i;
            }
            // cout<<count<<"\n";
        } else if (pole[i].second-k > pole[j].second) {
            // cout<<"b"<<"\n";
            if (j < i-1) {
                j++;
                i-=2;
            }   else {
                j = i;
            }
            // cout<<count<<endl;
            ans+=count;
            count = 0;
        } else {
            // cout<<"c"<<"\n";
            count=i-j;
        }
    }
    ans+=(count*(count+1))/2;
    cout<<ans<<endl;
    // for (long long i = 0; i < k; i++) {
    //     if (prefixove[i+1]==0) {
    //         ans++;
    //     }
    // }
    // cout<<ans<<endl;
    // cin>>q;
    // for (long long i = 0; i < q; i++) {
    //     cin>>x>>y;
    //     cout<<prefixove[y]-prefixove[x-1]<<endl;
    // }
}
