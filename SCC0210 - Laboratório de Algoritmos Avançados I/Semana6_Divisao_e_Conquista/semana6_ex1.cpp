#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int vet[1000];
int n, k;

bool funcao(int mid){
	int ac = 0;
	int k_aux = k;
	for (int i = 0; i <= n; ++i){
		ac += vet[i];
		if (ac > mid){
			k_aux--;
			if (k_aux < 0 || vet[i] > mid)
				return false;
			ac = vet[i];
		}
	 } 
	return true;
}


int passeio(int l, int h){
	int mid;
	bool result;

	while(h - l >= 0) { 
		mid = (l+h)/2;
		result  = funcao (mid);
		if (result) 
			h = mid-1;
		else l = mid+1;
	}
	
	return funcao(l) ? l : h;

}

int main(int argc, char const *argv[]){

	while(cin >> n >> k){
        int sum = 0;

        for (int i = 0; i <= n; i++){
            cin >> vet[i];
            sum += vet[i];
        }

        printf("%d\n", passeio(0, sum));
    }
	return 0;
}