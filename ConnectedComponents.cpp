//USE WITH CLASS GRAPH
class ConnectedComponents {
      Graph *g;
      vector<bool>visited;
      void dfs(int node, int compId) {
          if(visited[node]) return;
          nodeInComponent[node]=compId;
          visited[node]=true;
          for(int i=0;i<(g->adj)[node].size();i++)
              dfs((g->adj)[node][i].first, compId);
      }

      public :
          int count=0;
          vector<int>nodeInComponent;
          ConnectedComponents(Graph * g_){
              g=g_; 
              nodeInComponent.resize(g->n);
          }
           void run(){
              visited.resize((g->n),false);
              for(int i=0;i<(g->n);i++)
                  if(!visited[i]){
                      count++; dfs(i,count-1);
                  }
           }

  };
//USAGE
ConnectedComponents conComp(&g);

//state is maintained across multiple runs
conComp.run();

conComp.count // number of connected components in the graph
conComp.nodeInComponent[i] //componenet id (0-indexed) of a node
