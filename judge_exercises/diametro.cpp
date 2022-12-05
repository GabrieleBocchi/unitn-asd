#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int index;
    bool visited;
    vector<Node *> adj;
};

class Graph
{
    public:
        int nodes;
        int edges = 0;
        vector<Node> arr;
        Graph(int N)
        {
            this->nodes = N;
            this->arr.resize(N);
            for (int i = 0; i < N; i++)
            {
                arr[i].index = i;
                arr[i].visited = false;
            }
        }
        void insertEdge(Node *src, Node *dst)
        {
            src->adj.push_back(dst);
            dst->adj.push_back(src);
            this->edges++;
        }
        int sizeNodes()
        {
            return this->nodes;
        }
        int sizeEdges()
        {
            return this->edges;
        }
        void print()
        {
            for (int i = 0; i < this->nodes; i++)
            {
                cout << i << " -> ";
                for (Node *node : arr[i].adj)
                    cout << node->index << "  ";
                cout << endl;
            }
        }
};

int findMaxDistance(Graph graph, Node *start)
{
    queue<Node *> coda;
    coda.push(start);
    int *distance = new int[graph.sizeNodes()];
    for (int i = 0; i < graph.sizeNodes(); i++)
        distance[i] = -1;
    distance[start->index] = 0;
    while (!coda.empty())
    {
        Node *u = coda.front();
        coda.pop();
        for (Node *node : u->adj)
        {
            if (distance[node->index] == -1)
            {
                distance[node->index] = distance[u->index] + 1;
                coda.push(node);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < graph.sizeNodes(); i++)
        if (distance[i] > max)
            max = distance[i];
    return max;
}

int main()
{
    int N, M, src, dst, tmp, result = 0;
    ifstream in("input.txt");
    in >> N >> M;

    Graph graph(N);

    for (int i = 0; i < M; i++)
    {
        in >> src;
        in >> dst;
        graph.insertEdge(&graph.arr[src], &graph.arr[dst]);
    }

    for (int i = 0; i < N; i++)
    {
        tmp = findMaxDistance(graph, &graph.arr[i]);
        result = max(tmp, result);
    }

    ofstream out("output.txt");
    out << result;

    in.close();
    out.close();

    return 0;
}
