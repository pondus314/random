#include<bits/stdc++.h>
using namespace std;

struct emh{
        int mini;
        int maxi;
        int sum;
};

vector<emh> strom;
int siz = 1;

void printemh(int num) {
    emh out = strom[num];
    cout<<out.mini<<" "<<out.maxi<<" "<<out.sum<<endl;
}

void construct(int n, vector<int> cisla) {
    while (siz<n) {
        siz = siz*2;
    }
    siz = siz *2;
    for(int i = 0; i < siz/2; i++) {
        strom.push_back({-1,-1,-1});
    }
    for (int i = 0; i < siz/2; i++) {
        if (i < n) {
            strom.push_back({cisla[i],cisla[i],cisla[i]});
        } else {
            strom.push_back({-1,-1,-1});
        }

    }
    for (int i = siz/2-1; i > -1; i--) {
        strom[i].mini = min(strom[i*2].mini, strom[i*2+1].mini);
        strom[i].maxi = max(strom[i*2].maxi, strom[i*2+1].maxi);
        strom[i].sum = strom[i*2].sum + strom[i*2+1].sum;
    }

}

void update(int ind) {
    while (ind>1) {
        ind = ind/2;
        strom[ind].mini = min(strom[ind*2].mini, strom[ind*2+1].mini);
        strom[ind].maxi = max(strom[ind*2].maxi, strom[ind*2+1].maxi);
        strom[ind].sum = strom[ind*2].sum + strom[ind*2+1].sum;
    }
}

bool checker(emh he) {
    if (he.sum == (he.maxi*(he.maxi+1)-he.mini*(he.mini-1))/2) {
        return(true);
    } else {
        return(false);
    }
}

bool check(int ind1, int ind2) {
    int i1, i2;
    i1 = ind1;
    i2 = ind2;
    int depth = 1;
    while (i1!=i2) {
        i1 = i1/2;
        i2 = i2/2;
        depth = depth*2;
    }
    int tempmin = 100000123;
    int tempmax = -1;
    int tempsum = 0;
    i1 = i1*2;
    i2 = i2*2+1;
    if (depth == 1) {
        return(true);
    } else if (depth == 2) {
        return(checker({min(strom[ind1].mini,strom[ind2].mini),max(strom[ind1].maxi,strom[ind2].maxi), strom[ind1].sum+strom[ind2].sum }));
    }
    depth = depth/2;
    int i1a, i1b, i2a, i2b;
    bool done1 = false;
    bool done2 = false;

    while (depth > 1 and not (done1 and done2)) {
        depth = depth/2;
        // cout<<depth<<" depth"<<endl;
        if (not done1) {
            i1a = i1*2;
            i1b = i1*2+1;
            // cout<<i1a<<" "<<i1b<<" i1ab"<<endl;
            if (ind1 >= (i1a*depth+depth)) {
                i1 = i1b;
            }
            if (ind2 >= i1b*depth+depth) {

                if (ind1 == i1b*depth) {
                    tempsum+=strom[i1b].sum;
                    tempmin = min(strom[i1b].mini,tempmin);
                    tempmax = max(strom[i1b].maxi,tempmax);
                    done1 = true;
                    i1 = i1a;
                    // cout<<i1b<<" i1b"<<endl;
                    // printemh(i1b);
                } else if (ind1 < i1b * depth) {
                    tempsum+=strom[i1b].sum;
                    tempmin = min(strom[i1b].mini,tempmin);
                    tempmax = max(strom[i1b].maxi,tempmax);
                    i1 = i1a;
                    // cout<<i1b<<" i1b"<<endl;
                    // printemh(i1b);
                } else {
                    i1 = i1b;
                }



            }
            if (i1a*depth==ind1) {
                tempsum+=strom[i1a].sum;
                tempmin = min(strom[i1a].mini,tempmin);
                tempmax = max(strom[i1a].maxi,tempmax);
                done1 = true;
                // cout<<i1a<<" i1a"<<endl;
                // printemh(i1a);
            }
        }

        if (not done2) {
            i2a = i2*2;
            i2b = i2*2+1;
            // cout<<i2a<<" "<<i2b<<" i2ab"<<endl;

            if (ind2 < i2b*depth) {
                i2 = i2a;
            }

            if (ind1 < i2a*depth) {

                if (ind2 == (i2a*depth+depth-1)) {
                    // cout<<i2a<<" i2a"<<endl;
                    // printemh(i2a);
                    tempsum+=strom[i2a].sum;
                    tempmin = min(strom[i2a].mini,tempmin);
                    tempmax = max(strom[i2a].maxi,tempmax);
                    done2 = true;
                    i2 = i2b;
                } else if (ind2 > (i2a * depth+depth-1)) {
                    // cout<<i2a<<" i2a"<<endl;
                    // printemh(i2a);
                    tempsum+=strom[i2a].sum;
                    tempmin = min(strom[i2a].mini,tempmin);
                    tempmax = max(strom[i2a].maxi,tempmax);
                    i2 = i2b;
                } else {
                    i2 = i2a;
                }


            }
            if (i2b*depth+depth-1==ind2) {
                tempsum+=strom[i2b].sum;
                tempmin = min(strom[i2b].mini,tempmin);
                tempmax = max(strom[i2b].maxi,tempmax);
                done2 = true;
                // cout<<i2b<<" i2b"<<endl;
                // printemh(i2b);
            }
        }


    }

    // cout<<tempmin<<" "<<tempmax<<" "<<tempsum<<endl;
    return(checker({tempmin,tempmax,tempsum}));

}

int main() {
    vector<int> casti;
    int x, y, z, n, t, q;
    cin>>n>>t;
    for (int i = 0; i < n; i++) {
        cin>>x;
        casti.push_back(x);
    }
    construct(n, casti);

    // for (int i = 0; i < siz; i++) {
    //     cout<<strom[i].mini<<" "<<strom[i].maxi<<" "<<strom[i].sum<<endl;
    // }
    cin>>q;
    for (int i = 0; i < q; i++) {
        cin>>x>>y>>z;
        if (x==1) {
            if(check(siz/2+y-1,siz/2+z-1)) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else {
            strom[siz/2+y-1] = {z,z,z};
            update(siz/2+y-1);
        }
    }
}
