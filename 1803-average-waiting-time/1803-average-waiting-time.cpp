class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        double time = 0;
        double totaltime = 0;
        for(int i = 0 ; i < customers.size() ; i++)
        {
            int arrival = customers[i][0];
            int timetaken = customers[i][1];

            if(arrival > totaltime)
            totaltime = arrival;

            int extratime = 0;
            if(totaltime > arrival){
                extratime = totaltime - arrival;
            }
            
            time = time + extratime +timetaken;
            totaltime = totaltime + timetaken;

        }
        time = time / customers.size();
        return time;
    }
};