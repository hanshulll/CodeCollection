  int kMostFrequent(int arr[], int n, int k) 
    { 
        // Your code here	
    	unordered_map<int,int> mp;
    	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
    	int ans;
    	
    	for(int i=0; i<n; i++)
    	{
    	    mp[arr[i]]++;
    	}
    	
    	for(auto i=mp.begin(); i!=mp.end(); i++)
    	{
    	    minh.push({i->second,i->first});
    	    if(minh.size()>k)
    	    {
    	        minh.pop();
    	    }
    	}
    	int sum=0;
    	while(!minh.empty())
    	{
    	    int first=minh.top().first;
    	   	minh.pop();
    	    sum=sum+first;
    	    
    	}
    	
    	return sum;
    } 
