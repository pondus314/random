#include <bits/stdc++.h>
using namespace std;

vector<int> strom;

void build(int n, int sir) {
    int size = 1;
    while(size < n) {
        size*=2;
    }
    size*=2;
    for(int i = 0; i < size/2; i++) {
        strom.push_back(-1);
    }
    for(int i = 0; i < size/2; i++) {
        if (i >=n) {
            strom.push_back(-1);
        } else {
            strom.push_back(sir);
        }
    }
    for(int i = size/2-1; i > 0; i--) {
        strom[i] = max(strom[i*2], strom[i*2+1]);
    }
}

void update(int index) {
    int old = strom[index];
    strom[index] = max(strom[index*2], strom[index*2+1]);
    if (strom[index]!=old && index > 1) {
        update(index/2);
    }
}

int zisti(int index, int k) {
    // cout<<index<<"  "<<k<<"\n";
    int lsyn, rsyn;
    if (strom[index]>=k) {
        if (index >=strom.size()/2) {
            return(index-strom.size()/2);
        }else {
            lsyn = zisti(index*2,k);
            if (lsyn==-2) {
                rsyn = zisti(index*2+1,k);
                if (rsyn==-2) {
                    return(-2);
                } else {
                    return(rsyn);
                }
            } else {
                return(lsyn);
            }
        }
    } else {
        return(-2);
    }



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, q, x, ans;
    cin>>h>>w>>q;
    if (h > q) {
        h = q;
    }

    build(h, w);

    for (int i = 0; i < q; i++) {
        cin>>x;
        ans = zisti(1,x);
        cout<<ans+1<<"\n";
        if (ans != -2) {
            strom[ans+strom.size()/2]-=x;
            update((ans+strom.size()/2)/2);
        }
    }
}
