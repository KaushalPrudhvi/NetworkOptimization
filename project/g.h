#ifndef g_h
#define g_h
#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<vector>
#include<iostream>
//#include<conio.h>
#include<queue>

using namespace std;
 	
//vertex pair structure
struct Node{

    int destination;
    int weight;
    Node * next;
	

};

void createEdge(struct Graph * graph, int source, int destination, int number);


void createMSTEdge(Graph* graph, int source, int destination, int weight);

// edge related info
struct Edge{
	Node* source;
	Node* destination;
	int weight;
	int number;
	Edge* next;
};


//adjacency list
struct List{
    struct Node* head;
	

};

//graph
struct Graph{
    int V;
    List* array;
	Edge* edgeshead;
	
	

};
void print(struct Graph* graph);


// creating a new edge
struct Edge* newEdge(Node* source, Node* destination, int weigh){
	Edge* edge= (Edge*)malloc(sizeof(Edge));
	edge->source= source;
	edge->destination= destination;
	edge->weight= weigh;
	edge->next= NULL;
	edge->number= 0;
	
	return edge;
}








 
// newNode creation in a adjacecny list


struct Node* newNode(int destination){
	
    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->destination= destination;
    newnode->weight= 0;

    newnode->next= NULL;
    return newnode;

}
static int p=0;
 int *a= &p;


// to construct a Maximum Spannning Tree for Kruskal's
struct Graph* ST(int v , vector<Edge*> & mst){
    struct Graph* t = (struct Graph*)malloc(sizeof(struct Graph));
    t->V= v+1;
    t->array= (struct List*)malloc((v+1)*sizeof(struct List));
	t->edgeshead= NULL;
	for(int i=0; i< v+1; i++){
        t->array[i].head= NULL;
		


    }
	
	for(int i=0; i< mst.size();i++){
		//cout<<endl<<(mst[i]->source)->destination<<"\t"<<(mst[i]->destination)->destination;
		createMSTEdge(t, (mst[i]->source)->destination, (mst[i]->destination)->destination, mst[i]->weight);
	
	}
	return t;
}


// create edges in MST 
void createMSTEdge(Graph* graph, int source, int destination, int weight){
	
	
	struct Node* newnode3= newNode(destination);
	
    newnode3->next= graph->array[source].head;
	newnode3->weight= weight;
	
	
	//cout<<endl<<"some"<<weight;
    graph->array[source].head= newnode3;
	//cout<<endl<<graph->array[source].head->destination<<"\t";
	

    struct Node* newnode4= newNode(source);
	newnode4->weight = weight;
    newnode4->next= graph->array[destination].head;

    graph->array[destination].head= newnode4;
	
	//cout<<graph->array[destination].head->destination;
	
	
	//struct Edge* n= newEdge(newnode1,newnode2, weight);
}



// to create a sparse graph

struct Graph* Degree6Graph(int v , int seed){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V= v;
    graph->array= (struct List*)malloc(v*sizeof(struct List));
	graph->edgeshead= NULL;
	
	
	static long long edgeNumber=0;
	
    int i ;
    for(i=0; i< v; i++){
        graph->array[i].head= NULL;
		


    }
	srand((seed++));
	int x;
	  std::random_device rd;
      std::default_random_engine gen {rd()};
  
      std::poisson_distribution<std::size_t> dist {(7)};
	int y=0;
	int count=0;
	
	
	int same;
	//static int err=0;
	for(int m=0; m<4999; m++){
			
			if(graph->array[m].head==NULL){
				createEdge(graph, m,m+1 , edgeNumber++);
			}
		}
		
    for(int  i=0;  i<v; i++){
		count=0;
		same=0;
		srand((rand()*(seed++))+1); 
		y= dist(gen);
		
		//again:
		for(;count< y;count++ ){  
			srand((rand()*(y*seed++))+1); 
		
			x= (int)((rand()%(v-1))+1); //  0,1 , 0,3,0, 5, 0,6
			if(graph->array[i].head==NULL){
				createEdge(graph, i, x, edgeNumber++);
				
				
				
			}else{
				
				
				for (Node* temp=graph->array[i].head;  temp != NULL; temp= temp->next) {
					if (temp->destination == x || x==i) {
						//count++;
						//--;
						
						//goto again;
						
						same=1;
						break;
					}
				}
				if(same==1)
				continue;
				createEdge(graph, i, x, edgeNumber++);
				//count++;
			}
		}
			
	}
	
	int flag=0;
	for (Node* temp=graph->array[0].head;  temp != NULL; temp= temp->next) {
					if (temp->destination == v-1) {
						flag=1;
						break;
						
					}
	}
	if(flag==0){
		createEdge(graph, 0, v-1, edgeNumber++);
		}

	
    return graph;

}

// to create a dense graph
	
