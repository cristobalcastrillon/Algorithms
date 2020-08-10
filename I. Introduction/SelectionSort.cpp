// First approach to sorting algorithms.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int arr[8] = {5,4,1,8,7,2,6,3};
    
    cout << "Original array: " << endl;
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " " ;    
    }
    cout << endl;
    
    //Sort solution for an array of length 8:
    
    for(int it = 0; it < 7; it++){
        int min_ind = 0, min = 0;
        for(int i = it; i < 8; i++){
            if(i == it){
                min = arr[i];
                min_ind = i;
            }
            if(arr[i] < min){
                min = arr[i];
                min_ind = i;
            }
        }
        int x = arr[it];
        arr[it] = arr[min_ind];
        arr[min_ind] = x;
    }
    
    cout << "Sorted array: " << endl;
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " " ;    
    }
    cout << endl;
    
}
