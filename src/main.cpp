//#include <bits/stdc++.h>
#include <iostream>
#include "graph_algorithms.h"
#include "helper_functions.h"
#include "csr_graph.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    int VERTEX_COUNT = 3600;
    int EDGE_COUNT = 55000;
    
    string sNodes = "../input_data/air-routes-latest-nodes.csv";
    string sEdges = "../input_data/air-routes-latest-edges-sorted.csv";
    CSR_graph g(sNodes, sEdges, 55000, 3600);
      
    int size = 0;
    int airport_selection;
    //cout << "Enter the id of the airport you would like to select: ";
    //cin >> airport_selection;

    //cout << "Printing results for aiport with id " << airport_selection << ": " << endl;

    vector<int>& V=g.getNodes();
    vector<int>& E=g.getEdges();
    for(int i = 0; i < V.size(); i++){
        //cout << "Current Airport: " << i <<" "<< V[i] << endl;
    }
    
    //g.print_edges(airport_selection);

    int s = 0;
    int d = 0;

    cout << "Enter ids for pathfinding: ";

    cin >> s;
    cin >> d;

    if(g.CSR_DFS(s, d)){
        cout << "DFS: Found airport" << endl;
    }
    else{
        cout << "DFS: Did not find airport" << endl;
    }

    if(g.CSR_BFS(1, 11)){
        cout << "BFS: Found airport." << endl;
    }
    else{
        cout << "BFS: Did not find airport." << endl;
    }

    return 0;
}
