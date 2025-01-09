class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int count = 0;

        for(string x : words){

            int len_pref = pref.size();
            int len_string = x.size();

            if(len_string >= len_pref){
                bool flag = true;
                for(int i = 0 ; i < len_pref ; i++){
                    if(x[i] != pref[i])
                    {
                        flag = false;
                        break;
                    }
                }

                count = flag?count+1:count;   
            }
        }
        return count;
        
    }
};