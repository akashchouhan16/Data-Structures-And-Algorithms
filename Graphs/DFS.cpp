#include <list>
#include <cstdlib>
#include <iostream>
#include <iterator>
using namespace std;

class Graph
{
    int vertex;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new list<int>[vertex];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void DFS(int v);
};
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << ", ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            DFSUtil(*i, visited);
    }
}
void Graph::DFS(int v)
{

    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}
int main()
{
    int vertices;
    cout << "Enter Number of vertices : ";
    cin >> vertices;
    Graph gp(vertices);
    cout << "Enter valid edges(u to v) \n(Enter -1 -1 to terminate)\n : ";
    do
    {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;
        else
            gp.addEdge(u, v);
    } while (1);

    cout << "\nDFS Traversals";
    cout << "\nStarting from 0 : ";
    gp.DFS(0);
    cout << "\nStarting from 1 : ";
    gp.DFS(1);
    cout << "\nStarting from 2 : ";
    gp.DFS(2);
    return 0;
}