/* 
 * File:   Case.h
 * Author: GT
 *
 * Created on 17 janvier 2019, 01:18
 */

#ifndef CASE_H
#define	CASE_H

#include "iostream"
#include <string>
using  namespace std;

class Case {

public:
    Case();
    void TurnCaseInEmpty();
    void IncreaseValueCase();
    string DisplayCase() const;
    void DisplayNumberCase();
    bool  IsBombe();
    void TurnCaseInBombe();
    bool Isreveal();
    void TurnCaseReveal();
    void DevoilerCaseNbr() ;
    void HideCase();
    int GetNumberCase();
    //void Loops(int n);
    // destructor
     ~Case();
     //print objt
    friend ostream & operator << (ostream &out, const Case &c);

private:
    bool cases,casereveal;
    int quantityBombs;
    string caseImg;
    void ModifyDisplayBombe();


};


#endif	/* CASE_H */

