#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void djisktra(vector<vector<int>> &cityMap, int node, vector<int> &minDistances, unordered_set<int> &visited) {
    if (visited.count(node) > 0) {
        return;
    }
    visited.insert(node);
    for (int i = 0; i < minDistances.size(); i++) {
        if (cityMap[node][i] == 0) {
            continue;
        }
        if (minDistances[node] + cityMap[node][i] < minDistances[i]) {
            minDistances[i] = minDistances[node] + cityMap[node][i];
        }
    }
    int minEdge = INT_MAX;
    int nextNode = -1;
    for (int i = 0; i < minDistances.size(); i++) {
        if (visited.count(i) == 0 && minDistances[i] < minEdge) {
            minEdge = minDistances[i];
            nextNode = i;
        }
    }
    if (nextNode != -1) {
        djisktra(cityMap, nextNode, minDistances, visited);
    }
}

vector<int> djikstra_Algorithm(vector<vector<int>> cityMap, int startNode, int nodeNum) {
    vector<int> minDistances(nodeNum, INT_MAX);
    minDistances[startNode] = 0;
    unordered_set<int> visited;
    djisktra(cityMap, startNode, minDistances, visited);
    return minDistances;
}

int main() {
    vector<vector<int>> cityMap = {{0, 10, 0, 0, 15, 5},
                                   {10, 0, 10, 30, 0, 0},
                                   {0, 10, 0, 12, 5, 0},
                                   {0, 30, 12, 0, 0, 20},
                                   {15, 0, 5, 0, 0, 0},
                                   {5, 0, 0, 20, 0, 0}};

    for (int i = 0; i< cityMap.size(); i++) {
        int sum = 0;
        vector<int> vec =  djikstra_Algorithm(cityMap, i, 6);
        for (auto num: vec) {
            sum += num;
        }
        cout << "from City " << i << " " << "--> ";
        for (int j = 0; j < cityMap.size(); j++) {
            cout << vec[j] << " ";
        }
        cout << "total distance --> " << sum  ;
        cout << endl;
    }

    return 0;
}

