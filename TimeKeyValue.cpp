// 981. Time Based Key-Value Store
class TimeMap {
private:
    map<string, vector<pair<int, string>>> data;

public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(data.find(key) == data.end()){
            return "";
        }
        auto& pairs = data[key];

        auto it = std::upper_bound(pairs.begin(), pairs.end(), std::make_pair(timestamp, std::string("{")), 
            [](const std::pair<int, std::string>& val, const std::pair<int, std::string>& pivot) {
                return val.first < pivot.first;
                });

        if (it == pairs.begin()) {
            return "";
        }

        return (it-1)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
