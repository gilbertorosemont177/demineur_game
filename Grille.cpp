
#include "Grille.h"
//Constructor par defaut
Grille::Grille() {
    this->columns=9;
    this->rows=9;
    this->casevide=false;
    this->CreateColumnsDynamic();
}

Grille::Grille(int rows, int columns) {
    this->columns=columns;
    this->rows=rows;
    this->CreateColumnsDynamic();
    this->casevide=false;

}

void Grille::CreateColumnsDynamic() {
    this->_grillecases=new Case*[this->rows];
    for (int row = 0; row < rows; ++row)
        this->_grillecases[row]= new Case[columns];

    for (int i = 0; i <  rows; ++i){
        for (int j = 0; j < columns; ++j){

            /** bombes test*/
            if(i==0 && j==4) {
                this->_grillecases[i][j].ChangeCaseInBombe();
            }
            if(i==2 && j==4) {
                this->_grillecases[i][j].ChangeCaseInBombe();
            }
            if(i==2 && j==2) {
                this->_grillecases[i][j].ChangeCaseInBombe();
            }
            if(i==7 &&j==7){
                this->_grillecases[i][j].ChangeCaseInBombe();
            }

            /**end bombes test**/

        }

    }
}
 int Grille:: Getrows() {
     return this->rows;
 }
 int Grille::Getcolumns() {
     return this->columns;
 }
// lorsqu'on trouve une case vide va chercher
int Grille::DevoilerCasesVides(int row,int col) {
    //Case** &grille,
    if (row>this->rows-1 || row<0 || col>this->columns-1 || col<0){
        return -1;
    }
    if(this->_grillecases[row][col].IsBombe()){
        return 0;
    }

    if(this->_grillecases[row][col].Isreveal()){
        return 1;
    }
    if(this->_grillecases[row][col].GetNumberCase()>0){
        this->_grillecases[row ][col].ChangeCaseReveal();
    }
        if (this->_grillecases[row ][col].GetNumberCase() == 0) {
            this->_grillecases[row ][col].ChangeCaseReveal();
            if (DevoilerCasesVides(row - 1, col - 1) == 1) {
                DevoilerCasesVides(row - 1, col - 1);
            }
            if (DevoilerCasesVides(row + 1, col + 1) == 1) {
                DevoilerCasesVides(row + 1, col + 1);
            }
            if (DevoilerCasesVides( row -1, col ) == 1) {
                DevoilerCasesVides(row - 1, col );
            }
            if(DevoilerCasesVides(row-1,col+1)==1){
                DevoilerCasesVides(row - 1, col+1 );
            }
            if(DevoilerCasesVides(row,col-1)==1){
                DevoilerCasesVides(row,col-1);
            }
            if(DevoilerCasesVides(row,col+1)==1){
                DevoilerCasesVides(row,col+1);
            }
            if(DevoilerCasesVides(row+1,col-1)==1){
                DevoilerCasesVides(row+1,col-1);
            }
            if(DevoilerCasesVides(row+1,col)==1){
                DevoilerCasesVides(row+1,col);
            }
        }
}
// chercher les bombes et modifier le nombre de Case toutes le cases ont pare defaut 0 comme valeur
void Grille::ChercherBombes(int rowsize, int colssize) {

    for (int row = 0; row < rowsize; ++row) {

        for (int col = 0; col < colssize; ++col) {

            if (this->_grillecases[row][col].IsBombe()) {
                if (row + 1 < rowsize)
                    this->_grillecases[row + 1][col].Augmenter();
                if (row - 1 > -1)
                    this->_grillecases[row - 1][col].Augmenter();
                if (col + 1 < colssize) {
                    this->_grillecases[row][col + 1].Augmenter();
                    if (row - 1 > -1)
                        this->_grillecases[row - 1][col + 1].Augmenter();
                    if (row + 1 < rowsize)
                        this->_grillecases[row + 1][col + 1].Augmenter();
                }
                if (col - 1 > -1) {
                    this->_grillecases[row][col - 1].Augmenter();
                    if (row - 1 > -1)
                        this->_grillecases[row - 1][col - 1].Augmenter();
                    if (row + 1 < rowsize)
                        this->_grillecases[row + 1][col - 1].Augmenter();
                }
            }

        }

    }

}
