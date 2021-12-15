package LeetCode;
/*
https://leetcode.com/problems/word-search/
Given an m x n grid of characters board and a string word,
 return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
 where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once
 Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
 */
public class Search_Word {

    public static void main(String[] args) {
        char[][] borad = {
                {'A','B','C','D'},
                {'S' , 'F','C','S'},
                {'A' ,'D','E' , 'E'},

        };
        String Word = "ABCCED";
        System.out.println(exist(borad,Word));


    }
    public static boolean exist(char[][] board, String word) {
        char ch = board[0][0];
        for (int i = 0 ; i< board.length ; i++){
            for (int j = 0; j < board[i].length; j++) {
                if(board[i][j] == ch){
                   boolean ans =  search(board , i , j);
                   if(!ans) return false;
                }
            }
        }
        return true;
    }

    public static boolean search(char[][] board, int i, int j) {
        //
return false;
    }
}
