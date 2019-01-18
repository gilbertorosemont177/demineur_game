
#include "Grille.h"
//Constructor par defaut
Grille::Grille() {
    this->_columns=9;
    this->_rows=9;
    this->_caseempty=false;
    this->CreateColumnsDynamic();
}

Grille::Grille(int rows, int columns) {
    this->_columns=columns;
    this->_rows=rows;
    this->CreateColumnsDynamic();
    this->_caseempty=false;

}

void Grille::CreateColumnsDynamic() {
    this->_grillecases=new Case*[this->_rows];
    for (int row = 0; row < _rows; ++row)
        this->_grillecases[row]= new Case[_columns];

    for (int i = 0; i <  _rows; ++i){
        for (int j = 0; j < _columns; ++j){

            /** bombes test*/
            if(i==0 && j==4) {
                this->_grillecases[i][j].TurnCaseInBombe();
            }
            if(i==2 && j==4) {
                this->_grillecases[i][j].TurnCaseInBombe();
            }
            if(i==2 && j==2) {
                this->_grillecases[i][j].TurnCaseInBombe();
            }
            if(i==7 &&j==7){
                this->_grillecases[i][j].TurnCaseInBombe();
            }

            /**end bombes test**/

        }

    }
}
 int Grille:: Getrows() const{
     return this->_rows;
 }
 int Grille::Getcolumns() const {
     return this->_columns;
 }
// lorsqu'on trouve une case vide va chercher
int Grille::LookAllCasesEmptys(int posr,int poc) {
    //Case** &grille,
    if (row>this->_rows-1 || row<0 || col>this->_columns-1 || col<0){
        return -1;
    }
    if(this->_grillecases[row][col].IsBombe()){
        return 0;
    }

    if(this->_grillecases[row][col].Isreveal()){
        return 1;
    }
    if(this->_grillecases[row][col].GetNumberCase()>0){
        this->_grillecases[row ][col].TurnCaseReveal();
    }
        if (this->_grillecases[row ][col].GetNumberCase() == 0) {
            this->_grillecases[row ][col].TurnCaseReveal();
            if (LookAllCasesEmptys(row - 1, col - 1) == 1) {
                LookAllCasesEmptys(row - 1, col - 1);
            }
            if (LookAllCasesEmptys(row + 1, col + 1) == 1) {
                LookAllCasesEmptys(row + 1, col + 1);
            }
            if (LookAllCasesEmptys( row -1, col ) == 1) {
                LookAllCasesEmptys(row - 1, col );
            }
            if(LookAllCasesEmptys(row-1,col+1)==1){
                LookAllCasesEmptys(row - 1, col+1 );
            }
            if(LookAllCasesEmptys(row,col-1)==1){
                LookAllCasesEmptys(row,col-1);
            }
            if(LookAllCasesEmptys(row,col+1)==1){
                LookAllCasesEmptys(row,col+1);
            }
            if(LookAllCasesEmptys(row+1,col-1)==1){
               LookAllCasesEmptys(row+1,col-1);
            }
            if(LookAllCasesEmptys(row+1,col)==1){
               LookAllCasesEmptys(row+1,col);
            }
        }
}
// chercher les bombes et modifier le nombre de Case toutes le cases ont pare defaut 0 comme valeur
void Grille::LookForBombs() {

    for (int row = 0; row < this->Getrows(); ++row) {

        for (int col = 0; col < this->Getcolumns(); ++col) {

            if (this->_grillecases[row][col].IsBombe()) {
                if (row + 1 < this->Getrows())
                    this->_grillecases[row + 1][col].IncreaseValueCase();
                if (row - 1 > -1)
                    this->_grillecases[row - 1][col].IncreaseValueCase();
                if (col + 1 < this->Getcolumns()) {
                    this->_grillecases[row][col + 1].IncreaseValueCase();
                    if (row - 1 > -1)
                        this->_grillecases[row - 1][col + 1].IncreaseValueCase();
                    if (row + 1 < this->Getrows())
                        this->_grillecases[row + 1][col + 1].IncreaseValueCase();
                }
                if (col - 1 > -1) {
                    this->_grillecases[row][col - 1].IncreaseValueCase();
                    if (row - 1 > -1)
                        this->_grillecases[row - 1][col - 1].IncreaseValueCase();
                    if (row + 1 <  this->Getrows())
                        this->_grillecases[row + 1][col - 1].IncreaseValueCase();
                }
            }

        }

    }

}
