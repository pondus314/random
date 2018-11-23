#include<bits/stdc++.h>
using namespace std;

vector<string> slova;
vector<vector<int> > pocet(71813, vector<int> (26, 0));

vector<string> finder(string zaklad, vector<char> chyby, vector<string> mnozina = slova) {
    vector<string> vystup;
    vector<int> pocty(26, 0);
    for (int i = 0; i < zaklad.size(); i++) {
        if (isalpha(zaklad[i])) {
            pocty[zaklad[i]-'A']++;
        }
    }
    for (int i = 0; i < mnozina.size(); i++) {
        bool failed = false;

        if (mnozina[i].length()==zaklad.length()) {

            for (int j = 0; j < zaklad.length(); j++) {

                if ((zaklad[j]!='_' and zaklad[j]!=mnozina[i][j])) {
                    failed = true;
                } else if (zaklad[j]=='_') {

                    for (int k = 0; k < chyby.size(); k++) {

                        if (tolower(mnozina[i][j]) == chyby[k]) {
                            failed = true;
                        }

                    }

                }

            }

            for (int j =0; j < 26; j++) {
                if (pocty[j] != pocet[i][j] && pocty[j]>0) {
                    failed = true;
                }
            }
        } else {
            failed = true;
        }

        if (not failed) {
            vystup.push_back(mnozina[i]);
        }
    }
    return(vystup);
}

bool checker(string zaklad, vector<char> chybne, vector<string> mozina = slova) {
    vector<string> moznosti = finder(zaklad, chybne, mozina);
    vector<vector<bool> >pouzite(moznosti.size(), vector<bool> (26, false));
    vector<bool> spolocne(26, true);
    vector<int> pocty(26, 0);
    // cout<<zaklad<<endl;
    for (int i =0; i < zaklad.length(); i++) {
        if (isalpha(zaklad[i])) {
            pocty[zaklad[i]-'A']++;
        }
    }

    int spoloc = 26;
    string nove;
    char spolocny;

    if (moznosti.size()==0) {
        return(false);
    } else if (moznosti.size() == 1) {
        return(true);
    } else {
        for (int i = 0; i < moznosti.size(); i++) {
            for (int j =0; j < moznosti[i].length(); j++) {
                pouzite[i][moznosti[i][j]-'A'] = true;
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < pouzite.size(); j++) {
                if ((pouzite[j][i]==false || pocty[i] > 0) && spolocne[i]) {
                    spolocne[i] = false;
                    spoloc--;
                }
            }
        }
        if (spoloc==0) {
            return(false);
        } else {
            for(int i = 0; i < 26; i++) {
                if (spolocne[i]==true) {
                    spolocny = 'A'+i;
                }
            }
            for(int i = 0; i < moznosti.size(); i++) {
                nove = zaklad;
                for (int j = 0; j < moznosti[i].size(); j++) {
                    if (moznosti[i][j]==spolocny) {
                        nove[j] = spolocny;
                    }

                }
                if (checker(nove, chybne, moznosti)==false) {
                    return(false);
                }
            }
            return(true);
        }

    }
}

int main() {
    string slovo, placeholder;
    vector<char> wrong;
    vector<bool> guessed;
    int n,q;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>placeholder;
        slova.push_back(placeholder);
        for (int j = 0; j < placeholder.length(); j++) {
            pocet[i][placeholder[j]-'A']++;
        }
    }
    // cout<<"bdee \n";
    cin>>q;
    cin.ignore(256, '\n');
    for (int i =0; i < q; i++) {
        wrong.resize(0);
        slovo = "";
        guessed.resize(0);
        cin.ignore(256, '\n');
        getline(cin, placeholder);
        // cout<<placeholder<<endl;
        for (int j = 0; j < placeholder.length(); j++) {
            if (isalpha(placeholder[j])) {
                wrong.push_back(placeholder[j]);
            }
        }

        for (int j = 0; j < 7; j++) {
            cin.ignore(256, '\n');
        }
        getline(cin, placeholder);
        // cout<<placeholder<<endl;
        for (int j = 0; j < placeholder.length(); j++) {
            if (j%2==1) {
                continue;
            } else {
                // cout<<j<<"\n";
                if (isalpha(placeholder[j])) {
                    guessed.push_back(true);
                    slovo.push_back(placeholder[j]);
                } else {
                    guessed.push_back(false);
                    slovo.push_back('_');
                }
            }
        }
        if (checker(slovo, wrong)) {
            cout<<"ANO"<<endl;
        } else {
            cout<<"NIE"<<endl;
        }
        // cout<<slovo<<"\n";
    }
}
