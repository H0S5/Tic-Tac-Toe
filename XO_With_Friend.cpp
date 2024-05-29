
#include "functions.h"
using namespace std;
int main ()
{
    cout << "Enter Player One Name" << endl;
    cin >> player1;
    cout << "Enter Player Two Name" << endl;
    cin >> player2;
    game:
 // Player One

    player1:
    cout << "Type [00] To Show The Score" << endl;
    cout << player1 << " Turn";
        xo_show(num_plays);
        cin >> play;
     for (int  check = 0 ;check < ply_one_plays.size() ; check++)
            {
                if ( ply_one_plays[check] == stoi(play) || stoi(play) <= 0  || stoi(play) >= 10 )
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
                                 num_plays[j] = "X";
                                 xo_show(num_plays);
                                  if ( win_checker(ply_one_plays,player1))
                                      {
                                        ply1_points++;
                                        askAgain:
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
                                            cout << player1 << "`s Score Was Is:" << ply1_points;
                                            cout << player2 << "`s Score Was Is:" << ply2_points;
                                            return 0;
                                        }                      
                                      else 
                                            {
                                                cout << "Wrong Input" << endl;
                                                goto askAgain;
                                            }
                                      }
                                
                                cout << "Draw" << endl;
                                here3:
                                cout << "Do You Wanna Continue Playing ?"<< endl;
                                cout << "\t [Y/N]" << endl;
                                cin >> play;
                                    if (play == "Y" || play == "y" || play == "yes" || play == "Yes")
                                        {
                                            i = 0;
                                      reset_all();
                                      goto game;
                                        }
                                        else if (play == "N" || play == "n" || play == "no" || play == "No")
                                            {
                                             cout << player1 << "`s Score Was Is:" << ply1_points << endl;
                                             cout << player2 << "`s Score Was Is:" << ply2_points << endl;
                                            return 0;
                                            }
                                            else 
                                            {
                                                cout << "Wrong Input" << endl;
                                                goto here3;
                                            }
                            }
                        if ( play ==  num_plays[j])
                            {
                                ply_one_plays.push_back(stoi(num_plays[j]));
                                plays[j] = false;
                                 num_plays[j] = "X";
                                  i++;
                                  if ( i < 3)
                                  {
                                    goto player2;
                                  }
                                   if ( i >= 3)
                                     {
                                      xo_show(num_plays);
                                      if (play_again(ply_one_plays,player1,ply1_points) == 1)
                                        {
                                            goto game;
                                        }
                                        else if ( play_again(ply_one_plays,player1,ply1_points) == 0 )
                                            {
                                                return 0;
                                            }
                                      else goto player2;
                                      
                                      }


                             }

                       } 
    
                                      


 // Player Two

        player2:
        cout << "Type [00] To Show The Score" << endl;
        cout << player2 << " Turn";
        xo_show(num_plays);
            cin >> play;
            
            for (int  check = 0 ;check < ply_two_plays.size() ; check++)
            {
                if ( stoi(play) == ply_two_plays[check] || stoi(play) <= 0  || stoi(play) >= 10 )
                    {
                        cout << "Wrong Place" << endl;
                        goto player2;
                    }
            }
                        if (play == "00")
                        {
                            cout << player1 << "`s Score Is: " << ply1_points << endl;
                            cout << player2 << "`s Score Is: " << ply2_points << endl;
                        }
                for (int j = 0 ;j < num_plays.size() ; j++)
                    {
                        
                        if ( play ==  num_plays[j])
                            {
                                  i++;
                                ply_two_plays.push_back(stoi(num_plays[j]));
                                plays[j] = false;
                                 num_plays[j] = "O";
                                  if ( i < 3)
                                    {
                                        goto player1;
                                    }
                                  if ( i >= 3)
                                     {
                                       xo_show(num_plays);
                                       if (play_again(ply_two_plays,player2,ply2_points) == 1)
                                        {
                                            goto game;
                                        }
                                        else if ( play_again(ply_two_plays,player2,ply2_points) == 0 )
                                            {
                                                return 0;
                                            }
                                      else goto player1;
                                     }

    
                            }
                     }
}

