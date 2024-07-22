class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int,string>> value;
        vector<string> s1;
        for(int i = 0 ; i < names.size() ; i++)
        {
            value.push_back({heights[i] , names[i]});
        }
        sort(value.rbegin(), value.rend());

        for(int i = 0 ; i < value.size() ;i++)
        s1.push_back(value[i].second);

        return s1;


        
    }
};