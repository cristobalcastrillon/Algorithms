#include <iostream>
#include <stdlib.h>

using namespace std;

int * mergeSort(int *, int, int);
int * merge(int *, int *, int, int);

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

    //Create the 'ind' variable:
    int ind = 0;
    
    //Call the mergeSort() function on 'a';
    aPtr = mergeSort(aPtr, n, ind);

    //Print the sorted array:
    for(int i = 0; i < n; i++){
        cout << "[" << *(aPtr+i) << "]\n";
    }
}

//MergeSort algorithm.
//MergeSort parameters: arrPtr — pointer to the 'head' of an array; n — length of that array.
// ind — Index for Manual Debugging.
int * mergeSort(int * arrPtr, int n, int ind){
    //Create two temporal arrays of length l = n/2:
    int l = n/2;
    int a[l];
    int b[l];

    ind = rand() % 50;

    //This is what I call 'manual debugging'...
    cout << ind << ". This is how arrays 'a' and 'b' are 'populated'" << endl;
    //Populate the arrays:
    for(int i = 0; i < l; i++){
        a[i] = *(arrPtr+i);
        b[i] = *(arrPtr+l+i);

        //Printing because for whatever reason the debugger won't step into:
        cout << "a: [" << a[i] << "]\t" << "b: [" << b[i] << "]\n";
    }

    //Create pointers for each of the arrays:
    int * aPtr = &a[0];
    int * bPtr = &b[0];

    //Call the mergeSort() function on each of the arrays:
    if(l > 1){
        aPtr = mergeSort(aPtr, l, ind);
        bPtr = mergeSort(bPtr, l, ind);
    }

    if(l == 1){
        
    }

    //Call the merge() subroutine:
    arrPtr = merge(aPtr, bPtr, l, ind);

    return arrPtr;
}

//Merge subroutine.
//Merge parameters: aPtr — pointer to the first array; bPtr — pointer to the second array; l — length of each array.
// ind — Index for Manual Debugging.
//Assumptions: 
//  *'a' and 'b' are *sorted*.
//  *length of a + length of b = length of c.
int * merge(int * aPtr, int * bPtr, int l, int ind){
    
    //Create array 'c' of length 2l, which will be populated by the elements of 'a' and 'b':
    int m = 2 * l;
    int c[m];
    //Create a pointer to array 'c':
    int * cPtr = &c[0];

    //This is what I call 'manual debugging'...
    cout << ind << ". This is merged array 'c':" << endl;

    //Populate array 'c':
    int k = 0;
    int h = 0;

    for(int i = 0; i < m; i++){
        //There's a goddamn problem with the merge subroutine... FIND IT!

        //[4,3,5,2] 
        //–> [4,3] - [5,2] 

        //—> [4] merges with [3] in c[2] = [xxx, xxx]

        //      k     h
        //     [0]   [0] 
        //  —> [4] > [3]
        // EXPECTED:
        //      —> c[0] = [3] 
        //      —> c[1] = [4] 

        //—> [5] merges with [2] in c[2] = [xxx, xxx]

        //      k     h
        //     [0]   [0] 
        //  —> [5] > [2]
        // EXPECTED:
        //      —> c[0] = [2]
        //      —> c[1] = [5]

        //If array 'a' in index k is less than or equal to 'b' in h:
        //  'c' in i is equal to 'a' in k.
        if(*(aPtr+k) <= *(bPtr+h)){
            c[i] = *(aPtr+k);
            k++; //Move the index one position to ensure the same value is not used again.
        }

        //Otherwise (if 'a' in k is greater than 'b' in h), 'c' in i is equal to 'b' in h.
        if(*(aPtr+k) > *(bPtr+h)){
            c[i] = *(bPtr+h);
            h++; //Move the index one position to ensure the same value is not used again.
        }
        
        cout << "c: [" << c[i] << "]\n";
    }

    return cPtr;
}