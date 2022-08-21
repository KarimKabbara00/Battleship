#include <iostream>
#include <vector> //allows use of vectors
#include <fstream> //allows use of reading files
#include <string>
#include "Functions.h"
#include <time.h> //used for random number generator
#include <algorithm> //used to ensure captitalized input
#include <iomanip> //used to manipulate output for text formatting.
using namespace std;

class player{ // creates a player class
public:
    string name;
    int score;
};

class ships{ //creates base ship class

};

class Carrier: public ships{ // child class for carrier.
public:
    int GridsRequired = 5; // Grids required for this ship
    string letter = "C"; // Letter that shows up on board to represent ship
};
class Battleship: public ships{ // child class for battleship.
public:
    int GridsRequired = 4;
    string letter = "B";
};
class Cruiser: public ships{ // child class for Cruise.
public:
    int GridsRequired = 3;
    string letter = "R";
};
class Submarine: public ships{ // child class for submarine.
public:
    int GridsRequired = 3;
    string letter = "S";
};
class Destroyer: public ships{ // child class for destroyer.
public:
    int GridsRequired = 2;
    string letter = "D";
};

int main() {
    //Variables for player grid.
    //Coordinates to locate the first grid/part of a ship.
    string xC, yC; //x and y coordinates for carrier
    string xB, yB; //x and y coordinates for submarine
    string xR, yR; //x and y coordinates cruiser
    string xS, yS; //x and y coordinates submarine
    string xD, yD; //x and y coordinates destroyer
    string AlignmentC, AlignmentB, AlignmentR, AlignmentS, AlignmentD; // Holds the alignment type for each ship type. H or V.
    string Letter; // Holds ship letter
    int GridsRequired; // holds ship grid requirement;

    //Creates instance of each ship type.
    Carrier c1;
    Battleship b1;
    Cruiser r1;
    Submarine s1;
    Destroyer d1;

    //grid is created as a 11x10 for the code to work but the game only uses 10x10
    vector<vector<string>> P1G1 (10, vector<string>(11, " ")); //Player1 Grid1
    vector<vector<string>> P1G2 (10, vector<string>(11, " ")); //Player1 Grid2
    string tutorial;
    srand(time(0)); //initializes random seed
    string shipType;
    string letterInput; //holds user letter input
    int numberInput; //holds user number input
    string replay; // used for replaying the game
    bool exitGame = false; // used for exiting game

    //'line' is used to read in lines from the input file
    string line;

    ifstream myFile ("ship_placement1_good.csv"); // opens the file

    if (myFile.is_open()){ //checks if the file is open
        //while loop and for loop read through entire file and collect info from the file
        while(getline(myFile, line)){
            for(string::size_type i = 0; i < line.size(); ++i) { //Runs through the input file
                //Checks the input for a sequence of characters to identify the type of ship.
                if(line[i] == 'C' && line[i+1] == 'a'){
                    xC = line[i+8]; // gets the letter placement as a string
                    yC = line[i+9]; // gets the number placement as a string
                    GridsRequired = c1.GridsRequired; // holds the number of grids required for ship type
                    Letter = c1.letter; // holds the number of grids required for ship type
                    AlignmentC = line[i+11]; // gets whether it is H or V
                    try{ // ensures that ships neither go out of bounds, nor overlap.
                        PrintToBoard(HorOrVer(AlignmentC), xC, yC, Letter, GridsRequired, P1G1); // prints ship to board
                    }
                    catch(int error){ // catches exception if ship goes out of bounds
                        cout<<"Your alignment is exceeds the board limit. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0); //exits game so user can check input file
                    }
                    catch(char const*){ // catches exception if ships overlap
                        cout<<"Your alignment causes ships to overlap. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0); //exits game so user can check input file
                    }
                }
                //Logic that is used above is the same as logic below for other ship types.
                else if(line[i] == 'B' && line[i+1] == 'a'){
                    xB = line[i+11];
                    yB = line[i+12];
                    GridsRequired = b1.GridsRequired;
                    Letter = b1.letter;
                    AlignmentB = line[i+14];
                    try{
                        PrintToBoard(HorOrVer(AlignmentB), xB, yB, Letter, GridsRequired, P1G1);
                    }
                    catch(int error){
                        cout<<"Your alignment is exceeds the board limit. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                    catch(char const*){
                        cout<<"Your alignment causes ships to overlap. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                }

                else if(line[i] == 'C' && line[i+1] == 'r'){
                    xR = line[i+8];
                    yR = line[i+9];
                    GridsRequired = r1.GridsRequired;
                    Letter = r1.letter;
                    AlignmentR = line[i+11];
                    try{
                        PrintToBoard(HorOrVer(AlignmentR), xR, yR, Letter, GridsRequired, P1G1);
                    }
                    catch(int error){
                        cout<<"Your alignment is exceeds the board limit. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                    catch(char const*){
                        cout<<"Your alignment causes ships to overlap. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                }

                else if(line[i] == 'S' && line[i+1] == 'u'){
                    xS = line[i+10];
                    yS = line[i+11];
                    GridsRequired = s1.GridsRequired;
                    Letter = s1.letter;
                    AlignmentS = line[i+13];
                    try{
                        PrintToBoard(HorOrVer(AlignmentS), xS, yS, Letter, GridsRequired, P1G1);
                    }
                    catch(int error){
                        cout<<"Your alignment is exceeds the board limit. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                    catch(char const*){
                        cout<<"Your alignment causes ships to overlap. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                }

                else if(line[i] == 'D' && line[i+1] == 'e'){
                    xD = line[i+10];
                    yD = line[i+11];
                    GridsRequired = d1.GridsRequired;
                    Letter = d1.letter;
                    AlignmentD = line[i+13];
                    try{
                        PrintToBoard(HorOrVer(AlignmentD), xD, yD, Letter, GridsRequired, P1G1);
                    }
                    catch(int error){
                        cout<<"Your alignment is exceeds the board limit. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                    catch(char const*){
                        cout<<"Your alignment causes ships to overlap. Please try again."<<endl;
                        cout<<"Exiting game...";
                        exit(0);
                    }
                }
            }
        }
        myFile.close(); // closes the file after finished reading in all ships
    }
    else{ //checks if file is closed.
        cout<<"File is closed. Please ensure file is open to continue."<<endl;
        cout<<"Exiting game...";
        exit(0);
    }


    string name;// holds user's name
    player playerOne; // creates instance of player one
    player playerTwo; // creates instance of player two
    playerOne.score=0; playerTwo.score=0; // holds player score if they play again
    playerTwo.name = randomNPCName(); // generates random npc name
    /*------------------------PRINT CODE BELOW------------------------*/
    //Game begins here.
    while(true){
        // The Opponent vector is created every loop to wipe the board for a new game
        vector<vector<string>> P2G1 (10, vector<string>(11, " "));
        //Generates the NPC board. This is part of the while loop to ensure a random board if the user wants to play again.
        int type = NPCBoard(P2G1); // generates board for npc

        cout<<"\nEnter your name to begin: ";
        getline(cin, name); // getline is used to hold multiple words for one input
        playerOne.name = name;
        cout<<"\n\nWelcome to Battleship!"<<endl;
        cout<<"Would you like a tutorial? (Y/N)" <<endl; //asks user if they want a tutorial
        while(true){ // loops till user types correct input
            cin>>tutorial;
            if(tutorial == "Y" || tutorial =="y"){
                cout<<"\nThe objective of this game is to destroy your Opponent's ships before they destroy yours!"<<endl;
                cout<<"\nEach player has two boards: a Ship Board that holds all your ships, and an Attack History Board that\nshows your all your attempts at attacking."<<endl;
                cout<<"\nTo attack the enemy, enter the letter THEN the number that corresponds to the desired grid location."<<endl;
                cout<<"If the grid you choose to attack holds part of a ship, the ship will be destroyed! Your torpedoes will be\nmarked on your second board with an X to keep record."<<endl;
                cout<<"\nYour ships will be marked with a - if your Opponent successfuly targets their torpedo."<<endl;
                cout<<"\nEach ship uses a unique letter to be represented on the board and has a specific length:"<<endl;
                cout<<"\nC for Carrier,    5 grids\nB for Battleship, 4 grids\nR for Cruiser,    3 grids\nS for Submarine,  3 grids\nD for Destroyer,  2 grids"<<endl;
                cout<<"\nThe first one to destroy all the enemy's ships wins!"<<endl;
                cout<<"\n\nYour opponent's name is "<<playerTwo.name<<".";
                cout<<"\nEnjoy the game!"<<endl;
                break;
            }
            else if(tutorial=="N" || tutorial == "n"){
                cout<<"\n\nYour opponent's name is "<<playerTwo.name<<".";
                cout<<"\nEnjoy the game!"<<endl;
                break;
            }
            else{
                cout<<"Invalid entry, choose Y/N:"<<endl;
                continue;
            }
        }

        int counter=0, counterNPC=0; //counts the ships destroyed for player and NPC. There are 5 ships on the board.
        bool c = true, b = true, r = true, s = true, d = true; // used for ensuring Opponent doesnt hit destroyed ships again

        while(true){ // loop used to keep the game going
            cout<<"\n"<<setw(28)<<"Player Board"<<endl; //setw is used for formatting
            printBoard(P1G1); //prints the player board to the screen every turn
            cout<<"\n\n"<<setw(32)<<"Attack History Board"<<endl;
            printBoard(P1G2); // prints the attack history board


            bool inputChecker = false; //used to check if user input meets criteria
            cout<<"\n\nEnter letter (A-J) to attack the enemy, or Q to quit the game: ";
            cin>>letterInput; // asks for input for letter
            transform(letterInput.begin(), letterInput.end(), letterInput.begin(), ::toupper); // ensures letter input is capitalized

            if(letterInput=="Q" || letterInput=="q"){//allows for user to quit game
                exitGame=true; // ends the first loop to end the game
                break; // breaks out of the nested while loop
            }
            cout<<"\nEnter a number (1-10) to attack the enemy:";
            cin>>numberInput; // asks for input for number
            while(inputChecker==false){ //verifies input meets the criteria, and loops until input is correct
                if(checkError(letterInput)==true && checkError(numberInput) == true){
                    break;
                }
                else if(checkError(letterInput)==false){
                    cout<<"Letter (A-J): ";
                    cin>>letterInput;
                    // ensures letter input is capitalized
                    transform(letterInput.begin(), letterInput.end(), letterInput.begin(), ::toupper); // ensures letter input is capitalized
                    continue;
                }

                else if(checkError(numberInput)==false){
                    cout<<"\nNumber (1-10): ";
                    cin>>numberInput;
                    continue;
                }
            }

            //Marks where you have attacked the enemy board
            P1G2[numberInput-1][LetterToNum(letterInput)]="X";

            //logic for attacking the opponent
            cout<<endl<<endl<<endl<<endl<<endl;
            counter = attackNPC(type, numberInput, letterInput, P2G1, counter); // used for player attacking npc

            //Checks if player destroyed 5 ships
            if(counter==5){ //if == 5, the game ends.
                cout<<"\n\n\nYou have destroyed all the ships on the enemy board! "<<playerOne.name<<" wins!";
                playerOne.score++;
                break;
            }

            while(true){
                //logic for opponent attacking player
                // generates two random coordinates for the npc to strike
                int x = rand() % 10;
                int y = rand() % 10 + 1;

                if(P1G1[x][y]==c1.letter && c == true){ // checks if npc attack has hit a player ship
                    cout<<"\n\nYour opponent has destroyed your carrier!"<<endl;
                    //P1G1[x][y]="-";
                    counterNPC++;
                    c=false;
                    // updates the ship on the player board if npc strikes it
                    updateCarrier(P1G1, c, AlignmentC, LetterToNum(xC), StrToNum(yC));
                    break;
                }
                else if(P1G1[x][y]==b1.letter && b == true){
                    cout<<"\n\nYour opponent has destroyed your battleship!"<<endl;
                    //P1G1[x][y]="-";
                    counterNPC++;
                    b=false;
                    // updates the ship on the player board if npc strikes it
                    updateBattleship(P1G1, b, AlignmentB, LetterToNum(xB), StrToNum(yB));
                    break;
                }
                else if(P1G1[x][y]==r1.letter && r == true){
                    cout<<"\n\nYour opponent has destroyed your cruiser!"<<endl;
                    //P1G1[x][y]="-";
                    counterNPC++;
                    r=false;
                    // updates the ship on the player board if npc strikes it
                    updateCruiser(P1G1, r, AlignmentR, LetterToNum(xR), StrToNum(yR));
                    break;
                }
                else if(P1G1[x][y]==s1.letter && s == true){
                    cout<<"\n\nYour opponent has destroyed your submarine!"<<endl;
                    //P1G1[x][y]="-";
                    counterNPC++;
                    s=false;
                    // updates the ship on the player board if npc strikes it
                    updateSubmarine(P1G1, s, AlignmentS, LetterToNum(xS), StrToNum(yS));
                    break;
                }
                else if(P1G1[x][y]==d1.letter && d == true){
                    cout<<"\n\nYour opponent has destroyed your destroyer!"<<endl;
                    //P1G1[x][y]="-";
                    counterNPC++;
                    d=false;
                    // updates the ship on the player board if npc strikes it
                    updateDestroyer(P1G1, d, AlignmentD, LetterToNum(xD), StrToNum(yD));
                    break;
                }
                //below else if statement checks if npc has already hit a ship and makes them hit again if so
                else if((P1G1[x][y]==c1.letter && c == false) || (P1G1[x][y]==b1.letter && b == false) || (P1G1[x][y]==r1.letter && r == false) ||
                        (P1G1[x][y]==s1.letter && s == false) || (P1G1[x][y]==d1.letter && d == false) || (P1G1[x][y]=="-")){
                    continue;
                }
                else{ // if opponent misses
                    cout<<"\nYour opponent did not destroy any of your ships!"<<endl;
                    break;
                }
            }

            //Checks if opponent destroyed 5 ships
            if(counterNPC==5){ //if == 5, the game ends.
                cout<<"\nYour opponent, "<<playerTwo.name<<", has destroyed all your ships! You lose!"<<endl;
                playerTwo.score++;
                break; // ends game
            }
        }

        //Checks if user wants to quit game
        if(exitGame==true)
            break;

        //Checks if user wants to play again
        cout<<"\n\nWould you like to play again? (Y/N)"<<endl;
        cin>>replay;
        if(replay=="Y" || replay == "y"){ // checks input and replays
            cout<<"\n\nThe score is "<<playerOne.score<<"-"<<playerTwo.score<<"."<<endl;
            continue;
        }
        else if(replay=="N" || replay == "n"){
            cout<<"\n\nThe score is "<<playerOne.score<<"-"<<playerTwo.score<<"."<<endl;
            break;
        }
        else{ // if input is invalid, game ends
            cout<<"\nInvalid input."<<endl;
            cout<<"The score is "<<playerOne.score<<"-"<<playerTwo.score<<"."<<endl;
            cout<<"The game has ended"<<endl;
            break;
        }
    }
    cout<<"\n\n\nThank you for playing Battleship!"<<endl;
    cout<<"Made by Karim Kabbara.\n";
    return 0;
}