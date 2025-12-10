class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        const int n = 3;
        int row[n] = {0};
        int column[n] = {0};
        int diag = 0;
        int antidiag = 0;
        int chance = 1; //A=1, B=-1

        for(int i=0;i<moves.size();i++)
        {
            int r = moves[i][0];
            int c = moves[i][1];

            row[r] += chance;
            column[c] += chance;

            if(r==c)
            {
                diag+=chance;
            }
            if(r+c == n-1)
            {
                antidiag+=chance;
            }

            if(abs(row[r])==n || abs(column[c])==n || abs(diag)==n || abs(antidiag) == n)
            {
                return chance == 1?"A":"B";
            }
            chance = -chance;
            cout<<"r:"<<r<<" "<<"c:"<<c<<" "<<row[r]<<" "<<column[c]<<endl;
        }

        if(moves.size() == n*n) return "Draw";
        else return "Pending";

    }
};