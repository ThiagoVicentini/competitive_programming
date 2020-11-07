#include <iostream>

using namespace std;

int main(){
	
	double pi = 3.14159;
	double raio;
 
    	cin >> raio;
    
	cout.precision(2);
    	cout.setf(ios::fixed);
    	cout << "A areah do circulo de raio " << raio << " eh " << raio*raio*pi << endl;
	
	return 0;
}