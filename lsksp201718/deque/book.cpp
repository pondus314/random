#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, x;
    bool flipped = false;
    deque<int> dekadolna, dekahorna;
    cin>>k>>x;
    while (x!= 0) {
        if (flipped) {
            if (x > 0) {
                dekahorna.push_front(x);
                if (dekahorna.size() > k) {
                    dekadolna.push_back(dekahorna.back());
                    dekahorna.pop_back();
                }
            } else if (x==-1) {
                cout<<dekahorna.front()<<"\n";
                dekahorna.pop_front();
                if (dekadolna.size() > 0) {
                    dekahorna.push_back(dekadolna.back());
                    dekadolna.pop_back();
                }
            } else if (x==-2) {
                flipped = not flipped;
            }

        } else {
            if (x > 0) {
                dekahorna.push_back(x);
                if (dekahorna.size() > k) {
                    dekadolna.push_back(dekahorna.front());
                    dekahorna.pop_front();
                }
            } else  if (x==-1){
                cout<<dekahorna.back()<<"\n";
                dekahorna.pop_back();
                if (dekadolna.size() > 0) {
                    dekahorna.push_front(dekadolna.back());
                    dekadolna.pop_back();
                }
            } else if (x==-2) {
                flipped = not flipped;
            }
        }

        cin>>x;
    }
}
