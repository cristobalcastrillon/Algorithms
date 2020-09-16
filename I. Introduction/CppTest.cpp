#include <iostream>
#include <stdlib.h>

using namespace std;

void mergeSort(int[], int);
void merge(int[], int[], int);

int main(){

    int a[] = {2,5,4,1,3,7,8,6};
    int n =  sizeof(a)/sizeof(int);

    //Print the original array:
    for(int i = 0; i < n; i++){
        cout << "[" << a[i] << "]\n";
    }
    
    //Call the mergeSort() function on 'a':
    mergeSort(a, n);
    
}

//MergeSort algorithm.
//MergeSort parameters: arrPtr — pointer to the 'head' of an array; n — length of that array.
void mergeSort(int arr[], int n){
    //Create two temporal arrays of length l = n/2:
    int l = n/2;
    int a[l];
    int b[l];

    //Populate the arrays:
    for(int i = 0; i < l; i++){
        a[i] = arr[i];
        b[i] = arr[l+i];
    }

    //Call the mergeSort() function on each of the arrays:
    if(l > 1){
        mergeSort(a, l);
        mergeSort(b, l);
    }

    //Call the merge() subroutine:
    merge(a, b, l);
}

//Merge subroutine.
//Merge parameters: aPtr — pointer to the first array; bPtr — pointer to the second array; l — length of each array.
//Assumptions: 
//  *'a' and 'b' are *sorted*.
//  *length of a + length of b = length of c.
void merge(int a[], int b[], int l){
    
    //Create array 'c' of length 2l, which will be populated by the elements of 'a' and 'b':
    int m = 2 * l;
    int c[m];

    //Indexes for 'a' and 'b' respectively.
    int h = 0;
    int k = 0;

    //Index for 'c'.
    int i = 0;

    //Populate array 'c':
    while(i < m){

        if(a[h] <= b[k]){
            c[i] = a[h];

            //Making sure that it stays in the (memory) scope of the array...
            if(h < l){
                h++;
                i++;
            }

            if(h == l){
                c[i] = b[k];
                break;
            }

        }

        if(b[k] < a[h]){
            c[i] = b[k];

            //Making sure that it stays in the (memory) scope of the array...
            if(k < l){
                k++;
                i++;
            }

            if(k == l){
                c[i] = a[h];
                break;
            }

        }
    }
}