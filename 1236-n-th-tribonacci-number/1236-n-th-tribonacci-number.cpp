class Solution {
public:

    int f(int n , vector<int>& tri)
    {
        if(n <= 0 )return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        if(tri[n] != -1) return tri[n];

        return tri[n] = f(n-1,tri) + f(n-2 , tri) + f(n-3 ,tri);
    }

    int tribonacci(int n) {
        vector<int> tri(n+1 , -1);
        return f(n , tri);

    }
};