// Letter Combinations of a Phone Number



// Link:-
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<string> Ret(vector<string> v, char d){
	switch(d){
		case '2': {
			v.push_back("a");
			v.push_back("b");
			v.push_back("c");
			break;
		}
		case '3': {
			v.push_back("d");
			v.push_back("e");
			v.push_back("f");
			break;
		}
		case '4': {
			v.push_back("g");
			v.push_back("h");
			v.push_back("i");
			break;
		}
		case '5': {
			v.push_back("j");
			v.push_back("k");
			v.push_back("l");
			break;
		}
		case '6': {
			v.push_back("m");
			v.push_back("n");
			v.push_back("o");
			break;
		}
		case '7': {
			v.push_back("p");
			v.push_back("q");
			v.push_back("r");
			v.push_back("s");
			break;
		}
		case '8': {
			v.push_back("t");
			v.push_back("u");
			v.push_back("v");
			break;
		}
		case '9': {
			v.push_back("w");
			v.push_back("x");
			v.push_back("y");
			v.push_back("z");
			break;
		}
	}
	
	return v;	
}
vector<string> letterCombinations(string d){
	int len = d.length();
	int power = pow(3,len);
	vector<string> v;
	vector<string> temp;
	string s;
	if(len==0) {
		return v;
	}
	else if(len==1){
		v = Ret(v,d[0]);
	}
	else if(len==2){
		v = Ret(v,d[0]);
		v = Ret(v,d[1]);
		for(int i=0;i<3;i++){
			for(int j=3;j<6;j++){
				s = v[i]+v[j];
				temp.push_back(s);
			}
		}
		return temp;
	}
	else if(len==3){
		v = Ret(v,d[0]);
		v = Ret(v,d[1]);
		v = Ret(v,d[2]);
		for(int i=0;i<3;i++){
			for(int j=3;j<6;j++){
				for(int k=6;k<9;k++){
				s = v[i]+v[j]+v[k];
				temp.push_back(s);
				}
			}
		}
		return temp;
	}
	else if(len==4){
		v = Ret(v,d[0]);
		v = Ret(v,d[1]);
		v = Ret(v,d[2]);
		v = Ret(v,d[3]);
		for(int i=0;i<3;i++){
			for(int j=3;j<6;j++){
				for(int k=6;k<9;k++){
					for(int l=9;l<12;l++){
						s = v[i]+v[j]+v[k]+v[l];
						temp.push_back(s);
					}
				}
			}
		}
		return temp;
	}
}
int  main(){
	string digit;
    vector<string>::iterator i;
//	cin>>digit;
	vector<string >a = letterCombinations("283");
	for(i=a.begin();i!=a.end();i++) cout<<*i<<" ";	
}
