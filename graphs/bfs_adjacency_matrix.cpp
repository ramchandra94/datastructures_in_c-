#include<iostream>
#include<queue>
using namespace std;

void print(int **edges, int n, bool *visited){
    for(int k=0; k < n; k++){
        queue<int> connected;
    	connected.push(k);
        while(!connected.empty()){
            int curr = connected.front();
            connected.pop();
            if(!visited[curr]){
                cout << curr << " ";
                visited[curr] = true;
            }
        
            for(int i=0; i < n; i++){
                if(i == curr){
                    continue;
                }
                if(edges[curr][i] == 1){
                    if(visited[i]){
                        continue;
                    }
                    connected.push(i);
                }
            }
    	}
    }    
}
int main(){
    int n;
    int e;
    cin >> n >> e;
    
    if(n == 0){
        return 0;
    }
    int **edges = new int*[n];
    for(int i=0; i < n; i++){
        edges[i] = new int[n];
        for(int j=0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i=0; i < n; i++){
        visited[i] = false;
    }

    print(edges, n, visited);
    return 0;
}