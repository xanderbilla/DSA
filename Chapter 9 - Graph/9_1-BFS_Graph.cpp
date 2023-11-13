#include <iostream>
#include <queue>

class Graph
{
    int V;
    int** adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;

    adj = new int*[V];
    for (int i = 0; i < V; ++i)
    {
        adj[i] = new int[V];
        for (int j = 0; j < V; ++j)
            adj[i][j] = 0;
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v][w] = 1;
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int* queue = new int[V];
    int front = 0, rear = 0;

    visited[s] = true;
    queue[rear++] = s;

    while (front != rear)
    {
        s = queue[front++];
        std::cout << s << " ";
        
        for (int adjacent = 0; adjacent < V; ++adjacent)
        {
            if (adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }

    std::cout << std::endl;

    delete[] visited;
    delete[] queue;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Breadth First Traversal "
              << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
