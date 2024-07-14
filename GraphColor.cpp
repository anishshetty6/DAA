#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101],int n,int col){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col)
            return false;
    }
    return true;
}

bool solve(int node,int color[],int m,int N,bool graph[101][101]){
    if(node==N){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(node,color,graph,N,i)){
            color[node]=i;
        }
        if(solve(node,color,m,N,graph)) return true;
        color[node]=0;
    }
    return false;
}



void printSolution(int color[],int N)
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for (int i = 0; i < N; i++)
        cout << " " << color[i] << " ";
 
    cout << "\n";
}

bool graphColor(bool graph[101][101],int m,int N){
    int color[N]={0};
    if(solve(1,color,m,N,graph))
    {printSolution(color,N);
    return true;}
    return false;
}
int main(){
    int N=3;
    int m=4;
    bool graph[101][101];
    memset(graph,false,sizeof graph);
    
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;
    
    cout<<graphColor(graph,m,N)<<endl;
}









