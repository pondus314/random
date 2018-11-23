#include <iostream>
#include <vector>

using namespace std;

vector <vector <long double> > koeficient;
vector <long double> x;
vector <long double> y;

long double calculate(long double value){
	long double ret = 0;
	for(int i = 0; i < x.size(); i++){
		long double loc = koeficient[i].back();
		for(int j = 0; j < i; j++){
			loc *= value - x[j];
		}
		ret += loc;
	}
	return ret;
}

int a, b;

int main(){
	x = {1,2,3,4};
	y = {1,2,3,4};
	while(true){
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
		koeficient.resize(x.size());

		for(int i = 0; i < x.size(); i++){
			koeficient[i].resize(i+1);
			koeficient[i][0] = y[i];
			//cout << koeficient[i][0] << ' ';
		}
		//cout << '\n';
		for(int i = 1; i < x.size(); i++){
			for(int j = i; j < x.size(); j++){
				if(koeficient[j][i] == 0) koeficient[j][i] = (koeficient[j][i-1]-koeficient[j-1][i-1])/(x[j]-x[j-i]);
				//cout << koeficient[j][i] << ' ';
			}
		//cout << '\n';
		}

		for(long double i = -10; i < 10; i+=0.01){
			cout << i << ' ' << calculate(i) << '\n';
		}
	}
}
