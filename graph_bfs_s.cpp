#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;
    cin>>n;
    vector<int>v[n+1];
    vector<bool>visit(n+1,false);
    queue<int>q;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>a;
    /*
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    */
    q.push(1);
    int c=0;
    while(a>1 && !q.empty()){
        int val=q.front();
        visit[val]=true;
        q.pop();
        int i=0;
        while(i<v[val].size()){
            q.push(v[val][i]);
            i++;
        }
        a--;
    }
    
    while(!q.empty()){
        int val=q.front();
        if(visit[val]!=true){
            visit[val]=true;
            c++;
        }
        q.pop();
    }
    
    //c=q.size();
    cout<<c<<endl;
    return 0;
}