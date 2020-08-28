#include <iostream>
#include <stdlib.h>

using namespace std;

int * mergeSort(int *, int);
int * merge(int *, int *, int);
void simpleSort(int *, int *);

int main(){
    //Arrays are allocated statically in memory...
    int a[] = {2,5,4,1,3,7,8,6};
    int n =  sizeof(a)/sizeof(int);

    int *aPtr = &a[0];
    // ...so the pointer to the head of the array incremented in 1
    // should be the next element of the array.

    //Print the original array:
    for(int i = 0; i < n; i++){
        cout << "[" << *(aPtr+i) << "]\n";
    }
    
    //Call the mergeSort() function on 'a';
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

    if(l == 1){
        simpleSort(aPtr, bPtr);
    }

    //Call the merge() subroutine:
    arrPtr = merge(aPtr, bPtr, l);

    return arrPtr;
}

//Consider REMAKING all of the merge subroutine:
// * Doing so differently, by using a 'while' (or do-while) statement instead of a 'for':
//   * "while(h<l && k<l)" for example. 

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

    //Populate array 'c':
    int k = 0;
    int h = 0;

    for(int i = 0; i < m; i++){
        //There's a goddamn problem with the merge subroutine... FIND IT!

        //If array 'a' in index k is less than or equal to 'b' in h:
        //  'c' in i is equal to 'a' in k.
        if(*(aPtr+k) <= *(bPtr+h)){
            c[i] = *(aPtr+k);

            //Evaluate that the index 'k' is inside the space of the array 'a'.
            if(k < l){
                k++; //Move the index 'k' one position to ensure the same value is not used again.

                if(k == l){
                    *(aPtr+k-1) = *(bPtr+h);
                }
            }
        }

        //Otherwise (if 'a' in k is greater than 'b' in h, 'c' in i is equal to 'b' in h.
        if(*(aPtr+k) > *(bPtr+h)){
            c[i] = *(bPtr+h);
            
            //Evaluate that the index 'h' is inside the space of the array 'b'.
            if(h < l){
                h++; //Move the index 'h' one position to ensure the same value is not used again.

                if(h < l){
                    *(bPtr+h-1) = *(aPtr+k);
                }
            }
        }

        //The issue is located in the managing of the indexes!!!

        // cout << "c: [" << c[i] << "]\n";
    }

    return cPtr;
}


//SimpleSort function for base case (i.e. length of each array = 1):
void simpleSort(int * a, int * b){
    if(*a > *b){

        int temp1 = 0, temp2 = 0;

        temp1 = *(a);
        temp2 = *(b);

        *(a) = temp2;
        *(b) = temp1;
    }
}