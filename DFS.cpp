//USE WITH CLASS GRAPH
class DFS { 
    public:
        DFS(Graph *g_) {
            g = g_;
            visited.resize(g->n, false);
            nodeValue.resize(g->n);
        }
        vector<bool> visited;
        vector<ll> nodeValue;
        Graph *g;

      ll run(int source, ll (*updateNodeValue)(int, vector<ll>)) {
        if(visited[source]) return nodeValue[source];
        
        visited[source] = true;
        vector<ll> children_node_values;
        for (pair<int,ll> u : (g->adj)[source]) {
          children_node_values.push_back(run(u.first,updateNodeValue));
        }
        nodeValue[source] = updateNodeValue(source,children_node_values);
        return nodeValue[source];
      }

};

//USAGE
DFS dfs(&g); 

//state is maintained across multiple runs
dfs.run(0, computeNodeValueUsingChildrenValues);

//when a node is visited, the return values of all it's childres is stored in the vector `children_node_values` and passed to this function. This function returns the node value of the current node, which will also be returned to its parent
ll computeNodeValueUsingChildrenValues(int node, vector<ll> children_node_values){
  //eg, each node value is the longest path from that node
  int longest_path = -1;
  for(auto longest_path_child: children_node_values)
      longest_path = max(longest_path_child+1, longest_path);
  return longest_path;
}
dfs.visited[i] // indicates if the node i was visited in the DFS
dfs.nodeValue[i] //value of the node i as computed using the `computeNodeValueUsingChildrenValues` function
