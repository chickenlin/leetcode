class LRUCache {
    unordered_map<int, list<pair<int,int>>::iterator> table;
    list<pair<int, int>> cache;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = table.find(key);
        if (it == table.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = table.find(key);
        if (it != table.end())
        {
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return ;
        }
        if (cache.size() == capacity)
        {
            int removeKey = cache.back().first;
            table.erase(removeKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        table[key] = cache.begin();
    }
};
