#include <bits/stdc++.h>
#include <vector>
#include "edge.h"
#include "node.h"
#include "graph_algorithms.h"
#include "helper_functions.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

class CSR_graph{
    private:
        /*
        nodes: contains an int that indicates where the edges corresponding to that index is located in "edges"
        edges: contains the destinations that each node in nodes has a flight to
        aiport_information: contains other important information about each aiport
        edge_distances: corresponds to edges and matches each edge to how far the distance is
        */
        vector<int> nodes;
        vector<int> edges;
        vector<int> airport_information;
        vector<int> edge_distances; 
    public:
        //constructs the CRS graph using Kevin L. Lawrences airport dataset
        CSR_graph(string node_file, string edge_file, size_t max_edges, size_t max_verticies) : nodes(max_verticies, -1) {
            ifstream node_inputFile(node_file);
            ifstream edge_inputFile(edge_file);

            if(node_inputFile.is_open()){
                cout << "Opened successfully." << endl;
            }
            else{
                cout << "Cannot open file." << endl;
            }

            string node_id = "";
            string edge_info = "";

            string line = "";
            vector<vector<string>> node_data;
            vector<vector<string>> edge_data;

            while(getline(node_inputFile, line)){
                vector<string> vec;
                boost::algorithm::split(vec, line, boost::is_any_of(","));
                node_data.push_back(vec);
            }

            while(getline(edge_inputFile, line)){
                vector<string> vec;
                boost::algorithm::split(vec, line, boost::is_any_of(","));
                edge_data.push_back(vec);
            }

            edge_data.erase(edge_data.begin());     

            int prevAirportIndex = 0;
            int edgeCount = 0;
            for(vector<std::string> vec : edge_data){
                int currAirportIndex = stoi(vec.at(0));
                int currAirportEdge = stoi(vec.at(1));
                if(currAirportIndex != prevAirportIndex){
                    nodes.at(currAirportIndex) = edges.size();
                    prevAirportIndex = currAirportIndex;
                    //cout << "NEW AIPORT ALERT! - " << currAirportIndex << endl;
                }
                //cout << currAirportEdge << endl;
                edges.push_back(currAirportEdge);
            }

            for (int i = 1; i < nodes.size(); i++) {
                if (nodes[i] == -1) {
                    nodes[i] = nodes[i-1];
                }
            }

            edge_inputFile.close();
            node_inputFile.close();
        }

        //TODO: function that returns a pointer to an array of destinations for given airport
        int* extractDestinations(int airport_id, int& _size){
            int startPos = nodes.at(airport_id);
            int endPos = 0;
            if(airport_id == nodes.size()){
                endPos = edges.size()+1;
            }
            else{
                endPos = nodes.at(airport_id+1);
            }

            _size = endPos-startPos;
            return &(edges.at(startPos));
        }

        vector<int>& getNodes(){
            return nodes;
        }

        vector<int>& getEdges(){
            return edges;
        }
        //TODO: BFS and DFS starting at a given airport

        //TODO: shortest path between two airports

        //TODO:
};