#include <bits/stdc++.h>
using namespace std;

/*
1. arrays are default passed by pointers 
2. heaps are complete binary tree in which all the levels are filled (may be except the last one) and every node is far left as possible
3. this property enables heap to be stored in array 
4. time complexity - O(nlogn) 
5. logn for the heapify method 
   n for extracting n elements from the heap 
6. priority queue implemented using Heap
   
*/


void heapify(int arr[], int i, int n){
	int left = 2*i+1;
	int right = 2*i + 2 ;
	int largest = i;
	if(left < n && arr[largest] < arr[left]) largest = left;
	if(right < n && arr[largest] < arr[right]) largest = right ;
	if(largest != i){
		swap(arr[largest],arr[i]);
		heapify(arr,largest,n);
	}
}
void heapsort(int arr[], int n){
	// first make heap 
	for(int i=n/2-1; i>=0; i--)
		  heapify(arr,i,n); 
    // now extract element one by one and heapify again
	// arr[0] will contain the maximum value of the heap 
	for(int i=n-1; i>0; i--){
		swap(arr[0],arr[i]);
    	// now again apply heapfiy 
		heapify(arr,0,i);
	}

}
int main(){
	int arr[] = {3,35,4,3,4,7,58,5,64};
	int size = sizeof(arr)/sizeof(arr[0]);
	heapsort(arr,size); 
	for(int i=0; i<size; i++) cout << arr[i] <<" ";
	cout << endl; 
}