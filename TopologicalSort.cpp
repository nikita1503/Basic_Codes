class TopologicalSort{
      public:
          TopologicalSort(Graph *g_) {
              g = g_;

          }
          Graph *g;
          int levels=1;
          bool possible;
          vector<int>nodeLevel, ordered;
          void run() {
              vector<int>inDegree((g->n),0); nodeLevel.resize(g->n,0);
              for(int i=0;i<(g->n);i++) for(int j=0;j<(g->adj)[i].size();j++)
                  inDegree[(g->adj)[i][j].first]++;       

              queue<int> freeNodes;
              for(int i=0;i<(g->n);i++) if(!inDegree[i])
                  freeNodes.push(i);

              int number_nodes_visited=0;

              while(!freeNodes.empty()){
                  int currNode = freeNodes.front(); freeNodes.pop();
                  ordered.push_back(currNode); levels = max(levels, nodeLevel[currNode]+1);
                  for(int i=0;i<(g->adj)[currNode].size();i++){
                      inDegree[(g->adj)[currNode][i].first]--; nodeLevel[(g->adj)[currNode][i].first]=nodeLevel[currNode]+1;
                      if(inDegree[(g->adj)[currNode][i].first]==0)
                          freeNodes.push((g->adj)[currNode][i].first);
                  }

                  number_nodes_visited++;

              }

              //cycle detected
              if(number_nodes_visited != (g->n)) possible=false;
              else possible = true;
          }
  };
