#ifndef heap_h   
#define heap_h
#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<vector>
#include"g.h"
#include<iostream>
using namespace std;

void createEdge(struct Graph * graph, int source, int destination, int number);
void swap(struct Node **a,struct Node **b, int * Parent);
void maxHeapify(vector<struct Node*> &arr,int ,int i,int * Parent, int* D);
void BuildMaxHeap(vector<struct Node*> &arr, int * Parent, int* D);

void heapSort(vector<struct Node* >& arr, int * Parent, int* D);

 int max(vector<Node*> &arr, int* );
 int minimum(int a, int b);
  int parent(int i);
  void DELETE(vector<struct Node*> &arr);
 
 
 // get index of i's parent
 int parent(int i){
	return (i-1)/2;
}

//compute minimum
 
 int minimum(int a, int b){
	return a<b?a:b;
}

// return Max in a Max heap

struct Node* MAXIMUM(vector<Node*> &arr){
	return arr[0];
	
}

// returns max element index in an array
int max(vector<Node*> &arr, int* D){
	int  maxIndex= 0;
	for(int i=1; i< arr.size(); i++){
		if(D[arr[i]->destination] > D[arr[maxIndex]->destination])
			maxIndex= i;
	}
	return maxIndex;
}

// to insert into heap at a given position
void insertHeapify(vector<struct Node*> &arr, int i, int * Parent, int * D)
{

    while(i!=0 && D[arr[parent(i)]->destination]< D[arr[i]->destination]){
		swap(&arr[i], &arr[parent(i)], Parent);
		i=parent(i);
	}
	
   
}


// Insert into heap and heapify
void INSERT(vector<struct Node*> &arr, int i, int * Parent, int *D, struct Node* temp)
{


	arr.push_back(temp);
	Parent[temp->destination]= arr.size()-1;
				
    while(i!=0 && D[arr[parent(i)]->destination]< D[arr[i]->destination]){
		swap(&arr[i], &arr[parent(i)], Parent);
		i=parent(i);
	}
	
   
}


// swaps elements and simulatenously changes Parent[]

void swap(struct Node **a, struct Node **b, int* Parent ){
	struct Node* temp;
	
	int indexA= Parent[(*a)->destination];
	Parent[(*a)->destination]= Parent[(*b)->destination];
	Parent[(*b)->destination]= indexA;

	
	
	temp= *a;
	*a=*b;
	*b = temp;
}


//max Heapify

void maxHeapify(vector<struct Node*> &arr,int n, int i, int * Parent , int * D){
	int left= 2*i+1;
	int right= 2*i+2;
	int largest= i;	
	
	
	if(left<n && (D[arr[largest]->destination] < D[arr[left]->destination])){
		largest= left;
	}
	
	
	
	
	
	if(right<n && (D[arr[largest]->destination] < D[arr[right]->destination])){
		
		largest= right;
	}
	if(largest!= i){
		
		swap(&arr[i], &arr[largest], Parent);
		maxHeapify(arr, n, largest, Parent, D);
	}
}




// Build Maxheap
void BuildMaxHeap(vector<struct Node*> &arr, int * Parent, int* D){
	
	
	for(int i= (arr.size()/2)-1;i>=0;i--){
		maxHeapify(arr, arr.size(), i, Parent, D);
		
	}
	
}


// heapSort
void heapSort(vector<struct Node* >& arr, int * Parent, int* D)
{

	BuildMaxHeap(arr,Parent, D);
 
    
    for (int i = arr.size()-1; i > 0; i--) {
        
        swap(&arr[0], &arr[i],Parent);
 
        
        maxHeapify(arr, i, 0, Parent, D);
		
    }
}


// deletes max in a heap
void DeleteMax(vector<struct Node*> &arr, int * Parent, int* D){
	
	struct Node* last= arr[arr.size()-1];
	
	swap(&arr[0],&arr[arr.size()-1], Parent);
	
	
	
	arr.erase(arr.begin()+ (arr.size()-1));
	maxHeapify(arr,arr.size(), 0, Parent, D);	

}


// Delete an element
void DELETE(vector<struct Node* >& arr){
	
	arr.erase(arr.begin() + arr.size()-1);
				
}



#endif