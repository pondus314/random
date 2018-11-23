#include<bits/stdc++.h>
using namespace std;



int main() {
    vector<vector<string> > sibenice;
    string slovo, pismena;
    vector<char> unused;

    for (int i = 0; i < 8; i++) {
        sibenice.push_back(vector<string> ());
        sibenice[i].push_back("    _______");
        if (i > 0) {
            sibenice[i].push_back("   |/      | %s");
        } else {
            sibenice[i].push_back("   |/");
        }
        if (i > 1) {
            sibenice[i].push_back("   |      (_)");
        } else {
            sibenice[i].push_back("   |");
        }
        if (i == 3) {
            sibenice[i].push_back("   |       |");
        } else if (i < 3) {
            sibenice[i].push_back("   |");
        } else if (i == 4) {
            sibenice[i].push_back("   |      \\|");
        } else {
            sibenice[i].push_back("   |      \\|/");
        }
        if (i > 2) {
            sibenice[i].push_back("   |       |");
        } else {
            sibenice[i].push_back("   |");
        }
        if (i ==7) {
            sibenice[i].push_back("   |      / \\");
        } else if (i ==6) {
            sibenice[i].push_back("   |      /");
        } else {
            sibenice[i].push_back("   |");
        }
        sibenice[i].push_back("   |");
        sibenice[i].push_back("___|___");
    }

    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         cout<<sibenice[i][j]<<"\n";
    //     }
    //     cout<<"\n";
    // }

    cin>>slovo;
    cin>>pismena;
    bool used;
    vector<bool> guessed(slovo.length(),false);
    int c = 0;
    int faults = 0;

    for (int i = 0; i < pismena.length(); i++) {
        used = false;
        for(int j = 0; j < slovo.length(); j++) {
            if (pismena[i]==tolower(slovo[j])) {
                used = true;
                guessed[j]= true;
                c++;
            }
        }
        if (used == false) {
            unused.push_back(pismena[i]);
            faults++;
        }
        if (c == slovo.length()) {
            break;
        }
        if (faults==7) {
            break;
        }
    }
    string faulty(unused.begin(), unused.end());
    for (int i =0; i < 8; i++) {
        if (i == 1 and faults > 0) {
            printf(sibenice[faults][i].c_str(),faulty.c_str());
            cout<<"\n";
        } else {
            cout<<sibenice[faults][i]<<"\n";
        }
    }
    cout<<"\n";

    for (int i = 0; i < slovo.length(); i++) {
        if (guessed[i]) {
            cout<<slovo[i];
        } else {
            cout<<"_";
        }
        if (i < slovo.length()-1) {
            cout<<" ";
        } else {
            cout<<"\n";
        }
    }
}
