#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
//#include "functions.cpp"
using namespace std;
// ============================================================================
    int i = 0 ;
    int first_index = 100;
    int win_checker_bot = 0 ;
    int win_blocker = 0;
    int ply1_points = 0;
    int ply2_points = 0;
// ============================================================================
    array <string,9> num_plays {"1","2","3","4","5","6","7","8","9"};
    array <bool,9> plays {true,true,true,true,true,true,true,true,true};
// ============================================================================
    vector <int> ply_one_plays {10};
    vector <int> ply_two_plays {10} ;
    int wins[8][3]
    {
    {1,2,3},{4,5,6},{7,8,9},
    {1,4,7},{2,5,8},{3,6,9},
    {1,5,9},{3,5,7}
    };
// ===========================================================================
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
"\n "<< num_plays[0] << "    " << num_plays[1] << "    " << num_plays[2] << endl <<
"\n "<< num_plays[3] << "    " << num_plays[4] << "    " << num_plays[5] << endl <<
"\n "<< num_plays[6] << "    " << num_plays[7] << "    " << num_plays[8] << endl ;
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
       ply_two_plays.clear();
        plays = xo_reset_bool(plays);
        num_plays = xo_reset_string(num_plays);
        win_blocker = 0;
        win_checker_bot = 0 ;
        first_index = 100;
}
int main ()
{

    string player1;
    string player2 = "Bot";
    string play;
// ===========================================================================
    cout << "Enter Player One Name" << endl;
    cin >> player1;

    game:
while (true) // Player One
{
    player1:
    cout << "Type [00] To Show The Score" << endl;
    cout << player1 << " Turn";
        xo_show(num_plays);
        cin >> play;
     for (int  check = 0 ;check < ply_one_plays.size() ; check++)
            {
                if ( ply_one_plays[check] == stoi(play) || (stoi(play) <= -1  || stoi(play) >= 10 && stoi(play) != 00 ) )
                    {
                        cout << "Wrong Place!!" << endl;
                        goto player1;
                    } 
            }
                     if (play == "00")
                        {
                            cout << player1 << "`s Score Is: " << ply1_points << endl;
                            cout << player2 << "`s Score Is: " << ply2_points << endl;
                        }
                for (int j = 0 ;j < num_plays.size() ; j++)
                    {
                        if (i == 8 && play ==  num_plays[j] )
                            {
                                ply_one_plays.push_back(stoi(num_plays[j]));
                                plays[j] = false;
                                 num_plays[j] = "✖";
                        if ( win_checker(ply_one_plays,player1))
                                      {
                                        ply1_points++;
                                      cout << "Do You Wanna Continue Playing ?"<< endl;
                                      cout << "\t Y/N" << endl;
                                      cin >> play;
                                      if (play == "Y" || play == "y")
                                      {
                                        reset_all();
                                      goto game;
                                         }
                                         else if (play == "N" || play == "n")
                                        {
                                            cout << player2 << "`s Score Was Is:" << ply2_points;
                                            return 0;
                                        }                      
                                      }
                                
                                cout << "Draw" << endl;
                                cout << "Do You Wanna Continue Playing ?"<< endl;
                                cout << "\t Y/N" << endl;
                                cin >> play;
                                    if (play == "Y" || play == "y")
                                        {
                                            reset_all();
                                      goto game;
                                        }
                                        else if (play == "N" || play == "n")
                                            {
                                             cout << player2 << "`s Score Was Is:" << ply2_points << endl;
                                            return 0;
                                            }
                            }
                        if ( play ==  num_plays[j])
                            {
                                ply_one_plays.push_back(stoi(num_plays[j]));
                                plays[j] = false;
                                 num_plays[j] = "✖";
                                  i++;
                                  if ( i < 3)
                                  {
                                    goto player2;
                                  }
                                   if ( i >= 3)
                                     {
                                      if ( win_checker(ply_one_plays,player1))
                                      {
                                        ply1_points++;
                                      cout << "Do You Wanna Continue Playing ?";
                                      cout << "\t Y/N" << endl;
                                      cin >> play;
                                      if (play == "Y" || play == "y")
                                      {
                                        reset_all();
                                      goto game;
                                      }
                                      else if (play == "N" || play == "n")
                                        {
                                            cout << player1 << "`s Score Was Is:" << ply1_points;
                                            return 0;
                                        }
                                      else goto player2;
                                      
                                      }
                                      else goto player2;
                                      
                                      }
                             }
                           

                       } 
}    
                                      

// The Bot
player2:
if(i >= 3)
{
for (int f_index = 0 ; f_index < 8 ; f_index++)
        {
    win_checker_bot = 0 ;
            for (int s_index = 0 ;s_index < 3 ; s_index++)
                {
                        for (int ply =0; ply < ply_two_plays.size() ; ply++)
                        {           
                                 if (wins[f_index][s_index] == ply_two_plays[ply] )
                                    {
                                        win_checker_bot++;
                                        if (win_checker_bot == 2)
                                        {
                                            for (int search = 0 ;search < 3 ; search++)
                                             {
                                                if(wins[f_index][search] != ply_two_plays[ply])
                                                {
                                                    if ( plays[wins[f_index][search] - 1] == true)
                                                      {
                                                          ply_two_plays.push_back(wins[f_index][search]);
                                                        num_plays[wins[f_index][search] - 1] = "O";
                                                        i++;
                                                        win_checker_bot = 0 ;
                                                        plays[wins[f_index][search] - 1] = false;
                                                        
                                                            xo_show(num_plays);
                                                        if ( win_checker(ply_two_plays,player2))
                                                                {
                                                                    ply2_points++;
                                                                     cout << "Do You Wanna Continue Playing ?";
                                                                     cout << "\t Y/N" << endl;
                                                                     cin >> play;
                                                                   if (play == "Y" || play == "y")
                                                                  {
                                                                    reset_all();
                                                                     goto game;
                                                                   }
                                                                else if (play == "N" || play == "n")
                                                                    {
                                                                        cout << player1 << "`s Score Was Is:" << ply1_points << endl;
                                                                        cout << player2 << "`s Score Was Is:" << ply2_points << endl;
                                                                        return 0;
                                                                    }
                                                                        else 
                                                                        {
                                                                            goto player1;
                                                                        }
                                                                        }
                                                         }
                                                                        }
                                             }
                                                                }
                            
                        }
                }
        }
        }
            for (int f_index = 0 ; f_index < 8 ; f_index++)
        {
            win_blocker = 0;
            for (int s_index = 0 ;s_index < 3 ; s_index++)
                {
                        for (int ply =0; ply < ply_one_plays.size() ; ply++)
                        {
                                    if ( wins[f_index][s_index] == ply_one_plays[ply] && first_index != f_index)
                                            {
                                                win_blocker++;
                                                if ( win_blocker == 2 )
                                                    {
                                                     for ( int search = 0 ; search < 3 ; search++)
                                                        {
                                                            if (wins[f_index][search]  != ply_one_plays[ply] )
                                                                {
                                                                    if ( plays[wins[f_index][search] - 1] == true)
                                                                        {
                                                                            ply_two_plays.push_back(wins[f_index][search]);
                                                                            num_plays[wins[f_index][search] - 1] = "O";
                                                                            first_index = f_index;
                                                                            i++;
                                                                            win_blocker = 0 ;
                                                                            plays[wins[f_index][search] - 1] = false;
                                                                            if ( win_checker(ply_two_plays,player2))
                                                                      {
                                                                    ply2_points++;
                                                                     cout << "Do You Wanna Continue Playing ?";
                                                                     cout << "\t Y/N" << endl;
                                                                     cin >> play;
                                                                   if (play == "Y" || play == "y")
                                                                  {
                                                                    reset_all();
                                                                     goto game;
                                                                   }
                                                                else if (play == "N" || play == "n")
                                                                    {
                                                                        cout << player1 << "`s Score Was Is:" << ply1_points << endl;
                                                                        cout << player2 << "`s Score Was Is:" << ply2_points << endl;
                                                                        return 0;
                                                                    }
                                                                        }
                                                                            goto player1;
                                                                        }
                                                                }
                                                        }
                                                    }
                                            }
                        }
                        }
                        }
}
 random_device rd;
uniform_int_distribution<int> playing(1,9);
int the_Play = playing(rd);

     for (int  check = 0 ;check < ply_one_plays.size() ; check++)
            {
                if ( the_Play == ply_two_plays[check]  || the_Play == ply_one_plays[check])
                    {
                        goto player2;
                    } 
for (int j = 0 ; j < num_plays.size() ; j++)
{
    if (to_string(the_Play) == num_plays[j])
    {
        ply_two_plays.push_back(stoi(num_plays[j]));
        plays[j] = false;
         num_plays[j] = "O";
          i++;
             if ( i < 3)
                {
                  goto player1;
                 }
                                   if ( i >= 3)
                                     {
                                      xo_show(num_plays);
                                      if ( win_checker(ply_two_plays,player2))
                                      {
                                        ply2_points++;
                                      cout << "Do You Wanna Continue Playing ?";
                                      cout << "\t Y/N" << endl;
                                      cin >> play;
                                      if (play == "Y" || play == "y")
                                      {
                                        i = 0;
                                      ply_one_plays.clear();
                                      ply_two_plays.clear();
                                      plays = xo_reset_bool(plays);
                                      num_plays = xo_reset_string(num_plays);
                                      goto game;
                                      }
                                      else if (play == "N" || play == "n")
                                        {
                                            cout << player1 << "`s Score Was Is:" << ply1_points << endl;
                                            cout << player2 << "`s Score Was Is:" << ply1_points;
                                            return 0;
                                        }
                                      else goto player1;
                                      
                                      }
                                      else goto player1;
                                      
                                      }
    }
                           

} 
    }
}