#include <iostream>
#include <iomanip>

struct Node {
    int value;
    Node* next;

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct List {
    Node* start;
    Node* end;
    Node* median;
    int s;

    List() {
        start = NULL;
        end = NULL;
        median = NULL;
        s = 0;
    }

    bool empty() {
        return start == NULL;
    }

    void insertSorted(int value) {
        Node* n = new Node(value);
        s++;

        // Inserção na frente
        if (empty() || value < start->value) {
            n->next = start;
            start = n;
            if (end == NULL) end = n;
        }
        // Inserção no meio ou fim
        else {
            Node* aux = start;
            while (aux->next != NULL && aux->next->value < value) {
                aux = aux->next;
            }
            n->next = aux->next;
            aux->next = n;
            if (n->next == NULL) end = n;
        }

        atualizarMediana();
    }

    void atualizarMediana() {
        if (s == 0) {
            median = NULL;
            return;
        }

        int pos = (s - 1) / 2;
        Node* aux = start;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        median = aux;
    }

    double getMediana() {
        if (s == 0) return 0.0;
        if (s % 2 == 1) return (double)median->value;
        else return (median->value + median->next->value) / 2.0;
    }
};

int main() {
    int n, x;
    std::cin >> n;

    List l;

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        l.insertSorted(x);
        std::cout << "Lista: Mediana = " << std::fixed << std::setprecision(2) << l.getMediana() << std::endl;
    }

    return 0;
}
