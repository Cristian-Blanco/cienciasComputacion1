#include <iostream>
#include <stdio.h>
#include <cmath>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int Max(int a[], int N){
	int max = a[0];
	for(int i=1; i<N; i++){
		if(a[i]>max){
			max=a[i];
		}	
	}
	return	max;
}

void countingSort(int a[], int N, int div){
	int salida[N];
	int count[10] = {0};
	
	for(int i=0; i<N; i++){
		count[(a[i]/div)%10]++;
	}
	for(int i=1; i<10; i++){
		count[i] += count[i-1];
	}
	for(int i=N-1; i>=0; i--){
		salida[count[(a[i]/div)%10]-1]=a[i];
		count[(a[i]/div)%10]--;
	}
	for(int i=0; i<N; i++){
		a[i]=salida[i];
	}
}

void radixSort(int a[], int N){
	int m = Max(a, N);
	for(int div=1; m/div>0; div*=10){
		countingSort(a, N, div);
	}
}


int main(int argc, char** argv) {
	int a[10]={10,9,8,7,6,5,4,3,2,1};	
			
	radixSort(a,10);
	
	cout<<"Orden Ascendente"<<endl;
	for(int i=0; i<10; i++){
		cout<<a[i]<<", "; 
	}
	
	return 0;
}
