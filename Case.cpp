
#include "Case.h"

Case::Case(){
    this->cases=false;
    this->quantiteBombes=0;
    this->caseImg="x";
    this->caserevelee=false;
}

string Case::displayCase() const {


    return this->caseImg;
}
Case::~Case() {}
bool Case::IsBombe() {

    return this->cases;
}
ostream & operator << (ostream &out, const Case &c)
{
    out << c.displayCase()<< endl;
    return out;
}
void Case::ChangeCaseInBombe() {

    this->cases=true;
    this->ModifyDisplayBombe();
}
void Case::ModifyDisplayBombe() {

    this->caseImg="*";
}
void Case::DisplayNumberCase() {
    cout<<this->quantiteBombes;
}
void Case::Augmenter() {
    this->quantiteBombes+=1;
    //this->caseImg=to_string(this->quantiteBombes);
}
bool Case::Isreveal() {
        return this->caserevelee;
}
void Case::ChangeCaseReveal(){
    this->caserevelee=true;
}
void Case::DevoilerCaseNbr() {

    if(this->quantiteBombes==0)
        this->caseImg= " ";
    else
        this->caseImg=to_string(this->quantiteBombes);

}

void Case::Voiler(){
    this->caseImg="v";
}
int Case::GetNumberCase() {
    return this->quantiteBombes;
}
void Case::ChangeCaseVide() {
    this->caseImg=" ";
}

