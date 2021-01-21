#include <iostream>
#include<algorithm>
using namespace std;

class Edge{
    public:
    int source;
    int destination;
    int weight;
    
    Edge(int source, int destination, int weight){
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }

};

bool sortByWeight(const Edge &a, 
                  const Edge &b)
{
    return a.weight < b.weight;
}

void printMST(vector<Edge> &input, int numVertices)
{
    sort(input.begin(), input.end(), sortByWeight);
    vector<Edge> output;
    int count = 0;
    int * parents = new int[numVertices];
    for(int i=0; i < numVertices; i++){
        parents[i] = i;
    }
    int curr = 0;
    while(count < numVertices-1){
        int source = input[curr].source;
        int destination = input[curr].destination;
        int source_parent = parents[source];
        while(parents[source_parent] != source_parent){
            source_parent = parents[source_parent];
        }
        int destination_parent = parents[destination];
        while(parents[destination_parent] != destination_parent){
            destination_parent = parents[destination_parent];
        }
        if(source_parent == destination_parent){
            curr++;
        }
        else{
            output.push_back(input[curr]);
            parents[destination_parent] = source_parent;
            curr++;
            count++;
        }
    }
    
    for(int i=0; i < numVertices-1; i++){
        if(output[i].source <= output[i].destination){
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else{
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
        
    }
    
}

int main() {
    // Write your code here
	int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    
    vector<Edge> input;
    
    for(int i=0; i < numEdges; i++){
        int source, destination, weight;
        cin >> source >> destination >> weight;
        input.push_back(Edge(source, destination, weight));
    }
    
    printMST(input, numVertices);
    return 0;
}