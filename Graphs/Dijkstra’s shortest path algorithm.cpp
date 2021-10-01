/*
Problem Statement:
Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.

Sample Test Case:

0   4   0   0   0   0   0   8   0   

4   0   8   0   0   0   0   11   0   

0   8   0   7   0   4   0   0    2   

0   0   7   0   9   14   0   0   0   

0   0   0   9   0   10   0   0   0   

0   0   4   14   10   0   2   0  0   

0   0   0   0   0   2   0   1    6   

8   11   0   0   0   0   1   0   7   

0   0   2   0   0   0   6   7    0   

Vertex 		 Distance from Source

0 		 0

1 		 4

2 		 12

3 		 19

4 		 21

5 		 11

6 		 9

7 		 8

8 		 14
*/

#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>g){
   for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++)
        {
            cout<<g[i][j]<<"   ";
        }
        cout<<endl;
    }  
    cout<<endl;
}
int min_distance(int distance[],bool s[],int n){
    int ind;
    int min_d=INT_MAX;
    for(int i=0;i<n;i++){
        if(s[i]==false && min_d>=distance[i]){
            ind=i;
            min_d=distance[i];
        }
    }
    return ind;
}
void disp(int dist[],int n)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(vector<vector<int>>g,int src){
    int n=g.size();
    int distance[n];
    bool s[n];
    for(int i=0;i<n;i++){
        s[i]=false;
        distance[i]=INT_MAX;
    }
    distance[src]=0;
    for(int i=0;i<n;i++){
        int u=min_distance(distance,s,n);
        s[u]=true;
        for (int v = 0; v < n; v++)
             if (s[v]==false && g[u][v] && distance[u] != INT_MAX && distance[u] + g[u][v] < distance[v])
                distance[v] = distance[u] + g[u][v];
    }
   disp(distance,n);  
}
int main(){
    vector<vector<int>>g= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    display(g);
    dijkstra(g,0);
    return 0;
}

