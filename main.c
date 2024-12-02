

#include <stdio.h>
#include <stdlib.h>
#define N 10


struct client
{   int code_client ;
    char prenom_de_client[N];
    char nom_de_client[N];

};

struct date
{   int jour ;
    int mois;
    int annees;

};

struct compte
{   int num_compte ;
    int code_client ;
    int somme;
    struct date date ;


};



int choix ;

void menu()
{
    printf("1-gestion des clients\n");
    printf("2-gestion des comptes\n");
    printf("3-gestion des operations\n");
    printf("4-quitter le programme\n");
    printf("choisier le menu");
    scanf("%d",&choix);
    sous_menu(choix);
}

int choix_sm;

void sous_menu()
{
    if (choix==1)
    {
        printf("1-ajouter\n");
        printf("2-modifier\n");
        printf("3-supprimer\n");
        printf("4-afficher\n");
        printf("5-retour\n");
        printf("choisir un sous menu");
        scanf("%d",&choix_sm);
        gestion_client(choix_sm);

    }
    else if (choix ==2)
    {

        printf("1-ajouter\n");
        printf("2-afficher la liste\n");
        printf("3-supprimer\n");
        printf("4-retour\n");
        printf("choisir un sous menu");
        scanf("%d",&choix_sm);
        gestion_compte(choix_sm);
    }
    else if (choix ==3)
    {

        printf("1-retrait\n");
        printf("2-versement\n");
        printf("3-retour\n");
        printf("choisir un sous menu");
        scanf("%d",&choix_sm);
        gerer_operation(choix_sm);

    }
    else if (choix ==4)

    {
        return 0 ; // sortir

    }
    else
    {
        printf("choisir un menu ");
    }

}

struct client clients[20];
void gestion_client(int choix_sm)
{
    if (choix_sm ==1)
{

    struct client compte_client;
    FILE *file;

    printf("code client : ");
    scanf("%d",&compte_client.code_client);
    printf("prenom : ");
    scanf("%s",&compte_client.prenom_de_client);
    printf("nom : ");
    scanf("%s",&compte_client.nom_de_client);

    file=fopen("client.txt","a");
    fwrite(&compte_client,sizeof(compte_client),1,file);// le pointeur qui pointe sur fichier client)
    if (fwrite!=0)
    {
        printf("client ajouter avec succees");
    }
    else
    {
        printf("erreur");
    }
    fclose(file);
}
else if (choix_sm==2)
    {
        struct client compte_client;
        struct client nouveau_client;
        FILE *file;

        printf("nouveau code client ");
        scanf("%d",&nouveau_client.code_client);
        printf("nouveau prenom : ");
        scanf("%s", &nouveau_client.prenom_de_client);
        printf("nouveau nom : ");
        scanf("%s", &nouveau_client.nom_de_client);

        file = fopen("client.txt", "r");

        int nbclients = 0;

        while(fread(&compte_client, sizeof(compte_client), 1, file))
        {
            clients[nbclients] = compte_client;
            nbclients++;
        }
        fclose(file);
        remove("client.txt");

        FILE *new_file;
        new_file= fopen("nv.txt", "a");
        for ( int i=0 ; i<nbclients ; i++)
        {
            if (clients[i].code_client == nouveau_client.code_client)
                fwrite(&nouveau_client, sizeof(clients[i]), 1, new_file);
            else
                fwrite(&clients[i], sizeof(clients[i]), 1, new_file);
        }
        fclose(new_file);
        rename("nv.txt", "client.txt");
    }

else if (choix_sm==3)
{
        struct client compte_client;
        int code;
        FILE *file;

        printf(" code client a supprimer ");
        scanf("%d",&code);


        file = fopen("client.txt", "r");

        int nbclients = 0;

        while(fread(&compte_client, sizeof(compte_client), 1, file))
        {
            clients[nbclients] = compte_client;
            nbclients++;
        }
        fclose(file);
        remove("client.txt");

        FILE *new_file;
        new_file= fopen("nv.txt", "a");
        for ( int i=0 ; i<nbclients ; i++)
        {
            if (clients[i].code_client != code)
                fwrite(&clients[i], sizeof(clients[i]), 1, new_file);

        fclose(new_file);
        rename("nv.txt", "client.txt");
        }
}
else if (choix_sm==4)
    {
        FILE *file;
        int i;
        struct client compte_client;
        file = fopen("client.txt", "r");
        int nbclients = 0;
        while(fread(&compte_client, sizeof(struct client), 1, file))
        {
            clients[nbclients] = compte_client;
            nbclients++;
        }
        fclose(file);
        for (int i=0 ; i<nbclients ; i++)
        {
            printf("Code client : %d  ", clients[i].code_client);
            printf("Prenom: %s  ", clients[i].prenom_de_client);
            printf("Nom: %s  ", clients[i].nom_de_client);
            printf("\n");

        }
    }
else if (choix_sm==5)
    {
        menu();
    }


}

