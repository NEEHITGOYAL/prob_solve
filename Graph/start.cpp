#include<bits/stdc++.h>
using namespace std;   

//BFS of GRAPH
vector<int> bfsofgraph(int V,vector<int> adj[]){
    //V is no. of nodes
    vector<int> bfs;
    vector<int> vis(V+1,0); //visited array
    for(int i = 1;i<V+1;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] =1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node]){
                    if(!vis[i]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

//DFS of GRAPH

void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &storedfs){
    storedfs.push_back(node);
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it])
            dfs(it,vis,adj,storedfs);
    }
}

vector<int> dfsofgraph(int V,vector<int> adj[]){
    vector<int> storedfs;
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,storedfs);
        }
    }
}

//cycledetection in undirected graph using bfs
bool checkforcycle(int s,vector<int> adj[],vector<int>&vis){
   //Queue for storing node and parent of node
    queue<pair<int,int>> q;
    q.push({s,-1});
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push({it,node});
                vis[it] =1;
            }
            else if(par != it)
                return true;
        }
    }
    return false;
}

bool iscycle(vector<int> adj[],int V){
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i])
            if(checkforcycle(i,adj,vis))return true;
    }
    return false;
}

// Cycle detection in undirected graph using dfs
bool checkforcycle(int node,int parent,vector<int> &vis,vector<int> adj[]){
    vis[node] =1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(checkforcycle(it,node,vis,adj))return true;
        }
        else if(it != parent)
            return true;
    }
    return false;
}

bool iscycledfs(int V,vector<int> adj[]){
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i])
            if(checkforcycle(i,-1,vis,adj))return true;
    }
    return false;
}

//BIPARTITE CHECK USING BFS

bool bipartitebfs(int node,vector<int> adj[],int color[]){
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool checkbipartite(vector<int> adj[],int n){
    int color[n];
    memset(color,-1,sizeof color);
    for(int i=1;i<n;i++){
        if(color[i] == -1){
            if(!bipartitebfs(i,adj,color)){
                return false;
            }
        }
    }
    return true;
}

//BIPARTITE check using DFS

bool bipartitedfs(int node ,vector<int> adj[],int color[]){
    if(color[node] == -1)color[node] = 1;
    for(auto it:adj[node]){
        if(color[it] == -1){
            color[it] = 1-color[node];
            if(!bipartitedfs(it,adj,color))
                return false;
        }
        else if(color[it] == color[node]) return false;
    }
    return true;
}

bool checkbipartitedfs(vector<int> adj[],int n){
    int color[n];
    memset(color , -1 , sizeof color);
    for(int i=1;i<n;i++){
        if(!bipartitedfs(i,adj,color))
            return false;
    }
    return true;
}


int main(){

    int n,m; //n is no. of nodes and m is no. of edges
    int u,v;
    cin>>n>>m;

    //declare the adjacent matrix
    int adj[n+1][n+1];

    //take edge as inputs
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u][v] =1;
        adj[v][u] =1; //for undirected only
    }

    //MORE EFFICENT SPACE SAVING APPROACH

    vector<int> adjlist[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        //if u also want to store weights of 
        //edges u can make vector of pairs
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);//for undirected only
    }
    return 0;


}