#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


arbre creer_arbre_vide()
{
	return NULL ;
}

int est_arbre_vide(arbre a)
{
	return (a == NULL) ;
}

arbre creer_arbre(Elt e, arbre fg, arbre fd)
{
	arbre tmp ;
	tmp = malloc(sizeof(noeud)) ;
	tmp -> elt = e ;
	tmp -> fils_gauche = fg ;
	tmp -> fils_droit = fd ;
	return tmp ;
}

arbre creer_feuille(Elt e)
{
	return creer_arbre(e, creer_arbre_vide(), creer_arbre_vide()) ;
}

int est_feuille(arbre a)
{
  if (est_arbre_vide(a)) return 0 ;
  return (est_arbre_vide(a->fils_gauche) && est_arbre_vide(a->fils_droit)) ;
}

arbre fils_gauche(arbre a)
{
	assert(!est_arbre_vide(a)) ;
	return a -> fils_gauche ;
}

arbre fils_droit(arbre a)
{
	assert(!est_arbre_vide(a)) ;
	return a -> fils_droit ;
}

Elt racine(arbre a)
{
	assert(!est_arbre_vide(a)) ;
	return a -> elt ;
}

void print_arbre_rec(arbre a)
{
	if (est_arbre_vide(a)) printf(".") ;
	else{
		printf("%c (", a -> elt ) ;
		print_arbre_rec(a -> fils_gauche) ;
		printf(") (") ;
		print_arbre_rec(a -> fils_droit) ;
		printf(")") ;
	}
}
void print_arbre(arbre a)
{
	print_arbre_rec(a) ;
	printf("\n") ;
} 