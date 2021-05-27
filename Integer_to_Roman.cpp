// Integer to roman

// https://leetcode.com/problems/integer-to-roman/

#include<iostream>
#include<math.h>
using namespace std;
string intToRoman(int n){
	string val;
	int c=0,s,power,div;
	int temp = n;
	while(temp){
		temp/=10;
		c++;
	}
	while(c){
		temp=n;
		power = (pow(10,c-1));
		if(power == 0)
			s=temp%10;
		div=temp/power;
		s=div%10;
		
		if(c==1){
			if(s==1) val+='I';
			if(s==2) val+="II";
			if(s==3) val+="III";
			if(s==4) val+="IV";
			if(s==5) val+='V';
			if(s==6) val+="VI";
			if(s==7) val+="VII";
			if(s==8) val+="VIII";
			if(s==9) val+="IX";
			
		}
		else if(c==2){
			if(s==1) val+='X';
			if(s==2) val+="XX";
			if(s==3) val+="XXX";
			if(s==4) val+="XL";
			if(s==5) val+='L';
			if(s==6) val+="LX";
			if(s==7) val+="LXX";
			if(s==8) val+="LXXX";
			if(s==9) val+="XC";			
		}
		else if(c==3){
			if(s==1) val+='C';
			if(s==2) val+="CC";
			if(s==3) val+="CCC";
			if(s==4) val+="CD";
			if(s==5) val+='D';
			if(s==6) val+="DC";
			if(s==7) val+="DCC";
			if(s==8) val+="DCCC";
			if(s==9) val+="CM";			
		}
		else if(c==4){
			if(s==1) val+='M';
			if(s==2) val+="MM";
			if(s==3) val+="MMM";
			if(s==4) val+="CD";			
		}
		c--;
	}
	return val;
	
}
int main(){
	int n;
	cin>>n;
	string val = intToRoman(n);
	cout<<val;
}
