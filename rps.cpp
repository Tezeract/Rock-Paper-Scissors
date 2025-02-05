/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 2
 * Fall 2024
 *
 * <#description#>
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;

using namespace std;

//************************************************************************
// The following four functions have already been implemented for you.
// You should use them when writing the other functions, but do not edit
// their implementations.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();

//************************************************************************
// You must implement all of the following functions. Add your 
// implementations below rps() as indicated.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Utilizes the other functions in this file to play 
 *           the game Rock Paper Scissors.
 *
 *           Starter algorithm pseudocode: 
 *           1. Print the header
 *           2. Get player 1 name
 *           3. Get player 2 name
 *           4. Repeat the following until the user quits the program:
 *              * Get the menu choice
 *              * Play the game and announce the winner, 
 *                or quit the program (according to user's menu choice)
 *           5. Print the closing message 
 */
void rps();

/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *           Otherwise, return name entered by user.
 *              
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);

/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();



/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);


/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. 
 *           You can assume a user will enter a single character, 
 *           and nothing else, as their move.
 *
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);

/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won
 *           according to the rules to rock-paper-scissors. Returns false
 *           otherwise.
 */
bool isRoundWinner(char move, char opponentMove);


/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "",
 *           prints a message indicating the round is a draw. 
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);


/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "", 
 *           prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. 
 *           Returns the name of the game winner, or "" in event of a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// Implement the functions below this line.
//************************************************************************

// Rock paper scissors, the main function
void rps() {
    
    // Starts off with given RPS header
    printInitialHeader();
    
    // getting player names
    string playerOneName = getName(1);
    string playerTwoName = getName(2);
    int menuChoice = getMenuChoice();
    
    // Choice 2 is for the S'Mores version of the game (not included)
    while (menuChoice == 2) {
        cout << "Under Construction" << endl;
        announceWinner("");
        menuChoice = getMenuChoice();
    }
    
    // Loops regular RPS game until game is quit from the menu
    while (menuChoice == 1) {
        string gameWinner = doGame(playerOneName, playerTwoName, menuChoice);
        
        cout << endl;
        announceWinner(gameWinner);
        menuChoice = getMenuChoice();
        while (menuChoice == 2) {
            cout << "Under Construction" << endl;
            announceWinner("");
            menuChoice = getMenuChoice();
        }
    }
    printCloser();
    
    return;
}

// Gets and assigns names of each player based on their number of 1 or 2
string getName(int playerNumber) {
 
    
    string p1Name;
    string p2Name;
    
    if (playerNumber == 1) {
        
        cout << "Player 1, enter your name: ";
        getline(cin, p1Name );
        cout << endl;
        
        // If none or blank input, assigns default names
        // Rocky is for player 1 and Creed for player 2
        if (p1Name == "") {
            printErrorMessage(1);
            return "Rocky";
        }
        
        return p1Name;
        
    }
    if (playerNumber == 2) {
        
        cout << "Player 2, enter your name: ";
        getline(cin, p2Name );
        cout << endl;
        
        if (p2Name == "") {
            printErrorMessage(1);
            return "Creed";
        }
        else {
            return p2Name;
        }
    }
    
    return "";

}

// Prints menu from spec, uses cin to return player choice
int getMenuChoice() {
    
    int choice;
    
    // Prints menu from already implemented function
    printMenu();
    
    cin >> choice;
    cout << endl;
  
    // Takes in choice input. If not 1, 2, 3 redoes menu until valid choice.
    while ((choice != 1) && (choice != 2) && (choice != 3)) {
        cout << "Invalid menu choice" << endl;
        printMenu();
        cin >> choice;
    }
 
    if (choice == 2) {
        
        // 2 means the S'More version of RPS; not included
        return 2;
    }

    return choice;
}

// Gives true or false if a move binds by the RPS rules or not
bool isMoveGood(char move) {
    
    // ['R', 'r', 'P', 'p', 'S', 's'] = valid moves for RPS
    
    if ((move == 'r') || (move == 'R'))  {
        return true;
    }
   
    if ((move == 'p') || (move == 'P')) {
        return true;
    }
    
    if ((move == 's') || (move == 'S')) {
        return true;
    }
    else {
        return false;
    }
   
}

