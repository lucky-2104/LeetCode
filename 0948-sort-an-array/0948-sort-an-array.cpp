class Solution {
public:


    void mergeArray(vector<int>& nums , int left , int mid , int right){
        int n = mid-left+1, m = right-mid;
        
        auto *temp1 = new int[n] , *temp2 = new int[m];

        for(int i = 0 ; i < mid-left+1 ;i++)
        temp1[i] = nums[left+i];
        for(int i = 0 ; i < right-mid ;i++)
        temp2[i] = nums[mid+1+i];

        int i = 0 , j = 0 , k = left;
        while(i < n and j < m)
        {
            if(temp1[i] < temp2[j])
            {
                nums[k] = temp1[i];
                k++;i++;
            }
            else{
                nums[k] = temp2[j];
                k++;j++;
            }
        }
        while(i < n)
        {
            nums[k++] = temp1[i++];
        }
        while(j < m)
        {
            nums[k++] = temp2[j++];
        }

        delete[] temp1;
        delete[] temp2;
    }


    void merge_sort(vector<int>& nums , int st , int ed)
    {
        if(st >= ed)
        return;

        int mid = st + (ed-st)/2;
        merge_sort(nums , st , mid);
        merge_sort(nums , mid+1 , ed);
        mergeArray(nums , st , mid , ed);
    }
    vector<int> sortArray(vector<int>& nums) {

        merge_sort(nums,0,nums.size()-1);
        return nums;
        
    }
};