#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Vecteur{
	private:
		vector<double> coordonnees;
		
		bool dimension_ok(Vecteur autre) const { // On teste ici si les dimensions sont bonnes
			if(coordonnees.size() == (autre.getcoord()).size() ){
				return true;
			}else {
				string Err_dim("Les deux vecteurs ont des dimensions différentes !");
				throw Err_dim;
				//je ne sais pas si on doit mettre un return false ou pas 
				}
			}
			
		bool dimension_3(Vecteur autre) const { //on teste ici si les deux vecteurs sont de dimensions 3
			if((coordonnees.size() == 3) and (autre.getcoord().size()==3)){
				return true;
			}else {
				string Err_3("Les deux vecteurs ne sont pas de dimensions 3 !");
				throw Err_3;
				//je ne sais pas si on doit mettre un return false ou pas 
				}
			}		
	public:
		void augmente(double new_dim) {
			coordonnees.push_back (new_dim); 
			}
		void set_coord(size_t dim, double modif){
			if(dim <= coordonnees.size() ){
				coordonnees[dim-1] = modif;
			}else {
				string Err_segm_fault("le vecteur ne possède pas autant de dimension(s) !");
				throw  Err_segm_fault;
				}
			}
		void affiche() const {
			for (auto val : coordonnees){
				cout << val <<" ";
				}
			cout << endl;
			}
		bool compare(Vecteur autre) const {
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					if(coordonnees[i] != (autre.getcoord())[i]){
						return false;
						} else {continue;	}
					}
				}
		return true;
			}
		vector <double> getcoord() const { //on renvoie toutes les coordonnées d'un objet de la classe Vecteur
			return coordonnees;
			}
		double getvalue(size_t i) const { //on renvoie la coordonnées numero i d'un objet de la classe Vecteur
			return coordonnees[i];
			}		
			
		Vecteur addition(const Vecteur& autre) const {
			Vecteur result;
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente(autre.getvalue(i) + coordonnees[i])	;
					}
				}
			return result;
			}
			
		Vecteur soustraction(const Vecteur& autre) const { //on fait vecteur actuel - autre
			Vecteur result;
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente(coordonnees[i] - autre.getvalue(i))	;
					}

				}
			return result;
			}
			
		Vecteur oppose() const {
			Vecteur result;
			for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente( - coordonnees[i]);
					}
			return result;
			}
			
		Vecteur mult(double scalaire) const {
			Vecteur result;
			for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente(scalaire * coordonnees[i]);
					}
			return result;			
			}
			
		double prod_scal(Vecteur autre) const {
			double result(0);
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result += (autre.getvalue(i) * coordonnees[i]);
					}
				}
			return result;			
			}
	
		Vecteur prod_vect(Vecteur autre) const {
			Vecteur result;
			if (dimension_ok(autre) and dimension_3(autre)){
					result.augmente(coordonnees[1]*autre.getvalue(2)-coordonnees[2]*autre.getvalue(1)); //(U2*V3 - U3*V2)
					result.augmente(coordonnees[2]*autre.getvalue(0)-coordonnees[0]*autre.getvalue(2)); //(U3*V1 - U1*V3)
					result.augmente(coordonnees[0]*autre.getvalue(1)-coordonnees[1]*autre.getvalue(0)); //(U1*V2 - U2*V1)
				}
			return result;
			}
		
			//on utilise norme2 pour faciliter norme
		double norme2() const {
			double result(0);
			for (auto value : coordonnees){
				result += pow(value,2);
				}
			return result;
			} 			
		
		double norme() const {
			return sqrt(norme2());
			} 
	};
	
int main()
{
	Vecteur vect0;
	Vecteur vect1;
	Vecteur vect2;
	Vecteur vect3;
	vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
	vect1.set_coord(1, 2.0); // pour tester set_coord()

	// v2 = (2.6, 3.5,  4.1)
	vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);

	vect3 = vect1; //on rajoute une dimension a vect3
	vect3.augmente(3.2);

	cout << "Vecteur 1 : ";
	vect1.affiche();
	cout << endl;

	cout << "Vecteur 2 : ";
	vect2.affiche();
	cout << endl;
	
	cout << "Vecteur 3 : ";
	vect3.affiche();
	cout << endl;
