/*
This is the Prims Algorithm for getting the weight of minimum spanning tree for an undirected weighted graph.
The graph given is initially connected.
All the vertices are from 1 to n where n is the number of vertices in graph
*/

#include<bits/stdc++.h>

using namespace std;

// Driver Function
int main() {
	// Input number of Vertices
	int n;
	cout<<"Enter number of Vertices: ";
	cin>>n;

	// Input number of edges
	int e;
	cout<<"Enter number of Edges: ";
	cin>>e;

	// Input Edges
	cout<<"Enter Edges:\n";
	vector<vector<pair<int,int> > > adj(n+1); // Adjacency List
	for(int i=0;i<e;i++) {
		// Input format - vertex 1, vertex 2, weight of the edge
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	// Getting MST
	
	bool vis[n+1]; // Check if vertex is already visited
	memset(vis,false,sizeof(vis)); // Initially all vertices are not visited

	// Getting the closest vertex to current minimum spanning tree
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > ver;

	// Initial Condition
	ver.push({0,1}); // Starting vertex is 1

	// Weight of MST
	long long int mst = 0;
	while(!ver.empty()) {
		pair<int,int> top = ver.top();
		ver.pop();
		int u = top.second; // Vertex
		int w = top.first;	// Weight

		// Check if vertex is visited
		if(vis[u]) continue;

		vis[u] = true; // Mark current vertex as visited

		mst += w;

		// Add vertices directly connected to current mst
		for(auto v: adj[u]) {
			if(!vis[v.first]) {
				ver.push({v.second,v.first});
			}
		}
	}
	cout<<"MST weight: "<<mst;
	return 0;
}

/* 
Sample Input 1:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

Sample Output 1:
17

Sample Input 2:
5 5
1 3 10
2 3 10
3 4 20
4 5 20
1 5 1

Sample Output 2:
41
*/