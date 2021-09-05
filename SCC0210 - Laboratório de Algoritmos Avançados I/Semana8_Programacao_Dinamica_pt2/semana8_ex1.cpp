#include <iostream>
#include <cstring>

using namespace std;

#define MAX 5000

#define MIN(a,b,c) min(min((a), (b)), (c))  

char str1[MAX];
char str2[MAX];

int MEMO[MAX+1][MAX+1];

int delta = 1;
int alpha(int i, int j){
	if (str1[i] == str2[j])
	    return 0;
    else
        return 1;
}

int alin(int i, int j){
	if (i == 0){
		MEMO[0][j] =  j*delta;
		return MEMO[0][j];
	}
	if (j == 0){
		MEMO[i][0] =  i*delta;
		return MEMO[i][0];
	}

	if (MEMO[i][j] != -1)
		return MEMO[i][j];

	MEMO[i][j] = MIN(alpha(i-1,j-1)+alin(i-1,j-1), delta+alin(i-1,j), delta+alin(i,j-1));

	return MEMO[i][j];
}

int main(int argc, char const *argv[])
{
    cin >> str1 >> str2;    

	memset(MEMO, -1, sizeof MEMO);
	cout << alin(strlen(str1), strlen(str2)) << endl;

	return 0;
}
