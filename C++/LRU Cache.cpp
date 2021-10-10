map<int,pair<int,int>> mp;      // the first entry is the key, second will be value and third will be the time at which it was last accesses
int tm, maxSize;                 

LRUCache::LRUCache(int capacity) {
    
    // to ensure global variables are cleared
    
    tm = 0;
    maxSize = capacity;
    mp.clear();
}

int LRUCache::get(int key) {
    
    if(mp.find(key)!=mp.end())  // if you find the key then update the last accessed time and return
    {
        mp[key].second = tm;
        tm++;
        return mp[key].first;
    }
    else return -1;
}

void LRUCache::set(int key, int value) {
    
    if(mp.find(key)!=mp.end())   // if the key is there then update the value as well as time
    {
        mp[key] = {value,tm};
        tm++;
    }
    else      // else
    {
        if(mp.size()<maxSize)   // if you have still not crossed the maximum capacity then simply add a new entry 
        {
            mp[key] = {value,tm};
            tm++;
        }
        else    // else you have to search for the entry having least time i.e the one which was accessed Least Recently
        {
            int minTime_key = -1,minTime = INT_MAX;
            
            map<int,pair<int,int>>::iterator itr = mp.begin();
            
            while(itr!=mp.end())
            {
                if(itr->second.second < minTime)
                {
                    minTime = itr->second.second;
                    minTime_key = itr->first;
                }
                
                itr++;
            }
            
            mp.erase(minTime_key);  // erasing the Least Recently used entry
            
            mp[key] = {value,tm};  // adding a new entry
            tm++;
        }
    }
}

Close