#include <iostream>

using namespace std;

unsigned bits (int x, int k, int j) {
	return (x>>k)&~(~0<<j);
}

void intercambio(int a[], int i, int der){//recibimos el arreglo y las ubicaciones
	int change = a[i];
	a[i] = a[der];
	a[der] = change;
}

void cambioresiduos(int a[], int izq, int der, int b) {
	int i, j, t;
	if (der > izq && b >= 0) {
		i = izq; 
		j = der;
		while(j != i) {
			while(!bits(a[i], b, 1) && i < j){
				i++;
			}
			while(bits(a[j], b, 1) && j > i){
				j--;
			}
			intercambio(a, i, j);
		}
		if (!bits(a[i], b, 1)){
			j++;
		} 
		cambioresiduos(a, izq, j-1, b-1);
		cambioresiduos(a, j, der, b-1);
	}
}

int main(){
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	
	cambioresiduos(a, 0, 9, 4);//b = cantidad de bits, puede variar dependiendo del tamaño del arreglo
	
	for(int i=0; i<=99; i++){
		cout<<a[i]<<" ,";//imprimira el arreglo
	}
	cout<<endl;
	
	return 0;
}
