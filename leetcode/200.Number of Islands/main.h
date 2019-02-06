//
// Created by vaniot on 18-12-18.
//
/**
 * 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1

示例 2:

输入:
11000
11000
00100
00011

输出: 3


 */

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
private:
    int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//辅助数组
    int m,n;
    vector<vector<bool>> visited;//
    bool inArea(int x,int y){
        return x>=0&&x<m&&y>=0&&y<n;
    }
    /**
     * 从grid[x][y]位置开始,进行floodfill
     * x与y合法,终止条件为if中
     * @param grid
     * @param x
     * @param y
     */
    void dfs(vector<vector<char>>& grid,int x,int y){
        visited[x][y]=true;
        for (int i = 0; i <4 ; ++i) {
            int newX=x+d[i][0];
            int newY=y+d[i][1];
            if(inArea(newX,newY)&&!visited[newX][newY]&&grid[newX][newY]=='1'){ //陆地
                dfs(grid,newX,newY);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        if(m==0){
            return 0;
        }
        n=grid[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        int res=0;
        for(int i=0;i<m;i++){
            for (int j = 0; j <n ; ++j) {
                if(grid[i][j]=='1'&&!visited[i][j]){
                    res++;
                    dfs(grid,i,j);//深度优先遍历
                }
            }
        }
        return res;
    }

};


#endif //NOTES_MAIN_H
