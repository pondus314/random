#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, q, x;
    cin>>n>>k>>q;
    vector<int> kvety(n);
    deque<int> deka;
    vector<int> riesenia(n);
    for(int i = 0; i < n; i++) {
        cin>>kvety[i];
        if (i >= k) {
            if (kvety[i-k]==deka.front()) {
                deka.pop_front();
            }
        }
        if (deka.empty()) {
            deka.push_back(kvety[i]);
        } else if (kvety[i] < deka.front()) {
            deka.erase(deka.begin(),deka.end());
            deka.push_back(kvety[i]);
        } else if (kvety[i] > deka.front()) {
            deka.push_back(kvety[i]);
        }
        if (i >= k-1) {
            riesenia[i-k+1] = deka.front();
            // cout<<deka.front()<<endl;
        }
    }
    for(int i = 0; i < q; i++) {
        cin>>x;
        cout<<riesenia[x-1]<<"\n";
    }
}
