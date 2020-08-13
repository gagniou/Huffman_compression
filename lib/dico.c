#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dico.h"
#include "arbre.h"

dico creer_dico(Elt lettre,int longueur,char chem[]) 
{
	int i ;

    dico a ;
    a.taille = longueur ;
    a.elt = lettre ; 
    for (i=0; i<a.taille; i++) a.chemin[i]=chem[i] ;
    return a;
}

void annuaire2(arbre a,int indice,char chemin[],dico tab[])
{
	if(!est_arbre_vide(a))
	  {
	    if (!est_feuille(a))
	    {
		    chemin[indice]='0';
		    annuaire2(fils_gauche(a),indice+1,chemin,tab) ;
		    chemin[indice]='1';
		    annuaire2(fils_droit(a),indice+1,chemin,tab) ;
		    }
	    else
	    {
	      dico b;
	      b=creer_dico(racine(a),indice,chemin);
	      tab[(int)b.elt]=b;   
	    }
	    

	  } 
}