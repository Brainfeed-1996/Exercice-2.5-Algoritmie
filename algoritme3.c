void supprimerOccurrencesMultiples(Node** head) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* toDelete = runner->next;
                runner->next = runner->next->next;
                free(toDelete);
            } else {
                runner = runner->next;
            }
        }
        prev = current;
        current = current->next;
    }
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

    // Supprimer les occurrences multiples
    supprimerOccurrencesMultiples(&head);

    printf("Liste après suppression des occurrences multiples : ");
    afficherListe(head);

    return 0;
}
