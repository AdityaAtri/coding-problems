#include<bits/stdc++.h>
using namespace std;
/*
sort an array in which all the elements are atmost k distance away from its sorted position 
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Could have applied insertion sort -> best for nearly sorted array -> O(nk)
outer loop - n times
inner loop - at most k times to fix the element in its proper position

*/

void sort_nearlySorted(int arr[], int n, int k){
	priority_queue<int,std::vector<int>,std::greater<int> >pq;
	//insert the first k+1 elements 
	//build time  -> O(k)
	//heap is built 
	for(int i=0; i<=k ; i++) pq.push(arr[i]);
	//for the n-k elements insertion O((n-k)*log(k))
	//logk is the height of min heap 
	int i=k+1;
	int j=0;
	while(pq.size()!=0){
		arr[j]=pq.top();
		pq.pop();
		if(i<n)pq.push(arr[i]);
		i++;
		j++;
	}
}
int main(){
	int arr[] = { 2, 6, 3, 1, 56, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k=3; 
	sort_nearlySorted(arr,n,k);
	for(int i=0; i<n; i++) cout << arr[i] << " ";
	cout << endl ; 
}




