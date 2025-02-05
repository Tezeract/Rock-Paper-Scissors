/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 2
 * Fall 2024
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();
void test_getName();
void test_getMenuChoice();
void test_getMove();


void startTests() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    cout << endl;
    
    test_getName();
    cout << endl;
    
    test_announceRoundWinner();
    cout << endl;
    
    test_getMove();
    cout << endl;
    
    test_isRoundWinner();
    cout << endl;
    
    test_announceWinner();
    cout << endl;
    
    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;

    if (!isMoveGood('R')) {
        cout << "FAILED: isMoveGood('R') should have returned 'true'" << endl;
    }
    
    if (!isMoveGood('P')) {
        cout << "FAILED: isMoveGood('P') should have returned 'true'" << endl;
    }
    
    if (!isMoveGood('p')) {
        cout << "FAILED: isMoveGood('p') should have returned 'true'" << endl;
    }
   
    if (!isMoveGood('S')) {
        cout << "FAILED: isMoveGood('S') should have returned 'true'" << endl;
    }
   
    if (!isMoveGood('s')) {
        cout << "FAILED: isMoveGood('s') should have returned 'true'" << endl;
    }
   
    cout << "'test': Expected: 0, Actual: " << isMoveGood('test') << endl;


    return;
}

void test_isRoundWinner() {
    cout << "Now testing function isRoundWinner()\n";
    cout << "('r', 's') , Expected: 1, Actual: " << isRoundWinner('r', 's') << endl;
    cout << "('r', 'p') , Expected: 0, Actual: " << isRoundWinner('r', 'p') << endl;
    cout << "('x', 'p') , Expected: 0, Actual: " << isRoundWinner('x', 'p') << endl;
    
    return;
}

void test_announceRoundWinner() {
    
    cout << "Now testing function announceRoundWinner()\n";
        
    announceRoundWinner("");
    cout << endl;
    
    announceRoundWinner("Name");
    cout << endl;
    
    announceRoundWinner("2");
    cout << endl;
       
    return;
}

void test_announceWinner() {
    cout << "Now testing function announceWinner()\n";
    
    announceWinner("Joel");
    cout << endl;

    announceWinner("");
    cout << endl;
    
    announceWinner("'r'");
    cout << endl;
    return;
}

void test_getName() {
    cout << "Now testing function getName()\n";
    
    getName(1);
    cout << endl;
    
    return;
}

void test_getMove() {
    
}
