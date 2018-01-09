#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string stortestPalindrome(string s){
	int size = s.length();
	int end =s.length()-1;
	int i=0,j=end;
	string tmp ="";
	while (i<j){
		if(s[i] == s[j]) {
			i++;
			j--;
		}
		else{
			i=0;
			end--;
			j =end;
		} 	

	}
	string out="";
	for(int k=size-1;k>end;k--){
		out =out +s[k];
	}
	for(int k =0;k<size;k++){
		out =out + s[k];
	}
	return out;
}
int main(){
	string s;
	printf("please write a test string :");
	cin>>s;
	string out =stortestPalindrome(s);
	cout<<out<<endl;
	return 0;
}
