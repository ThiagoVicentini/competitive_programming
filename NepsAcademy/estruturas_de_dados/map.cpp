#include<iostream>
#include<map>

using namespace std;

int main(){
	map <string,int> coffee;
	coffee["Espresso"]= 25;
	coffee["Cappuccino"]= 30;
	coffee["Tea"]=20;

	cout << coffee["a"];	

	return 0;
}