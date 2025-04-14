//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool isValid(vector<int>& neighbours, int c, vector<int>& colours){
        for(int i=0; i<neighbours.size(); i++) {
            if(colours[neighbours[i]]==c) return false;
        }
        return true;
    }
    
    bool helper(int v, vector<pair<int, int>>& edges, int m, int node) {
        
        if(node == v) return true;
        
        unordered_map<int, vector<int> >graph;
        vector<int> colours(v,-1);

        for(int i=0; i<edges.size(); i++) {
                graph[edges[i].first].push_back(edges[i].second);
                graph[edges[i].second].push_back(edges[i].first);
        }
       
        for (auto& itr : graph) {
            int node = itr.first;
            vector<int>& neighbours = itr.second;
            sort(neighbours.begin(), neighbours.end(), [&](int a, int b) {
                    return graph[a].size() < graph[b].size();
                });
        }
        for(auto itr = graph.begin(); itr!=graph.end(); itr++){
            if(colours[itr->first] == -1) {
                for(int c=1; c<=m; c++) {
                    if(isValid(itr->second, c, colours)){
                        colours[itr->first] = c;
                        if(helper(v, edges, m, itr->first+1)) return true;
                        else colours[itr->first] = -1;
                    }
                }
                return false;
            }
        }
        
        return true;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    
        return helper(v, edges, m, 0);
    }
};







        //to ge thte entire graph printed
        // for(auto itr = graph.begin(); itr!=graph.end(); itr++) {
        //     cout<<itr->first<<": ";
        //     for(int i=0; i<itr->second.size(); i++) cout<<itr->second[i]<<" ";
        //     cout<<endl;
        // }
        
        











//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends