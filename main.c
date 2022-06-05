#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct client {
char *nom;
char *prenom;
char *cin;
int  num_tel;
}client;


typedef struct liste_client{
client* m;
struct liste_client* suivant;
struct liste_client* precedent;
}liste_client;


typedef struct employees {
char *nom;
char *prenom;
int mat;
float salaire;
float depense;
int num_tel;
}employees;


typedef struct liste_employees{
employees *e;
struct liste_employees* suivant;
struct liste_employees* precedent;
}liste_employees;


typedef struct produit {
int ref;
float prix;
char *categorie;
int qteStock;
}produit;


typedef struct liste_produit
{
    produit *pro;
    struct liste_produit* suivant;
    struct liste_produit* precedent;
}liste_produit;


typedef struct quant
{
    liste_produit* a;
    int quantiter;
}quant;


typedef struct facture {
char* type;
char* mode_de_paiemment;
int num_fact;
int nb_prod;
quant *pr;
float prix_ht;
float prix_total;
}facture;


typedef struct liste_facture
{   facture* f;
    struct liste_facture* suivant;
    struct liste_facture* precedent;

}liste_facture;


typedef struct achat {
liste_facture *a;
}achat;


typedef struct listes_achat {
achat *a;
 struct liste_achat *suivant;
 struct liste_achat *precedent;
}listes_achat;


typedef struct cheque
{
   char* montant_lett; //montant en lettre
    char* a_order_de;
    float mont;
}cheque;


typedef struct liste_cheque
{   cheque* a;
    struct liste_cheque* suivant;
    struct liste_cheque* precedent;
}liste_cheque;


typedef struct depense
{ char* aqui;
  char* motif; //concerne a quoi
  char* mode_paiement;
  float pt;
}depense;


typedef struct liste_depense
{    depense* a;
     struct liste_depense *precedent;
     struct liste_depense *suivant;
}liste_depense;


typedef struct vente {
liste_facture *v;
}vente;


typedef struct listes_vente {
vente *a;
struct listes_vente *suivant;
struct listes_vente *precedent;
}listes_vente;


typedef struct bon_liv {
client* b;
char* a; //mode de paiemment
float prix_liv;
}bon_liv;


typedef struct liste_bon_liv
{
    bon_liv* a;
    struct liste_bon_liv* suivant;
    struct liste_bon_liv*precedent;
}liste_bon_liv;


typedef struct fournisseur {
char *nom_four;
int num_tel;
}fournisseur;

typedef struct liste_fourn{
       fournisseur *f;
        struct liste_fourn *suivant;

        struct liste_fourn *precedent;
       }


liste_facture* ajouter_facture(liste_facture* f,facture* fact)
{
    liste_facture* tmp;
    tmp=(liste_facture*)malloc(sizeof(liste_facture));
    tmp->precedent=f;
    tmp->suivant=f->suivant;
    f->suivant->precedent=tmp;
    f->suivant=tmp;
    return f;
}


liste_facture* supprimer_facture(liste_facture* fact,int num)
{
    int cpt=0;
    liste_facture* tmp;
    tmp=fact;
    do{
        if(tmp->f->num_fact==num)
        {
            cpt++;
            break;
        }
        else{
            tmp=tmp->suivant;
        }
    }while(tmp->suivant!=fact);
    if(cpt==0)
    {
        printf("vérifiez le numéro de facture");
    }
    else if(cpt!=0)
    {
        tmp->suivant->precedent=tmp->precedent;
        tmp->precedent->suivant=tmp->suivant;
        free(tmp);
    }

    return fact;
}


