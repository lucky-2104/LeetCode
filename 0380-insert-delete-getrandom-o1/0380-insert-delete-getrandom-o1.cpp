class RandomizedSet {
public:
    unordered_set<int> uos;
    RandomizedSet() {
    
    }
    
    bool insert(int val) {

        if(uos.find(val) != uos.end())
        return false;
        uos.insert(val);
        return true;

    }
    
    bool remove(int val) {
        if(uos.find(val) == uos.end())
            return false;
        uos.erase(val);
        return true;
        
    }
    
    int getRandom() {
        int randvalue = rand() % uos.size();
        auto value = uos.begin();
        int b = 0;
        for(value ; value != uos.end() ; value++)
        {
            if(b == randvalue)
                break;
            b++;
        }
        return *value;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */