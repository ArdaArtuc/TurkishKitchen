#pragma once
#include <map>
#include <vector>
#include <string>
using namespace std;

class KitchenGraph {
public:
    map<string, vector<string>> adj;
    void addPath(string a, string b);
    void shortestPath(string start, string end);
};
