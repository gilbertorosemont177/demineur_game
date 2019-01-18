
#include "Case.h"

Case::Case(){
    this->cases=false;
    this->quantityBombs=0;
    this->caseImg="x";
    this->casereveal=false;
}

string Case::DisplayCase() const {


    return this->caseImg;
}
Case::~Case() {}
bool Case::IsBombe() {

    return this->cases;
}
ostream & operator << (ostream &out, const Case &c)
{
    out << c.DisplayCase()<< endl;
    return out;
}
void Case::TurnCaseInBombe() {

    this->cases=true;
    this->ModifyDisplayBombe();
}
void Case::ModifyDisplayBombe() {

    this->caseImg="*";
}
void Case::DisplayNumberCase() {
    cout<<this->quantityBombs;
}
void Case::IncreaseValueCase() {
    this->quantityBombs+=1;
    //this->caseImg=to_string(this->quantiteBombes);
}
bool Case::Isreveal() {
        return this->casereveal;
}
void Case::TurnCaseReveal(){
    this->casereveal=true;
}
void Case::DevoilerCaseNbr() {

    if(this->quantityBombs==0)
        this->caseImg= " ";
    else
        this->caseImg=to_string(this->quantityBombs);

}

void Case::HideCase(){
    this->caseImg="v";
}
int Case::GetNumberCase() {
    return this->quantityBombs;
}
void Case::TurnCaseInEmpty() {
    this->caseImg=" ";
}

