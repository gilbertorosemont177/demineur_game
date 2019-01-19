
#include "Grille.h"
//Constructor par defaut
Grille::Grille() {
    this->_columns=9;
    this->_rows=9;
    this->_caseempty=false;
    this->_gameover=false;
    this->CreateColumnsDynamic();
}

Grille::Grille(int rows, int columns) {
    this->_columns=columns;
    this->_rows=rows;
    this->_gameover=false;
    this->_caseempty=false;
       this->CreateColumnsDynamic();

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
            if (i == 5 && j == 5) {
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
int Grille::LookAllCasesEmptys(int row,int col) {
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
Grille::~Grille(){

}

Case **& Grille::GetCases() {
    return this->_grillecases;
}

void Grille::DeleteCases(){
    delete [] this->_grillecases;
}
void Grille::PrintGrilles(){
    cout << "" << endl;
    for (int i = 0; i < this->Getrows(); ++i) {
        if (i == 0) {

            for (int g = 0; g < 15; ++g) {
                cout << "__";
            }
            cout << endl;
            cout << endl;
        }
        for (int j = 0; j < this->Getcolumns(); ++j) {
       
            if (this->_grillecases[i][j].Isreveal()) {
                this->_grillecases[i][j].DevoilerCaseNbr();            
            }
            if(this->_gameover && this->_grillecases[i][j].IsBombe()){
                this->_grillecases[i][j].ModifyDisplayBombe();
            }
            cout << "| " << this->_grillecases[i][j].DisplayCase();
                if (j==this->Getcolumns()-1) {
                    cout << " |";
                }
        }
        cout << endl;
        if (i == this->Getrows()-1) {
            for (int g = 0; g < 15; ++g)
                cout << "__";
            cout << endl;
        }
    }

}
bool Grille::Win(){

    int nbrbombs=5;
    int casestotal=this->_columns*this->_rows;
    int cases=casestotal-nbrbombs;
    int compteurcasereveals=0;
    for (int row=0; row<Getrows(); ++row){
        for(int col=0; col<Getcolumns();++col){
            if(this->_grillecases[row][col].Isreveal())
                compteurcasereveals+=1;
        }
    }
    if(compteurcasereveals==cases){
        this->_gameover=true;
        return true;
        
    }
    return false;
 }
void Grille::RevealAllCases(){

    for (int row=0; row<Getrows(); ++row){
            for(int col=0; col<Getcolumns();++col){
                this->_grillecases[row][col].TurnCaseReveal();  
            }
        }
    this->_gameover=true;
}
//manque method creer des bombes aleatoires