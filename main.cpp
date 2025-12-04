#include <iostream>
#include "Kitchen.h"
#include "RecipeStep.h"
#include "KitchenGraph.h"
using namespace std;

int main(){
    Kitchen kitchen;
    kitchen.loadMenu();



    RecipeStep* menemen = new RecipeStep("Menemen");
    RecipeStep* chop = new RecipeStep("Chop");
    chop->children.push_back(new RecipeStep("Tomatoes"));
    chop->children.push_back(new RecipeStep("Peppers"));
    RecipeStep* cook = new RecipeStep("Cook");
    cook -> children.push_back(new RecipeStep("Eggs"));
    RecipeStep* season = new RecipeStep("Season");
    menemen->children.push_back(chop);
    menemen->children.push_back(cook);
    menemen->children.push_back(season);

    KitchenGraph g;
    g.addPath("Prep", "Stove");
    g.addPath("Stove", "Oven");
    g.addPath("Oven", "Plating");
    g.addPath("Prep", "Storage");

    int choice;
    do{
        cout<<"\n=== Turkish Kitchen ===\n";
        cout<<"1. Show Menu 2. Place Order 3. Undo 4. Process Order 5. Show Recipe 6. Kitchen Path 7. Exit\nChoice: ";
        cin>>choice; cin.ignore();
        if(choice ==1) kitchen.showMenu();
        else if(choice == 2){ string f; cout<<"Enter food: "; getline(cin,f); kitchen.placeOrder(f);}
        else if(choice == 3) kitchen.undoOrder();
        else if(choice == 4) kitchen.processOrder();
        else if(choice == 5){ cout<<"\n--- Menemen Recipe ---\n"; printSteps(menemen);}
        else if(choice == 6) g.shortestPath("Prep", "Plating");
    }while(choice !=7);
    return 0;
    }

