#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour supprimer toutes les occurrences de x
void supprimerOccurrences(Node** head, int x) {
    Node* temp = *head;
    Node* prev = NULL;

    // Supprimer les occurrences de x au début de la liste
    while (temp != NULL && temp->data == x) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    // Supprimer les occurrences de x dans le reste de la liste
    while (temp != NULL) {
        while (temp != NULL && temp->data != x) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}

// Fonction pour ajouter un nœud à la liste
void ajouterNoeud(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Ajouter des nœuds à la liste
    ajouterNoeud(&head, 3);
    ajouterNoeud(&head, 2);
    ajouterNoeud(&head, 3);
    ajouterNoeud(&head, 1);
    ajouterNoeud(&head, 3);

    printf("Liste originale : ");
    afficherListe(head);

    // Supprimer toutes les occurrences de 3
    supprimerOccurrences(&head, 3);

    printf("Liste après suppression de 3 : ");
    afficherListe(head);

    return 0;
}
