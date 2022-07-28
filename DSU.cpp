//Disjoint-set-union
//Input - size of array
//parent of each element in unioned sets (par)
//Complexity - prepare O(n), root - amortiser O(1), merge O(1)

struct DSU {
    vector<int>par;
    DSU(int n) {par.resize(n,-1);}
    int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
    void merge(int x,int y){
            if((x = root(x)) == (y = root(y)))     return ;
            if(par[y] < par[x])	swap(x, y);
            par[x] += par[y];
            par[y] = x;
    }
};

main() {
//n is size of the array
DSU dsu(n);

//merge sets to which elements x,y belong (0-indexed)
dsu.merge(x,y)

//get parent of the set to which element i belongs (0-indexed)
int parenti = dsu.root(i)
}
