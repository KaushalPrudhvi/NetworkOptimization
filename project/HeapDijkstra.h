#ifndef HeapDijkstra_h
#define HeapDijkstra_h

// main module
void HeapDijkstra(Graph* graph, int s, int t){
	// -1 represents unseen vertices
	//0 represents inTree vertices
	// 1 represents Fringes
	
	
	int a= graph->V;
	int status[a];
	int D[a];
	int P[a];
	
	

	for(int i=0; i< a; i++){
		status[i]= -1; //unseen
		D[i]=-1;
		P[i]=-1;
	}
	
	
		int source = s;
	status[source]= 0; //inTree

	int dad[a];
	for(int i=0;i<a; i++){
		dad[i]=-1;
	}
	
	vector<struct Node*> H; //  heap
	
	struct Node* temp1= graph->array[source].head;
	while(temp1!=NULL){
		status[temp1->destination]=1;       //Fringe;
		H.push_back(temp1); 
		P[temp1->destination]= H.size()-1; // get Position
		dad[temp1->destination]= source;
		D[temp1->destination]= temp1->weight; // assign weights
		
		temp1= temp1->next;

	}
	// build max heap`
	
	BuildMaxHeap(H, P, D);
	while(H.size()!=0){
		// get maximum BW element
		Node* tempPtr= MAXIMUM(H);
		int dest= tempPtr->destination;
		Node* temp= graph->array[dest].head;
		status[tempPtr->destination]= 0;    //inTree
		
		
		//delete max
		DeleteMax(H, P, D);
		while(temp!=NULL){
			if(status[temp->destination]==-1){
				status[temp->destination]=1; // fringe
				 
				D[temp->destination]= minimum(D[tempPtr->destination], temp->weight);
				dad[temp->destination]= tempPtr->destination;
				
				//insert into heap
				INSERT(H, H.size()-1, P,D, temp);
				
			}
			
			else if((status[temp->destination]==1)&& D[temp->destination]< minimum(D[tempPtr->destination], temp->weight)){
				int in= P[temp->destination];
				
				swap(&H[H.size()-1], &H[P[temp->destination]], P);
 				
				// delete an element at any index
				DELETE(H);
				//heapify
				insertHeapify(H, in , P, D);
				
				
				
				maxHeapify(H, H.size(), in , P, D);
				
				
				 
				
				D[temp->destination]= minimum(D[tempPtr->destination], temp->weight);
				
				// insert again 
				
				INSERT(H, H.size()-1, P, D, temp);
				
				// point to new parent
				dad[temp->destination]= tempPtr->destination;
				
			}
			temp= temp->next;
			
		}
	}
		
	// check if t is in tree
	if (status[t] != 0){
		printf("Using HEAP DIJKSTRA : No S-T path");
		
	}
	// print s-t path
	else{ 
		int p = t;
		cout<<endl<<"Using HEAP DIJKSTRA 	:The BW["<<t<<"]"<<"is "<<D[t]<<" and the path is(";
		while (p != source){
			cout<<p<<"<-"; 
			p = dad[p];
		}
		cout<<s<<")";
	}

	
	
	
}


#endif