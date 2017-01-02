#include <iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include <iomanip>
#include<windows.h>
#include<stdio.h>
#include<fstream>

using namespace std;

const int GAUCHE= 75;
const int DROITE=77;
const int HAUT= 72;
const int BAS= 80;
int BestScore;


typedef vector<vector<int> > Grille;



/**Grille vide
*@return t un tableau d'entier à deux dimensiions
**/
Grille grilleVide() {
    Grille t= {{0,0,0,0},{0,0,0,0},{0,0,0,0}, {0,0,0,0}};
   return t;
}


/** Random
*@param a et b deux entiers
*@return un entier entre a et b, avec b bexclus
**/
int rand_a_b(int a, int b) {
    return rand()%(b-a) +a;
}


/** Génère un chiffre aleatoire entre 2 et 4
*@param Grille un tableau d'entiers à deux dimensions de taille 4
*@return Grille , un tableau à deux dimension aléatoirement initialisé à 2 ou à 4
**/
Grille aleatoire(Grille grille) {
HANDLE hconsole;
hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
int couleur1;
couleur1=4;
int i,j,a,b,c,d,p,k;
    a=0;
    b=11;
    c=0;
    d=4;
    k=0;
    p=rand_a_b(a,b);
    i=rand_a_b(c,d);
    j=rand_a_b(c,d);
    while(k==0) {
        if(p<10) {
            if(grille[i][j]==0) {

                grille[i][j]=2;
                k=1;
            } else {

                i=rand_a_b(c,d);
                j=rand_a_b(c,d);
            }
        } else {
            if(grille[i][j]==0) {
                grille[i][j]=4;
                k=1;
            } else {
                i=rand_a_b(c,d);
                j=rand_a_b(c,d);
            }
        }
    }

    return grille;
}


/** Initialise Grille
*@param grille, un tableau d'entiers à deux dimensions
*@return un tableau d'entiers à deux dimensions initialisé aléatoirement
**/
Grille  initialiseGrille ( Grille  grille ) {

   int a,b,x,y,x2,y2;
    a=0;
    b=4;
    srand(time(NULL));

    x=rand_a_b(a,b);
    y=rand_a_b(a,b);


    grille[x][y]=2;

    x2=rand_a_b(a,b);
    y2=rand_a_b(a,b);

    while(x2==x && y==y2) {
        x2=rand_a_b(a,b);
        y2=rand_a_b(a,b);
    }
    grille[x2][y2]=2;

    cout<<endl;

    return grille;

}


/**Fait un  déplacement à gauche
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille  deplacementGauche ( Grille grille ) {
for(int i=0 ; i<4; i++) {
        for(int j=0 ; j<4; j++) {
            if(grille[i][j]==0) {
                for(int k=0; k<3; k++) {
                    if(grille[i][k+1]!=0 && grille[i][k]==0) {
                        grille[i][k]=grille[i][k+1];
                        grille[i][k+1]=0;

                    }
                }
            }
        }
    }

    return grille;


}


/**Fait une opération (d'additiion) entre les valeurs des cases d'un tableau , après avoir fait un déplacement à gauche
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille operationGauche (Grille grille){
  for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){

                    if(grille[i][j]==grille[i][j+1]) {

                        grille[i][j]=2*grille[i][j];
                        grille [i][j+1]=0;

               }
        }
                    }
                  return grille;

}


/**Fait un  déplacement à droite
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille deplacementDroite (Grille grille ) {
    for(int i=0 ; i<4; i++) {

        for(int j=0 ; j<4; j++) {
            if(grille[i][j]==0) {
                for(int k=3; k>0; k--) {
                    if(grille[i][k-1]!=0 && grille[i][k]==0) {
                        grille[i][k]=grille[i][k-1];
                        grille[i][k-1]=0;
                    }
                }
            }
        }
    }
    return grille;
}


/**Fait une opération (d'additiion) entre les valeurs des cases d'un tableau , après avoir fait un déplacement à droite
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille operationDroite(Grille grille){
		for(int i=0;i<4;i++){
   for(int j=3;j>0;j--){

					 if(grille[i][j]==grille[i][j-1]){
					 	grille[i][j]*=2;
                        grille[i][j-1]=0;

  }

					 }

   }

			return grille;
}


/**Fait un  déplacement en haut
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille deplacementHaut ( Grille grille ) {
 for(int i=0 ; i<4; i++) {

        for(int j=0 ; j<4; j++) {
            if(grille[j][i]==0) {
                for(int k=0; k<3; k++) {
                    if(grille[k+1][i]!=0 && grille[k][i]==0) {
                        grille[k][i]=grille[k+1][i];
                        grille[k+1][i]=0;
                    }
                }
            }
        }
    }
    return grille;

}


/**Fait une opération (d'additiion) entre les valeurs des cases d'un tableau , après avoir fait un déplacement en haut
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille OperationHaut(Grille grille){
for(int k=0;k<4;k++){
   for(int i=0;i<3;i++){

					 if(grille[i][k]==grille[i+1][k]){
					 	grille[i][k]*=2;
                 grille[i+1][k]=0;
					 }
			  }

}
			return grille;

}


/**Fait un  déplacement en bas
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille deplacementBas(Grille grille){
	for(int i=0 ; i<4; i++) {

        for(int j=0 ; j<4; j++) {
            if(grille[j][i]==0) {
                for(int k=3; k>0; k--) {
                    if(grille[k-1][i]!=0 && grille[k][i]==0) {
                        grille[k][i]=grille[k-1][i];
                        grille[k-1][i]=0;
                    }
                }
            }
        }
    }
    return grille;
		 return grille;
}


/**Fait une opération (d'additiion) entre les valeurs des cases d'un tableau , après avoir fait un déplacement en bas
*@param grille , un tableau d'entiers à deux dimensions
*@return le tableau grille
**/
Grille OperationBas(Grille grille){
		for(int k=0;k<4;k++){
   for(int i=3;i>0;i--){

					 if(grille[i][k]==grille[i-1][k]){
					 	grille[i][k]*=2;
                        grille[i-1][k]=0;

			  }
   }
		}
			return grille;
}


