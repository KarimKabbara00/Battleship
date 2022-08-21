//
// Created by karim on 03/26/2020.
//

#include <iostream>
#include <vector>

using namespace std;

//used for changing letter coordinates to numbers.
//this is done to be able to access any grid on the board
int LetterToNum(string letter){

    if(letter=="A")
        return 1;
    else if(letter=="B")
        return 2;
    else if(letter=="C")
        return 3;
    else if(letter=="D")
        return 4;
    else if(letter=="E")
        return 5;
    else if(letter=="F")
        return 6;
    else if(letter=="G")
        return 7;
    else if(letter=="H")
        return 8;
    else if(letter=="I")
        return 9;
    else if(letter=="J")
        return 10;
    else
        return 0;
}

//converts number(string) from input file to an integer
int StrToNum(string number){
    if(number=="1")
        return 0;
    else if(number=="2")
        return 1;
    else if(number=="3")
        return 2;
    else if(number=="4")
        return 3;
    else if(number=="5")
        return 4;
    else if(number=="6")
        return 5;
    else if(number=="7")
        return 6;
    else if(number=="8")
        return 7;
    else if(number=="9")
        return 8;
    else if(number=="10")
        return 9;
}

// used to check alignment of ships
bool HorOrVer(string letter){
    if (letter=="H")
        return true;
    else if (letter == "V")
        return false;
    else
        return true;
}

//Prints ships to user board
void PrintToBoard(bool q, string x, string y, string carrierType, int f, vector<vector<string>> &grid) {

    if (q == true) { //Horizontal
        for (int i = LetterToNum(x); i < f + LetterToNum(x); i++) { //LetterToNum takes letter in input and converts to num
            if(i>10) // Handles going over the board limit
                throw 11;
            //Makes sure ships dont overlap
            if(grid[StrToNum(y)][i]=="C" || grid[StrToNum(y)][i]=="B" || grid[StrToNum(y)][i]=="R" || grid[StrToNum(y)][i]=="S" || grid[StrToNum(y)][i]=="D"){
                throw "Error";
            }
            grid[StrToNum(y)][i] = carrierType;
        }
    }

    if (q == false){ // Vertical
        for (int i = StrToNum(y); i < f + StrToNum(y); i++) { //LetterToNum takes letter in input and converts to num
            if(i>10)
                throw 11;

            if(grid[i][LetterToNum(x)]=="C" || grid[i][LetterToNum(x)]=="B" || grid[i][LetterToNum(x)]=="R" || grid[i][LetterToNum(x)]=="S" || grid[i][LetterToNum(x)]=="D"){
                throw "Error";
            }
            grid[i][LetterToNum(x)] = carrierType;
        }
    }
}

//used to check if input letter is correct
bool checkError(string x){
    if(x == "A" || x == "B" || x == "C" || x == "D" || x == "E" || x == "F" || x == "G" || x == "H" || x == "I" || x == "J"){
        return true;
    }
    else{
        cout<<"\nInvalid letter, try again.\n";
        return false;
    }

}

//used to check if input number is correct
bool checkError(int y){
    if(y == 1 || y == 2 || y == 3 || y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 9 || y == 10){
        return true;
    }

    else {
        cout << "\nInvalid number, try again.\n";
        return false;
    }
}

