class Solution {
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    bool solve(vector<vector<int>>& grid,vector<vector<int>> &dis,int val)
    {
        int n=grid.size();
        queue<pair<int,int>> q;
        if(dis[0][0]>=val)
        q.push({0,0});
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0]=true;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int row=curr.first;
            int col=curr.second;
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and vis[nrow][ncol]==false)
                {
                    if(dis[nrow][ncol]>=val)
                    {
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        return vis[n-1][n-1]==true;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return 0;


        vector<vector<int>> dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }

        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            int row=curr.first;
            int col=curr.second;

            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==0 and dis[nrow][ncol]>1+dis[row][col])
                {
                    dis[nrow][ncol]=1+dis[row][col];
                    q.push({nrow,ncol});
                }
            }
        }
        
        int low=0,high=400;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(solve(grid,dis,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};