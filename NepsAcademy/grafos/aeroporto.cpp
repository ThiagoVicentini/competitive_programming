//Thiago Henrique Vicentini
//Telegram: @ThiagoVicentini
//Discord: Anakin#8592

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void preencheComZero(int* vetor, int n){ //preenche um vetor de tamanho n com zeros
    for(int i=1;i<=n;i++)
        vetor[i]=0;
}

void maxArray(int* vetor, int n){

    int max = 0;        //variavel que guarda valor maximo do vetor
    vector<int> maxx;   //estrutura para guardar os aeroportos com maior trafego

    for(int i=1;i<=n;i++)
        if(vetor[i] > max) //percorre o vetor identificando o valor dele
            max = vetor[i];


    for(int i=1; i<=n; i++){
        if(vetor[i] == max){    //percorre os valores do vetor novamente buscando os aeroportos com máximo trafego
            maxx.push_back(i);      //e o adiciona o indice (numero referente ao aeroporto) ao vector
        }
    }
    sort(maxx.begin(), maxx.end()); //funcao que ordena o vector em ordem crescente

    for(vector<int>::iterator it=maxx.begin(); it!=maxx.end(); ++it)
        cout << *it << " ";     //printa os valores do vector
    cout << "\n\n";
}

int main(){

    int A, V;
    int aeroporto[101];
    cin >> A >> V;
    preencheComZero(aeroporto, A);

    int x=0, y=0, j=1;
    while(A != 0 or V != 0){
        for(int i=0; i<V; i++){
            cin >> x >> y;
            aeroporto[x]++;
            aeroporto[y]++;
        }
        cout << "Teste " << j << endl;
        maxArray(aeroporto, A);

        j++;
        cin >> A >> V;
        preencheComZero(aeroporto, A);
    }
    return 0;
}
