#include <iostream>

using namespace std;

void mergeSort(int array[], int n);
void merge(int A[], int B[], int n);

int main(){
    int A[] = {5,4,1,8,7,2,6,3};
    int n = sizeof(A) / sizeof(int);

    cout << "A is an array of size " << n << ", with values ";
    for(int i = 0; i < n; i++){
        cout << "[" << A[i] << "\t";
    }
    cout << "]" << endl;

    mergeSort(A, n);

    cout << "After the mergeSort, A is ";
    for(int i = 0; i < n; i++){
        cout << "[" << A[i] << "\t";
    }
    cout << "]" << endl;
}

void mergeSort(int array[], int n) {

    //'n' is the size of the array.
    int m = n/2;

    //Declarando arrays: 
    //  * Dos de length: m = n/2; A y B.
    int A[m];
    int B[m];

    //Poblando arrays...
    //x es el indice para poblar A; y el indice para poblar B.
    int x = 0, y = m;
    for(int i = 0; i < m; i++){
        A[i] = array[x];
        B[i] = array[y];
        x++;
        y++;
    }

    // if(m == 1) {
    //     merge(A, B, n);
    // } 

    mergeSort(A, m);
    mergeSort(B, m);
    merge(A, B, n);
}

void merge(int A[], int B[], int n) {
    int i = 0, j = 0;

    //  * Uno de length: n = 2 * m; C.
    int C[n];

    for(int k = 0; k < n; k++){
        if(A[i] < B[j]){
            C[k] = A[i];
            i++;
        }
        else{
            C[k] = B[j];
            j++;
        }
    }
}