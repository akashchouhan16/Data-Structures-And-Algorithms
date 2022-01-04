/*
This is the Kruskal's Algorithm for getting the weight of minimum spanning tree for an undirected weighted graph.
The graph given is initially connected.
All the vertices are from 1 to n where n is the number of vertices in graph
*/

#include<bits/stdc++.h>

using namespace std;

// Implementing DSU for getting connected vertices
// Finding the Parent Node
int find_par(int v, int par[]) {
	if(v==par[v]) return v;
	return par[v] = find_par(par[v],par);
}

// Joining two vertices
bool join_set(int a,int b,int par[],int ran[]) {
	a = find_par(a,par);
	b = find_par(b,par);

	// Incase a and b are already connected
	if(a==b) return false;

	// Joining sets by putting a as parent of b
	if(ran[a] < ran[b]) swap(a,b);
	par[b] = a;
	ran[a]++;

	return true;
}

// Driver Function
int main() {
	// Input number of vertices
	int n;
	cout<<"Enter number of Vertices: ";
	cin>>n;

	// Input number of edges
	int e;
	cout<<"Enter Number of Edges: ";
	cin>>e;

	// Input Edges
	cout<<"Enter Edges:\n";
	vector<pair<int,pair<int,int> > > edges;
	for(int i=0;i<e;i++) {
		// Input format - vertex 1, vertex 2, weight of the edge
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({w,{u,v}});
	}

	// Sorting edges on the basis of their weight
	sort(edges.begin(),edges.end());

	// Getting MST
	long long int mst = 0;

	// Initialising parent array and rank array
	int par[n+1],ran[n+1];
	for(int i=1;i<=n;i++) {
		par[i]=i;
		ran[i]=1;
	}

	// Weight of MST
	for(auto edge: edges) {
		int u = edge.second.first;
		int v = edge.second.second;
		int w = edge.first;

		// If join set is successfull add weight to mst
		if(join_set(u,v,par,ran)) {
			mst += w;
		}
	}
	cout<<"MST Weight: "<<mst;
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