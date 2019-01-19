#include "GameDemineur.h"
#include "Grille.h"


GameDemineur::GameDemineur() {


}
void GameDemineur::MessageGameStart() {


cout<<"----------  GAME ------------\n"
        <<"1- Niveau Debutant grille(9x9) \n"
        <<"2- Niveau Avancé \n"
        <<"3- EXIT \n"
        <<"-----------       -----------"
        <<endl;

    cout << "Entrez un choix valide (1 - 3): "<<endl;


    int option= ValidationOptionNumber();
    

    this->ChoicePlayLevel(option);
}

void GameDemineur::ChoicePlayLevel(int choix) {

    switch(choix) {
        case 1  :
            LevelBeginner();
            break;
        case 2  :
            LevelAvance();
            break;
        case 3  :
            Exit();
            break; //optional
        default :
            cout << "vous devez entrer un choix valide choissisez(1-3)!!! \n";
            MessageGameStart();
            break;


    }

}
void  GameDemineur::LevelBeginner() {
    
this->grille = Grille(9,9);
    //this->GrilleCases=this->grille.GetCases();
    this->grille.LookForBombs();

    cout<<endl;
    cout<<" Bienvenue au LevelBeginner"<<endl;
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
    cout<<"2 -Voulez-vous mettre un drapeau choix(2)"<<endl;
    cout<<"3 -Voulez-vous revenir au Menu Principal choix(3)"<<endl;
    cout<<""<<endl;

    cout << "Menu 2 Entrez un choix valide (1 - 3): "<<endl;

    int option =ValidationOptionNumber();
    ChoiceAction(option);
}

void GameDemineur::ChoiceAction(int choix){
       
       
                switch(choix){
                           case 1:
                               GetCoordinatesXY();
                               break;
                           case 3:
                               GoToMenuPrincipal();
                               break;
                           default :
                               MenuGameStarted();
                               break;
                       }



}
void GameDemineur::GetCoordinatesXY(){

     cout<<"Pouvez vous saisir les coordonnees de la case:"<<endl;


    cout << "Entrez un entier le row X ="<<endl;

    int optionx=ValidationOptionNumber();
    cout << "Entrez un entier le row Y ="<<endl;

    int optiony=ValidationOptionNumber();

        Play(optionx,optiony);
}
void GameDemineur::LevelAvance() {
    cout<<"level avance"<<endl;

}
void GameDemineur::Exit() {
    cout<<"EXIT"<<endl;
}

void GameDemineur::Play(int x,int y ){


   cout<<"COORDONNNES X ="<< x <<endl;
   cout<<"COORDONNNES Y="<< y<<endl;



        if(this->grille.GetCases()[x][y].IsBombe()) {
           this->grille.GetCases()[x][y].Isreveal();
            cout<<"BOOM!!!!!"<<endl;
            cout<<"VOUS AVEZ PERDU !!!!!"<<endl;
            MessageGameStart();

        }
        else {
            this->grille.LookAllCasesEmptys(x, y);
            this->grille.PrintGrilles();
            this->MenuGameStarted();
        }





}
int GameDemineur::ValidationOptionNumber(){
    int numberoption;

    cin >> numberoption;
    while(!cin)
    {
        cout << "La valeur que vous avez saisi n'est pas un nombre du Menu!!! ) \n"<<endl;
        cin.clear();
        cin.ignore();
        cin >> numberoption;
    }
    return numberoption;
}


