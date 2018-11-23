#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> age;

int getprogenitor(int me) {
    if (parent[me] == me) {
        return(me);
    }
    parent[me] = getprogenitor(parent[me]);
    return(parent[me]);
}

bool isfamily(int me1, int me2) {
    return (getprogenitor(me1)==getprogenitor(me2));
}

void adopt(int adopter, int adoptee) {
    if (age[getprogenitor(adopter)] < age[getprogenitor(adoptee)]) {
        parent[getprogenitor(adopter)] = getprogenitor(adoptee);
    } else {
        parent[getprogenitor(adoptee)] = getprogenitor(adopter);
        if (age[getprogenitor(adopter)] == age[getprogenitor(adoptee)]) {
            age[getprogenitor(adopter)]++;
        }
    }
}

int main() {
    int x, y, n, q;
    string typ;
    cin>>n>>q;
    for (int i =0; i < n; i++) {
        parent.push_back(i);
        age.push_back(0);
    }
    for (int i =0; i < q; i++) {
        cin>>typ>>x>>y;
        if (typ=="odhrab") {
            adopt(x,y);
        } else if (typ=="cesta") {
            if(isfamily(x,y)) {
                cout<<"ANO"<<endl;
            } else {
                cout<<"NIE"<<endl;
            }
        }
    }
}