struct compte comptes[20];
void gestion_compte(int choix_sm)
{
    if (choix_sm==1)
    {
        struct compte compte_client;
        FILE *file;

        printf("code compte : ");
        scanf("%d",&compte_client.num_compte);
        printf("code client : ");
        scanf("%d",&compte_client.code_client);
        printf("somme : ");
        scanf("%d",&compte_client.somme);
        printf("jour : ");
        scanf("%d",&compte_client.date.jour);
        printf("mois : ");
        scanf("%d",&compte_client.date.mois);
        printf("annees : ");
        scanf("%d",&compte_client.date.annees);


        file=fopen("compte.txt","a");
        fwrite(&compte_client,sizeof(compte_client),1,file);// le pointeur qui pointe sur fichier compte
        if (fwrite!=0)
    {
        printf("compte ajouter avec succees");
    }
    else
    {
        printf("erreur");
    }
    fclose(file);
    }

    else if (choix_sm==2)
    {
        struct compte compte_client;
        FILE *file;

        file = fopen("compte.txt", "r");

        while(fread(&compte_client, sizeof(compte_client), 1, file))
            {
                    printf(" numero compte : %d  ", compte_client.num_compte);
                    printf("Code client : %d  ", compte_client.code_client);
                    printf(" Somme %d", compte_client.somme);
                    printf(" Date creation %d /  %d  / %d \n", compte_client.date.jour, compte_client.date.mois, compte_client.date.annees);

            }
        fclose(file);
    }
    else if (choix_sm==3)
    {
        struct compte compte_client;
        int code;
        FILE *file;

        printf(" code compte a supprimer ");
        scanf("%d",&code);


        file = fopen("compte.txt", "r");

        int nbcomptes = 0;

        while(fread(&compte_client, sizeof(compte_client), 1, file))
        {
            comptes[nbcomptes] = compte_client;
            nbcomptes++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *new_file;
        new_file= fopen("nv.txt", "a");
        for ( int i=0 ; i<nbcomptes ; i++)
        {
            if (comptes[i].num_compte != code)
            {   fwrite(&comptes[i], sizeof(comptes[i]), 1, new_file);
                fclose(new_file);
                rename("nv.txt", "compte.txt");

            }
        }
}
    else if (choix_sm==4)
    {
       menu();
    }
}

void gerer_operation(int choix_sm)
{
    if (choix_sm==1)
    {
        struct compte compte_client;
        int code,montant;
        FILE *file;

        printf("Code Compte : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte_client, sizeof(compte_client), 1, file))
            {
            comptes[nb] = compte_client;
            nb++;
            }
        fclose(file);
        remove("compte.txt");

        FILE *new_file;
        new_file = fopen("new_file.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].num_compte == code)
            {
                do
                { printf("\n montant : ");
                  scanf("%d", &montant);
                }while(montant>comptes[i].somme);
                comptes[i].somme = comptes[i].somme - montant;
                printf("\n code compte %d", comptes[i].num_compte);
                printf("\n code client %d", comptes[i].code_client);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte_client.date.jour, compte_client.date.mois, compte_client.date.annees);
                printf("\n-----------------------------------------");
            }
            fwrite(&comptes[i], sizeof(comptes[i]), 1, new_file);
        }
        fclose(new_file);
        rename("new_file.txt", "compte.txt");
    }
    else if (choix_sm==2)
    {
        struct compte compte_client;
        int code1,code2,montant;
        FILE *file;

        printf("Code compte de depart : ");
        scanf("%d", &code1);

        printf("Code compte d'arrivee : ");
        scanf("%d", &code2);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte_client, sizeof(compte_client), 1, file))
            {
            comptes[nb] = compte_client;
            nb++;
            }
        fclose(file);
        remove("compte.txt");

        FILE *new_file;
        new_file= fopen("new_file.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {


            if (comptes[i].num_compte == code1)
            {
                do
                { printf("\n montant : ");
                  scanf("%d", &montant);
                }while(montant>comptes[i].somme);
                comptes[i].somme = comptes[i].somme - montant;
                printf(" compte depart : ");
                printf("\n code compte %d", comptes[i].num_compte);
                printf("\n code client %d", comptes[i].code_client);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte_client.date.jour, compte_client.date.mois, compte_client.date.annees);
                printf("\n-----------------------------------------");
            }
            else if (comptes[i].num_compte == code2)

            {
                comptes[i].somme = comptes[i].somme + montant;
                printf(" compte d'arrivee :");
                printf("\n code compte %d", comptes[i].num_compte);
                printf("\n code client %d", comptes[i].code_client);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte_client.date.jour, compte_client.date.mois, compte_client.date.annees);
                printf("\n-----------------------------------------");
            }
            fwrite(&comptes[i], sizeof(comptes[i]), 1, new_file);
        }
        fclose(new_file);
        rename("new_file.txt", "compte.txt");
    }
    else if(choix_sm==3)
    {
     menu();
    }
}

void main()
{
    menu();
}
























