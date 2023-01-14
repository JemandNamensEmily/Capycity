#include "CapycitySim.h"
#include <iostream>
#include <list>
//#include <algorithm>
using namespace std;

CapycitySim::CapycitySim(){
    cout<<"Please Create your first plan:"<<endl;
    currentBlueprint = nullptr;
    CurrentPlanNum=0;
    newPlan();

}
void CapycitySim::deleteduplicatePlan(Blueprint* myblueprint){//deletes any copys of myblueprint it finds
        for(list<Blueprint*>::iterator k = Blueprintset.begin();k!=Blueprintset.end();k++){
            if(currentBlueprint!=*k &&(*myblueprint)(**k)){
                    //not same pointer, delete copy
                    cout<<"Plan "<<(*k)->GetPlanNum()<<" deleted, copy exists in Plan "<<myblueprint->GetPlanNum()<<endl;
                    delete *k;
                    Blueprintset.erase(k);
                    return;//don't need to keep looking
            }
        }
}
void CapycitySim::newPlan(){
    //deal with current Blueprint
    deleteduplicatePlan(currentBlueprint);
    CurrentPlanNum++;
    //get area size
    cout<<"How wide is your area? ";
    int width;
    do{
        cin>>width;
    }while(width<=0);

    cout<<"How long is it? ";
    int len;
    do{
        cin>>len;
    }while(len<=0);
    //create
    currentBlueprint = new Blueprint(len,width,CurrentPlanNum);
    //add to list
    Blueprintset.push_back(currentBlueprint);
    cout<<"Plan "<<currentBlueprint->GetPlanNum()<<" is open"<<endl;

}
void CapycitySim::planMenue(){
    cout<<"Would you like to create a new Plan -N or access an old Plan -O or Quit -Q?"<<endl;
    char todo;
    cin>>todo;
    todo = toupper(todo);
    if(todo=='N'){
        newPlan();
    }
    else if(todo=='O'){
        deleteduplicatePlan(currentBlueprint);//delete any existing copys of the old Plan

        cout<<"Which plan would you like to open? ";
        //show options
        for(auto k: Blueprintset){
            cout<<k->GetPlanNum()<<" ";
        }
        cout<<endl;
        int num;//plan to open
        cin>>num;
        //find the plan of that number
        bool found = false;
        for(auto k:Blueprintset){
            if(k->GetPlanNum()==num){
                currentBlueprint = k;
                found = true;
            }
        }
        if(!found){
            cout<<"Plan could not be found."<<endl;
        }
        else{
            cout<<"Plan "<<num<<" now open."<<endl;
        }

    }
}
void CapycitySim::printall(){//print in descending order of Kennzahl
    auto sortRule = [](Blueprint*& plan1, Blueprint*& plan2){
        return plan1->calculateKennzahl()>plan2->calculateKennzahl();
    };
    Blueprintset.sort(sortRule);
    cout<<endl;
    for(auto k: Blueprintset){

        k->print();
        cout<<endl<<endl;
    }
}
CapycitySim::~CapycitySim(){
    for(auto k: Blueprintset){
        if(k!=nullptr){
            delete k;
            k=nullptr;
        }
    }
    //don't delete currentPlan, it's in the set
}
