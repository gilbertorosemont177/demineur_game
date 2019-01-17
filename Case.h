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
     void displayNumberCase();
     bool  IsBombe();
     void changeInBombe();
     bool isreveal();
    void changeReveal();
    void devoilerNumber() ;
    void Voiler();
    int getNumberCase();
    void changeMethod(int n);
    void Boucles(int n);
    // destructor
     ~Case();
     
    friend ostream & operator << (ostream &out, const Case &c);

private:
    bool cases,reveal;
    int quantiteBombes;
    string caseImg;
    void ModifyDisplayBombe();


};


#endif	/* CASE_H */

