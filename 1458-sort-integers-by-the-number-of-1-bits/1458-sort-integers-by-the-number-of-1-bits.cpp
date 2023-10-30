class Solution {
public:
int decToBinary(int n)
{
    int i = 0;
    int check = 0;
    int count = 0;
    while (n > 0) {

        check = n % 2;

        if(check == 1)
        count++;

        n = n / 2;
        i++;
    }
    return count;
}
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> array;

        for(int i = 0 ; i < arr.size() ; i++)
        {
            array.push_back({decToBinary(arr[i]),arr[i]});
        }
        vector<int> ans;
        sort(array.begin(), array.end()); 
        for(int i = 0 ; i<array.size() ;i++)
        {
            ans.push_back(array[i].second);
        }

        return ans;
        
    }
};