#include <bits/stdc++.h>
using namespace std;

/*
1. Get Top Priority Element (Get minimum or maximum) - O(1)
2. Insert an element - O(Logn)
3. Remove top priority element - O(Logn)
4. Decrease Key - O(Logn)
*/

// extract min is followed by minheapify 
class MinHeap{
	
	private:
		int *heap;
		int max_size;
		int curr_size;
	public:
		//constructor 
		MinHeap(int size){
			max_size = size;
			curr_size = 0;
			heap = new int[size];
		}
		// get the parent index
		int parent(int child){
			return (child-1)/2;
		}
		// get the left child
		int leftchild(int parent){
			return 2*parent+1;
		}
		// get the right child
		int rightchild(int parent){
			return 2*parent+2;
		}
		// returns the minimum element present at the top of the min heap
		int getmin(){
			return heap[0];
		}
		//to extract the root which is minimum element of all 
		int extractmin();
		//change the value of node at index i
		void changevalue(int index, int new_val);
		//insert a new node in a heap 
		void insertnode(int val);
		//delete a node stored at index i
		void deletenode(int index);
		//minheapify
		void minheapify(int index);
		//printing the heap array
		void printheap();

};

void MinHeap::printheap(){
	for(int i=0; i<curr_size; i++) cout << heap[i] << " ";
	cout << endl; 
}

void MinHeap::minheapify(int index){
	int left = 2*index +1;
	int right = 2*index +2 ;
	int smallest = index;
	if(left < curr_size &&  heap[smallest]>heap[left]) smallest = left;
	if(right < curr_size && heap[smallest]>heap[right]) smallest = right;
	if(smallest != index){
		swap(heap[smallest],heap[index]);
		minheapify(smallest);
	}
}

void MinHeap::deletenode(int index){
	//this will bring the INT_MIN to the top (root) of the minheapify
	changevalue(index,INT_MIN);
	//now extract that node
	extractmin();
}
void MinHeap::insertnode(int val){
	if(curr_size >= max_size){
		cout << "Heap is full" << endl;
		return ;
	}
	curr_size++;
	int index = curr_size - 1;
	heap[index]=val;
	while(index !=0 && heap[index] < heap[parent(index)]){
		swap(heap[index],heap[parent(index)]);
		index  = parent(index);
	}
}
void MinHeap::changevalue(int index, int new_val){
	heap[index]=new_val;
	while(index!=0 && heap[index]<heap[parent(index)]){
		swap(heap[index],heap[parent(index)]);
		index = parent(index); 
	}
}

int MinHeap :: extractmin(){
	if(curr_size <= 0 ){
		cout << "No element to extract" << endl;
		return INT_MIN;
	}
	if(curr_size == 1 ){
		curr_size--;
		return heap[0];
	}
	int root = heap[0];
	swap(heap[0],heap[curr_size-1]);
	curr_size--;
	minheapify(0);
	return root;
}

int main(){
	MinHeap heap_struct(12);
	heap_struct.insertnode(3); 
    heap_struct.insertnode(2); 
    heap_struct.deletenode(1); 
    heap_struct.insertnode(15); 
    heap_struct.insertnode(5); 
    heap_struct.insertnode(4); 
    heap_struct.insertnode(45);
    cout << heap_struct.extractmin() << endl; 
    cout << heap_struct.getmin() << endl;
    heap_struct.changevalue(2,1);
    cout << heap_struct.getmin() << endl;
    heap_struct.printheap();
}





