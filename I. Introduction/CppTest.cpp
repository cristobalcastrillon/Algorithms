#include <iostream>
#include <stdlib.h>

using namespace std;

int * mergeSort(int *, int);
int * merge(int *, int *, int);

int main(){

    int a[] = {2,5,4,1,3,7,8,6};
    int n =  sizeof(a)/sizeof(int);

    int *aPtr = &a[0];

    //Print the original array:
    for(int i = 0; i < n; i++){
        cout << "[" << *(aPtr+i) << "]\n";
    }
    
    //Call the mergeSort() function on 'a':
    aPtr = mergeSort(aPtr, n);

    //Print the sorted array:
    for(int i = 0; i < n; i++){
        cout << "[" << *(aPtr+i) << "]\n";
    }
}

//MergeSort algorithm.
//MergeSort parameters: arrPtr — pointer to the 'head' of an array; n — length of that array.
int * mergeSort(int * arrPtr, int n){
    //Create two temporal arrays of length l = n/2:
    int l = n/2;
    int a[l];
    int b[l];

    //Populate the arrays:
    for(int i = 0; i < l; i++){
        a[i] = *(arrPtr+i);
        b[i] = *(arrPtr+l+i);
    }

    //Create pointers for each of the arrays:
    int * aPtr = &a[0];
    int * bPtr = &b[0];

    //Call the mergeSort() function on each of the arrays:
    if(l > 1){
        aPtr = mergeSort(aPtr, l);
        bPtr = mergeSort(bPtr, l);
    }

    //Call the merge() subroutine:
    arrPtr = merge(aPtr, bPtr, l);

    return arrPtr;
}

//Merge subroutine.
//Merge parameters: aPtr — pointer to the first array; bPtr — pointer to the second array; l — length of each array.
//Assumptions: 
//  *'a' and 'b' are *sorted*.
//  *length of a + length of b = length of c.
int * merge(int * aPtr, int * bPtr, int l){
    
    //Create array 'c' of length 2l, which will be populated by the elements of 'a' and 'b':
    int m = 2 * l;
    int c[m];
    
    //Create a pointer to array 'c':
    int * cPtr = &c[0];

    //Indexes for 'a' and 'b' respectively.
    int h = 0;
    int k = 0;

    //Index for 'c'.
    int i = 0;

    //Populate array 'c':
    while(h < l && k < l){
        if(*(aPtr+h) <= *(bPtr+k)){
            c[i] = *(aPtr+h);
            h++;
            i++;
        }

        else{
            c[i] = *(bPtr+k);
            k++;
            i++;
        }
    }

    if(!(h < l)){
        while(k < l){
            c[i] = *(bPtr+k);
            i++;
            k++;
        }
    }

    else{
        while(h < l){
            c[i] = *(aPtr+h);
            i++;
            h++;
        }
    }

    return cPtr;
}