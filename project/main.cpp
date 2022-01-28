#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<vector>
#include"g.h"
#include"edgeheap.h"
#include"heap.h"
#include"NoHeapDijkstra.h"
#include"HeapDijkstra.h"
#include"KruskalMST.h"
#include<iostream>
#include<sys/time.h>
#include<math.h>

int main()
{
    srand(time(0));
	static int y= rand()*10000+1;
	static int seed= y;
    
    clock_t start, end;
	double runningTime=0;
    int V = 5000;
	struct Graph* printgraph = Degree6Graph(V, seed++);
	print(printgraph);
	
	// iterations to randomly generate 5 pairs of graphs and 5 pavirs of vertices for each iteration to test the Project
	for(int j=0;j< 5; j++)
	{
		//seed as high as possuble
		cout<<"\nNow Testing Pair["<<j+1<<"] Graph";
		
	for(int i=0; i<5; i++){
	srand(seed*100*rand()*rand());
	//generate source randomly
	int s= rand()%(V-1)+1;
	
	//generate t randomly
	int t= rand()% (V-1)+1;
	
	cout<<endl;
	cout<<endl;
	
	
	
	cout<<"\n=======================================================================================================\n";	
	cout<<"\nNow Testing using Pair["<< i+1 <<"] with vertices (s: "<<s<<",t:"<<t<<")"<<endl;
	struct Graph* graph1 = Degree6Graph(V, seed++);
	struct Graph* graph2 = Degree1000Graph(V, seed++);
	
	
	
	cout<< "\n======================Graph with Degree 6 =======================\n";
	
	start= clock();
	NoHeapDijkstra(graph1, s,t);
	
	end= clock();
	runningTime= ((double) (end - start)) / CLOCKS_PER_SEC;
		
	
	cout<<endl<<"Practical Running TIme of Dijkstra(No Heap is):"<<runningTime*1000<<"ms";
		
		cout<<endl; 
		
	start= clock();
	HeapDijkstra(graph1, s, t);
	end= clock();
	runningTime= ((double) (end - start)) / CLOCKS_PER_SEC;
	
	cout<<endl<<"Practical Running TIme of Dijkstra(With  Heap is):"<<runningTime*1000<< "ms";
	
	cout<<endl;
	
	start= clock();
	KruskalMST(graph1,s,t);
	end= clock();
	runningTime= ((double) (end - start)) / CLOCKS_PER_SEC;
	
	cout<<endl<<"Practical Running TIme of Kruskal's: "<<runningTime*1000<< "ms";
		 
		
	cout<<endl;
	cout<<endl;
	cout<< "\n==================Graph with Degree of about 20%====================\n";
	start= clock();
	
	NoHeapDijkstra(graph2, s,t);
	end= clock();
	runningTime= ((double) (end - start)) / CLOCKS_PER_SEC;
	
	cout<<endl<<"Practical Running TIme of Dijkstra(No Heap is):"<<runningTime*1000<<"ms";
		cout<<endl; 
		
		
	start= clock();
	HeapDijkstra(graph2, s, t);
	
	end= clock();
	runningTime= ((double) (end - start)) / CLOCKS_PER_SEC;
	
	cout<<endl<<"Practical Running TIme of Dijkstra( With  Heap is):"<<runningTime*1000<< "ms";
	
	cout<<endl;
	
	start= clock();
	KruskalMST(graph2,s,t);
	end= clock();
	runningTime= ((double) (end - start)) / CLOCKS_PER_SEC;
	
	cout<<endl<<"Practical Running TIme of Kruskal's: "<<runningTime*1000<< "ms";
	
	cout<<"\n========================================================================================================\n";	 
	}
	
	}
	cout<<"\n A model Adjacency list of a graph can be found at graph.txt";
	
	
	return 0;

}




