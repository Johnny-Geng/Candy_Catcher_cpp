#include <iostream>

using namespace std;


/** 
 * Prints the leaderboard in the appropriate (sorted by candy count) order
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 */
void printLeaderboard(string players[], int candy[], int numplayers);


/** 
 * Update the candy count of the given player to reflect the number
 * of pieces of candy they found. Do nothing (just return)
 * if the given player does not exist in the arrays already
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   playerName: Name of the player to update
 *   candyFound: Number of pieces of candy found by playerName
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void struckGold(string players[], int candy[], string playerName, int candyFound, int numplayers);

/** 
 * Add 2 to all player candy counts that are still in the game.
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void rainingCandy(string players[], int candy[], int numplayers);

/** 
 * Cut in half all candy counts of players who are in even positions on the
 * leaderboard (0-indexed). Use integer division, since the big bully
 * is greedy and doesn't like "half" pieces of candy.
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void theft(string players[], int candy[], int numplayers);

/** 
 * Gives one piece of candy from the top player to each other player in
 * reverse order.  Starting from the last player, Big Bully takes one 
 * piece of candy from the top player and gives it to the last place player,
 * then repeats for the second  to last player, continuing until the top 
 * player is out of candy or we've given one piece of candy to every other 
 * player (i.e. we've reached the 2nd place player).
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void toughLuck(string players[], int candy[], int numplayers);


/** 
 * Returns the index of the specified player or -1 if it doesn't exist
 *
 * Parameters:
 *   players: Array of player names
 *   playerName: Name of the player to search for
 *   numplayers: Number of players in the players arrays
 * 
 * Returns: Index of given playerName or -1
 */
int findPlayer(string players[], string playerName, int numplayers);

/** 
 * Prints the main menu and returns the integer selection the user 
 * wants to perform.  If the user provides an invalid selection, 
 * simply return -1 which the calling function (e.g. main() can
 * use to detect the error.
 *
 * Returns: integer selection of the user or -1 if the selection
 *  was invalid
 */
int printPromptAndGetInput();


/**
 * Sort the player and candy array from highest candy count to lowest.  
 *
 * We recommend one of the simplest sorting algorithms:  Selection sort
 * Look at the class notes or online resources for how to implement this.
 *
 * Parameters
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Total number of players
 */
void sortLeaderboard(string players[], int candy[], int numplayers);

/** 
 * Delete the given player and its corresponding candy count from the arrays
 * by moving all later players/candy counts up one spot, overwriting the
 * player to be deleted.  This function will be called by dropLosers()
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy counts at location i corresponds to
 *          the player name at location i in the players array)
 *   playerName: Name of the player to delete
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 * Returns: false if the specified player does not exist, or true if
 *          the player was successfully deleted.
 */
bool deletePlayer(string players[], int candy[], string playerName, int numplayers);

/**
 * Delete all players from the game who do not have positive candy counts. 
 * 
 * Note that when a player is deleted, the index of other players may
 * shift, so special care must be taken.
 *
 * Parameters
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Total number of players before deleting.
 *
 * Returns: the number of players remaining after deleting.
 */
int dropLosers(string players[], int candy[], int numplayers);

/**
 * By implementing this correctly and integrating it into your
 * project so that player names are displayed with spaces, even
 * though the user enters them without spaces you can earn
 * some additional extra credit.
 * 
 * Breaks up a string at capital letters and inserts spaces 
 * So if the input is "KatnissEverdeen" return "Katniss Everdeen".
 * You may assume the first letter is a caps (and even if it
 * not you will still get a reasonable result; so "johnBrown" 
 * should still return "john Brown").
 *
 * Parameters:
 *  in: string with no spaces
 *
 * Returns: a version of the string with spaces
 */
string breakStringAtCaps(string in);

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

void printLeaderboard(string players[], int candy[], int numplayers)
{
    for (int i = 0; i < numplayers; i++){
        cout << breakStringAtCaps(players[i]) << " " << candy[i] << endl;
    }
}

void struckGold(string players[], int candy[], string playerName, int candyFound, int numplayers)
{
    int playerIndex = findPlayer(players, playerName, numplayers);
    if ( playerIndex!= -1){

        if (candyFound <= 0){
            cout << "Bad candy count...ignoring" << endl;
        }

        else {
            candy[playerIndex] += candyFound;
        }
    }

    else {
        cout << "Invalid player...ignoring" << endl;
    }
}

void rainingCandy(string players[], int candy[], int numplayers)
{
    for(int i = 0; i < numplayers; i++){
        candy[i] += 2;
    }
}

void theft(string players[], int candy[], int numplayers)
{
    for(int i = 0; i < numplayers; i += 2){
        candy[i] /= 2;
    }
}

