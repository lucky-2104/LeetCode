class Solution {
public: 
    string convert(string s, int numRows) {

        if(numRows == 1)
        return s;
        vector<string> strArray(numRows,"");
        int flag = 0;
        int j = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(j==0 or j == numRows-1)
            {
                flag = !flag;
            }
            if(flag == 1)
            {
                strArray[j] = strArray[j] + s[i];
                j++;
            }
            if(flag == 0)
            {
                strArray[j] = strArray[j] + s[i];
                j--;
            }
        }
        string ans= "";

        for(auto x : strArray)
        {
            ans = ans + x;
        }
        return ans;
        
    }
};