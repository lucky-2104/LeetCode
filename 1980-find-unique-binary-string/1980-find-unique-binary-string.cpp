class Solution {
public:
    
    int binary_decimal(string s)
    {
        int decimal = 0;
        int base  = 1;
        
        for(int i = s.size()-1 ; i >= 0 ; i--)
        {
            if(s[i] == '1')
                decimal = decimal + base * 1;
            base = base * 2;
            
        }
        return decimal;
    }
    
    string decimal_binary(int i , vector<char> start, string ans)
    {
        int n = start.size()-1;
        while(i > 0)
        {
            start[n] = char(i % 2 + 48);
            i = i / 2;
            n--;
        }
        
        for(int i = 0 ; i < start.size() ; i++)
        ans = ans + start[i];
        
        return ans;
        
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums[0].size();
        
        vector<char> start(n , '0');
        
        sort(nums.begin() , nums.end());
        
        string ans = "";
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i != binary_decimal(nums[i]))
            {
                ans = decimal_binary(i , start ,ans);
                break;
            }
        }
        
        if(ans == ""){
            cout << "Here";
            ans = decimal_binary(n , start , ans);
        }
        return ans;
        
        
    }
};