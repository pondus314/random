#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > mergesortpairs(vector<pair<int, int> > polo) {
    vector<pair<int, int> > polo1, polo2, novepolo;
    for (int i = 0; i < polo.size(); i++) {
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

    int i = 0;
    int j = 0;
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

int main()  {
    int x, y, z;
    vector<pair<int, int> > pole;
    cin>>x;
    for(int i = 0; i < x; i++) {
        cin>>y>>z;
        pole.push_back(make_pair(y,z));
    }
    pole = mergesortpairs(pole);
    for (int i = 0; i < x; i++) {
        cout<<pole[i].first<<" "<<pole[i].second<<endl;
    }
}
