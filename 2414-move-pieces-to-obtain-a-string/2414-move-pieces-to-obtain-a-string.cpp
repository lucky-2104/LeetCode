class Solution {
public:
    bool canChange(string start, string target) {

        int n = start.size();

        for(int i = 0 , j = 0 ; i < n || j < n ; i++ , j++){

            while(i < n and start[i] == '_') i++;
            while(j < n and target[j] == '_') j++;

            char cmp = start[i];

            if(cmp != target[j]) return 0;

            if(cmp == 'L' and i < j) return 0;
            if(cmp == 'R' and i > j) return 0;
        }
        return 1;
        
    }
};