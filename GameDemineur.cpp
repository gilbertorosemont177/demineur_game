#include "GameDemineur.h"
#include "Grille.h"


GameDemineur::GameDemineur() {


}
void GameDemineur::MessageGameStart() {


cout<<"----------  GAME ------------\n"
        <<"1- Niveau Debutant grille(9x9) (-- just this option works now) \n"
       // <<"2- Niveau Avancé ()\n"
        <<"2- Quitter \n"
        <<"-----------       -----------"
        <<endl;

    cout << "Entrez un choix valide (1 - 2): "<<endl;


    int option= ValidationOptionNumber();
    

    this->ChoicePlayLevel(option);
}

void GameDemineur::ChoicePlayLevel(int choix) {

    switch(choix) {
        case 1  :
            LevelBeginner();
            break;
       /* case 2  :
            LevelAvance();
            break;*/
        case 2  :
            Exit();
            break; //optional
        default :
            cout << "vous devez entrer un choix valide choissisez(1-2)!!! \n";
            MessageGameStart();
            break;
    }
}
void  GameDemineur::LevelBeginner() {
    
    this->grille = Grille(9,9);
    this->grille.LookForBombs();
    cout<<" Bienvenue au LevelBeginner";
    this->grille.PrintGrilles();
    MenuGameStarted();
    
}
void GameDemineur::GoToMenuPrincipal(){

    this->grille.DeleteCases();
    MessageGameStart();

}
void GameDemineur::MenuGameStarted(){

   cout<<""<<endl;
    cout<<"1- Voulez-vous ouvrir une case choix(1) "<<endl;
  //  cout<<"2 -Voulez-vous mettre un drapeau choix(2)"<<endl;
    cout<<"2 -Voulez-vous revenir au Menu Principal choix(3)"<<endl;
    cout<<""<<endl;

    cout << "Entrez un choix valide (1 - 2): "<<endl;

    int option =ValidationOptionNumber();
    ChoiceAction(option);
}

void GameDemineur::ChoiceAction(int choix){
        switch(choix){
            case 1:
                 GetCoordinatesXY();
                 break;
            case 2:
                GoToMenuPrincipal();
                break;
            default :
                 MenuGameStarted();
                 break;
            }
}
void GameDemineur::GetCoordinatesXY(){

    cout<<"Pouvez vous saisir les coordonnées de la case:"<<endl;
    cout << "Entrez un entier le row X ="<<endl;

    int optionx=ValidationCoordinates();
    cout << "Entrez un entier le col Y ="<<endl;

    int optiony=ValidationCoordinates();
     Play(optionx,optiony);
}
void GameDemineur::LevelAvance() {
    cout<<"level avance"<<endl;
}
void GameDemineur::Exit() {
    cout<<"EXIT"<<endl;
}

void GameDemineur::Play(int x,int y ){

    cout<<"COORDONNNES X ="<< x 
    <<" COORDONNNES Y="<< y<<endl;
    if(this->grille.GetCases()[x][y].IsBombe()) {
           this->grille.GetCases()[x][y].Isreveal();
            cout<<"BOOM!!!!!"<<endl;
            cout<<"VOUS AVEZ PERDU !!!!!"<<endl;
            cout<<"!!!! ---VOICI LA GRILLE SUR LAQUELLE VOUS AVEZ JOUÉ --!!!"<<endl;
            this->grille.RevealAllCases();
            this->grille.PrintGrilles();
            cout<<" +++ END GAME+++"<<endl;
            MessageGameStart();
        }
        else {
            this->grille.LookAllCasesEmptys(x, y);
            if(this->grille.Win()){
                this->grille.PrintGrilles();
                cout<<"!!!!!!  ++++VOUS AVEZ GAGNÉ ++++!!!!!!!"<<endl;
                this->MessageGameStart();
            }
            else{
                this->grille.PrintGrilles();
                this->MenuGameStarted();
            }
        }
}
int GameDemineur::ValidationOptionNumber(){
    int numberoption;

    cin >> numberoption;
    while(!cin)
    {
        cout << "1- Validation !!! La valeur saisi n'est pas un entier Entrez un entier !!! ) \n"<<endl;
        cin.clear();
        cin.ignore();
        cin >> numberoption;
    }
    return numberoption;
}
int GameDemineur::ValidationCoordinates(){
    
    int coordinates=0;
    bool verificationcoord=false;
    cin >> coordinates;
    while(!cin || !verificationcoord){
    while(!cin )
    {
        cout << "1- Validation - !!! La valeur saisi n'est pas un entier Entrez un entier !!! ) \n"<<endl;
        cin.clear();
        cin.ignore();
        cin >> coordinates;
    }
    if(coordinates<0 || coordinates >= this->grille.Getrows()){
            cout << "2 -Validation - Coordonnees !!!coordonnees saisi sont hors de la grille (entre 0 - 8) \n"<<endl;
            cin.clear();
            cin.ignore();
            cin >> coordinates;
      }
      else{
          verificationcoord=true;
      }
      
    }
    
    
    return coordinates;
    


}


