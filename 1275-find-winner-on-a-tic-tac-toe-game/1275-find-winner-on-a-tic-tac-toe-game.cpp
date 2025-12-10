class Solution {
private:
    char arr[3][3] = {'E'};
    int n = sizeof(arr)/sizeof(arr[0]);

    bool CheckRow(int idx, char piece)
    {
        for(int k = 0; k<n;k++)
        {
            if(arr[idx][k] != piece) return false;
        }
        return true;
    }

    bool CheckColumn(int idx, char piece)
    {
        for(int k = 0; k < n; k++)
        {
            if(arr[k][idx] != piece) return false;
        }
        return true;
    }

    bool CheckLeftDiagnol(char piece)
    {
        for(int k=0; k<n;k++)
        {
            if(arr[k][k] != piece) return false;
        }
        return true;
    }

    bool CheckRightDiagnol(char piece)
    {
        for(int k=0; k<n;k++)
        {
            if(arr[k][n-1-k] != piece) return false;
        }
        return true;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        char players[2][2] = {{'A','X'},{'B','O'}};
        int chance = 0;
        for(int i=0;i<moves.size();i++)
        {
            char player = players[chance%2][0];
            char piece = players[chance%2][1];
            int x = moves[i][0];
            int y = moves[i][1];
            //cout<<"Player:"<<player<<endl;
            //cout<<"piece:"<<piece<<endl;
            //cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
            arr[x][y] = piece;
            bool result = false;

            result = CheckRow(x, piece) || CheckColumn(y, piece) || CheckRightDiagnol(piece) || CheckLeftDiagnol(piece) ;
            if(result == true)
            {
                return string(1,player);
            }
             
            chance++;
        }
        int ele = moves.size();
        if(ele == 9) return "Draw";
        
        return "Pending";

    }
};