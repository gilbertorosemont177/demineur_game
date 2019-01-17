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
    void ChangeCaseVide();
    void Augmenter();
    string displayCase() const;
    void DisplayNumberCase();
    bool  IsBombe();
    void ChangeCaseInBombe();
    bool Isreveal();
    void ChangeCaseReveal();
    void DevoilerCaseNbr() ;
    void Voiler();
    int GetNumberCase();
    void Boucles(int n);
    // destructor
     ~Case();
     //print objt
    friend ostream & operator << (ostream &out, const Case &c);

private:
    bool cases,caserevelee;
    int quantiteBombes;
    string caseImg;
    void ModifyDisplayBombe();


};


#endif	/* CASE_H */

