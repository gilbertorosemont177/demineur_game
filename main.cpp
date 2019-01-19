/* 
 * File:   main.cpp
 * Author: GT
 *
 * Created on 17 janvier 2019, 00:52
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "GameDemineur.h"
#include "Case.h"
using namespace std;

/*
 * TEST DE LA CLASSE CASE et des methodes devoiler case vide et chercher bombes
 */
void PrintGrilletest(Case** &grille,int rowssize, int colssize );
void createGrilleGame(Case** &grille,int rows, int columns);
void chercherBombes(Case** &grille,int r,int cx);
int devoilerCasesVides(Case** &grille, int r ,int c);




int  main(){

  GameDemineur game;
    game.MessageGameStart();
   

   
    return 0;
}


