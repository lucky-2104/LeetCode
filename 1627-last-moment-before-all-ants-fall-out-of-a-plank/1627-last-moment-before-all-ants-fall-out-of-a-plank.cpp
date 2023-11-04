class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        int max_left ,max_right;
        if(left.size() != 0)
        max_left = left[left.size()-1];
        else
        max_left = -1;
        if(right.size() != 0)
        max_right = right[0];
        else
        max_right = -1;

        if(max_right == -1)
        return max_left;
        if(max_left == -1)
        return n - max_right;

        return max(max_left,n - max_right);





    }
};