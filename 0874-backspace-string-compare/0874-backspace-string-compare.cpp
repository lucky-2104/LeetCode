class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> s1;
        stack<char> s2;

        for(auto i : s)
        {
            cout << i << " ";
            if( i == '#' and !s1.empty())
            s1.pop();
            else
            {
                if(i != '#')
                s1.push(i);
            }
        }

        for(auto i : t){
            cout << i << " ";
            if(i == '#' and !s2.empty())
            s2.pop();
            else
            {
                if(i !='#')
                s2.push(i);
            }
        }

        if(s1.size() != s2.size())
        return false;

        while(!s1.empty())
        {
            char c1 = s1.top();s1.pop();
            char c2 = s2.top();s2.pop();

            if(c1 != c2)
            return false;

        }
        return true;
    }
};