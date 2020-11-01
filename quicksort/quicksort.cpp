#include <iostream>

using namespace std;


void intercambio(int a[], int i, int der){//recibimos el arreglo y las ubicaciones
	int j = a[i];
	a[i] = a[der];
	a[der] = j;
}

void ordenrapido(int a[], int izq, int der) {
	int i, j, v; 	
	if (der > izq) {
		v = a[der]; 
		i = izq -1; 
		j = der;
		while (true) {
			while (a[++i] < v);
			while (a[--j] > v && j >= 0);
			if(i>=j) {
				break;
			}
			intercambio(a, i, j);
		}
		intercambio(a, i, der);
		ordenrapido(a, izq, i-1);
		ordenrapido(a, i+1, der);
	}
}


int main(){
	int a[10] ={10,9,8,7,6,5,4,3,2,1};
	ordenrapido(a, 0, 9);//le mandamos el arreglo, su inicio y final
	
	for(int i=0; i<=9; i++){
		cout<<a[i]<<" ,";//imprimira el arreglo
	}
	cout<<endl;
}
