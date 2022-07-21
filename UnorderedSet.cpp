//unordered set of int
unordered_set<int> s;

//unordered set of any other type
struct pair_hash { 
    std::size_t operator()(const pair<int, int>& x) const { 
          //return hashing on x
            return x.first * 97 + x.second; 
        }
};
unordered_set<pair<int, int>, pair_hash> s;