//generates npc board.
int NPCBoard(vector<vector<string>> &P2G1){

    int Rnd = rand()% 3 + 1; //between 1 or 3

    switch(Rnd){
        case 1:
            P2G1[1][1]="C", P2G1[1][2]="C", P2G1[1][3]="C", P2G1[1][4]="C", P2G1[1][5]="C";
            P2G1[3][1]="B", P2G1[4][1]="B", P2G1[5][1]="B", P2G1[6][1]="B";
            P2G1[6][4]="R", P2G1[6][5]="R", P2G1[6][6]="R";
            P2G1[0][9]="S", P2G1[1][9]="S", P2G1[2][9]="S";
            P2G1[5][9]="D", P2G1[6][9]="D";
            break;
        case 2:
            P2G1[3][2]="C", P2G1[4][2]="C", P2G1[5][2]="C", P2G1[6][2]="C", P2G1[7][2]="C";
            P2G1[0][5]="B", P2G1[0][6]="B", P2G1[0][7]="B", P2G1[0][8]="B";
            P2G1[2][6]="R", P2G1[2][7]="R", P2G1[2][8]="R";
            P2G1[3][6]="S", P2G1[3][7]="S", P2G1[3][8]="S";
            P2G1[0][1]="D", P2G1[0][2]="D";
            break;
        case 3:
            P2G1[9][1]="C", P2G1[9][2]="C", P2G1[9][3]="C", P2G1[9][4]="C", P2G1[9][5]="C";
            P2G1[2][4]="B", P2G1[3][4]="B", P2G1[4][4]="B", P2G1[5][4]="B";
            P2G1[7][8]="R", P2G1[7][9]="R", P2G1[7][10]="R";
            P2G1[0][9]="S", P2G1[1][9]="S", P2G1[2][9]="S";
            P2G1[5][9]="D", P2G1[6][9]="D";
            break;

    }

    //uncomment the below block to see the NPC board.
    cout<<endl<<endl;
    cout<<"NPC BOARD REMOVE ME"<<endl;
    cout<<"     A   B   C   D   E   F   G   H   I   J";
    for (int i = 0; i < P2G1.size(); i++)
    {
        cout<<endl;
        cout<<i+1;
        for (int j = 0; j < P2G1[i].size(); j++)
        {
            cout << P2G1[i][j];
            cout<<" | ";
        }
    }
    cout<<endl<<endl;

    return Rnd;
}

//prints attack history board to screen
void printBoard(vector<vector<string>> &P1G1){

    cout<<endl;
    cout<<"     A   B   C   D   E   F   G   H   I   J";
    for (int i = 0; i < P1G1.size(); i++)
    {
        cout<<endl;
        cout<<i+1;
        for (int j = 0; j < P1G1[i].size(); j++)
        {

            cout << P1G1[i][j];
            cout<<" | ";
        }
    }
    cout<<endl;
}

//if carrier is hit, updates on player board
void updateCarrier(vector<vector<string>> &P1G1, bool c, string AlignmentC, int xC, int yC){
    if(c==false){
        // checks alignment
        if(AlignmentC=="H"){ // horizontal
            for(int i=xC; i<xC+5; i++){
                P1G1[yC][i]="-";
            }
        }
        else{ //vertical
            for(int i=yC; i<yC+5; i++){
                P1G1[i][xC]="-";
            }
        }
    }
}

//if battleship is hit, updates on player board
void updateBattleship(vector<vector<string>> &P1G1, bool b, string AlignmentB, int xB, int yB){
    if (b==false){
        if(AlignmentB=="H"){
            for(int i=xB; i<xB+4; i++){
                P1G1[yB][i]="-";
            }
        }
        else{
            for(int i=yB; i<yB+4; i++){
                P1G1[i][xB]="-";
            }
        }
    }
}

//if cruiser is hit, updates on player board
void updateCruiser(vector<vector<string>> &P1G1, bool r, string AlignmentR, int xR, int yR){
    if(r==false){
        if(AlignmentR=="H"){
            for(int i=xR; i<xR+3; i++){
                P1G1[yR][i]="-";
            }
        }
        else{
            for(int i=yR; i<yR+3; i++){
                P1G1[i][xR]="-";
            }
        }
    }
}

//if submarine is hit, updates on player board
void updateSubmarine(vector<vector<string>> &P1G1, bool s, string AlignmentS, int xS, int yS){
    if(s==false){
        if(AlignmentS=="H"){
            for(int i=xS; i<xS+3; i++){
                P1G1[yS][i]="-";
            }
        }
        else{
            for(int i=yS; i<yS+3; i++){
                P1G1[i][xS]="-";
            }
        }
    }
}

