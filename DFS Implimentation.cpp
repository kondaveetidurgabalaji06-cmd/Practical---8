#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next, graph, visited);
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);

    cout << "\nDFS Traversal: ";

    DFS(start, graph, visited);

    cout << endl;

    return 0;
}
