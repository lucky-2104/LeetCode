class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int> s;

        for(int i = 0 ; i < arr.size() ; i++){
            s.insert(arr[i]);
        } 

        unordered_map<int , int> ump;
        int i = 1;
        for(auto itr : s){
            
            ump[itr] = i;
            i++;
        }
        for(int i = 0 ; i < arr.size();i++)
        {
            arr[i] = ump[arr[i]];
        }
        return arr;

        
    }
};