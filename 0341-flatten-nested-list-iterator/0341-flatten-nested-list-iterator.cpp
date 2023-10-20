/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:

    stack<NestedInteger> s1;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1 ; i >= 0 ;i--)
        s1.push(nestedList[i]);
    }
    
    int next() {

        int result = s1.top().getInteger();
        s1.pop();
        return result;
        
    }
    
    bool hasNext() {
        while(!s1.empty())
        {
            NestedInteger current = s1.top();

            if(current.isInteger())
            return true;

            s1.pop();

            vector<NestedInteger> nested = current.getList();
            for(int i = nested.size() - 1 ; i >= 0 ; i--)
            s1.push(nested[i]);
        }
        return false;


    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */