//leetcode 189
#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
} 
//O(n^2)
// int n=nums.size();
//         int index=0;
//         while(k>0)
//         {
//         for(int i=0;i<n;i++)
//         {
//             swap(nums[0],nums[index]);
//             index++;
//         }
//         index=0;
//         k--;
//         }
// 
// alternative
//isme while loop ki jagha ek kaam aur kar sakte hai k%=size
// int n=nums.size();
//         if(k<n)
//         {
//         vector<int>ans;
//         int a=n-k;
//         for(int i=a;i<n;i++)
//         {
//             ans.push_back(nums[i]);
//         }
//         for(int i=0;i<a;i++)
//         {
//             ans.push_back(nums[i]);
//         }
//         for(int i=0;i<n;i++)
//         {
//             nums[i]=ans[i];
//         }
//         }
//         else
//         {
//         int index=0;
//         while(k>0)
//         {
//         for(int i=0;i<n;i++)
//         {
//             swap(nums[0],nums[index]);
//             index++;
//         }
//         index=0;
//         k--;
//         }
//         }

//         best
//         k %= nums.size();
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin()+k);
//         reverse(nums.begin()+k, nums.end());
