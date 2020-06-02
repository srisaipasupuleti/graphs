
/*  input format 
    no:of vertices
    no:of edges
    input edges
    then input root node 
*/


#include<bits/stdc++.h>
using namespace std;
int addedge(vector<int> adj[],int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
    return 0;
}
int showadj(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<"vertex "<<i;
        for(int j=0;j<adj[i].size();j++){
            cout<<"->"<<adj[i][j];
        }
        cout<<"\n";
    }
    return 0;
}

void dfsutl(vector<int> adj[],int s,bool* visited){
    cout<<"->"<<s;
    visited[s]=true;
    for(auto it=adj[s].begin();it!=adj[s].end();it++){
        int i=*it;
        if(visited[i]==false){
            dfsutl(adj,i,visited);
        }
    }
}


void dfs(vector<int> adj[],int s,int v){
    bool visited[v]={false};
    dfsutl(adj,s,visited);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int v;cin>>v;
    vector<int> adj[v];
    int n;cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        addedge(adj,a,b);
    }
    int s;
    cin>>s;
    showadj(adj,v);
    dfs(adj,s,v);
    cout<<"\n";
    return 0;
}