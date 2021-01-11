#include <iostream>
using namespace std;

bool hasPath(int **edges, int n, int v1, int v2, bool *visited){
	if(v1 == v2){
        return true;
    }
    visited[v1] = true;
    for(int i=0; i < n; i++){
        if(edges[v1][i] == 1 && !visited[i]){
            if(hasPath(edges, n, i, v2, visited)){
                return true;
            }
        }
    }	
    return false;
}

int main() {
    // Write your code here
    int n;
    int e;
    
    cin >> n >> e;
    
    
    int **edges = new int*[n];
    for(int i=0; i < n; i++){
        edges[i] = new int[n];
        for(int j=0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i < e; i++){
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = 1;
        edges[ev][sv] = 1;
    }
    
    bool *visited = new bool[n];
    for(int i=0; i < n; i++){
        visited[i] = false;
    }
    
    int v1, v2;
    cin >> v1 >> v2;

    bool val = hasPath(edges, n, v1, v2, visited);
    if(val){
        cout << "true" << endl;    
    }else{
        cout << "false" << endl;
    }
    
}
