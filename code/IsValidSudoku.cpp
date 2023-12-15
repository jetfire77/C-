 #include<bits/stdc++.h>

using namespace std;

  bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0 ; i< 9; i++){
            if(board[i][col]==c  && i != row)
                {

                    cout<<"char c="<<c<<" ";
                    cout<<"i = "<<i<<" j= "<<col<<" ";
                 cout<<"false2";
                 return false;
 
                }
            

            if(board[row][i]==c && i != col)
            {
                 cout<<"false3";
                 return false; 
            }
          

            if(board[3*(row/3)+ i/3] [3*(col/3)+i%3]==c) 
                { cout<<"char c="<<c<<" ";
                    cout<<"i = "<<i<<" j= "<<col<<" ";
                    cout<<"false4";
                    return false;}

        }

        return true;
    }



  bool solve(vector<vector<char>>& board){

        for(int i = 0 ; i< board.size(); i++){
            for(int j = 0 ;  j<board[0].size(); j++){
                if(board[i][j] !='.'){
                    char c =  board[i][j];
                        if(isValid(board, i, j, c) == false) {

                            cout<<"false1";

                            return false;
                        }
                    
                    
                }
            }
        }
        return true;

    }


 bool isValidSudoku(vector<vector<char>>& board) {

        return solve(board);
   
    }


  

 int main()
        {
            

           std::vector<std::vector<char>> board {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};



          



 cout<<isValidSudoku(board);


            
        }