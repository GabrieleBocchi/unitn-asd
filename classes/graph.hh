#include <iostream>
#include <vector>
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

class OrientedGraph : public Graph
{
    public:
        OrientedGraph(int n) : Graph(n) {}
        void insertEdge(Node *src, Node *dst)
        {
            src->adj.push_back(dst);
            this->edges++;
        }
};