//
// Created by karim on 03/26/2020.
//
#include <iostream>
using namespace std;

#ifndef FINALPROJECT_OOP_FUNCTIONS_H
#define FINALPROJECT_OOP_FUNCTIONS_H

int LetterToNum(string letter);
int StrToNum(string number);
bool HorOrVer(string letter);
void PrintToBoard(bool q, string x, string y, string carrierType, int f, vector<vector<string>> &grid);
int NPCBoard(vector<vector<string>> &P2G1);
bool checkError(string x);
bool checkError(int y);
void printBoard(vector<vector<string>> &P1G1);
int attackNPC(int type, int numberInput, string letterInput, vector<vector<string>> &P2G1, int counter);
void updateCarrier(vector<vector<string>> &P1G1, bool c, string AlignmentC, int xC, int yC);
void updateBattleship(vector<vector<string>> &P1G1, bool b, string AlignmentB, int xB, int yB);
void updateCruiser(vector<vector<string>> &P1G1, bool r, string AlignmentR, int xR, int yR);
void updateSubmarine(vector<vector<string>> &P1G1, bool s, string AlignmentS, int xS, int yS);
void updateDestroyer(vector<vector<string>> &P1G1, bool d, string AlignmentD, int xD, int yD);
string randomNPCName();

#endif //FINALPROJECT_OOP_FUNCTIONS_H