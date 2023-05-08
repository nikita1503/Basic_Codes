//COPY THE BLACKBOX, there is no need to change anything in it.
//Check the main function at bottom for USAGE

//****************BLACKBOX START*****************
//START COPYING FROM HERE
class Graph {
	vector<vector<pair<int,ll>>>adj;
	int n;
	bool is_directed;
	
	public:
		vector<ll>min_dist_from_source;
		Graph(int n_, bool is_directed_){
			n=n_; is_directed = is_directed_;
			adj.resize(n,vector<pair<int,ll>>());
		}

		bool node_has_edges(int u) {
			return (adj[u].size()!=0);
		}
		void add_edge(int u, int v, ll c=0){
			add_edge_weighted_undirected(u,v,c);
			if(!is_directed)
				add_edge_weighted_undirected(v,u,c);
		}

		void BFS(int source, bool clean=false){
			if(min_dist_from_source.size()==0)
				min_dist_from_source.resize(n,-1);
			else if(clean) {
				min_dist_from_source.clear();
				min_dist_from_source.resize(n,-1);
			}

			vector<bool> visited(n, false);
			queue<int> q;
			q.push(source);
			
			visited[source] = true;
			min_dist_from_source[source] = 0;
			
			while(!q.empty()) {
				int cur_node = q.front();
				vector<pair<int,ll>> cur_node_adj = adj[cur_node];
			
				for (unsigned int i = 0; i < cur_node_adj.size(); ++i) {
					int adj_node = cur_node_adj[i].first;
					if (visited[adj_node] == false) {
						visited[adj_node] = true;
						min_dist_from_source[adj_node] = min_dist_from_source[cur_node] + 1;
						q.push(adj_node);
					}
				}
				q.pop();
			}
			
			return;
		}

	private :
		void add_edge_weighted_undirected(int u, int v, ll c) {
			pair<int,ll>p = make_pair(v,c);
			adj[u].push_back(p);
		}
	
};

//END COPYING HERE
//********************BLACKBOX END******************


int main() {
   // Initialise graph; input = number of nodes, is_directed
  Graph g(4, false);
  
  // Add Weighted edge
  g.add_edge(u,v,weight);
	
  // Add Un-Weighted edge
  g.add_edge(u,v);
 
  //do BFS on the graph g start at Source
  //An array `min_dist_from_source` of size "number of nodes" is created in the class with the minimum distance from Source to each node, i.e. `shortest path length from Node 2 -> Node 3 = min_dist[3] `
  //If a `Node i` is unreachable from `Node 2`, then `min_dist[i]=-1` 
  //if running BFS multiple times and want to clear previous minimum distances then do g.BFS(source, true)
  g.BFS(source);
  vector<int>min_dist = g.min_dist_from_source[target]
 

  return 0;
}
