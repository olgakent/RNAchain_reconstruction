#include<string>
#include<vector>
using namespace std;

struct Edge;

struct Node {
	string label;
	vector<Edge*> outEdges;
	vector<Edge*> inEdges;
	bool start;
};

struct Edge {
	string label;
	Node *origin;
	Node *destination;
	bool used;
};

class Graph {
private:
	vector<Node*>nodes;
	vector<Edge*>edges;
	vector<string>paths;
	Node*findVertex(string name);
	void visit(Node* current, string path);
	bool completePath();
	void addPath(string path);
public:
	void addVertex(string name);
	void addEdge(string origin,string destination,string label);
	void printEulerians();
	Graph();
	~Graph();
};
