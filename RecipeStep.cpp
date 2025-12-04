#include "RecipeStep.h"
#include <iostream>
using namespace std;

void printSteps(RecipeStep* root, int depth = 0) {
    for (int i = 0; i < depth;i++ ) {
        cout << "  "; 
    }
    cout << "- " << root->name << endl;
    for(auto c: root->children) {
        printSteps(c, depth + 1);
    }
}
