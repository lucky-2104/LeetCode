class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int left=0 , right = 1;
        int time = 0;
        while(right < colors.size())
        {
            if(colors[left] == colors[right])
            {
                // cout << left <<" " << right << endl;
                // cout << colors[left] << " "  << colors[right] << endl;
                if(neededTime[left] < neededTime[right]){
                    time = time + neededTime[left];
                    left = right;
                }
                else{
                    time = time + neededTime[right];
                }
            }
            else
            {
                // cout << "HERE" << endl;
                left = right;
            }
            right++;
            // cout <<"Iteration ->" << right << " " <<time <<endl;
        }
        cout << left << " " << right;
        return time;
        

    }
};