// returns the player move
char getMove(string playerName) {
   
    char playerChoice;
    
    cout << playerName << ", enter your move: ";
    cin >> playerChoice;
    
    // If move is good, simply returns move.
    if (isMoveGood(playerChoice)) {
        cout << endl;
        return playerChoice;
    }
    
    // If move is not good, the spec error message outputs
    else {
        printErrorMessage(2);
        cout << endl;
    }
    
    // Error returns a default of 'r'
    return 'r';
}

// Runs through the entire possibilities set of RPS
bool isRoundWinner(char move, char opponentMove) {
    
    // All returns based on if player one is the round winner
    // true = p1 winner, false = p2 winner
    
    if ((move == 'r') || (move == 'R'))  {
        
        if ((opponentMove == 's') || (opponentMove == 'S')) {
            return true;
        }
        else if ((opponentMove == 'p') || (opponentMove == 'P')) {
            return false;
        }
        else if ((opponentMove == 'r') || (opponentMove == 'R')){
            return false;
        }
    }
    else if ((move == 's') || (move == 'S'))  {
        
        if ((opponentMove == 'p') || (opponentMove == 'P')) {
            return true;
        }
        else if ((opponentMove == 'r') || (opponentMove == 'R')) {
            return false;
        }
        else if ((opponentMove == 's') || (opponentMove == 'S')){
            return false;
        }
    }
    else if ((move == 'p') || (move == 'P'))  {
        
        if ((opponentMove == 'r') || (opponentMove == 'R')) {
            return true;
        }
        else if ((opponentMove == 's') || (opponentMove == 'S')) {
            return false;
        }
        else if ((opponentMove == 'p') || (opponentMove == 'P')){
            return false;
        }
    }
    return 0;
}


void announceRoundWinner(string winnerName) {
    
    // A blank indicates a draw was made
    if (winnerName == "") {
        cout << "This round is a draw!";
    }
    else {
        cout << winnerName << " wins the round!";
    }
    return;
}

// Does a single round of RPS
int doRound(string p1Name, string p2Name) {
    
    // Getting the moves of the players
    char p1Move = getMove(p1Name);
    char p2Move = getMove(p2Name);
  
    
    // Returns 0 if there is a draw
    // (Draw means getMove returns the same value per player)
    if (p1Move == p2Move) {
        return 0;
    }
    
    // Returns 1 if player one is the winner
    if (isRoundWinner(p1Move, p2Move)) {
        return 1;
    }
    else if (!isRoundWinner(p1Move, p2Move)) {
        
        // Returns 2 if player two is the winner
        return 2;
    }
    return 0;
}


// Outputs the winner of a whole game using spec standard
void announceWinner(string winnerName) {
    
    // "" being the symbol for a draw
    if (winnerName == "") {
        cout << "No winner!" << endl;
        return;
    }
    
    cout << "Congratulations " << winnerName << "!" << endl;
    cout << "You won EECS 183 Rock-Paper-Scissors!" << endl;
    
    return;
}

// Does a whole game of RPS; each game 3 rounds max
string doGame(string p1Name, string p2Name, int gameType) {

    int p1WinCount = 0;
    int p2WinCount = 0;
    int rounds = 1;
    
        // Loops a round three times
        while (rounds <= MAX_ROUNDS) {
            
            // "" = placeholder value for winnerName
            string winnerName = "";
            int roundWinner = doRound(p1Name, p2Name);
            rounds += 1;
            
            // Player one beats player two
            if (roundWinner == 1) {
                winnerName = p1Name;
                p1WinCount += 1;
           }
            // player two beats player one
            else if (roundWinner == 2) {
                winnerName = p2Name;
                p2WinCount += 1;
           }
            // no player beats each other
            else if (roundWinner == 0) {
                winnerName = "";
           }
            announceRoundWinner(winnerName);
            cout << endl << endl;
          
        }
        
        // compares player win counts and returns player with the most
        if (p1WinCount > p2WinCount) {
           return p1Name;
        }
        else if (p1WinCount < p2WinCount) {
            return p2Name;
        }
        else if (p1WinCount == p2WinCount) {
            return "";
        }
    
   
    return "";
}




//***********************************************************************
// DO NOT modify the four functions below.
//***********************************************************************
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice --> ";
    
    return;
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" 
            << endl << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    } else {
        cout << "This should never print!";
    }
    
    return;
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}
