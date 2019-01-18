/* 
 * File:   GameDemineur.h
 * Author: GT
 *
 * Created on 18 janvier 2019, 16:03
 */

#ifndef GAMEDEMINEUR_H
#define	GAMEDEMINEUR_H
#include  "Case.h"
#include "Grille.h"
using namespace std;

class GameDemineur {
    
    public :
    GameDemineur();
     void MessageGameStart();
     void ChoixPlay(int choix);
    void ChoixActionGame(int choix);
    void GoToMenuPrincipal();
    void Play(int x, int y);
    void GetCoordonneesXY();
    void menuintoGame();
    int ValidationNumber();
//    void testMenu();


private :

     void LevelBeginner();
     void LevelAvance();
     void Exit();
    bool lost=false;
    Case ** GrilleCases;
    Grille grille;



};

    
  


#endif	/* GAMEDEMINEUR_H */

