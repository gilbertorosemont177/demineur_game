/* 
 * File:   main.cpp
 * Author: GT
 *
 * Created on 17 janvier 2019, 00:52
 */

#include <cstdlib>
#include <iostream>
#include <string>

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

    Case **cases;

    createGrilleGame(cases,9,9);

    chercherBombes(cases,9,9);
    devoilerCasesVides(cases, 4,0 );


    PrintGrilletest(cases,9,9);
   

    delete[] cases;
    return 0;
}

void createGrilleGame(Case** &liste,int rows, int columns) {

    liste = new Case *[rows];
    for (int row = 0; row < rows; ++row)
        liste[row] = new Case[columns];
    // on place des bombes dans la methode grille
    // de facon dinamique
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {

            if (i == 0 && j == 4) {
                liste[i][j].ChangeCaseInBombe();
            }
            if (i == 2 && j == 4) {
                liste[i][j].ChangeCaseInBombe();
            }
            if (i == 2 && j == 2) {
                liste[i][j].ChangeCaseInBombe();
            }
            if (i == 7 && j == 7) {
                liste[i][j].ChangeCaseInBombe();
            }
            if (i == 5 && j == 5) {
                liste[i][j].ChangeCaseInBombe();
            }


        }

    }

}


int devoilerCasesVides(Case** &grille,int row,int col) {
    if (row>8 || row<0 || col>8 || col<0){
        return -1;
    }
    if(grille[row][col].IsBombe()){
        return 0;
    }

    if(grille[row][col].Isreveal()){
        return 1;
    }
    if(grille[row][col].GetNumberCase()>0){
        grille[row ][col].ChangeCaseReveal();
    }
        if (grille[row ][col].GetNumberCase() == 0) {
            grille[row ][col].ChangeCaseReveal();
            if (devoilerCasesVides(grille, row - 1, col - 1) == 1) {
                devoilerCasesVides(grille, row - 1, col - 1);
            }
            if (devoilerCasesVides(grille, row + 1, col + 1) == 1) {
                devoilerCasesVides(grille, row + 1, col + 1);
            }
            if (devoilerCasesVides(grille, row -1, col ) == 1) {
                devoilerCasesVides(grille, row - 1, col );
            }
            if(devoilerCasesVides(grille,row-1,col+1)==1){
                devoilerCasesVides(grille, row - 1, col+1 );
            }
            if(devoilerCasesVides(grille,row,col-1)==1){
                devoilerCasesVides(grille,row,col-1);
            }
            if(devoilerCasesVides(grille,row,col+1)==1){
                devoilerCasesVides(grille,row,col+1);
            }
            if(devoilerCasesVides(grille,row+1,col-1)==1){
                devoilerCasesVides(grille,row+1,col-1);
            }
            if(devoilerCasesVides(grille,row+1,col)==1){
                devoilerCasesVides(grille,row+1,col);
            }
        }
}

void chercherBombes(Case** &grille,int rowsize, int colssize) {

    for (int row = 0; row < rowsize; ++row) {

        for (int col = 0; col < colssize; ++col) {

            if (grille[row][col].IsBombe()) {
                if (row + 1 < rowsize)
                    grille[row + 1][col].Augmenter();
                if (row - 1 > -1)
                    grille[row - 1][col].Augmenter();
                if (col + 1 < colssize) {
                    grille[row][col + 1].Augmenter();
                    if (row - 1 > -1)
                        grille[row - 1][col + 1].Augmenter();
                    if (row + 1 < rowsize)
                        grille[row + 1][col + 1].Augmenter();
                }
                if (col - 1 > -1) {
                    grille[row][col - 1].Augmenter();
                    if (row - 1 > -1)
                        grille[row - 1][col - 1].Augmenter();
                    if (row + 1 < rowsize)
                        grille[row + 1][col - 1].Augmenter();
                }
            }

        }

    }

}
void PrintGrilletest(Case** &grille,int rowssize, int colssize) {
    int lastnumber = 8;
    int lastrow = 8;
    cout << "" << endl;
    for (int i = 0; i < rowssize; ++i) {
        if (i == 0) {

            for (int g = 0; g < 15; ++g) {
                cout << "__";
            }
            cout << endl;
            cout << endl;
        }
        for (int j = 0; j < colssize; ++j) {


            if (grille[i][j].Isreveal()) {
                grille[i][j].DevoilerCaseNbr();

            } else if (!grille[i][j].Isreveal() || grille[i][j].IsBombe()) {
                grille[i][j].Voiler();
            }
            cout << "| " << grille[i][j].displayCase();
            if (j == lastnumber) {
                cout << " |";
            }


        }


        cout << endl;
        if (i == 8) {

            for (int g = 0; g < 15; ++g)
                cout << "__";
            cout << endl;
        }

    }

}

