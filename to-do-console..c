/* Ci-dessous est le code d'une application console
pour gérer une liste de tâches à faire, en permettant
l'ajout, la modification, la suppression et l'affichage.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //.

#define MAX_TACHES 100
#define MAX_TTR_LNGR 20
#define MAX_DESC_LNGR 80
#define MAX_DLINE_LNGR 10
#define MAX_STATUT_LNGR 40

typedef struct {
    int id;
    char titre[MAX_TTR_LNGR];
    char descrip[MAX_DESC_LNGR];
    char deadline[MAX_DLINE_LNGR];
    char statut[MAX_STATUT_LNGR];
} Tache;

Tache taches[MAX_TACHES];
int numTaches = 0;

void ClaireTampon() {
	int c;
    while ((c = getchar()) != '\n') {}
}

void Ajout() {
    Tache tache;

    printf(" Ajouter une nouvelle tache :\n");

    printf(" Identifiant (unique) : ");
    scanf("%d", &tache.id);
    ClaireTampon();

    printf(" Titre : ");
    fgets(tache.titre, MAX_TTR_LNGR, stdin);
    tache.titre[strlen(tache.titre) - 1] = '\0';

    printf(" Description : ");
    fgets(tache.descrip, MAX_DESC_LNGR, stdin);
    tache.descrip[strlen(tache.descrip) - 1] = '\0';

    printf(" Deadline (jour heure minute) : ");
    fgets(tache.deadline, MAX_DLINE_LNGR, stdin);
    tache.deadline[strlen(tache.deadline) - 1] = '\0';

    printf(" Statut (\"FINALISEE\", \"EN COURS\" ou autre) : ");
    fgets(tache.statut, MAX_STATUT_LNGR, stdin);
    tache.statut[strlen(tache.statut) - 1] = '\0';

    taches[numTaches++] = tache;

    printf(" >>> Parfait! la tache a ete ajoutee.\n");
}

void Affichage() {
    if (numTaches == 0) {
        printf(" Il n'y a aucune tache a afficher.\n");
        return;
    }

    // Tri des taches par ordre alphabetique (titre)
    for (int i = 0; i < numTaches - 1; i++) {
        for (int j = i + 1; j < numTaches; j++) {
            if (strcmp(taches[i].titre, taches[j].titre) > 0) {
                Tache temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }

    printf(" Liste des taches :\n");
    printf("__________________________________________________________________________________________________________________\n");
    printf("| Identifiant | Titre                    | Description              | Deadline         | Statut                  |\n");
    printf("__________________________________________________________________________________________________________________\n");

    for (int i = 0; i < numTaches; i++) {
        printf("| %-12d", taches[i].id);
        printf("| %-25s", taches[i].titre);
        printf("| %-25s", taches[i].descrip);
        printf("| %-17s", taches[i].deadline);
        printf("| %-24s|\n", taches[i].statut);
    }

    printf("__________________________________________________________________________________________________________________\n");
}

void Modification() {
    int tacheID;
    int trouvee = 0;

    printf(" Modifier une tache :\n");
    printf(" Identifiant de la tache : ");
    scanf("%d", &tacheID);
    ClaireTampon();

    for (int i = 0; i < numTaches; i++) {
        if (taches[i].id == tacheID) {
            trouvee = 1;

            printf(" Nouvelle description : ");
            fgets(taches[i].descrip, MAX_DESC_LNGR, stdin);
            taches[i].descrip[strlen(taches[i].descrip) - 1] = '\0';

            printf(" Nouveau statut : ");
            fgets(taches[i].statut, MAX_STATUT_LNGR, stdin);
            taches[i].statut[strlen(taches[i].statut) - 1] = '\0';

            printf(" Nouvelle deadline (jour heure minute) : ");
            fgets(taches[i].deadline, MAX_DLINE_LNGR, stdin);
            taches[i].deadline[strlen(taches[i].deadline) - 1] = '\0';

            printf(" >>> Parfait! la tache a ete modifiee.\n");
            break;
        }
    }

    if (!trouvee) {
        printf(" Il n'y a aucune tache avec cet identifiant.\n");
    }
}

void Suppression() {
    int tacheID;
    int trouvee = 0;

    printf(" Supprimer une tache :\n");
    printf(" Identifiant de la tache : ");
    scanf("%d", &tacheID);
    ClaireTampon();

    for (int i = 0; i < numTaches; i++) {
        if (taches[i].id == tacheID) {
            trouvee = 1;

            for (int j = i; j < numTaches - 1; j++) {
               taches[j] = taches[j + 1];
            }

            numTaches--;
            printf(" >>> Parfait! la tache a ete supprimee..\n");
            break;
        }
    }

    if (!trouvee) {
        printf(" Il n'y a aucune tache avec cet identifiant.\n");
    }
}

void RechercheId() {
    int tacheID;
    int trouvee = 0;

    printf(" Rechercher une tache par identifiant :\n");
    printf(" Identifiant de la tache : ");
    scanf("%d", &tacheID);
    ClaireTampon();

    for (int i = 0; i < numTaches; i++) {
        if (taches[i].id == tacheID) {
            trouvee = 1;

            printf(" Tache trouvee :\n");
            printf("__________________________________________________________________________________________________________________\n");
            printf("| Identifiant | Titre                    | Description              | Deadline         | Statut                  |\n");
            printf("__________________________________________________________________________________________________________________\n");
            printf("| %-12d", taches[i].id);
            printf("| %-25s", taches[i].titre);
            printf("| %-25s", taches[i].descrip);
            printf("| %-17s", taches[i].deadline);
            printf("| %-24s|\n", taches[i].statut);
            printf("__________________________________________________________________________________________________________________\n");
            break;
        }
    }

    if (!trouvee) {
        printf(" Il n'y a aucune tache avec cet identifiant.\n");
    }
}

void RechercheTitre() {
    char searchTitle[MAX_TTR_LNGR];
    int trouvee = 0;

    printf(" Rechercher une tache par titre :\n");
    printf(" Titre de la tache : ");
    fgets(searchTitle, MAX_TTR_LNGR, stdin);
    searchTitle[strlen(searchTitle) - 1] = '\0';

    printf(" Resultats de la recherche :\n");
    printf("__________________________________________________________________________________________________________________\n");
    printf("| Identifiant | Titre                    | Description              | Deadline         | Statut                  |\n");
    printf("__________________________________________________________________________________________________________________\n");

    for (int i = 0; i < numTaches; i++) {
        if (strstr(taches[i].titre, searchTitle) != NULL) {
            trouvee = 1;
            printf("| %-12d", taches[i].id);
            printf("| %-25s", taches[i].titre);
            printf("| %-25s", taches[i].descrip);
            printf("| %-17s", taches[i].deadline);
            printf("| %-24s|\n", taches[i].statut);
        }
    }

    if (!trouvee) {
        printf(" Il n'y a aucune tache avec ce titre.\n");
    }

    printf("__________________________________________________________________________________________________________________\n");
}

void JoursRestants() {
    printf(" Le nombre de jours restants jusqu'au delai de chaque tache :\n");
    printf("______________________________________________________________________________\n");
    printf("| Identifiant | Titre                    | Deadline         | Jours restants |\n");
    printf("______________________________________________________________________________\n");

    for (int i = 0; i < numTaches; i++) {
        int jour, heure, minute;
        sscanf(taches[i].deadline, "%d %d %d", &jour, &heure, &minute);

        // Calcul du nombre de jours restants
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        int Jours = jour - tm.tm_mday;

        if (Jours <= 3) {
            // Tri par deadline des tâches dans les 3 jours
            for (int i = 0; i < numTaches - 1; i++) {
                for (int j = i + 1; j < numTaches; j++) {
                    if (strcmp(taches[i].deadline, taches[j].deadline) > 0) {
                        Tache temp = taches[i];
                        taches[i] = taches[j];
                        taches[j] = temp;
                    }
                }
            }
                
            printf("| %-12d", taches[i].id);
            printf("| %-25s", taches[i].titre);
            printf("| %-17s", taches[i].deadline);
            printf("| %-15d| \n", Jours);
        }
    }
    
    printf("______________________________________________________________________________\n");
}

void Statistiques() {
    int TachesCompletes = 0;
    int TachesEnCours = 0;
    int TachesIncompletes = 0;

    printf(" Statistiques :\n");
    printf(" Nombre total de taches : %d\n", numTaches);

    for (int i = 0; i < numTaches; i++) {
        if (strcmp(taches[i].statut, "FINALISEE") == 0) {
            TachesCompletes++;
        } else if (strcmp(taches[i].statut, "EN COURS") == 0) {
            TachesEnCours++;
        } else {
            TachesIncompletes++;
        }
    }

    printf(" Nombre de taches completes : %d\n", TachesCompletes);
    printf(" Nombre de taches en cours : %d\n", TachesEnCours);
    printf(" Nombre de taches incompletes : %d\n", TachesIncompletes);
}

void AffichageMenu() {
    printf("\n\t Bienvenue au gestionnaire de taches To-Do ! \n\n");
    printf(" 1. Ajout de taches\n");
    printf(" 2. Affichage de taches\n");
    printf(" 3. Modification de taches\n");
    printf(" 4. Suppression d'une tache\n");
    printf(" 5. Recherche par identifiant\n");
    printf(" 6. Recherche par titre\n");
    printf(" 7. Taches de 3 jours\n");
    printf(" 8. Statistiques\n");
    printf(" 9. Quitter\n");
    printf("\n Veuillez choisir votre choix : ");
}

void TraitementChoix(int choix) {
    switch (choix) {
        case 1:
            Ajout();
            break;
        case 2:
            Affichage();
            break;
        case 3:
            Modification();
            break;
        case 4:
            Suppression();
            break;
        case 5:
            RechercheId();
            break;
        case 6:
            RechercheTitre();
            break;
        case 7:
            JoursRestants();
            break;
        case 8:
            Statistiques();
            break;
        case 9:
            printf(" A la prochaine !\n");
            exit(0);
        default:
            printf(" Votre choix n'est pas valide.\n");
            break;
    }
}

int main() {
    int choix;
    
    do {
        AffichageMenu();
        scanf("%d", &choix);
        ClaireTampon();
        TraitementChoix(choix);
    } while (1);
    
    return 0;
}