/** Vérifie si un déplacement est possible , horizetalement et verticalement
*@param grille , un tableau d'entiers à deux dimensions
*@return true si le déplacement est possible, et false si non
**/
bool EstPossible(Grille grille){
	for(int i=0;i<4;i++)                    //Verifie si deux cases adjacentes horizontales sont similaires
	  for(int j=0;j<3;j++)
	   if(grille[i][j]==grille[i][j+1])

	     return true;


  for(int k=0;k<4;k++)                      //Verifie si deux cases adjacentes verticales sont similaires
	  for(int l=0;l<3;l++)
	   if(grille[l][k]==grille[l+1][k])
	     return true;

return false;



}


/**Calcul le score cumulé
*@param grille , un tableau d'entiers à deux dimensions
*@return score, un entier
**/
int score(Grille grille) {
    int score=0;
    for(int i=0 ; i<4; i++) {
        for(int j=0 ; j<4; j++) {
            if(grille[i][j]!=0) {
                if(grille[i][j]==4) {
score=score+4;
                }
if(grille[i][j]==8) {
score=score+16;
                }
if(grille[i][j]==16) {
                    score=score+48;
                }
    if(grille[i][j]==32) {
                    score=score+120;
                }
    if(grille[i][j]==64) {
                    score=score+296;
                }
if(grille[i][j]==128) {
                    score=score+736;
                }
if(grille[i][j]==256) {
                    score=score+1764;
                }
if(grille[i][j]==512) {
            score=score+4008;
                }
if(grille[i][j]==1024) {
                    score=score+9032;
                }
if(grille[i][j]==2048) {
                    score=score+10000;
                }

            }else {


            }
        }

    }
    return score ;
}


/**Choisit une direction, et effectue les instructions en fonction de la direction choisie,
à savoir : déplacement,opération , et aléatoire
*@param grille , un tableau d'entiers à deux dimensions
*@param direction, un entier corespondant à la direction choisie
*@return t, un tableau à deux dimensions d'entiers
**/
Grille  deplacement ( Grille grille,int direction) {

  Grille t;
    switch( direction ) {

    case GAUCHE: {
    t=deplacementGauche ( grille );
        t=operationGauche(t);
        if(EstPossible(t)) {
            t=deplacementGauche ( t );

            t=aleatoire(t);
        }
        return t;
    }

    case DROITE: {
        t=deplacementDroite ( grille );
        t=operationDroite(t);
        if(EstPossible(t)) {
            t=deplacementDroite ( t ) ;
            t=aleatoire(t);
        }
        return t;
    }

    case HAUT: {
        t=deplacementHaut ( grille );
        t=OperationHaut(t);
        if(EstPossible(t)) {
            t=deplacementHaut ( t ) ;
            t=aleatoire(t);
        }
        return t;
    }

    case BAS: {
        t=deplacementBas ( grille );
        t=OperationBas(t);
        if(EstPossible(t)) {
            t=deplacementBas ( t ) ;
            t=aleatoire(t);
        }
        return t;
    default:
        cerr << "Deplacement_non-autorise!"<<endl;
        exit(-1);
    }
}

}


