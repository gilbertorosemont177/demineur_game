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

    void CaseVide(Case** &grille,int posr,int poc);
    void ChercherBombes();
    
    void PrintGrilles();
    int Getrows() const;
    int Getcolumns() const;
    int DevoilerCasesVides(int posrow,int poscol);

    ~Grille();

private:

    Case **_grillecases;
    void CreateColumnsDynamic();
    int rows;//x
    int columns;//y
    bool casevide;
};


#endif	/* GRILLE_H */

