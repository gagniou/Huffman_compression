#include "liste.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

node* l_make_node(void* data)
{
    node* tmp;
    tmp=malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;
    tmp->previous=NULL;
    return tmp;
}

void l_free_node(node* n)
{
    if (n->data!=NULL) free(n->data);
    if (n!=NULL) free(n);
    return;
}

void l_free_list(node* n)
{
    n=l_head(n); //on remonte au sommet de la liste
    while (n-> next!=NULL)
    {
        n=n->next;
        l_free_node(n->previous);
    }
    //l_free_node(n);
    return;
}

int l_length(node const* n)
{
    int cpt=1;
    node const * tmp;
    tmp=n;
    if (n==NULL) return 0;
    while (tmp->next != NULL)
    {
        cpt++ ;
        tmp=tmp->next;
    }
    tmp=n;
    while (tmp->previous != NULL)
    {
        cpt++ ;
        tmp=tmp->previous;
    }
    return cpt;
}

node* l_head(node* n)
{
    if (n==NULL) return NULL;
    while (n->previous!=NULL) n=n->previous;
    return n;
}

node* l_tail(node* n)
{
    if (n==NULL) return NULL;
    while (n->next!=NULL) n=n->next;
    return n;
}

node* l_skip(node* n, int i)
{
    while ((i!=0) && (n!=NULL))
    {
        if (i>0)
        {
            n=n->next;
            i--;
        }else{
            n=n->previous;
            i++;
        }
    }
    return n;
}

node* l_append(node** p, node* tail)
{
    assert(p);
    
    if (*p==NULL) 
    {
        *p=tail;
        return tail;
    }else
    {
        node *tmp=l_tail(*p);
        tail->previous=tmp;
        tmp->next=tail;
    }

    return tail;
}

node* l_prepend(node** p, node* head)
{
    assert(p);
    if (*p==NULL) 
    {
        *p=head;
        return head;
    }
    else
    {
        node *tmp=l_head(*p);
        head->next=tmp;
        tmp->previous=head;
    }
    return head;
}


node* l_insert(node** p, node* body)
{
    assert(p);
    if (*p==NULL) 
    {
        *p=body;
        return body;
    }
    else
    {
        node *tmp=*p;
        body->next=tmp->next;
        body->previous=tmp;
        if (tmp->next!=NULL) tmp->next->previous=body;
        tmp->next=body;
    }   
    return body;
}

node* l_remove(node* n)
{
    if (n==NULL) return NULL;
    if (n->next!=NULL) n->next->previous=n->previous;
    if (n->previous!=NULL) n->previous->next=n->next;
    return n->next;
}