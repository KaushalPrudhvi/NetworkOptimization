#ifndef NoHeapDijkstra_h
#define NoHeapDijkstra_h


// main function
void NoHeapDijkstra(Graph* graph, int s, int t){

	// -1 represents unseen vertices
	//0 represents inTree vertices
	// 1 represents Fringes
	
	int a= graph->V;
	int status[a];
	int D[a];
	int dad[a];
	for(int i=0; i< a; i++){
		status[i]= -1;
		D[i]=-1;
		dad[i]=-1;
		
	}


	int source=s;
	status[source]= 0; //inTree

// queue of fringes
	vector<struct Node*> que;
	

		struct Node* temp1= graph->array[source].head; // get the adjacency list of source
	while(temp1!=NULL){
		status[temp1->destination]=1;//Fringe;
		que.push_back(temp1); 
		
		dad[temp1->destination]= source;
		D[temp1->destination]= temp1->weight; //assign weights
		temp1= temp1->next;

	}

	// Now fringes are identified 
	// while que is not empty

// loop till no fringes

	while(que.size()!=0){
		//get the max fringe
		int maxIndex= max(que, D);
		//get ptr of max fringe and process
		Node* tempPtr= que.at(maxIndex);
		int dest= tempPtr->destination;
		Node* temp= graph->array[dest].head;
		
		que.erase(que.begin()+ maxIndex); // remove the element
		
		status[tempPtr->destination]=0; //inTree
		
		while(temp!=NULL){
			if(status[temp->destination]==-1){
				status[temp->destination]=1; //fringe
				D[temp->destination]= minimum(D[tempPtr->destination], temp->weight);
				dad[temp->destination]= tempPtr->destination;
				que.push_back(temp);
				
				
			}else if((status[temp->destination]==1)&& D[temp->destination]< minimum(D[tempPtr->destination], temp->weight)){
				D[temp->destination]= minimum(D[tempPtr->destination], temp->weight);
				dad[temp->destination]= tempPtr->destination;
				
			}
			temp= temp->next;
		}
		
	}
	// check if t is in tree
	
	if (status[t] != 0){
		printf("No S-T path");
		
	}
	else{ 
		int p = t;
		//print out the path
		cout<<"Using DIJKSTRA(no HEAP):	The BW["<<t<<"]"<<"is "<<D[t]<<" and the path is(";
		while (p != source){
			cout<<p<<"<-"; 
			p = dad[p];
		}
		cout<<s<<")";
	}

	
	
	
}

#endif