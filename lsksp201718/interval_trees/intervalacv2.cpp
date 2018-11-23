#include <bits/stdc++.h>
using namespace std;

struct vrchol {
    int lavy, pravy;
    int mini, maxi;
};

vector<vrchol> strom;

void build(int n, vector<pair<int, int> > polo) {
    int size = 1;
    while(size < n) {
        size*=2;
    }
    size*=2;
    for(int i = 0; i < size/2; i++) {
        strom.push_back({-1,-1,1000123456,-1000123456});
    }
    for(int i = 0; i < size/2; i++) {
        if (i >=n) {
            strom.push_back({size/2+i, size/2+i, 1000123456,-1000123456});
        } else {
            strom.push_back({size/2+i, size/2+i, polo[i].first, polo[i].second});
        }
    }
    for(int i = size/2-1; i > 0; i--) {
        strom[i].maxi = max(strom[i*2].maxi, strom[i*2+1].maxi);
        strom[i].mini = min(strom[i*2].mini, strom[i*2+1].mini);
        strom[i].lavy = strom[i*2].lavy;
        strom[i].pravy = strom[i*2+1].pravy;
    }
}

void update(int index) {
    strom[index].maxi = max(strom[index*2].maxi, strom[index*2+1].maxi);
    strom[index].mini = min(strom[index*2].mini, strom[index*2+1].mini);
    if (index > 1) {
        update(index/2);
    }
}

pair<int, int> zisti(int index, int left, int right) {
    // cout<<index<<"  "<<left<<"  "<<right<<"\n";
    pair<int, int> lsyn, rsyn;
    if (left > strom[index].pravy || right < strom[index].lavy) {
        return(make_pair(1000123456,-1000123456));
    }
    if(left < strom[index].lavy) {
        left = strom[index].lavy;
    }
    if (right > strom[index].pravy) {
        right = strom[index].pravy;
    }
    if (left==strom[index].lavy && right==strom[index].pravy) {
        return(make_pair(strom[index].mini, strom[index].maxi));
    } else {
        lsyn = zisti(index*2,left, right);
        rsyn = zisti(index*2+1,left, right);
        return(make_pair(min(lsyn.first ,rsyn.first), max(lsyn.second, rsyn.second) ));
    }

}

int main() {
    int t, n, m, a, b;
    vector<pair<int, int>> pole;
    pair<int, int> ans;
    cin>>t;
    for(int i = 0; i < t; i++) {
        strom.resize(0);
        pole.resize(0);
        cin>>n;
        for(int j = 0; j < n; j++) {
            cin>>a;
            pole.push_back(make_pair(a,a));
        }
        build(n, pole);
        cin>>m;
        for (int j = 0; j < m; j++) {
            cin>>a>>b;
            ans = zisti(1, strom.size()/2+a-1, strom.size()/2+b-1);
            cout<<ans.first<<" "<<ans.second<<"\n";
        }
    }
}
