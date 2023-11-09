/*
    Not so simple Graph

    Write C++ code for implementing a Graph data structure that supports a directed graph with 
    self-loops and parallel edges. You are expected to implement the following methods and a main
    method is already built for you:

        void *insertEdge*(int from, int to, int weight);   // 1
        bool *isEdge*(int from, int to);                   // 2
        int *sumEdge*(int from, int to);                   // 3
        vector<int> *getWeight*(int from, int to);         // 4
        vector<int> *getAdjacent*(int vertex);             // 5


    Sample Input:
        7    
        1 0 0 10  
        1 0 1 20 
        1 0 2 30
        2 0 0  
        3 0 2 
        4 0 1
        5 0
    
    Sample Output:
        1  
        30
        20 
        0 1 2
*/
//Partner - Samantha Bennett
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Graph {
   private:
       std::map <std::pair<int, int>, std::vector<int>> m;

    public:
      void insertEdge(int from, int to, int weight);  
      bool isEdge(int from, int to);  
      int sumEdge(int from, int to); 
      std::vector<int> getWeight(int from, int to); 
      std::vector<int> getAdjacent(int vertex); 
};

void Graph::insertEdge(int from, int to, int weight) {
    m[make_pair(from, to)].push_back(weight);
}
        
bool Graph::isEdge(int from, int to) {
    for (auto member : m) {
        if (member.first.first == from && member.first.second == to)
			return true;
    }
    return false;
}

int Graph::sumEdge(int from, int to) {
    int sum = 0;
    for (int i = 0; i < m[make_pair(from, to)].size(); i++) {
        sum += m[make_pair(from, to)][i];
    }

    return sum;
}

std::vector<int> Graph::getWeight(int from, int to) {
    sort(m[make_pair(from, to)].begin(), m[make_pair(from, to)].end());
    return m[make_pair(from, to)];
}

std::vector<int> Graph::getAdjacent(int vertex) {
    vector<int> adjacent;
    for (auto member : m) {
        if (member.first.first == vertex) {
            for(int j = 0; j < member.second.size(); j++)
			    adjacent.push_back(member.first.second);
		}
        else if (member.first.second == vertex) {
            for (int j = 0; j < member.second.size(); j++)
            adjacent.push_back(member.first.first);
        }
	}
    sort(adjacent.begin(), adjacent.end());
    return adjacent;
}
