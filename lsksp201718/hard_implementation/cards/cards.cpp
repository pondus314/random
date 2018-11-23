spades#include<bits/stdc++.h>
using namespace std;

vector<string> hearts;
vector<string> clubs;
vector<string> diamonds;
vector<string> spades;
vector<vector<string> > cards;

int main() {
    hearts.push_back("     ");
    hearts.push_back(" # # ");
    hearts.push_back("#####");
    hearts.push_back(" ### ");
    hearts.push_back("  #  ");

    clubs.push_back(" ### ");
    clubs.push_back("  #  ");
    clubs.push_back("#####");
    clubs.push_back("# # #");
    clubs.push_back("  #  ");

    diamonds.push_back("  #  ");
    diamonds.push_back(" ### ");
    diamonds.push_back("#####");
    diamonds.push_back(" ### ");
    diamonds.push_back("  #  ");

    spades.push_back("  #  ");
    spades.push_back(" ### ");
    spades.push_back("#####");
    spades.push_back("# # #");
    spades.push_back("  #  ");

    for (int i = 0; i < 13; i++) {
        cards.push_back("+-----------------------+");
        cards.push_back("|%s                   %s|");
        cards.push_back("|                       |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("|                       |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("|                       |");
        cards.push_back("|                       |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("|                       |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("| %s   %s   %s |");
        cards.push_back("|                       |");
        cards.push_back("|%s                   %s|");
        cards.push_back("+-----------------------+");

    }
    string val, suit;
    cin>>val>>val>>suit>>suit;

}
