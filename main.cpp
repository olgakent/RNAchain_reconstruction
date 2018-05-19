/*******************************************************************************
Author:			Olga Kent
Course:		    CSCI 393 Independent Study / Graph theory
Professor:		Christina Zamfirescu
Name:			main.cpp

 A program that reconstructs the RNA chain out of two sets of fragments:
 1) one set is obtained after applying the G-enzyme on the RNA chain
 2) the other set is obtained after applying the UC-enzyme on another,
 identical RNA chain.

 Example input:
	gEnzyme  = "AUCG,AUG,G,CU,ACUAUACG";
	ucEnzyme = "GGAC,U,AU,GAU,C,U,AC,GC,AU";
 Example ouput:
	Possible chains
	AUCGGACUAUACGAUGCU
	AUCGAUGGACUAUACGCU
	AUGGACUAUACGAUCGCU
	AUGAUCGGACUAUACGCU
 *******************************************************************************/


#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;
#include"Graph.h"

void readEnzyme(vector<string> &enzyme) {
	string line,result="";
	getline(cin, line);
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			continue;
		}
		else if (line[i] == ',') {
			result += ' ';
		}
		else {
			result += line[i];
		}
	}
	stringstream input(result);
	while (input >> line) {
		enzyme.push_back(line);
	}
}

void splitEnzyme(string item, vector<string> &splited,char char1,char char2) {
	string current="";
	for (int i = 0; i < item.size(); i++) {
		if (item[i] == char1|| item[i] == char2) {
			current += item[i];
			splited.push_back(current);
			current = "";
		}
		else {
			current += item[i];
		}
	}
	if (current.size() > 0) {
		splited.push_back(current);
	}
}
void splitUCEnzyme(string item, vector<string> &splited) {
	string current = "";
	for (int i = 0; i < item.size(); i++) {
		if (item[i] == 'G')	{
			if (current.size() > 0) {
				splited.push_back(current);
			}
			current = "" + item[i];
			splited.push_back(current);
		}
		else {
			current += item[i];
		}
	}
}

int main() {

	cout << "**************************************************\n";
	cout << "              RNA CHAIN RECONSTRUCTION             \n";
	cout << "**************************************************\n";

	vector<string> gEnzyme;
	vector< vector<string> > gEnzymeSplit;

	vector<string> ucEnzyme;
	vector< vector<string> > ucEnzymeSplit;

	cout << "Enter G-enzyme fragments: ";
	readEnzyme(gEnzyme);

	int i;
	for (i = 0; i < gEnzyme.size(); i++) {
		vector<string> splited;
		splitEnzyme(gEnzyme[i], splited,'U','C');
		gEnzymeSplit.push_back(splited);
		for (int i1 = 0; i1 < splited.size(); i1++) {
			cout << splited[i1] << " ";
		}
		cout << endl;
	}

	cout << "Enter UC-enzyme fragments: ";
	readEnzyme(ucEnzyme);

	for (i = 0; i < ucEnzyme.size(); i++) {
		vector<string> splited;
		splitEnzyme(ucEnzyme[i], splited, 'G', 'G');
		ucEnzymeSplit.push_back(splited);
		for (int i1 = 0; i1 < splited.size(); i1++) {
			cout << splited[i1] << " ";
		}
		cout << endl;
	}

	Graph graph;
	for (i = 0; i < gEnzymeSplit.size(); i++) {
		graph.addVertex(gEnzymeSplit[i][0]);
		graph.addVertex(gEnzymeSplit[i][gEnzymeSplit[i].size()-1]);

		string arc = "";
		for (int i1 = 1; i1 < gEnzymeSplit[i].size()-1; i1++) {
			arc += gEnzymeSplit[i][i1];
		}
		if (gEnzymeSplit[i].size() > 1) {
			graph.addEdge(gEnzymeSplit[i][0], gEnzymeSplit[i][gEnzymeSplit[i].size() - 1],arc);
		}
	}
	for (i = 0; i < ucEnzymeSplit.size(); i++) {
		//graph.addVertex(gEnzymeSplit[i][0]);
		//graph.addVertex(gEnzymeSplit[i][gEnzymeSplit[i].size() - 1]);

		string arc = "";
		for (int i1 = 1; i1 < ucEnzymeSplit[i].size() - 1; i1++) {
			arc += ucEnzymeSplit[i][i1];
		}
		if (ucEnzymeSplit[i].size() > 1) {
			graph.addEdge(ucEnzymeSplit[i][0], ucEnzymeSplit[i][ucEnzymeSplit[i].size() - 1], arc);
		}
	}

	cout << "Possible chains: " << endl;

	graph.printEulerians();
	//cin.get();
	//cin.get();

	return 0;
}
