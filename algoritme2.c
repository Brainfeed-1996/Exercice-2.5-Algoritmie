void supprimerOccurrencesApresK(Node** head, int x, int k) {
    Node* temp = *head;
    Node* prev = NULL;
    int count = 0;

    // Parcourir la liste et compter les occurrences de x
    while (temp != NULL) {
        if (temp->data == x) {
            count++;
            if (count > k) {
                if (prev != NULL) {
                    prev->next = temp->next;
                } else {
                    *head = temp->next;
                }
                Node* toDelete = temp;
                temp = temp->next;
                free(toDelete);
                continue;
            }
        }
        prev = temp;
        temp = temp->next;
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

    // Ne laisser que les 2 premières occurrences de 3
    supprimerOccurrencesApresK(&head, 3, 2);

    printf("Liste après suppression des occurrences de 3 après les 2 premières : ");
    afficherListe(head);

    return 0;
}
