# Candy_Catcher_cpp
This program is a fun game called Candy Catcher.
## Background:
In this game, players will compete to collect as much candy as possible in a “Hunger Games”-style arena. Beware -- a “Big Bully” with a sweet tooth hides somewhere in the arena. As the players collect candy, their scores will be updated on a leaderboard and displayed so that the players’ hometown “Districts” can cheer them on. Several rounds of events will take place as the players explore. Some events will cause players to gain candy; others will cause them to lose some of their candy. After all the rounds are finished the player with the most pieces of candy to be the winner! 
## Logistics:
1. Enter the number of players you wish to have
____
2. Enter the name of initial players and their starting number of candies, separated by a space in the following style
   - Example: <br>
   A 4-player entry would look like this:<br>
   ```
    *Your prompt for number of players:*
    4
    *Prompt to enter name and starting number of candies*
    KatnissEverdeen 4
    *Prompt to enter name and starting number of candies*
    PeterParker 2
    *Prompt to enter name and starting number of candies*
    Batman 5
    *Prompt to enter name and starting number of candies*
    ClarkKent 1
    ```
    -***WARNING***: Please do **NOT** put any space between a player's first name and last name; use capital letter to distinguish instead.<br>
    i.e. use ```KatnissEverdeen``` instead of ```Katniss Everdeen```.
            
____
3. An initial leaderboard will be sorted and printed
____
4. Choose the event that will occur by enter the option number<br>
   1. Struck Gold: Player “x” finds “y” pieces of candy
      - For this event option, please enter the name of players and their starting number of candies, separated by a space in the following style (case sensitive)
      ```
       KatnissEverdeen 4
      ```
   2. Raining Candy: All players collect 2 pieces of candy
   3. Theft: Big Bully steals half of the candy of all even-index players (minimum 1 piece)
   4. Tough Luck: Big Bully gives one piece of candy from the top player to each other player in reverse order
   5. Quit
____
5. The game will continue to run until the user chooses to quit or all players are eliminated
____
6. A final leaderboard will be displayed
## Purpose:
This program is designed to demonstrate the fundamentals of C++ such as:<br>
loops, functions, arrays, sorting, etc.

   
