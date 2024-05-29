#include <array>

#include <vector>

#include <string>

using namespace std;

    string play;

    string player1;

    string player2 = "Bot";

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

    int wins[8][3]
    {
    {1,2,3},{4,5,6},{7,8,9},

    {1,4,7},{2,5,8},{3,6,9},

    {1,5,9},{3,5,7}
    };
    
// ============================================================================

    vector <int> ply_one_plays {0};

    vector <int> ply_two_plays {0} ;


// ===========================================================================