liste_client* ajouter_client(liste_client* c,client* a)
{
    liste_client* tmp,tmp2;
        tmp=c;
   do{
        if(tmp->m->cin==a->cin)
        {
           printf("ce client se trover déja");
           break;
        }
          tmp=tmp->suivant;
    } while(tmp->suivant!=c);
    tmp2=(liste_client*)malloc(sizeof(liste_client));
    tmp2->suivant=c;
    tmp2->precedent=tmp;
    c->precedent=tmp2;
    tmp2=c;
        return c;
}
liste_client* supprimer_client(liste_client* c,client* a)
{
      liste_client* tmp;
        tmp=c;
        int cpt=0;
    do{
        if(tmp->m->cin==a->cin)
        {
            cpt++;
           break;
        }
        else{ tmp=tmp->suivant;}
    }while(tmp->suivant!=c);
    if(cpt==0)
    {
        printf("vérifiez vos données");
    }
    else if(cpt!=0){
            tmp->suivant->precedent=tmp->precedent;
            tmp->precedent->suivant=tmp->suivant;
            free(tmp);}

  return c;
    }
float calcule_les_ressources(liste_vente* l , liste_bon_liv* m)
{
    float s,s2=0,s1=0;
   do{

      s1=s1+l->a->v->f->prix_total;
      l=l->suivant;
   }while(l->suivant!=l);
   do{
      s2=s2+m->a->prix_liv;
      m=m->suivant;
   }while(m->suivant!=m);
   s=s1+s2;
   return s;
}

