class Trie {
  vector<vector<int>>graph;
  

  void add_node(int parent_idx, int edge_id) {
      int child_idx = create_node();
      graph[parent_idx][edge_id] = child_idx;
  }

  int create_node(){
      graph.push_back(vector<int>(27,-1));
      return graph.size()-1;
  }

  int get_edge_id(string s, int idx, int end_idx){
      if(idx<=end_idx) return s[idx]-'a';
      return 26;
  }

  public:
  Trie() {
      graph.clear();
      create_node();
  }
  void add_string(string s){
      int curr_node_idx = 0;
      for(int i=0;i<=s.size();i++){
          int edge_id = get_edge_id(s,i,s.size()-1);
          if(graph[curr_node_idx][edge_id]==-1) graph[curr_node_idx][edge_id]=create_node();
           curr_node_idx=graph[curr_node_idx][edge_id];
      }
  }

  bool search_string(string s, int start_idx, int end_idx){
      int curr_node_idx = 0;
      for(int i=0;i<=end_idx-start_idx+1;i++){
          int edge_id = get_edge_id(s,i+start_idx,end_idx);
          if(graph[curr_node_idx][edge_id]==-1) return false;
           curr_node_idx=graph[curr_node_idx][edge_id];
      }
      return true;
  }
};


# Usage 
Trie trie;

trie.add_string(s);

trie.search_string(s,start_index_inclusive,end_index_inclusive)
