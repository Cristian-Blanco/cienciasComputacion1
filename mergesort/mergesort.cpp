#include <iostream>

using namespace std;

void MergeLists(int list[], int start1, int end1, int start2, int end2) {
	int finalStart = start1;
	int finalEnd = end2;
	int indexC = 0;
	int result[(end2 - start1) + 1];

	while ((start1 <= end1) && (start2 <= end2)) {
		if (list[start1] < list[start2]) {
			result[indexC] = list[start1];
			start1++;
		} else {
			result[indexC] = list[start2];
			start2++;
		}
		indexC++;
	}
		// Mover la parte de la lista que queda
		
		if (start1 <= end1) {
			for (int i = start1; i <= end1; i++){
				result[indexC] = list[i];
				indexC++;
			}
		} else {
			for (int i = start2; i <= end2; i++){
				result[indexC] = list[i];
				indexC++;
			}
		}
		
		// Ahora vuelve a poner el resultado en la lista
		indexC = 0;
		for (int i = finalStart; i <= finalEnd; i++){
			list[i] = result[indexC];
			indexC++;
		}
}

void MergeSort(int vector[], int first, int last){
	int middle;
	if (first < last){
		middle = (first + last ) / 2;
		MergeSort(vector, first, middle);
		MergeSort(vector, middle + 1, last);
		MergeLists(vector, first, middle, middle + 1, last);
	}
}


int main(){
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	MergeSort(a,0,9);//lista, primera posicion, ultima posicion
	for(int i=0; i<10; i++){
		cout<<a[i]<<", ";
	}
	return 0;
}
