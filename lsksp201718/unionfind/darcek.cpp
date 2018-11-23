#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> age;
vector<int> relwgt;

pair<int, int> getprogenitor(int me) {
    // cout<<"bdee"<<endl;
    if (parent[me] == me) {
        return(make_pair(me, 0));
    }
     pair <int, int> gotten = getprogenitor(parent[me]);
     parent[me] = gotten.first;
     relwgt[me] = gotten.second+relwgt[me];
    return(make_pair(parent[me], relwgt[me]));
}

bool isfamily(int me1, int me2) {
    return (getprogenitor(me1).first==getprogenitor(me2).first);
}

void adopt(int adopter, int adoptee, int wgtdif) {
    int age1, age2;
    if (age[getprogenitor(adopter).first] < age[getprogenitor(adoptee).first]) {
        // cout<<"mee"<<endl;
        age2 = relwgt[adopter];
        age1 = relwgt[adoptee];
        relwgt[adopter] = age1-age2-wgtdif;
        parent[getprogenitor(adopter).first] = getprogenitor(adoptee).first;

    } else {
        // cout<<"baa?"<<endl;
        age1 = relwgt[adopter];
        age2 = relwgt[adoptee];
        relwgt[adoptee] = age1-age2+wgtdif;
        // cout<<"bee?"<<endl;
        parent[getprogenitor(adoptee).first] = getprogenitor(adopter).first;
        // cout<<"blee"<<endl;
        if (age[getprogenitor(adopter).first] == age[getprogenitor(adoptee).first]) {
            age[getprogenitor(adopter).first]++;
        }
    }
    // cout<<"mnau"<<endl;
}

int main() {
    int x, y, z, n, q;
    string typ;
    cin>>n>>q;
    for (int i =0; i < n; i++) {
        parent.push_back(i);
        age.push_back(0);
        relwgt.push_back(0);
    }
    for (int i =0; i < q; i++) {
        cin>>typ>>x>>y;
        // cout<<i<<typ<<endl;
        if (typ=="!") {
            // cout<<"beer"<<endl;
            cin>>z;
            // cout<<x<<" "<<y<<" "<<z<<endl;
            adopt(x-1,y-1,z);
        } else if (typ=="?") {
            if(isfamily(x-1,y-1)) {
                cout<<getprogenitor(y-1).second-getprogenitor(x-1).second<<endl;
            } else {
                cout<<"UNKNOWN"<<endl;
            }
        }
        // for(int j = 0; j < n; j++) {
        //     cout<<parent[j]<<endl;
        // }
    }
}
