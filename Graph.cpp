/*******************************************************************************
Author:			Olga Kent
Course:		    CSCI 393 Independent Study / Graph theory
Professor:		Christina Zamfirescu
Name:			Graph.cpp
*******************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;


#include "Graph.h"



Node * Graph::findVertex(string name) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->label == name)
			return nodes[i];
	}
	return NULL;
}

void Graph::visit(Node * current,string path) {
	// check if end;
	path = path + current->label;
	if (current->inEdges.size() == current->outEdges.size()+1) {
		if (completePath()) {
			addPath(path);
			return;
		}
	}
	for (int i = 0; i < current->outEdges.size(); i++) {
		if (current->outEdges[i]->used == false) {
			current->outEdges[i]->used = true;
			visit(current->outEdges[i]->destination,path+current->outEdges[i]->label);
			current->outEdges[i]->used = false;
		}
	}
}

bool Graph::completePath() {
	for (unsigned int i = 0; i < edges.size(); i++) {
		if (edges[i]->used==false) {
			return false;
		}
	}
	return true;
}

void Graph::addPath(string path) {
	for (int i = 0; i < paths.size(); i++) {
		if (paths[i] == path)
			return;
	}
	paths.push_back(path);
}

void Graph::addVertex(string name) {
	if (findVertex(name) == NULL) {
		Node *node = new Node;
		node->label = name;
		nodes.push_back(node);
	}
}

void Graph::addEdge(string origin, string destination, string label) {
	addVertex(origin);
	Node *originNode = findVertex(origin);
	addVertex(destination);
	Node *destinationNode = findVertex(destination);
	Edge *edge = new Edge();
	edge->label = label;
	edge->destination = destinationNode;
	edge->origin = originNode;
	edge->used = false;
	destinationNode->inEdges.push_back(edge);
	originNode->outEdges.push_back(edge);
	edges.push_back(edge);
}

void Graph::printEulerians() {
	paths.clear();
	int i;
	for (i = 0; i <(int) nodes.size(); i++) {
		if (nodes[i]->inEdges.size() == nodes[i]->outEdges.size() - 1) {
			visit(nodes[i], "");
		}
	}
	for (i = 0; i <(int)paths.size(); i++) {
		cout << paths[i] << endl;
	}
}


Graph::Graph()
{
}


Graph::~Graph()
{
}
