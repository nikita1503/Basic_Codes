//low and high are inclusive
//iterative
binarySearch(arr,x)
    int L = -1, R = n, M;
    while (L + 1 < R) {
       M = (L+R)/2;
    if (a[M] >= X) R = M; else L = M;
        
    //R will point to the just element>=x
    //L will point to the just element<x
}

//Generalised
//the array has consecutive 0s followed by consecutive 1s.
//l is always in 0s, r is always in 1s
//we will stop when l and r have reached the border, i.e. last 0 and first 1
//return l is we want last 0, return 1 if we want first 1

binarySearch(min_possible_ans, max_possible_ans)
    int L = min_possible_ans-1, R = max_possible_ans+1, M;
    while (L + 1 < R) {
       M = (L+R)/2;
    if (predicate(M)==0) L = M; else R = M;

    //if we want last 0
    return L;
    // if we want first 1
    return R;
}
