class Solution {
public:
    pair<int,pair<int,int>> convertTomapping(vector<int>& mapping , int nums,int indx)
    {
        vector<int> digits;
        int temp = nums;

        if(nums == 0)
        return{mapping[nums],{indx,nums}};

        while(temp > 0)
        {
            int rem = temp % 10;
            digits.push_back(mapping[rem]);
            temp = temp/10;
        }
        
        int n = digits.size();
        int converted = 0;
        for(int i = n-1 ; i > -1 ;i--)
        {
            converted = converted + (digits[i]*pow(10,n-1));
            n--;
        }
        
        return {converted,{indx , nums}};
     }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<int,pair<int,int>>> ans;
        vector<int> ans2;
        int indx = 0;
        for(auto i : nums)
        {
            pair<int,pair<int,int>> temp = convertTomapping(mapping , i , indx);
            ans.push_back(temp);
            indx++;
        }
        sort(ans.begin() , ans.end());
        for(auto itr : ans)
        {
            ans2.push_back(itr.second.second);
        }

        return ans2;
        
    }
};