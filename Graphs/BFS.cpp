#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
//For Un-directed Graph
void Edge(int x, int y)
{
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void BreadthFirstSearch(int vertex)
{

    queue<int> Q;
    Q.push(vertex);
    visited[vertex] = true;
    while (!Q.empty())
    {
        int v = Q.front();
        cout << v << ", ";
        Q.pop();

        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            if (!visited[*i])
            {
                Q.push(*i);
                visited[*i] = true;
            }
        }
    }
}
int main()
{
    int n, e, x, y;
    cout << "Enter the Number of Vertices(n) and Edges(e) : ";
    cin >> n >> e;
    visited.assign(n, false);
    graph.assign(n, vector<int>());
    cout << "Enter the values for the Un-directed Graph : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        Edge(x, y);
    }
    cout << endl
         << "BFS : ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BreadthFirstSearch(i);
        }
    }
    return 0;
}