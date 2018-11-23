#include<bits/stdc++.h>
using namespace std;

struct hmeh{
    double x;
    double v;
};

double k, m, dt, t, g, f, o, o0;

double zrychlenie(hmeh vstup) {
    return(-k/m*vstup.x-vstup.v*g+f*sin(o*t)/m);
}

hmeh euler(hmeh vstup) {
    double a = zrychlenie(vstup);
    double xn = vstup.v*dt;
    double vn = a*dt;
    return(hmeh {xn,vn});
}

hmeh rk4(hmeh vstup) {
    hmeh k1, k2, k3, k4;
    k1 = euler(vstup);
    k2 = euler({vstup.x+k1.x/2,vstup.v+k1.v/2});
    k3 = euler({vstup.x+k2.x/2,vstup.v+k2.v/2});
    k4 = euler({vstup.x+k3.x,vstup.v+k3.v});
    return(hmeh {vstup.x+(k1.x+2*k2.x+2*k3.x+k4.x)/6,vstup.v+(k1.v+2*k2.v+2*k3.v+k4.v)/6});
}

int main() {
    cin>>k>>m>>f>>o0>>dt;
    o = 0.99*o0;
    g = 0.1*o0;
    double x, v;
    cin>>x>>v;
    hmeh state = hmeh {x,v};
    for(int i = 0; i < 10000; i++) {
        cout<<t<<" "<<state.x<<"  "<<state.v<<"\n";
        t+=dt;
        state = rk4(state);
        // if (i%100 == 42) {
        // }
    }
}
