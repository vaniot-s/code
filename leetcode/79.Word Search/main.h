//
// Created by vaniot on 18-12-17.
//
/**
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

思路:依赖于递归,回溯退回上一步
 寻找上右下左的方向
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
private:
    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}}; //偏移量数组
    int m, n;
    vector <vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    /**
     * 从board[startx][starty]开始,寻找word[index...word.size())
     * @param board
     * @param word
     * @param index
     * @param startx
     * @param starty
     * @return
     */
    bool searchWord(const vector <vector<char>> &board, const string &word, int index, int startx, int starty) {
        if (index == word.size() - 1) {
            return board[startx][starty] == word[index];
        }
        if (board[startx][starty] == word[index]) {
            visited[startx][starty] = true;
            //从startx,starty出发,向四个方向寻,
            for (int i = 0; i < 4; ++i) {
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if (inArea(newx, newy) && !visited[newx][newy]) {
                    if (searchWord(board, word, index + 1, newx, newy)){
                        return true;
                    }
                }
            }
            visited[startx][starty] = false;

        }
        return false;
    }

public:
    bool exist(vector <vector<char>> &board, string word) {
        m = board.size();
        assert(m > 0);
        n = board[0].size();
        visited = vector < vector < bool >> (m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(searchWord(board,word,0,i,j)){ //第一次遍历
                    return true;
                }
            }
        }
        return false;
    }
};


#endif //NOTES_MAIN_H
