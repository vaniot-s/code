/**
 *

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
[".Q..",  // 解法 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // 解法 2
"Q...",
"...Q",
".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
搜索树
*/
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

class main {
private:
    vector <vector<string>> res;
    vector<bool> col,dia1,dia2;

    /**
     * 尝试在一个n皇后问题中,摆放第index行的皇后的位置
     * @param n
     * @param index
     * @param row
     */
    void putQueen(int n, int index, vector<int> &row) {
        if (index == n) {
            res.push_back(generateBoard(n, row));
            return;
        }

        //递归回溯
        for (int i = 0; i < n; ++i) {
            //尝试将第index行的皇后摆放在第i列
            if (!col[i]&&!dia1[index+i]&&!dia2[index-i+n-1]) {//列额方向不冲突 ,对角线
                row.push_back(i);
                col[i]=true;
                dia1[index+i]=true;
                dia2[index-i+n-1]=true;
                putQueen(n,index+1,row); //index+1
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                //回溯的过程
                row.pop_back();
            }
        }
        return ;
    }

   vector<string> generateBoard(int n,vector<int> &row){
        assert(row.size()==n);
        vector<string> board(n,string(n,'.'));
       for (int i = 0; i <n ; ++i) {
           board[i][row[i]]='Q';
       }
       return board;
    }
public:
    vector <vector<string>> solveNQueens(int n) {
        res.clear();
        col.clear();
        for(int i = 0 ; i < n ; i ++)
            col.push_back(false);

        dia1.clear();
        dia2.clear();
        for(int i = 0 ; i < 2 * n - 1 ; i ++){
            dia1.push_back(false);
            dia2.push_back(false);
        }
        vector<int> row;
        putQueen(n, 0, row); //
        return  res;
    }
};

#endif //NOTES_MAIN_H4