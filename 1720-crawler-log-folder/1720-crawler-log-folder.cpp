class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0 ;

        for(int i = 0 ; i < logs.size() ; i++)
        {
            if(logs[i] == "../" and count > 0)
            count--;
            else if(logs[i] == "./")
            continue;
            else if(logs[i] != "../" and logs[i]!="./")
            count++;
        }
        return count;
        
    }
};