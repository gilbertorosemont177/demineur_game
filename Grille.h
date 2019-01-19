/* 
 * File:   Grille.h
 * Author: GT
 *
 * Created on 17 janvier 2019, 02:34
 */

#ifndef GRILLE_H
#define	GRILLE_H

#include "Case.h"

class Grille{

public:
    Grille(int rows, int columns);
    Grille();

    int LookAllCasesEmptys(int posr,int poc);
    void LookForBombs();
    
    void PrintGrilles();
    int Getrows() const;
    int Getcolumns() const;
      void DeleteCases();

      bool Win();
      void RevealAllCases();
    Case **& GetCases() ;
    ~Grille();
    //int RevealCasesEmptys(int posrow,int poscol);

private:

    Case **_grillecases;
    void CreateColumnsDynamic();
    int _rows;//x
    int _columns;//y
    bool _caseempty;
    bool _gameover;
};


#endif	/* GRILLE_H */