/*****************************************************/
	cout << "Pour 1 et 2 :"<<endl;
	try{
		if (vect1.compare(vect2)) {
		cout << "Le vecteur 1 est "
			 << "égal au";
		} else {
			cout << "Le vecteur 1 est "
			     << "différent du";
		}
		cout << " vecteur 2." << endl;
		
	} catch (string erreur){
		cerr << "Erreur: " <<erreur << endl;
		}
/**************************************************/
	cout << "Pour 1 et 3 :"<<endl;
	try{
		if (vect1.compare(vect3)) {
		cout << "Le vecteur 1 est "
			 << "égal au";
		} else {
			cout << "Le vecteur 1 est "
				 << "différent du";
		}
		cout << " vecteur 3," << endl;
		
	} catch (string erreur){
		cerr << "Erreur: " <<erreur <<endl << endl;
		}	
/***************************************************/
	Vecteur vect4;	 vect4.augmente(1.0); vect4.augmente(2.0); vect4.augmente(-0.1);
	Vecteur vect5;	 vect5.augmente(2.6); vect5.augmente(3.5); vect5.augmente(4.1);
	
	cout << "Vecteur 4 : ";
	vect4.affiche();

	cout << "Vecteur 5 : ";
	vect5.affiche();
	
	cout << "la somme : "; 
	Vecteur vect6= vect4.addition(vect5);
	vect6.affiche();							//(3.6 5.5 4.0)
	
/********************************************************/

	cout << "aaaaaand : ";
	vect6= vect4.addition(vect5);
	vect6.affiche();
	cout << endl;								//(3.6 5.5 4.0)
/**********************************************************/
	vect0.augmente(0);
	vect0.augmente(0);
	vect0.augmente(0);
	cout << "add avec le vecteur nul vect4 = ";
	vect6= vect0.addition(vect4);
	vect6.affiche();							//(1 2 -0.1)
	cout << endl;
/**********************************************************/

	cout << "Vecteur 4 : ";
	vect4.affiche();
	cout << "Vecteur 5 : ";
	vect5.affiche();
	
	cout << "la soustraction : ";
	vect6= vect4.soustraction(vect5);
	vect6.affiche();							//(-1.6, -1.5, -4.2)
	cout << endl;
/************************************************************/

	cout << "sous avec le vecteur nul du vect4 = ";
	vect6= vect4.soustraction(vect0);
	vect6.affiche();
	cout << endl;
/*************************************************************/

	cout<< "l'opposé du vect 4 :" ;
	vect4.oppose().affiche();
	cout <<endl;
/*************************************************************/

	cout << "Vecteur 4 : ";
	vect4.affiche();
	cout << "Vecteur 5 : ";
	vect5.affiche();
	
cout <<"4 plus l'opposé de 5 : ";
vect4.addition(vect5.oppose()).affiche();
cout <<"4 moins 5 : ";
vect4.soustraction(vect5).affiche();
cout <<endl;									//(0 0 0.9)

/*************************************************************/
	cout << "Vecteur 4 : ";
	vect4.affiche();
		
	cout <<"3 fois vect4 : ";
	vect4.mult(3).affiche();
	cout <<endl;								//(3.0, 6.0, -0.3)
/*************************************************************/

	vect4.affiche(); cout << " * " <<endl;  vect5.affiche();
	cout << " = " << vect4.prod_scal(vect5) << "\n" <<endl;         // =9.19
/*************************************************************/
	vect4.affiche(); cout << " ^ " <<endl;  vect5.affiche();
	cout << " = "; 
	vect4.prod_vect(vect5).affiche() ;                         //(8.55, -4.36, -1.7)
	cout << "\n" <<endl; 
/*************************************************************/
	cout <<"|| ("; vect4.affiche(); cout <<") || au 2 = "<< vect4.norme2() << endl; // 35.82
	cout <<"|| ("; vect5.affiche(); cout <<") || au 2 = "<< vect5.norme2() << endl; //5.01

}
 

