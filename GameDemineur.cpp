#include "GameDemineur.h"
#include "Grille.h"


GameDemineur::GameDemineur() {


}
void GameDemineur::MessageGameStart() {


    cout<<"----------  GAME ------------\n"
        <<"1- Niveau Debutant grille(9x9) \n"
       


}

void GameDemineur::ChoixPlay(int choix) {

    switch(choix) {
        case 1  :
            LevelBeginner();
            break;


    }

}
void  GameDemineur::LevelBeginner() {

    this->grille = Grille(9,9);
    this->grille.ChercherBombes();




}

void GameDemineur::menuintoGame(){

    cout<<""<<endl;
    cout<<"1- Voulez-vous ouvrir une case choix(1) "<<endl;
    cout << "Menu 2 Entrez un choix valide (1 - 3): "<<endl;

}

void GameDemineur::ChoixActionGame(int choix){
       
       



}
void GameDemineur::GetCoordonneesXY(){

    cout<<"Pouvez vous saisir les coordonnees de la case:"<<endl;


}