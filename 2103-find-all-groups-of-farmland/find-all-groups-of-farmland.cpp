class Solution {
public:
    void solve(vector<vector<int>>& land,int row,int col,int &b,int &r)
    {
        if(row<0 || row>=land.size() || col<0 || col>=land[0].size() || land[row][col]==0)
        {
            return ;
        }

        if(land[row][col]==1)
        {
            land[row][col]=0;
            b=max(b,row);
            r=max(r,col);
        }
        solve(land,row,col-1,b,r);
        solve(land,row,col+1,b,r);
        solve(land,row-1,col,b,r);
        solve(land,row+1,col,b,r);

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>result;
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(land[i][j]==1)
                {
                    
                    int b=i;
                    int r=j;
                    solve(land,i,j,b,r);
                    result.push_back({i,j,b,r});
                }
            }
        }
        return result;
    }
};