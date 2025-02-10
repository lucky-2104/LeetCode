class Solution {
public:
    string clearDigits(string s) {

        int count = 0;
        string ans = "";
        stack<char> st;

        for(int i = 0 ; i < s.size() ; i++){

            if(s[i] >= 'a' and s[i] <= 'z')
            st.push(s[i]);

            if((s[i] >= '0' and s[i] <= '9') and st.size() > 0 and (st.top() >= 'a' and st.top() <= 'z'))
            st.pop();
        }

        while(!st.empty()){

            ans = ans + st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;




            

        
    }
};