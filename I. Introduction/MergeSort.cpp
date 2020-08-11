#include <iostream>

using namespace std;

int * mergeSort(int array[]);

int main(){
    int array[] = {5,4,1,8,7,2,6,3};
}

void mergeSort(int * array, int n) {

    //'n' is the size of the array.
    int m = n/2;

    //Declarando arrays: 
    //  * Dos de length: m = n/2; A y B.
    int * A = new int[m];
    int * B = new int [m];

    //Poblando arrays...
    //x es el indice para poblar A; y el indice para poblar B.
    int x = 0, y = m;
    for(int i = 0; i < m; i++){
        *(A+i) = *(array+x);
        *(B+i) = *(array+y);
        x++;
        y++;
    }

    if(m == 1) {
        merge(A, B, n);
    }

    mergeSort(A);
    mergeSort(B);
}

void merge(int * A, int * B, int n) {
    int i = 0, j = 0;

    //  * Uno de length: n = 2 * m; C.
    int * C = new int[n];

    for(int k = 0; k < n; k++){
        if(*(A+i) < *(B+j)){
            *(C+k) = *(A+i);
            i++;
        }
        else{
            *(C+k) = *(B+j);
            j++;
        }
    }
}