//if destroyer is hit, updates on player board
void updateDestroyer(vector<vector<string>> &P1G1, bool d, string AlignmentD, int xD, int yD){
    if(d==false){
        if(AlignmentD=="H"){
            for(int i=xD; i<xD+2; i++){
                P1G1[yD][i]="-";
            }
        }
        else{
            for(int i=yD; i<yD+2; i++){
                P1G1[i][xD]="-";
            }
        }
    }
}

//function for user attacking npc.
int attackNPC(int type, int numberInput, string letterInput, vector<vector<string>> &P2G1, int counter){
    if(type==1){
        if(P2G1[numberInput-1][LetterToNum(letterInput)]=="C"){ //if input hits ship, changes the ship to "-"
            P2G1[1][1]="-"; P2G1[1][2]="-"; P2G1[1][3]="-"; P2G1[1][4]="-"; P2G1[1][5]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Carrier."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="B"){
            P2G1[3][1]="-", P2G1[4][1]="-", P2G1[5][1]="-", P2G1[6][1]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Battleship."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="R"){
            P2G1[6][4]="-", P2G1[6][5]="-", P2G1[6][6]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Cruiser."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="S"){
            P2G1[0][9]="-", P2G1[1][9]="-", P2G1[2][9]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Submarine."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="D"){
            P2G1[5][9]="-", P2G1[6][9]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Destroyer."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="-"){
            cout<<"\nYou already hit this ship!";
        }
        else
            cout<<"\nYou missed!";
    }

    else if(type==2){
        if(P2G1[numberInput-1][LetterToNum(letterInput)]=="C"){
            P2G1[3][2]="-", P2G1[4][2]="-", P2G1[5][2]="-", P2G1[6][2]="-", P2G1[7][2]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Carrier."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="B"){
            P2G1[0][5]="-", P2G1[0][6]="-", P2G1[0][7]="-", P2G1[0][8]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Battleship."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="R"){
            P2G1[2][6]="-", P2G1[2][7]="-", P2G1[2][8]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Cruiser."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="S"){
            P2G1[3][6]="-", P2G1[3][7]="-", P2G1[3][8]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Submarine."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="D"){
            P2G1[0][1]="-", P2G1[0][2]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Destroyer."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="-"){
            cout<<"\nYou already hit this ship!";
        }
        else
            cout<<"\nYou missed!";
    }
    else if(type==3){
        if(P2G1[numberInput-1][LetterToNum(letterInput)]=="C"){
            P2G1[9][1]="-", P2G1[9][2]="-", P2G1[9][3]="-", P2G1[9][4]="-", P2G1[9][5]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Carrier."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="B"){
            P2G1[2][4]="-", P2G1[3][4]="-", P2G1[4][4]="-", P2G1[5][4]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Battleship."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="R"){
            P2G1[7][8]="-", P2G1[7][9]="-", P2G1[7][10]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Cruiser."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="S"){
            P2G1[0][9]="-", P2G1[1][9]="-", P2G1[2][9]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Submarine."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="D"){
            P2G1[5][9]="-", P2G1[6][9]="-";
            cout<<"\nYou hit the enemies ship! Well done! You destroyed the Destroyer."<<endl;
            counter++;
        }
        else if(P2G1[numberInput-1][LetterToNum(letterInput)]=="-"){
            cout<<"\nYou already hit this ship!";
        }
        else
            cout<<"\nYou missed!";
    }
    return counter;
}

// generates random opponent name
string randomNPCName(){

    int Rnd = rand()% 5 + 1; //between 1 or 5
    string name;

    switch(Rnd){
        case 1: name = "Wyatt"; return name;
        case 2: name = "Cody"; return name;
        case 3: name = "Poppy"; return name;
        case 4: name = "Abigail"; return name;
        case 5: name = "Bob"; return name;
    }
}