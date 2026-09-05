#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int n;  // number of nodes
    // list<int>* adjList; // dynamic adjacency list that stores list of neighbours of each nodes ( list of list)
    unordered_map<int,vector<int>>adjList;
     
    Graph(int n){
        this->n = n;
       
    }
    
    void addEdge(int u, int v){

    //for undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);

    // for directed graph
    //  adjList[u].push_back(v);
    }
    void print(){
        for(int u = 0;u<n;u++){
            cout<<"Neighbours of "<<u<<" : ";
           
            
            for(int v : adjList[u]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
};



int main(){
    
    Graph graph1(5);
    graph1.addEdge(0,1);
    graph1.addEdge(1,2);
    graph1.addEdge(1,3);
    graph1.addEdge(2,3);
    graph1.addEdge(2,4);
    graph1.addEdge(3,4);

    graph1.print();
    
    return 0;
}
