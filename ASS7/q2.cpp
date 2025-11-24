#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n){
    int left = 0, right = n-1;

    while(left < right){
        int minIndex = left;
        int maxIndex = right;

        // find min and max in the remaining array
        for(int i=left;i<=right;i++){
            if(a[i] < a[minIndex]) minIndex = i;
            if(a[i] > a[maxIndex]) maxIndex = i;
        }

        // place minimum at left
        swap(a[left], a[minIndex]);

        // if maxIndex was left, it moved to minIndex
        if(maxIndex == left)
            maxIndex = minIndex;

        // place maximum at right
        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

int main(){
    int a[]={5,2,9,1,6,4};
    int n=6;

    improvedSelectionSort(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
