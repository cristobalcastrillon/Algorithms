#include <iostream>

using namespace std;

int* mergeSort(int array[]);

int main(){
    int array[] = {5,4,1,8,7,2,6,3};
}

int* mergeSort(int array[]) {

    int n = sizeof(array);
    int m = n/2;
    //Declarando arrays.
    //Tres arrays: 
    //  * Dos de length: n = 1; A y B.
    int * A = new int[m];
    int * B = new int[m];

    if(m == 1) {
        int i = 0, j = 0;
        //  * Uno de length: h = 2n; C.

        int * C = new int[n];

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
        return C;
    }    
}