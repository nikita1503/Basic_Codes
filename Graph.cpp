typedef int ll;
class Graph {
	
	bool is_directed;
	
	public:
		vector<vector<pair<int,ll>>>adj;
	    int n;
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

	private :
		void add_edge_weighted_undirected(int u, int v, ll c) {
			pair<int,ll>p = make_pair(v,c);
			adj[u].push_back(p);
		}
	
};

//USAGE

//Directed Graph UnWeighted
Graph g(numebr_nodes, true);
g.add_edge(u,v);

//Directed Graph Weighted
Graph g(numebr_nodes, true);
g.add_edge(u,v,weight);

//UnDirected Graph UnWeighted
Graph g(numebr_nodes, false);
g.add_edge(u,v);


//UnDirected Graph Weighted
Graph g(numebr_nodes, false);
g.add_edge(u,v,weight);
