class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto it: word){
            mp[it]++;
        }
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        vector<int> sized(27, -1);
        int count = 0;
        while(!pq.empty()){
            int current_char = pq.top().second;
            count++;
            int sizes = 0;
            if(count<=8) sizes = 1;
        
            else if(count<=16) sizes = 2;

            else if(count<=24){
                sizes = 3;
            }
            else{
                sizes = 4;
            }
            sized[int(current_char-'a')] =  sizes;
            pq.pop();
        }
        int required = 0;
        for(auto it: word){
            required+= sized[int(it-'a')];
        }
        return required;
    }
};