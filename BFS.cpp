//USE WITH CLASS GRAPH
class BFS { 
    public:
        BFS(Graph *g_) {
            g = g_;
            min_dist_from_source.resize(g->n,-1);
            visited.resize(g->n, false);
        }
        vector<ll>min_dist_from_source;
        vector<bool> visited;
				Graph *g;

        void run(int source) {
			queue<int> q;
			q.push(source);
			
			visited[source] = true;
			min_dist_from_source[source] = 0;
			
			while(!q.empty()) {
				int cur_node = q.front();
				vector<pair<int,ll>> cur_node_adj = g->adj[cur_node];
			
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

};


//USAGE
BFS bfs(&g); 

//state is maintained across multiple runs
bfs.run(source_node);

bfs.visited[i] // indicates if the node i was visited in the BFS
bfs.min_dist_from_source[i] //shortest path length from source to node i
