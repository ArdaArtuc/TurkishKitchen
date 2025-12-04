#include "Kitchen.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Kitchen::loadMenu(){
    menu["Adana Kebap"] = {"Adana Kebap", {"Kıyma","Pul biber","Tuz"}, 15};
    menu["Iskender"] = {"Iskender", {"Doner","Pide","Yogurt", "Tereyagi"}, 20};
    menu["Menemen"] = {"Menemen", {"Yumurta","Domates","Biber"}, 10};
    menu["Kuru Fasulye"] = {"Kuru Fasulye", {"Fasulye","Salca","Sogan"}, 25};
    menu["Baklava"] = {"Baklava", {"Yufka","Fistik","Serbet"}, 30};
}

void Kitchen::showMenu(){
    cout<<"\n--- Menu ---\n";
    for(auto &m: menu)
        cout<<"- "<<m.first<<"("<<m.second.time<<"min)\n";
}

void Kitchen::placeOrder(string item){
    if(menu.count(item)){
        orderQueue.push(item);
        undoStack.push(item);
        cout<<"Order added: "<<item<<endl;
    } else cout<<"Item not found.\n";
}
void Kitchen::undoOrder(){
    if(!undoStack.empty()){
       cout<<"Undo: "<<undoStack.top()<<endl;
         undoStack.pop();
    } else cout<<"No orders to undo.\n";
}
void Kitchen::processOrder(){
    if(!orderQueue.empty()){
        cout<<"Cooking "<<orderQueue.front()<<"...\nDone!\n";
        orderQueue.pop();
    } else cout<<"No orders to process.\n";
    }
vector<string> Kitchen::getMenuItems(){
    vector<string> items;
    for(auto &m: menu)
        items.push_back(m.first);
        sort(items.begin(), items.end());
    return items;
}
