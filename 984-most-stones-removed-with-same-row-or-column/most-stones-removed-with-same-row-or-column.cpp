class Solution {
public:
   bool samegroup(vector<int>&v1,vector<int>&v2)
 {
       return (v1[0]==v2[0]||v1[1]==v2[1]);
 }
   void dfs(vector<vector<int>>&stones,vector<int>&visited,int idx)
   {
         visited[idx]=1;
         for(int i=0;i<stones.size();i++)
         {
            if(visited[i]==0&&samegroup(stones[idx],stones[i]))
                 {
                    visited[i]=1;
                    dfs(stones,visited,i);
                 }
         }
   }
    int removeStones(vector<vector<int>>& stones) {
        int len=stones.size();
        vector<int>visited(len,0);
        int group=0;
        for(int i=0;i<len;i++)
        {
            if(visited[i]==0)
             {
                group++;
                dfs(stones,visited,i);
             }
        }
        return len-group;
    }
};