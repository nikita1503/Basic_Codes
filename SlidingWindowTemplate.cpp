slidingWindow() {
    //create flat buckets
    vector<int>buckets(128,0);

    //deepen the bucket for elements that are needed
    for(int i=0;i<p.size();i++) buckets[p[i]]--;

    // initialise counters
    int chars_left_in_p=p.size(), chars_extra=0;

    int l=0,r=0;

    //Ending condition
    while(r<s.size()){
        //if bucket is not full for the element, then that element is needed, update counter
        if(buckets[s[r]]++<0)chars_left_in_p--;
        //else bucket is full of overflowing for the element, update the counter
        else chars_extra++;

        //while till bucket is not overflowing
        while(chars_extra>0){
            //if the element is in a level of not full bucket, then this element was a required one, update counter
            if(buckets[s[l]]--<=0)chars_left_in_p++;
            //else it was not a required one and causing overflow, update counter
            else chars_extra--;
            l++;
        }

        //check conditions
        if(chars_left_in_p==0)
            ans.push_back(l);

        r++;
        
    }

    return ans;
}
