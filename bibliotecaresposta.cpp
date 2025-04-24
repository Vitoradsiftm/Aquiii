#include <stdio.h>
#include <iostream>

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
    int s;

    List() {
        start = NULL;
        end = NULL;
        s = 0;
    }

    bool empty() {
        return start == NULL && end == NULL;
    }

    void pushBack(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    void pushFront(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
    }

    void print() {
        Node* aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("NULL\n");
    }

    int size() {
        return s;
    }

    void popFront() {
        if (empty()) return;
        if (size() == 1) {
            delete(start);
            start = NULL;
            end = NULL;
            s = 0;
            return;
        }

        Node *aux = start;
        start = start->next;
        delete(aux);
        s--;
    }

    void popBack() {
        if (empty()) return;
        if (size() == 1) {
            delete(start);
            start = NULL;
            end = NULL;
            s = 0;
            return;
        }

        Node *aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }

        delete(end);
        end = aux;
        end->next = NULL;
        s--;
    }

    void insert(int v, int p) {
        if (p <= 0) {
            pushFront(v);
            return;
        }

        if (p >= s) {
            pushBack(v);
            return;
        }

        Node *n = new Node(v);
        s++;

        Node *a = start;
        for (int i = 0; i < p - 1; i++) {
            a = a->next;
        }

        n->next = a->next;
        a->next = n;
    }

    void atividade1a(int n) {
        for (int i = 0; i < n; i++) {
            popBack();
        }
    }

    void atividade1b(int n) {
        if (n < s) {
            Node *aux = start;
            for (int i = 0; i < s - n - 1; i++) {
                aux = aux->next;
            }
            end = aux;
            s -= n;
            for (int i = 0; i < n; i++) {
                Node *toDel = aux->next;
                aux->next = toDel->next;
                delete(toDel);
            }
        } else {
            while (!empty()) {
                popFront();
            }
        }
    }

    void atividade2() {
        if (s <= 1) return;
        if (s == 2) {
            popBack();
            return;
        }
        Node *second = start->next;
        start->next = second->next;
        delete(second);
        s--;
    }

    void atividade3() {
        pushBack(s);
    }

    void atividade4(int n) {
        for (int i = 1; i <= n; i++) {
            pushBack(i);
        }
    }

    void atividade5a(int v) {
        if (s <= 1) return;
        Node* aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }
        Node *n = new Node(v);
        n->next = end;
        aux->next = n;
        s++;
    }

    void atividade5b(int v) {
        insert(v, s - 1);
    }

    // NOVA FUNÇÃO: Qual livro João está lendo?
    int livroAtual(int paginasLidas) {
        if (paginasLidas <= 0) return 0;
        Node* aux = start;
        int i = 1;
        while (aux != NULL) {
            if (paginasLidas < aux->value) return i;
            paginasLidas -= aux->value;
            aux = aux->next;
            i++;
        }
        return 0;
    }

};

int main() {
    List l;
    int n, x, j;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        l.pushBack(x);
    }

    std::cin >> j;

    std::cout << l.livroAtual(j) << std::endl;

    return 0;
}
