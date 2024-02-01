#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 128

void print_image(FILE *fptr);

// fonction pour retirer le retour à la ligne dans le fichier "words.txt" après
// avoir choisi un mot
void retirerRetourALaLigne(char *chaine) {
  int longueur = strlen(chaine);
  int i, j = 0;

  for (i = 0; i < longueur; i++) {
    // si le caractère courant n'est pas un retour à la ligne
    if (chaine[i] != '\n') {
      chaine[j++] = chaine[i];
    }
  }
  // ajoute un caractère nul à la fin pour terminer la nouvelle chaîne
  chaine[j] = '\0';
}

int main() {
  char nom[100];
  char mot[100];
  char lettreUsed[0];
  char lettre;
  int length = 0;
  int lengthLettre = 0;
  int tentatives = 0;
  int compteur = 8;
  int savelettre = 0;
  bool lettrefound = false;
  int c;
  char *filename = "image.txt";
  FILE *fptr = NULL;
  int compteurLettre = 0;
  int estPresent = 0;
  FILE *fichierMots;
  char nomFichier[] = "words.txt";

  // ouvre le fichier image.txt
  if ((fptr = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error opening %s\n", filename);
    return 1;
  }
  print_image(fptr);
  fclose(fptr);

  // ouvre le fichier words.txt
  fichierMots = fopen(nomFichier, "r");

  if (fichierMots == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 1;
  }

  int compteurLignes = 1;

  // variable pour la ligne aléatoire
  int randomWord;
  // choisi une ligne aléatoire dans le fichier words.txt
  srand(time(NULL));
  randomWord = rand() % 835 + 1;

  // récupère le mot à la ligne choisi aléatoirement
  while (fgets(mot, sizeof(mot), fichierMots) != NULL) {
    if (compteurLignes == randomWord) {
      break;
    }
    compteurLignes++;
  }

  retirerRetourALaLigne(mot);

  // choisi le nom
  printf("\n\nEntrez votre nom : ");
  scanf("%s", nom);

  // recupere le nombre de lettre dans le mot
  length = strlen(mot);

  // converti le mot en majuscule
  for (int i = 0; i < length; ++i) {
    mot[i] = toupper(mot[i]);
  }

  // initialisation du tableau pour les _
  char underscore[length + 1];

  // entre les _ dans le tableau en fonction de la longueur du mot
  for (int i = 0; i < length; i++) {
    underscore[i] = '_';
  }

  underscore[length] = '\0';

  // affiche les _
  for (int i = 0; i < length; i++) {
    printf("%c", underscore[i]);
  }

  // boucle pour choisir les lettres
  while (tentatives < 8) {

    printf("\nIl vous reste %d tentatives", compteur);
    printf("\nChoisissez une lettre : ");
    scanf(" %c", &lettre);
    lettre = toupper(lettre);

    // verifie si c'est bien une lettre
    while (!isalpha(lettre)) {
      printf("Ce n'est pas une lettre");
      printf("\nChoisissez une lettre : ");
      scanf(" %c\n", &lettre);
      lettre = toupper(lettre);
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }

    // parcourir le tableau pour vérifier la présence du caractère
    lengthLettre = strlen(lettreUsed);
    for (int i = 0; i < lengthLettre; ++i) {
      if (lettreUsed[i] == lettre) {
        estPresent = 1; // le caractère est présent dans le tableau
        break;
      }
    }

    if (estPresent == 1) {
      printf("Cette lettre a déjà été utilisé\n");
    } else {
      lettreUsed[compteurLettre] = lettre;
      compteurLettre++;
    }

    if (estPresent == 0) {
      // verifie si la lettre choisie est dans le mot
      for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == lettre) {
          // stock la position de la lettre dans une autre variable
          savelettre = i;
          // Remplace l'underscore par la lettre
          underscore[savelettre] = lettre;
          lettrefound = true;
        }
      }
    }

    // met à jour le nombre de tentatives si la lettre choisi n'est pas bonne
    if (lettrefound == false && estPresent == 0) {
      compteur--;
      tentatives++;
    } else {
      lettrefound = false;
      estPresent = 0;
    }

    // affiche le pendu

    if (tentatives == 1) {
      printf(" ⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸"
             "⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 2) {
      printf("    ⢰⣶⣶⣶\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n"
             "    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 3) {
      printf("    ⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶\n    ⢸⣿⣿⣿⠛⠛⠛⢻⣿⣿⠟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛\n    ⢸⣿⣿⣿\n "
             "   ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n"
             "    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 4) {
      printf("    ⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶\n    ⢸⣿⣿⣿⠛⠛⠛⢻⣿⣿⠟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛\n    "
             "⢸⣿⣿⣿⠀⣠⣾⡿⠋\n "
             "   ⢸⣿⣿⣿⣾⡿⠋\n    ⢸⣿⣿⣿⠁\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n"
             "    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 5) {
      printf("    ⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶\n    ⢸⣿⣿⣿⠛⠛⠛⢻⣿⣿⠟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛\n    "
             "⢸⣿⣿⣿⠀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n "
             "   ⢸⣿⣿⣿⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣷⣶⣦\n    ⢸⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⠇\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡿⠋\n    "
             "⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n"
             "    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 6) {
      printf("    ⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶\n    ⢸⣿⣿⣿⠛⠛⠛⢻⣿⣿⠟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛\n    "
             "⢸⣿⣿⣿⠀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n "
             "   ⢸⣿⣿⣿⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣷⣶⣦\n    ⢸⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⠇\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡿⠋\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣿⣿\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⣿⣿\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⣿⣿\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣿⣿\n    ⢸⣿⣿⣿\n"
             "    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 7) {
      printf("    ⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶\n    ⢸⣿⣿⣿⠛⠛⠛⢻⣿⣿⠟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛\n    "
             "⢸⣿⣿⣿⠀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n "
             "   ⢸⣿⣿⣿⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣷⣶⣦\n    ⢸⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⠇\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡿⠋\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣄\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣾⠟⣿⣿⠻⣷⣦⡀\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⣿⣿⠀⠈⠉\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣿⣿\n    ⢸⣿⣿⣿\n"
             "    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    if (tentatives == 8) {
      printf("    ⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶\n    ⢸⣿⣿⣿⠛⠛⠛⢻⣿⣿⠟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛\n    "
             "⢸⣿⣿⣿⠀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n "
             "   ⢸⣿⣿⣿⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣷⣶⣦\n    ⢸⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⠇\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡿⠋\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣄\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣾⠟⣿⣿⠻⣷⣦⡀\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⣿⣿⠀⠈⠉\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡆\n    "
             "⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⢻⣿⡀\n"
             "    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠇⠈⣿⣧\n    ⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡏⠀⠀⠸⣿⡆\n    "
             "⢸⣿⣿⣿\n    ⢸⣿⣿⣿\n    "
             "⢸⣿⣿⣿\n⢀⣀⣀⣀⣸⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n⢸⣿⣿"
             "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿\n");
    }

    // affiche le mot à chaque fois
    for (int i = 0; i < length; i++) {
      printf("%c", underscore[i]);
    }
    printf("\n");
    // vérifie si le mot a été trouvé afin de terminer la partie
    if (strcmp(underscore, mot) == 0) {
      break;
    }
  }

  // partie perdue / partie gagné
  if (tentatives >= 8) {
    printf("\nDéfaite");
  } else {
    printf("\nBravo, vous avez gagné !");
  }

  return 0;
}

void print_image(FILE *fptr) {
  char read_string[MAX_LEN];

  while (fgets(read_string, sizeof(read_string), fptr) != NULL)
    printf("%s", read_string);
}
