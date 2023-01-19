//#include <bits/stdc++.h>
#include <iostream>
#include "graph_algorithms.h"
#include "helper_functions.h"
#include "csr_graph.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    string sNodes = "../input_data/air-routes-latest-nodes.csv";
    string sEdges = "../input_data/air-routes-latest-edges-sorted.csv";
    CSR_graph g(sNodes, sEdges, 55000, 3600);
      
    int size = 0;
    int airport_selection;
    cout << "Enter the id of the airport you would like to select: ";
    cin >> airport_selection;

    cout << "Printing results for aiport with id " << airport_selection << ": " << endl;

    //fix all the getNodes()
    vector<int>& V=g.getNodes();
    vector<int>& E=g.getEdges();
    for(int i = 0; i < V.size(); i++){
        cout << "Current Airport: " << i <<" "<< V[i] << endl;
    }
    
    int startPos = V.at(airport_selection);
    int endPos = 0;
    if(airport_selection == V.size()){
        endPos = E.size()+1;
    }
    else{
        endPos = V.at(airport_selection+1);
    }

    cout << "Printing results for aiport with id " << airport_selection << ": " << endl;

    for(int i = startPos; i < endPos; i++){
        cout << E.at(i) << endl;
    }

    return 0;
}
