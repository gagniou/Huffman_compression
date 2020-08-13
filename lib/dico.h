#ifndef __DICO_H__
#define __DICO_H__
#include "arbre.h"

/*
	Définition de la structure dico contenant :
		- un caractere
		- un 'chemin' = une chaine de caractere qui contient le codage du caractere
		- la taille du chemin
*/

struct DICO {
  Elt elt ;
  int taille ; 
  char chemin[256] ;											//256 car dans une distribution 'normale' d'un texte un arbre de Huffman ne dépasserra pas cette hauteur
  };
typedef struct DICO dico ;
		
//Fonction qui créée un dictionnaire contenant le caractère, son chemin et la taille de son chemin				
dico creer_dico(Elt lettre,int longueur,char chem[]);

//Fonction qui détermine le codage de chaque caractère et créée le dictionnaire				
void annuaire2(arbre a,int indice,char chemin[],dico tab[]);

#endif