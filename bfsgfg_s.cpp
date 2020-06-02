
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
/*int showadj(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<"vertex "<<i;
        for(int j=0;j<adj[i].size();j++){
            cout<<"->"<<adj[i][j];
        }
        cout<<"\n";
    }
    return 0;
}*/

void bfs(vector<int> adj[],int s,int v){
    queue<int> q;
    q.push(s);
    bool visited[v]={false};
    visited[s]=true;
    while(!q.empty()){
        int f=q.front();
        vector<int>::iterator it;
        for(it=adj[f].begin();it!=adj[f].end();it++){
            int i=*it;
            if(visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
        cout<<"->"<<f;
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int v,n;
        cin>>v>>n;
        vector<int> adj[v];
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            addedge(adj,a,b);
        }
        bfs(adj,0,v);
        cout<<"\n";
    }
    return 0;
}