/** Affiche la grille avec de la couleur
*@param g , un tableau à dux dimensions d'entiers
*afiche la grille
**/
void afficheGrille(Grille g) {
HANDLE hconsole;
hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

int couleur1,couleur2,couleur3,couleur4;
int couleur5,couleur6,couleur7,couleur8;
int couleur9,couleur10,couleur11,couleur12;
couleur1=15;
couleur2=14;
couleur3=4;
couleur4=13;
couleur5=8;
couleur6=9;
couleur7=15;
couleur8=10;
couleur9=11;
couleur10=6;
couleur11=3;
couleur12=12;
SetConsoleTextAttribute(hconsole,couleur1);// commande poue appliquer de la couleu au texte de la console
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
SetConsoleTextAttribute(hconsole,couleur11);

    cout<<"                 2048  2048  2048  2048  2048  2048  2048  2048"<<endl;
    cout<<endl;
    cout<<endl;
    SetConsoleTextAttribute(hconsole,couleur1);
    for (int i=0; i<9; i++) {


        if(i%2 == 0)


            cout<<"                         *****************************"<<endl;

        if(i%2 == 1) {

                cout<<"                         *";

            for(int j=0; j<4; j++) {




                if(g[(i-1)/2][j] == 0) {        //Si il n'y a rien dans la grille afifcher un espace de 6 caractères

                    cout<<"      *";
                }

                if ( g[(i-1)/2][j]<10 && g[(i-1)/2][j]>0 ) { //Si le chiffre est composé de 1 nombre afficher un espace de 3 et 2 à gauche et à droite du chiffre

                    if(g[(i-1)/2][j]==4){
                      SetConsoleTextAttribute(hconsole,couleur2);
                       }
                       if(g[(i-1)/2][j]==8){
                       SetConsoleTextAttribute(hconsole,couleur3);
                       }
                       if(g[(i-1)/2][j]==2){
                         SetConsoleTextAttribute(hconsole,couleur4);
                       }
                    cout<<"   "<<g[(i-1)/2][j];
                    SetConsoleTextAttribute(hconsole,couleur1);
                    cout<<"  *";


                }

                if (g[(i-1)/2][j]>10 && g[(i-1)/2][j]<100) { //Si le chiffre est composé de 2 nombres afficher un espace de 2 à gauche et à droite du chiifre
                        if(g[(i-1)/2][j]==16){
                            SetConsoleTextAttribute(hconsole,couleur5);
                        }
                          if (g[(i-1)/2][j]==32){
                            SetConsoleTextAttribute(hconsole,couleur6);
                          }
                        if (g[(i-1)/2][j]==64){
                            SetConsoleTextAttribute(hconsole,couleur7);
                        }

                    cout<<"  "<<g[(i-1)/2][j];
                    SetConsoleTextAttribute(hconsole,couleur1);
                    cout<<"  *";
                }
                if (g[(i-1)/2][j]>99 && g[(i-1)/2][j]<1000) {  //Si le chiffre est composé de 3 nombres afficher un espace de 2 à gauche et 1 à droite du chiifre
                          if (g[(i-1)/2][j]==128){
                             SetConsoleTextAttribute(hconsole,couleur8);
                          }
                if (g[(i-1)/2][j]==256){
                SetConsoleTextAttribute(hconsole,couleur9);
                }
                if (g[(i-1)/2][j]==254){

                    SetConsoleTextAttribute(hconsole,couleur10);
                }

                    cout<<"  "<<g[(i-1)/2][j];
                     SetConsoleTextAttribute(hconsole,couleur1);
                     cout<<" *";
                }
                if (g[(i-1)/2][j]>999 && g[(i-1)/2][j]<10000) {     //Si le chiffre est composé de 4 nombres afficher un espace de 1 à gauche et à droite du chiifre
                     if (g[(i-1)/2][j]==1024){
                            SetConsoleTextAttribute(hconsole,couleur11);
                            }

                        if (g[(i-1)/2][j]==2048){
                            SetConsoleTextAttribute(hconsole,couleur12);
                        }
                   SetConsoleTextAttribute(hconsole,couleur2);
                    cout<<" "<<g[(i-1)/2][j];
                     SetConsoleTextAttribute(hconsole,couleur1);
                     cout<<" *";

                }


            }

            cout<<endl;
        }

    cout<<endl;


    }

SetConsoleTextAttribute(hconsole,couleur2);

  score(g);

   cout<<"                      Score :"<<" "<<score(g)<<"         "<<"BestScore :"<<BestScore<<endl;

}


/**Booléen qui vérifie si le tableau est plein ou non
*@param grille,un tableau à deux dimensions d'entiers
*@return true si le tableau est plein, et false si non
**/
bool estPlein(Grille grille){
	for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
	   if(grille[i][j]==0)
	    return false;
else
    return true;
}


