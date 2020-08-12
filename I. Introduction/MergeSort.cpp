#include <iostream>

using namespace std;

void mergeSort(int * arrPtr, int n);
void merge(int * a, int * b, int n);

int main(){

    int a[] = {5,4,1,8,7,2,6,3};
    int n = sizeof(a) / sizeof(int);

    int * arrPtr = a;

    cout << "a is an array of size " << n << ", with values ";

    for(int i = 0; i < n ; i++){
        cout << *(a+i) << " ";
    }

    cout << endl;

    mergeSort(arrPtr, n);
    cout << "After the mergeSort, a is ";
    
    for(int i = 0; i < n ; i++){
        cout << *(a+i) << " ";
    }

    cout << endl;

    return 0;
}

void mergeSort(int * array, int n) {

    //'n' is the size of the array.
    int m = n/2;

    //Declarando arrays: 
    //  * Dos de length: m = n/2; a y b.
    int * a = new int[m];
    int * b = new int [m];

    //Poblando arrays...
    //'x' es el indice para poblar a; 'y' el indice para poblar b.
    int x = 0, y = m;
    for(int i = 0; i < m; i++){
        *(a+i) = *(array+x);
        *(b+i) = *(array+y);
        x++;
        y++;
    }

    if(m == 1) {
        merge(a, b, n);
    } 

    mergeSort(a, m);
    mergeSort(b, m);

    delete [] a;
    delete [] a;
}

void merge(int * a, int * b, int n) {
    int i = 0, j = 0;

    //  * Uno de length: n = 2 * m; c.
    int * c = new int[n];

    for(int k = 0; k < n; k++){
        if(*(a+i) < *(b+j)){
            *(c+k) = *(a+i);
            i++;
        }
        else{
            *(c+k) = *(b+j);
            j++;
        }
    }
}