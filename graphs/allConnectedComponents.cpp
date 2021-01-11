#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printAllConnectedComponentsHelper(bool **edges, 
                                       int numVertices, 
                                       int startNode, 
                                       bool *visited, 
                                       vector<int> &output)
{

	output.push_back(startNode);
    visited[startNode] = true;
    for(int i=0; i < numVertices; i++){
        if(edges[startNode][i] && !visited[i]){
            printAllConnectedComponentsHelper(edges, numVertices, i, visited, output);
        }
    }
}

void printAllConnectedComponents(bool **edges, int numVertices){
	bool *visited = new bool[numVertices];
    for(int i=0; i < numVertices; i++){
        if(!visited[i]){
            vector<int> component;
        	printAllConnectedComponentsHelper(edges, numVertices, i, visited, component);
            sort(component.begin(), component.end());
    		for(int i=0; i < component.size(); i++){
    			cout << component[i] << " ";
    		}
    		cout << endl;
        }
    }
}

int main() {
    // Write your code here
    int n;
    int e;
    
    cin >> n >> e;
    
    
    bool **edges = new bool*[n];
    for(int i=0; i < n; i++){
        edges[i] = new bool[n];
        for(int j=0; j < n; j++){
            edges[i][j] = false;
        }
    }
    
    for(int i=0; i < e; i++){
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }
    printAllConnectedComponents(edges, n);
}