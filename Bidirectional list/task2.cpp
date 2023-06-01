#include <iostream>
using namespace std;

struct list {
    int data;
    list*prev;
    list*next;
};

// Функция для добавления элемента в конец списка
void add_node(list *&head, list *&tail, int value) {
    list*temp = new list;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Функция для удаления последних вхождений повторяющихся элементов
void remove_duplicates(list *&head, list *&tail) {
    list*curr = tail;
    while (curr != NULL) {
        list*temp = curr->prev;
        while (temp != NULL) {
            if (curr->data == temp->data) {
                list*prev_node = temp->prev;
                list*next_node = temp->next;

                if (prev_node != NULL) {
                    prev_node->next = next_node;
                } else {
                    head = next_node;
                }

                if (next_node != NULL) {
                    next_node->prev = prev_node;
                } else {
                    tail = prev_node;
                }

                list*to_delete = temp;
                temp = prev_node;
                delete to_delete;
            } else {
                temp = temp->prev;
            }
        }
        curr = curr->prev;
    }
}

// Вспомогательная функция для вывода списка
void print_list(list*temp) {
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    list*head = NULL;
    list*tail = NULL;

    int n;
    cout << "Enter n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        add_node(head, tail, num);
    }

    remove_duplicates(head, tail);

    print_list(head);

}