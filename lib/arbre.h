#pragma once

/*
	Définition de la structure noeud contenant :
		- un élément de type char -> Correspond au caractère à coder
		- un fils gauche
		- un fils droit
*/
typedef char Elt ;																					//Les éléments que l'on va manipuler sont des caractères
struct znoeud {
	Elt elt ;
	struct znoeud *fils_gauche ;
	struct znoeud *fils_droit ;	
};
typedef struct znoeud noeud ;
typedef struct znoeud *arbre ;

/* **** Implémentation du type abstrait de données **** */

//Fonction qui créée un arbre vide et retourne cet arbre
arbre creer_arbre_vide() ;

//Fonction qui teste si un arbre est vide
int est_arbre_vide(arbre a) ;

//Fonction qui créée un arbre.
//Arguments : caractère contenue dans la racine, fils gauche, fils droit
arbre creer_arbre(Elt e, arbre fg, arbre fd) ;

//Fonction qui créée une feuille (un arbre dont les fg et fd sont des arbres vides)
arbre creer_feuille(Elt e) ;

//Fonction qui teste si l'arbre a est une feuille
int est_feuille(arbre a) ;

//Fonction qui retourne le fils gauche de l'arbre passé en argument
arbre fils_gauche(arbre a) ;

//Fonction qui retourne le fils droit de l'arbre passé en argument
arbre fils_droit(arbre a) ;

//Fonction qui retourne la racine de l'arbre passé en argument
Elt racine(arbre a) ;

//Fonction qui print l'arbre passé en paramètres
void print_arbre_rec(arbre a) ;
void print_arbre(arbre a) ; 																		//Pour la notation préfixée

#endif