struct Graph* Degree1000Graph(int v , int seed){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V= v;
    graph->array= (struct List*)malloc(v*sizeof(struct List));
	graph->edgeshead= NULL;
	
	
	static long long edgeNumber1=0;
	
    int i ;
    for(i=0; i< v; i++){
        graph->array[i].head= NULL;
		


    }
	srand((seed++));
	int x;
	  std::random_device rd;
      std::default_random_engine gen {rd()};
  
      std::poisson_distribution<std::size_t> dist {(1000)};
	int y=0;
	int count=0;
	
	
	int same;
	//static int err=0;
	for(int m=0; m<4999; m++){
			
			if(graph->array[m].head==NULL){
				createEdge(graph, m,m+1 , edgeNumber1++);
			}
		}
    for(int  i=0;  i<v; i++){
		count=0;
		same=0;
		srand((rand()*(seed++))+1); 
		y= dist(gen);
		
		//again:
		for(;count< y;count++ ){  
			srand((rand()*(y*seed++))+1); 
		
			x= (int)((rand()%(v-1))+1); 
			//cout<<endl<<x;
			if(graph->array[i].head==NULL){
				createEdge(graph, i, x, edgeNumber1++);
			
			}else{
			
				for (Node* temp=graph->array[i].head;  temp != NULL; temp= temp->next) {
					if (temp->destination == x || x==i) {
						
						
						same=1;
						break;
					}
				}
				if(same==1)
				continue;
				createEdge(graph, i, x, edgeNumber1++);
				
			}
		}
			
	}
	
	int flag=0;
	for (Node* temp=graph->array[0].head;  temp != NULL; temp= temp->next) {
					if (temp->destination == v-1) {
						flag=1;
						break;
						
					}
	}
	if(flag==0){
		createEdge(graph, 0, v-1, edgeNumber1++);
		}

    return graph;

}

// create edges in a graph
static int b=1;
void createEdge(struct Graph * graph, int source, int destination, int number){
	
	srand((b*rand()*destination ));
	b++;
	
	int weigh= rand()%3333+1;
    //cout<<endl<< weigh;
	
    struct Node* newnode1= newNode(destination);
	
    newnode1->next= graph->array[source].head;
	newnode1->weight= weigh;

    graph->array[source].head= newnode1;

    struct Node* newnode2= newNode(source);
	newnode2->weight = weigh;
    newnode2->next= graph->array[destination].head;

    graph->array[destination].head= newnode2;
	struct Edge* n= newEdge(newnode1,newnode2, weigh);
	
		n->number= number;
	if(graph->edgeshead==NULL){
		graph->edgeshead= n;
		n->next= NULL;
		}
	else{
		
		Edge* tempedge= graph->edgeshead;
		graph->edgeshead= n;
		n->next= tempedge;		
	}
	
	
	

}

// returns number of edges

long long numOfEdges(Graph* g){
	//cout<<endl;
	int edgescount=0;
	Edge* temp= g->edgeshead;
	while(temp->next){
		edgescount++;
		//cout<<"("<<temp->source->destination<<","<<temp->destination->destination<<","<<temp->weight<<","<<temp->number<<")";	
		//cout<<"\t";
		
		
		temp= temp->next;
		
		}
		//cout<<"Total Number of edges are:"<< edgescount;
		//cout<<endl;
		
		return edgescount;
	
}


// function to print graph in adjacency list form
void print(Graph* graph){
    int i;
	ofstream fhand;
	fhand.open("graph.txt", ios::app);
	fhand<<"vertex 1 vertex 2 weight";
    for(i=0; i< graph->V; i++){
		cout<<"Graph is being written onto the text in 2seconds and the output is at the end\n";
			
        struct Node* tempListHead= graph->array[i].head;
		fhand<<"\n";
		fhand<<"Vertex[";
		fhand<<i;
		fhand<<"]";
        //cout<<endl<< "Vertex"<<endl<<"["<< i <<"]\t";
        while(tempListHead){
			fhand<<"(";
			fhand<<tempListHead->destination;
			fhand<<",";
			fhand<<tempListHead->weight;
			fhand<<")\t";
			
			
			//cout<<"("<< tempListHead->destination<< ","<< tempListHead->weight<<")"<<"\t";
            tempListHead= tempListHead->next;

        }
        cout<<endl;
		
    }
	fhand<<"\n===================End of this graph===================";
	fhand.close();
}


//print edges
void printEdges(Graph * g){
	cout<<endl;
	int edgescount=0;
	Edge* temp= g->edgeshead;
	while(temp->next){
		edgescount++;
		cout<<"("<<temp->source->destination<<","<<temp->destination->destination<<","<<temp->weight<<","<<temp->number<<")";	
		cout<<"\t";
		
		
		temp= temp->next;
		
		}
		cout<<"Total Number of edges are:"<< edgescount;
		cout<<endl;
}


#endif