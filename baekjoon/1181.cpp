#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
using pii=pair<int,int>;
using lint=long long;
int n;
string str[22222];
bool compare(const string& a, const string& b){
	if (a.length() < b.length()) return true;
	else if (a.length() == b.length()){
		if (strcmp(a.c_str(), b.c_str()) <0)
			return true;
		else
			return false;
	}
	else
		return false;
}

void input(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str[i];
	}
}

void process(){
	std::sort(str, str+n, compare);
}

void output(){
	for(int i=0; i<n; i++){
		if(i==0){
			cout << str[i] <<"\n";
			continue;
		}
		else{
			if(str[i].compare(str[i-1])){
				cout << str[i] <<"\n";
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	input();
	process();
	output();
	return 0;
}
