#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct VectorComparator {
    bool operator()(const std::vector<int>& v1, const std::vector<int>& v2) const {
        return v1[2] > v2[2];
    }
};

void primsAlgorithm(const vector<vector<int>>& towerMap, int node, vector<vector<int>>& output,
                    int& sum, priority_queue<std::vector<int>, std::vector<std::vector<int>>, VectorComparator>& currentSet,
                    std::unordered_set<int>& finishedSet) {
    if (finishedSet.count(node) > 0) {
        return;
    }
    for (int i = 0; i < towerMap.size(); i++) {
        if (towerMap[node][i] != INT_MAX) {
            currentSet.push({node, i, towerMap[node][i]});
        }
    }
    finishedSet.insert(node);

    while (true) {
        if (!currentSet.empty()) {
            vector<int> temp_node = currentSet.top();
            currentSet.pop();

            if (finishedSet.count(temp_node[0]) > 0 && finishedSet.count(temp_node[1]) > 0) {
                continue;
            }

            sum = sum + temp_node[2];
            output.push_back(temp_node);

            if (finishedSet.count(temp_node[0]) > 0) {
                primsAlgorithm(towerMap, temp_node[1], output, sum, currentSet, finishedSet);
                return;
            } else {
                primsAlgorithm(towerMap, temp_node[0], output, sum, currentSet, finishedSet);
                return;
            }
        }
        return;
    }
}

void minCost(std::vector<std::vector<int>> towerMap, int root) {
    priority_queue<std::vector<int>, std::vector<std::vector<int>>, VectorComparator> currentSet;
    unordered_set<int> finishedSet;
    vector<vector<int>> output;
    int sum = 0;

    primsAlgorithm(towerMap, root, output, sum, currentSet, finishedSet);

    cout << "Edges :" << endl;
    for (int i = 0; i < output.size(); i++) {
        cout << output[i][0] << " -- " << output[i][1] << " len - " << output[i][2] <<endl;
    }
    cout << "Total length :- " << sum;
}



int main() {
    vector<vector<int>> towerMap = {{INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,1},
                                    {3,INT_MAX,2,1,10,INT_MAX},
                                    {INT_MAX,2,INT_MAX,3,INT_MAX,5},
                                    {INT_MAX,1,3,INT_MAX,5,INT_MAX},
                                    {INT_MAX,10,INT_MAX,5,INT_MAX,4},
                                    {1,INT_MAX,5,INT_MAX,4,INT_MAX}};
    minCost(towerMap,0);

    return 0;
}
