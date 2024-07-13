// 146. LRU Cache
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        moveToFront(key);
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            moveToFront(key);
            return;
        }
        if (cache.size() >= capacity) {
            int lruKey = usage.back();
            usage.pop_back();
            cache.erase(lruKey);
        }
        usage.push_front(key);
        cache[key] = {value, usage.begin()};
    }

private:
    int capacity;
    std::list<int> usage;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;

    void moveToFront(int key) {
        usage.erase(cache[key].second);
        usage.push_front(key);
        cache[key].second = usage.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
