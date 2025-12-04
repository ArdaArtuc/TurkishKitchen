#pragma once
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include "Food.h"
#include <stack>
using namespace std;

class Kitchen {
private:
unordered_map<string, Food> menu;
queue<string> orderQueue;
stack<string> undoStack;
public:
void loadMenu();
void showMenu();
void placeOrder(string item);
void undoOrder();
void processOrder();
vector<string> getMenuItems();
};



