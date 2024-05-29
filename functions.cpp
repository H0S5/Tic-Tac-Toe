#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>

using namespace std;

extern string player1;

extern string player2;

extern string play;

 // ============================================================================

extern int  i  ;

extern  int  first_index ;

extern int  win_checker_bot  ;

extern int  win_blocker ;

extern int  ply1_points ;

extern int  ply2_points ;

// ============================================================================

extern array <string,9> num_plays ;

extern array <bool,9> plays;

extern int wins[8][3];

// ============================================================================

extern  vector <int> ply_one_plays ;

extern vector <int> ply_two_plays ;

// ============================================================================

     array <string,9> xo_reset_string (array <string,9> num_plays)
{
    for ( int i = 0 ;i < num_plays.size() ; i++)
        {
            num_plays[i] = 49 + i;
        }
        return num_plays;
}
array <bool,9> xo_reset_bool (array <bool,9> plays)
{
        for ( int i = 0 ;i < plays.size() ; i++)
        {
            plays[i] = true;
        }
        return plays;
}
void xo_show (array <string,9> num_plays)
{
cout << 
"\n "<< num_plays[0] << "  |  " << num_plays[1] << "  |  " << num_plays[2] <<
"\n "<< num_plays[3] << "  |  " << num_plays[4] << "  |  " << num_plays[5] << 
"\n "<< num_plays[6] << "  |  " << num_plays[7] << "  |  " << num_plays[8] << endl ;
}
bool win_checker (vector <int> plyer_plays,string player)
{
    int win ;
    for (int f_index = 0 ; f_index < 8 ; f_index++)
        {
            win = 0;
            for (int s_index = 0 ;s_index < 3 ; s_index++)
                {
                        for (int ply =0; ply <= plyer_plays.size() ; ply++)
                        {
                            if ( win == 3)
                                {
                                    xo_show(num_plays);
                                    cout << player << " Won The Game" << endl;
                                    return true ;
                                }
                                else if (plyer_plays[ply] == wins[f_index][s_index])
                                    {
                                        win++;
                                    }
                        }
                }
        }
        return false;
}
void reset_all ()
{
       i = 0;
        ply_one_plays.clear();
        ply_one_plays[0] = {0};
       ply_two_plays.clear();
        ply_two_plays[0] = {0};
        plays = xo_reset_bool(plays);
        num_plays = xo_reset_string(num_plays);
        win_blocker = 0;
        win_checker_bot = 0 ;
        first_index = 100;
}
int play_again (vector <int> plyer_plays , string player_name,int plyer_points)
{
    if ( win_checker(plyer_plays,player_name))
    {
        plyer_points++;
        askAgain:
        cout << "Do You Wanna Continue Playing ?";
        cout << "\t [Y/N]" << endl;
        cin >> play;
        if (play == "Y" || play == "y" || play == "yes" || play == "Yes")
            {
                reset_all();
                return 1;
            }
        else if (play == "N" || play == "n" || play == "no" || play == "No")
            {
                cout << player1 << "`s Score Was Is: " << ply1_points << endl;
                cout << player2 << "`s Score Was Is: " << ply2_points << endl;
                cout << "here" << endl;
                return 0;
            }
            else 
                {
                    cout << "Wrong Input" << endl;
                    goto askAgain;
                }
}
else return 2;
return 0;
}