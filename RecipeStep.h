#pragma once
#include <string>
#include <vector>
using namespace std;

struct RecipeStep {
   string name;
   vector<RecipeStep*> children;
   RecipeStep(string n) : name(n) {}
};
void printSteps(RecipeStep* root, int depth = 0);