void toughLuck(string players[], int candy[], int numplayers)
{
    for(int i = numplayers-1; i > 0; i--){
        if (candy[0] > 0){
            candy[0] -= 1;
            candy[i] += 1;
        }
        else {
            break;
        }
    }
}


int findPlayer(string players[], string playerName, int numplayers)
{
    for (int i = 0; i < numplayers; i++){
        if (players[i] == playerName){
            return i;
        }
    }
    return -1;
}

int printPromptAndGetInput()
{   
    // print the menu
    cout << "What event will occur this round?" << endl; 
    cout << "0. Quit" << endl;
    cout << "1. Struck Gold: Player \"x\" finds \"y\" pieces of candy" << endl;
    cout << "2. Raining Candy: All players collect 2 pieces of candy" << endl;
    cout << "3. Theft: Big Bully steals half of the candy of all even-index players (minimum 1 piece)" << endl;
    cout << "4. Tough Luck: Big Bully gives one piece of candy from the top player to each other player in reverse order." << endl;
    int choice;
    cin >> choice;
    if (choice >=0 && choice <=4) {
        return choice;
    }
    else {
        return -1;
    }
}

void sortLeaderboard(string players[], int candy[], int numplayers)
{
    for(int i=0; i<numplayers-1; i++){
        int max = i;
        for (int j= i+1; j<numplayers;j++){
            if (candy[j] > candy[max]) {
                max = j;
            }
        }
        // swap the order
        string temp_player = players[i];
        players[i] = players[max];
        players[max] = temp_player;

        int temp_candy = candy[i];
        candy[i] = candy[max];
        candy[max] = temp_candy;
        
    }
}

string breakStringAtCaps(string in)
{
    int size = in.size();
    for(int i = 1; i < size; i++){
        if (in[i] >= 'A' && in[i] <='Z'){
            string sub1 = in.substr(0, i);
            string sub2 = " ";
            string sub3 = in.substr(i);
            in = sub1 + sub2 + sub3;
            break;
        }
    }
    return in;

}

bool deletePlayer(string players[], int candy[], string playerName, int numplayers)
{
    int playerIndex = findPlayer(players, playerName, numplayers);
    if (playerIndex == -1){
        return false;
    }
    else {
        for (int x = playerIndex; x < numplayers-1; x++){
            players[x] = players[x+1];
            candy[x] = candy[x+1];
        }
        return true;
    }
}

int dropLosers(string players[], int candy[], int numplayers)
{

    int numLosers = 0;
    for (int i=0; i < numplayers; i++){
        if (candy[i] <= 0){
            numLosers++;
        }
    }

    while(numLosers > 0){
        for (int i=0; i < numplayers; i++){
            if (candy[i] <= 0){
                deletePlayer(players, candy, players[i], numplayers);
                numLosers--;
                numplayers--;
                break;
            }
        }
    }

    return numplayers;

}



/**********************************************************
 *  Main must be completed by you.
 **********************************************************/
int main()
{
    const int SIZE = 20;
    string players[SIZE];
    int candy[SIZE];
    int numplayers = 0;

    /* Add your code here */

    // Get the initial players and their candy count
    cout << "*Your prompt for number of players (1-20):*" << endl;
    cin >> numplayers;
    for (int i = 0; i < numplayers; i++){
        cout << "*Prompt to enter name and starting number of candies*" << endl;
        cin >> players[i] >> candy[i];
    }
    
    // Sort and print the initial leaderboard
    sortLeaderboard(players, candy, numplayers);
    cout << "Initial Leaderboard:"<< endl;
    printLeaderboard(players, candy, numplayers);

    // Game Actions
    int choice = printPromptAndGetInput();
    while (choice != 0){
        // Error check
        if (choice == -1){
            cout << "Bad event option...type a number in {0,1,2,3,4}" << endl;
        }

        else if (choice == 1){
            string playerName;
            int candyFound;
            cin >> playerName >> candyFound;
            struckGold(players, candy, playerName, candyFound, numplayers);
            
        }

        else if (choice == 2){
            rainingCandy(players, candy, numplayers);
        }

        else if (choice == 3){
            theft(players, candy, numplayers);
        }

        else if (choice == 4){
            toughLuck(players, candy, numplayers);
        }

        numplayers = dropLosers(players, candy, numplayers);
        // Blank leaderboard check
        if (numplayers == 0){
            break;
        }
        else {
            sortLeaderboard(players, candy, numplayers);
            cout << "Current Leaderboard:"<< endl;
            printLeaderboard(players, candy, numplayers);
            choice = printPromptAndGetInput();
        }
    }
    /* End your code here */

    cout << endl;
    cout << "FINAL LEADERBOARD:" << endl;
    printLeaderboard(players, candy, numplayers);


    return 0;
}