/**Booléen qui vériie si la gille est pleine, et si aucun déplacement n'est posible.Donc si la partie estterminée
*@param grille,un tableau à deux dimensions d'entiers
*@return true si la partie est terminée, et false si non
**/
bool estTerminee(Grille grille){
                                             //Si la grille est pleine
     if(estPlein(grille))                  //Si aucun deplacement est possible
	 if(EstPossible(grille)==false)
	   return true;

	  return false;

}


/** Ecrit un message lorsque la partie est terminé
**/
void dessinestTerminee(){
 system("CLS");
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"                       Game Over"<<"        "<<"You loose"<<endl;
cout<<"                       Game Over"<<"        "<<"You loose"<<endl;

}


/**Booléen qui vérifie si le joueur a gagné , donc sil a pu atteindre 2048
*@param grille,un tableau à deux dimensions d'entiers
*@return true si on a 2048 dans une des cases du tableau , et false si non
**/
bool estGagnant(Grille grille){
	for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
	  if(grille[i][j]==2048)
	   return true;

	   return false;
}


/**Affiche le menu pincipal du jeu
**/
void jeu(){
    Grille grille;
    HANDLE hconsole;
hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

int couleur1;
couleur1=4;
int couleur2;
couleur2=15;
SetConsoleTextAttribute(hconsole,couleur2);
     cout<<"********************************************************************************"<<endl;
		cout<<"*"<<"                                                                              *"<<endl;
		cout<<"*"<<"                                                                              *"<<endl;
		cout<<"*"<<"                                                                              *"<<endl;



SetConsoleTextAttribute(hconsole,couleur1);

		cout<<"*                        Bienvenue dans le jeux 2048                           *"<<endl<<endl;

		cout<<"*        Veuillez appuyer sur nimporte qu'elle touche pour continuer           *"<<endl;
		SetConsoleTextAttribute(hconsole,couleur2);
		cout<<"*"<<"                                                                              *"<<endl;
		cout<<"*"<<"                                                                              *"<<endl;
		cout<<"*"<<"                                                                              *"<<endl;
		cout<<"********************************************************************************"<<endl;
getch();
		system("CLS");


}


/**Sauvegarde le Meilleur score dans un fichier texte
**/
void NewBestScore(){
	 ofstream filescore("score.txt");       // Ouvre et/ou créer le fichier texte score
	 filescore<<BestScore;                  // Ecris le meilleurs score dans le fichier
	 filescore.close();                     // Ferme le fichier
}


/**Lit le score ainsi que le meilleur score
**/
void ReadScore(){
		ifstream filescore("score.txt");
	 if(filescore){                         // Lis le meilleur score si il existe
		 filescore>>BestScore;             // Alloue à la variable bestscore sa valeur
		}else{
		 BestScore=0;
	            }                           //Sinon initialisation du meilleur score à 0
		filescore.close();                 //Ferme le fichier
	}




int main() {
ReadScore();
bool x,y;
   jeu();

while (y==true){
   system("cls");
    Grille t= initialiseGrille(grilleVide());

    afficheGrille(t);


    while(x==true) {
        int a=0;
        int b=0;
        b=getch();
        if(b==224) {
            a=getch();
        }
        Grille t2=t;
        t=deplacement(t,a);
        system("cls");
        cout<<endl;

        afficheGrille(t);

        if(EstPossible(t2)==false) {
            cout<<"                        Choisissez une autre direction!"<<endl;
        }



if (estTerminee(t)==true){
    dessinestTerminee();
    cout<<endl;
    cout<<endl;

cout<<"                  Appuyer sur une touche pour continuer"<<endl;
getch();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    Grille grille;
    HANDLE hconsole;
hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

int couleur1;
couleur1=4;
SetConsoleTextAttribute(hconsole,couleur1);

    cout<<"                 Merci d'avoir jouer. A la prochaine fois"<<endl;


   couleur1=15;
SetConsoleTextAttribute(hconsole,couleur1);

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    system("cls");
    cout<<"                              Voulez-vous rejouer?"<<endl;
    cout<<endl;
    cout<<endl;
    couleur1=10;
    SetConsoleTextAttribute(hconsole,couleur1);

    cout<<"              Appuyer sur n'importe qu'elle touche pour relancer le jeu"<<endl;
    y=estTerminee(t);
getch();
system("cls");

jeu();
Grille t= initialiseGrille(grilleVide());

    afficheGrille(t);

}

if(score(t)>BestScore){
  BestScore=score(t);
  NewBestScore();
  }



if (estGagnant(t)==true){

    cout<<"                    Congratulations , you win"<<endl;
    cout<<"****************************************************"<<endl,
    cout<<"                    Congratulations , you win"<<endl;



}
    }
    }
}
