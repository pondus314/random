#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> age;
vector<int> size;

int getprogenitor(int me) {
    if (parent[me] == me) {
        return(me);
    }
    parent[me] = getprogenitor(parent[me]);
    return(parent[me]);
}

int pocet(int me1, int me2) {
    return (size[getprogenitor(me1)]*size[getprogenitor(me2)]);
}

bool isfamily(int me1, int me2) {
    return (getprogenitor(me1)==getprogenitor(me2));
}

void adopt(int adopter, int adoptee) {
    if (age[getprogenitor(adopter)] < age[getprogenitor(adoptee)]) {
        size[getprogenitor(adoptee)]+=size[getprogenitor(adopter)];
        parent[getprogenitor(adopter)] = getprogenitor(adoptee);
    } else {
        size[getprogenitor(adopter)]+=size[getprogenitor(adoptee)];
        parent[getprogenitor(adoptee)] = getprogenitor(adopter);
        if (age[getprogenitor(adopter)] == age[getprogenitor(adoptee)]) {
            age[getprogenitor(adopter)]++;
        }
    }
}

int main() {
    int x, y, n, q, maxmesto;
    string mesto1, mesto2;
    unordered_map<string, int> mesta;
    cin>>q;
    maxmesto = -1;
    // for (int i =0; i < n; i++) {
    //     parent.push_back(i);
    //     age.push_back(0);
    //     size.push_back(1);
    // }
    for (int i =0; i < q; i++) {
        cin>>mesto1>>mesto2;
        if (mesta.find(mesto1) == mesta.end() ) {
            maxmesto++;
            mesta[mesto1] = maxmesto;
            parent.push_back(maxmesto);
            age.push_back(0);
            size.push_back(1);
            x = maxmesto;
        }   else {
            x = mesta[mesto1];
        }
        if (mesta.find(mesto2) == mesta.end()) {
            maxmesto++;
            mesta[mesto2] = maxmesto;
            parent.push_back(maxmesto);
            age.push_back(0);
            size.push_back(1);
            y = maxmesto;
        }   else {
            y = mesta[mesto2];
        }
        // cout<<x<<" "<<y<<endl;
        if(not isfamily(x, y)) {
            cout<<(size[getprogenitor(x)])*(size[getprogenitor(y)])<<endl;
            adopt(x, y);
        } else {
            cout<<0<<endl;
        }
        // cout<<size[getprogenitor(x)]<<" "<<size[getprogenitor(y)]<<endl;

        // if (typ=="odhrab") {
        // adopt(x,y);
        // } else if (typ=="cesta") {
            // if(isfamily(x,y)) {
                // cout<<"ANO"<<endl;
            // } else {
                // cout<<"NIE"<<endl;
            // }
        // }
    }
}
