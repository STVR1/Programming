#include <iostream>
#include<string>
#include<regex>
#include <vector>
#include <algorithm>
#include<fstream>
using namespace std;
//Class for Graph representation 
class Graph {
public:
    //Vector of vectors for incidence list
    vector<vector<int>> adjList;
    //Incidence list
    Graph(vector<vector<int>> const& edges, int n) {
        adjList.resize(n);
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (i == edges[j][0]) {
                   for (int k = 1; k < 2; k++) {
                       adjList[i].push_back(edges[j][k]);
                   }
                }
            }
        }
    }
};
//Function for showing the incidence list
void printGraph(Graph const& graph, int n) {
    for (int i = 0; i < n; i++){
        cout << i << " --> ";
        for (int v : graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
//Function for visiting all other vertexes from the certain chosen one 
void DFS(Graph const& graph, int i, vector<bool>& visited) {
    //Mark the current vertex
    visited[i] = true;
    //Start our cycle
    for (int u : graph.adjList[i]){
        if (!visited[u]) {
            DFS(graph, u, visited);
        }
    }
}
//Function for checking our Graph
bool isStronglyConnected(Graph const& graph, int n) { 
    //Take the certain vertex
    for (int i = 0; i < n; i++){
        //Vector for marking out visits
        vector<bool> visited(n);
        //Start to move
        DFS(graph, i, visited);
        //If vector has the element 0 (false), this graph isn't strongly connected 
        if (find(visited.begin(), visited.end(), false) != visited.end()) {
            return false; //Return our result
        }
    }
    return true; //Return our result (if the cycle is fully completed)
}
//Function for checking txt file
string check() {
    string pathcheck;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path for txt file\n";
        getline(cin, pathcheck);
    } while (!regex_match(pathcheck, checking));
    return pathcheck;
}
int main(){   
    //The first step is writing all edges to our vector of vectors and checking a thing: all edges must be directed 
    vector<vector<int>> edges;                  //Set variables for working with file
    fstream file;
    string path = check();                     
    int i = 0;
    bool directed = true;
    int limit1 = 0;
    int limit2 = 0;
    char c[1];
    int size = 1;
    vector<int> temp;
    file.open(path, fstream::in);               //Open file
    if (file.is_open()) {
        while (!file.eof()) {
            c[0] = file.get();
            if (isdigit(c[0])) {
                temp.push_back(atoi(c));
                i++;
            }
            else if (c[0] == '-' && temp[i - 1] == -1) {                    //Define the graph's edges on direction 
                temp.push_back(-2);                                         //and write to our vector (temp)
                i++;                                                        //certain integers.
                directed = false;                                           //We also lead a counter to define the size
            }                                                               //of our vector of vectors of edges
            else if (c[0] == '\n') {
                size++;
                temp.push_back(-1);
                i++;
            }
            else {
                temp.push_back(-1);
                i++;
            }
        }
        file.close();             //Close file
    }     
    else {
        cout << "Error. Can't open it\n";
        file.close();
        return 0;
    }
    edges.resize(size);
    int point = 0;                                                 //On this step we write correct numbers (vertexes)
    i = 0;                                                         //in out vector of vectors of edges
    for (int j = 0; j < temp.size(); j++) {
        if (temp[j] != -1 && temp[j] != -2 && limit1 == 0) {
            point = temp[j];
            limit1++;
        }
        else if (temp[j] != -1 && temp[j] != -2 && limit1 > 0) {
            point = point * 10 + temp[j];
        }
        if (temp[j] != -1 && temp[j] != -2 && temp[j + 1] == -1) {
            edges[i].push_back(point);
            point = 0;
            limit1 = 0;
            limit2++;
            if (limit2 == 2) {
                i++;
                limit2 = 0;
            }
        }
    }
    int max = edges[0][0];
    int n = 0;                                         //Here I calculate the number of vertexes using the method
    for (i = 0; i < edges.size(); i++) {               //of max meaning
        for (int j = 0; j < 2; j++) {
            if (edges[i][j] > max) {
                n = edges[i][j]+1;
                max = edges[i][j];
            }
            else {
                n = max+1;
            }
        }
    }
    //Start to make the task
    //Check a thing: Graph must be directed
    if (directed==true) {
        //Build a graph 
        Graph graph(edges, n);
        printGraph(graph, n);
        //Check the type of graph
        if (isStronglyConnected(graph, n)) {
            cout << "\nThe graph is strongly connected";
        }
        else {
            cout << "\nThe graph is not strongly connected";
        }
    }
    else {
        cout << "\nThe graph is not strongly connected";
    }
    return 0;
}