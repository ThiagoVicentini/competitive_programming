#include <iostream>
#include <cstdio>
#include <cmath>

#define ERRO 0.00000001
#define MAX 1000

using namespace std;

double p, q, r, s, t, u;

double funcao(double x){
	return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u);
}


double prestacao(double a, double b){
	double mid;
	double result;
	int i=0;
	while(b - a > ERRO) {  // enquanto a diferenca entra min e max for maior que o erro
		if(i>MAX)
			return 1;
		mid = (a+b)/2.0;
		result  = funcao(mid);
		if (result > 0) 
			a = mid;
		else b = mid;
		i++;
	}
	return b;
}

int main(int argc, char const *argv[]){
	double a = 0;
	double b = 1;
	double raiz;

	while(cin >> p >> q >> r >> s >> t >> u){
		raiz = prestacao(a, b);
		if(raiz != 1)
			printf("%.4f\n", raiz);
		else
			cout << "No solution\n";

	}

	return 0;
}