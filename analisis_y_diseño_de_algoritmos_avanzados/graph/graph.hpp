#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Node{
    T value; 
    Node* next; 
    // ?
    // vector<Edge<T>> neighbors;
};

template <typename T>
struct Edge{
    Node<T> *source; 
    Node<T> *dest;
    float weight;
};


template <typename T>
class Graph{

    int size; //total nodes in graph

    Node<T> **head; 

    // Store all edges and nodes
    vector<Edge<T>> edges;
    vector<Node<T>> nodes;

    Graph(){}

    Graph(Edge<T> edges[], int edgesSize, int size){
        this->head = new Node<T>*[edgesSize](); 
        this->size = size; 

        //initialize head pointer
        for(int i = 0; i <size; i++){
            head[i] = nullptr; 
        }

        //add edges
        for(int i = 0; i < edgesSize; i++){
            Node<T> source = edges[i].source;
            Node<T> dest = edges[i].dest; 
            float weight = edges[i].weight;
            // Agregar referencias a source y dest al array
            // this->head[ sizeof(this->head)/sizeof(*Node<T>) + 1 ] = *source;
            // this->head[ sizeof(this->head)/sizeof(*Node<T>) + 1 ] = *dest;
            
            // head[source] = 
        }
    }

    void addNode(Node<T> &node){
        this->edges.push_back(*node);
    }
    void addEdge(Node<T> &nodeA, Node<T> &nodeB, float weight){
        Edge<T> edge = new Edge<T>;
        edge.source = nodeA;
        edge.dest = nodeB;
        edge.weight = weight;
    }

    Node<T>* setAdjListNode(T dest, Node<T>* head){
        Node<T>* newNode = new Node<T>;
        newNode->value = dest; 
        newNode->next = head; 
        return newNode;
        
    }



};