float calcule_des_emplois(liste_achat* l,liste_depense* m,liste_employees* emp )
{
      float s,s2=0,s1=0,s3=0;
   do{
     s1=s1+l->a->a->f->prix_total;
      l=l->suivant;
   }while(l->suivant!=l);
    do{
     s3=s3+emp->e->salaire;
      emp=emp->suivant;
   }while(emp->suivant!=emp);
   do{

      s2=s2+m->a->pt;
      m=m->suivant;
   }while(m->suivant!=m);
   s=s1+s2+s3;
   return s;
}
listes_achat* creer_achat(listes_achat *a,int n)
{
    listes_achat* tmp=a;
    int i;
    tmp=(listes_achat*)malloc(sizeof(listes_achat));
     scanf("%s",&(tmp->a->a->f->type));
     scanf("%s",&(tmp->a->a->f->mode_de_paiemment));
     scanf("%d",&(tmp->a->a->f->num_fact));
     scanf("%d",&(tmp->a->a->f->nb_prod));
     scanf("%d",&(tmp->a-a->f->pr->a->pro->ref);
     scanf("%f",&(tmp->a->a->f->pr->a->pro->prix);
     scanf("%s",&(tmp->a->a->f->pr->a->pro->categorie))
     scanf("%d",&(tmp->a->a->f->pr->a->pro->qteStock);
     scanf("%d",&(tmp->a->a->f->pr->quantiter);
     scanf("%f",&(tmp->a->a->f->prix_ht);
     scanf("%f",&(tmp->a->a->f->prix_total);
    for(i=0;i<n-1;i++)
    {tmp->suivant=(listes_achat*)malloc(sizeof(listes_achat));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
     scanf("%s",&(tmp->a->a->f->type));
     scanf("%s",&(tmp->a->a->f->mode_de_paiemment));
     scanf("%d",&(tmp->a->a->f->num_fact));
     scanf("%d",&(tmp->a->a->f->nb_prod));
     scanf("%d",&(tmp->a-a->f->pr->a->pro->ref);
     scanf("%f",&(tmp->a->a->f->pr->a->pro->prix);
     scanf("%s",&(tmp->a->a->f->pr->a->pro->categorie))
     scanf("%d",&(tmp->a->a->f->pr->a->pro->qteStock);
     scanf("%d",&(tmp->a->a->f->pr->quantiter);
     scanf("%f",&(tmp->a->a->f->prix_ht);
     scanf("%f",&(tmp->a->a->f->prix_total);
    }
    a->precedent=tmp;
    tmp->suivant=a;
    return a;
}
listes_vente* creer_ventes(listes_vente *a,int n)
{
    listes_achat* tmp=a;
    int i;
    tmp=(listes_vente*)malloc(sizeof(listes_vente));
     scanf("%s",&(tmp->a->v->f->type));
     scanf("%s",&(tmp->a->v->f->mode_de_paiemment));
     scanf("%d",&(tmp->a->v->f->num_fact));
     scanf("%d",&(tmp->a->v->f->nb_prod));
     scanf("%d",&(tmp->a->v->f->pr->a->pro->ref);
     scanf("%f",&(tmp->a->v->f->pr->a->pro->prix);
     scanf("%s",&(tmp->a->v>f->pr->a->pro->categorie))
     scanf("%d",&(tmp->a->v->f->pr->a->pro->qteStock);
     scanf("%d",&(tmp->a->v->f->pr->quantiter);
     scanf("%f",&(tmp->a->v->f->prix_ht);
     scanf("%f",&(tmp->a->v->f->prix_total);
    for(i=0;i<n-1;i++)
    {tmp->suivant=(listes_vente*)malloc(sizeof(listes_vente));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
     scanf("%s",&(tmp->a->v->f->type));
     scanf("%s",&(tmp->a->v->f->mode_de_paiemment));
     scanf("%d",&(tmp->a->v->f->num_fact));
     scanf("%d",&(tmp->a->v->f->nb_prod));
     scanf("%d",&(tmp->a->v->f->pr->a->pro->ref);
     scanf("%f",&(tmp->a->v->f->pr->a->pro->prix);
     scanf("%s",&(tmp->a->v>f->pr->a->pro->categorie))
     scanf("%d",&(tmp->a->v->f->pr->a->pro->qteStock);
     scanf("%d",&(tmp->a->v->f->pr->quantiter);
     scanf("%f",&(tmp->a->v->f->prix_ht);
     scanf("%f",&(tmp->a->v->f->prix_total);
    }
    a->precedent=tmp;
    tmp->suivant=a;
    return a;
}
liste_bon_liv* creer_bon_liv(liste_bon_liv *l,int n)
{
  liste_bon_liv* tmp=l;
    int i;
    tmp=(liste_bon_liv*)malloc(sizeof(liste_bon_liv));
  scanf("%s",&(tmp->a->b->nom);
    scanf("%s",&(tmp->a->b->prenom);
    scanf("%s",&(tmp->a->b->cin);
    scanf("%d",&(tmp->a->b->num_tel);
    scanf("%s",&(tmp->a->a);
    scanf("%f",&(tmp->a->prix_liv);
         for(i=0;i<n-1;i++)
    {tmp->suivant=(liste_bon_liv*)malloc(sizeof(liste_bon_liv));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
    scanf("%s",&(tmp->a->b->nom);
    scanf("%s",&(tmp->a->b->prenom);
    scanf("%s",&(tmp->a->b->cin);
    scanf("%d",&(tmp->a->b->num_tel);
    scanf("%s",&(tmp->a->a);
    scanf("%f",&(tmp->a->prix_liv);
    }
    l->precedent=tmp;
    tmp->suivant=l;
    return l;

}
liste_cheque* creer_cheque(liste_cheque *l,int n)
{
    liste_cheque *tmp;
    tmp=l;
    int i;
    tmp=(liste_cheque*)malloc(sizeof(liste_cheque));
      scanf("%s",&(tmp->a->montant_lett);
    scanf("%s",&(tmp->a->a_order_de);
    scanf("%f",&(tmp->a->mont);
       for(i=0;i<n-1;i++)
    {tmp->suivant=((liste_cheque*)malloc(sizeof(liste_cheque));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
   scanf("%s",&(tmp->a->montant_lett);
    scanf("%s",&(tmp->a->a_order_de);
    scanf("%f",&(tmp->a->mont);
    }
    l->precedent=tmp;
    tmp->suivant=l;
    return l;
}


liste_employees* creer_employees(liste_employees *emp,int n)
{
    liste_employees* tmp;
    tmp=emp;
    int i;
         tmp=(liste_employees*)malloc(sizeof(liste_employees));
    scanf("%s",&(tmp->e->nom);
    scanf("%s",&(tmp->e->prenom);
    scanf("%d",&(tmp->e->mat);
    scanf("%f",&(tmp->e->salaire);
    scanf("%f",&(tmp->e->depense));
    scanf("%d",&(tmp->e->num_tel);
           for(i=0;i<n-1;i++)
    {tmp->suivant=(liste_bon_liv*)malloc(sizeof(liste_bon_liv));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
   scanf("%s",&(tmp->e->nom);
    scanf("%s",&(tmp->e->prenom);
    scanf("%d",&(tmp->e->mat);
    scanf("%f",&(tmp->e->salaire);
    scanf("%f",&(tmp->e->depense));
    scanf("%d",&(tmp->e->num_tel);
    }
    emp->precedent=tmp;
    tmp->suivant=emp;
    return emp;
}

liste_depense* creer_depense(liste_depense* dep,int n)
{
     liste_depense* tmp;
    tmp=dep;
    int i;
    tmp=(liste_depense*)malloc(sizeof(liste_depense));
    scanf("%s",&(dep->a->aqui);
     scanf("%s",&(dep->a->motif);
      scanf("%s",&(dep->a->mode_paiemment);
       scanf("%f",&(dep->a->pt);
                for(i=0;i<n-1;i++)
    {tmp=(liste_depense*)malloc(sizeof(liste_depense));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
 scanf("%s",&(dep->a->aqui);
     scanf("%s",&(dep->a->motif);
      scanf("%s",&(dep->a->mode_paiemment);
       scanf("%f",&(dep->a->pt);
    }
    dep->precedent=tmp;
    tmp->suivant=dep;
    return dep;

}

liste_client* creer_liste_client(liste_client* l,int n)
{
      liste_client* tmp;
     tmp=l;
    int i;
    tmp=(liste_client*)malloc(sizeof(liste_client));
    scanf("%s",&(l->m->nom);
     scanf("%s",&(l->m->prenom);
       scanf("%s",&(l->m->cin);
        scanf("%d",&(l->m->num_tel);
                        for(i=0;i<n-1;i++)
    {tmp=(liste_client*)malloc(sizeof(liste_client));
    tmp->suivant->precedent=tmp;
    tmp=tmp->suivant;
  scanf("%s",&(l->m->nom);
     scanf("%s",&(l->m->prenom);
       scanf("%s",&(l->m->cin);
        scanf("%d",&(l->m->num_tel);
    }
    l->precedent=tmp;
    tmp->suivant=l;
    return l;


}
client* creer_client(client* cl)
{
    cl=(client*)malloc(sizeof(client));
   scanf("%s",&(cl->nom);
   scanf("%s",&(cl->prenom);
   scanf("%s",&(cl->cin);
   scanf("%d",&(cl->num_tel);
   return cl
}

facture* creer_facture(facture* fct)
{
    fct=(facture*)malloc(sizeof(facture));
    scanf("%s",&(fct->type));
    scanf("%s",&(fct->mode_de_paiemment));
    scanf("%d",&(fct->num_fact));
    scanf("%d",&(fct->nbr_prod));
    scanf("%d",&(fct->pr->a->pro->ref));
    scanf("%f",&(fct->pr->a->pro->prix));
    scanf("%s",&(fct->pr->a->pro->categorie));
    scanf("%d",&(fct->pr->a->pro->qteStock));
    scanf("%f",&(fct->prix_ht));
    scanf("%d",&(fct->prix_total));
    return fct;

}

void main()
{

     listes_vente* tmp,a;
    int n,m,ach,k,po,e,nbr_emp,nbr_dep,numfact,var,vntach,nbclt;
    float som_emp,som_res;
    listes_achat *b;
    liste_facture *l;
    liste_bon_liv *c;
    liste_cheque* che;
    liste_employees* lis_emp;
    liste_depense* lis_dep;
    liste_client* li_cl;
    client* cl;
    facture* fact;

    printf("                                              bonjour dans nous application                             \n");
    printf("si vous voudrez remplit une fiche d'achat appuyez sur 1\n"
           ,"si vous voudrez remplit une fiche de vente appuyez sur 2\n"
           ,"si vous voudrez remplit une fiche de bon de livraison appuyez sur 3\n"
           ,"si vous voudrez creer des employées appuyez sur 4\n"
           ,"si vous voudrez creer une depense appuyez sur 5 \n"
           ,"si vous voudrez calculer les emplois appuyez sur 6 \n"
           ,"si vous voudrez calculer les ressources appuyez sur 7\n"
           ,"si vous voudrez ajouter une facture appuyez sur 8\n"
           ,"si vous voudrez supprimer facture appuyez sur 9\n"
           ,"si vous voudrez creer une liste client appuyez sur 10\n"
           ,"si vous voudrez ajouter un client appuyez sur 11 \n"
           ,"si vous voudrez supprimer un client appuyez sur 12\n"
           );
 scanf("%d",&po);
   if(po==1)
   {
    printf("donnez le nombre d'achat");
    scanf("%d",&ach);
    b=creer_achat(b,ach);
   }

   if(po==2)
    {
    printf("donnez le nombre des ventes");
    scanf("%d",&n);
    a=creer_ventes(a,n);
      printf("passez au paiemment ");
      tmp=a;
     while(tmp->suivant!=tmp)
     {if(tmp->v->f->prix_total<6000)
     {
         printf("payez en espese");
     }
     else{
         printf("payez en cheque");
         printf("combien de cheque voudrez-vous donnez\n");
         scanf("%d",&e);
         che=creer_cheque(che,e);
     }
     }

      if(po==3){
    printf("donnez le nombre des bons de livraison ");
    scanf("%d",&k);
    c=creer_bon_liv(c,k);}
    if(po==4)
    {
        printf("donnez le nombre des employees");
        scanf("%d",&nbr_emp);
         lis_emp=creer_employees(lis_emp,nbr_emp);

    }
    if(po==5)
    {
        printf("donnez le nombres des depenses");
        scanf("%d",&nbr_dep);
      lis_dep=creer_depense(lis_dep,nbr_dep);

    }
    if(po==6)
    {
       som_emp=calcule_des_emplois(b,lis_dep,lis_emp);//b c'est liste achat
       printf("la perte est : %f",som_emp);
    }
    if(po==7)
    {
       som_res=calcul_les_ressources(a,c);//a c'est la liste des vente et c liste depense
       printf("le gains est %f",som_res);
    }


    if(po==8)
    {
        printf("si la facture est par rapport le vente appuyez sur 1");
               ,"si la facture est par rapport l'achat appuyez sur 2");
               scanf("%d",&vntach);
               if(vntach==1)
               {
                   fact=creer_facture(fact);
                   a->a->v=ajouter_facture( a->a->v,fact)
               }
               else if(vntach==2)
               {
                   fact=creer_facture(fact);
                   b->a->a=ajouter_facture(b->a->a,fact)
               }
               else{
                printf("voir vos données");
               }

    }
    if(po==9)
    {
        printf("si la facture est par rapport le vente appuyez sur 1");
               ("si la facture est par rapport l'achat appuyez sur 2");
               if(var==1)
               {
                   printf("donner le numero de facture");
                   scanf("%d",&numfact);
                   a->a->v=supprimer_facture(a->a->v,numfact);
               }
               else if(var==2)
               {
                   printf("donner le numero de facture");
                   scanf("%d",&numfact);
                   b->a->a=supprimer_facture(b->a->a,numfact);
               }
               else{
                printf("voir vos données");
               }
    }
    if(po==10)

    {
        printf("donner le nombre de client");
        scanf("%d",&nbclt);
        li_cl=creer_liste_client(li_cl,nbclt);
    }
    if(po==11)
    {
        cl=creer_client(cl);
        li_cl=ajouter_client(li_cl,cl);
    }
    if(po=12)
    {

        li_cl=supprimer_client(li_cl,cl);

    }



}

