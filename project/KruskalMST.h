#ifndef KruskalMST_h
#define KruskalMST_h
#include<vector>
#include<utility>
#include<queue>
#include<iostream>

using namespace std;
 // make set
void MakeSet(int* dad, int* rank, int v){
	dad[v]=-1;
	rank[v]=0;
}

//find

int Find(int *dad, int v){
	int w=v;
	while(dad[w]!=-1)
		w=dad[w];
	
	return w;
	
}


//Union
void Union(int* dad, int * rank, int r1, int r2){
	if(rank[r1]>rank[r2])
	dad[r2]= r1;
	else if(rank[r1]<rank[r2])
		dad[r1]= r2;
	else{
		dad[r2]= r1;
		rank[r1]+=1;
	}
	
	//cout<<"I am here";
		
}

// to construct s-t path using BFS
void PATH(Graph* graph, int s, int t, int* path, vector<pair<int, int>> & BWPath){
	queue<int > spanning;
	int a= graph->V;
	int color[a];
	for(int i=0; i<a; i++){
		color[i]=-1;
		BWPath[i].first=-1;
		BWPath[i].second=5000000;
		// white
	}
	//1: gray
	//0: black
	color[s]=1;
	spanning.push(s);
	int parent=0;
	while(!spanning.empty()){
		
		int temp= spanning.front();
		spanning.pop();
		parent= temp;
		
		color[temp]= 0; //visited
		
		struct Node* nodehead= graph->array[temp].head;
		while(nodehead){
			//cout<<"The value of destination is: " <<nodehead->destination <<"and the color is" << color[nodehead->destination];;
				
			if(color[nodehead->destination]==-1){
				
				color[nodehead->destination]= 1;
				path[nodehead->destination]= parent; 
				BWPath[nodehead->destination].first= nodehead->destination;
				BWPath[nodehead->destination].second= nodehead->weight;
				spanning.push(nodehead->destination);
			}
			if(nodehead->destination==t)
			{
				//cout<<"The value of t is: " <<t;
				
				// break if t is reached and exit for loop 
				goto x;
			}
			nodehead= nodehead->next;
			
		}
		
	}
	
	x:
	int y=0;
	
}

 

// Main module

void KruskalMST(Graph* graph, int s, int t){


int a = graph->V;
vector<Edge*> e; // e is a heap that contains pointers to edges.
struct Edge* temp= graph->edgeshead;

// array used to iterate through the edges and sort them;
//e.push_back(edgeshead);
while(temp){

	e.push_back(temp);
	temp= temp->next;
	
	
}
vector<pair<int, int>> BWPath(a);
	//first : destination
	// Parent->destination Second: Weight;
	
 // call heapSort to sort edges
heapSort1(e);


//cout<<endl<<endl;

int path[a];
int dad[a];
int rank[a];
for(int i=0; i< a ; i++){
	dad[i]=-1;
	rank[i]=0;
	path[i]=-1;
	
}


// to store edges
vector<Edge*> MST;

// Kruskal MST algorithm
for(int i=e.size()-1; i>=0; i--){
	struct Edge* temp= e[i];
	int r1= Find(dad, (temp->source)->destination);
	int r2= Find(dad, (temp->destination)->destination);
	if(r1!=r2){
		Union(dad, rank, r1, r2);
		MST.push_back(temp);
	}
	
}
//construct Maximum spanning tree
struct Graph* MSTGRAPH = ST(MST.size(), MST);

	// find s-t path
		PATH(MSTGRAPH, s, t, path, BWPath);
		int p = t;
		int value= BWPath[p].second;
		while(p!=s){
			value= minimum(value, BWPath[path[p]].second);
			
			p= path[p];
			//cout<<endl<<p;
			 
		}
		
		//cout<<"i am here";
		cout<<endl<<"Using KRUSKAL's:		 The BW["<<t<<"]"<<"is "<<value<<" and the path is(";
		p=t;
		while (p != s){
			//cout<<"i am here";
			cout<<p<<"<-"; 
			p = path[p];
			
		}
		cout<<s<<")";

	
} 



#endif