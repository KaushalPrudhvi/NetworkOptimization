#ifndef edgeheap_h   
#define edgeheap_h


#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include"g.h"

using namespace std;

//Used for swapping of type  edges

void swap1(struct Edge **a, struct Edge **b){
	struct Edge* temp;
	
	temp= *a;
	*a= *b;
	*b = temp;
}

// maxheapify
void maxHeapify1(vector<Edge*> &arr, int n , int i){
	int left= 2*i+1;
	int right= 2*i+2;
	int largest= i;	
	if(left<n && arr[largest]->weight < arr[left]->weight){
		largest= left;
	}
	if(right<n && arr[largest]->weight< arr[right]->weight){
		largest= right;
	}
	if(largest!= i){
		swap1(&arr[i], &arr[largest]);
		maxHeapify1(arr,n, largest);
	}
}


//build max heap
void BuildMaxHeap1(vector<Edge*> &arr){
	for(int i= (arr.size())/2-1;i>=0;i--){
		maxHeapify1(arr, arr.size()-1, i);
	}
}


//heap sort for Kruskals
void heapSort1(vector<Edge* >& arr)
{

	BuildMaxHeap1(arr);
 
    
    for (int i = arr.size()-1; i > 0; i--) {
        
        swap1(&arr[0], &arr[i]);
 
        
        maxHeapify1(arr,i, 0);
    }
}
#endif
