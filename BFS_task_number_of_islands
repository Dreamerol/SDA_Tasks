
zadacha BFS islands
#include<iostream>
#include<vector>
#include <queue>

bool isValid(pair<int, int> a, int n, int m){
   return (a.first<=n-1 && a.first >= 0 && a.second >= 0 && a.second<=m-1);
}
    void nbs(queue<pair<int, int>>& nums, vector<vector<char>>& grid,int n, int m){
        
    while(!nums.empty()){
                int x = nums.front().first;
                int y = nums.front().second;

                    vector<pair<int,int>> pairs = {{x-1, y},{x+1,y}, {x,y-1}, {x,y+1}};
        for(int i = 0;i<pairs.size();i++){
            int x1 = pairs[i].first;
            int y1 = pairs[i].second;
            if(isValid(pairs[i],n,m)&& grid[x1][y1] == '1')
             {
               // cout<<pairs[i].first<<' '<<pairs[i].second<<'\n';
                grid[x1][y1] = '0';
                nums.push(pairs[i]);
                }
        }
        grid[x][y] = '0';
        
        nums.pop();
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countIslands = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    countIslands++;
                    queue<pair<int, int>> nums;
                    nums.push({i,j});
              
                    nbs(nums, grid, n, m);

                    

                }
            }
        }
        return countIslands;

    
