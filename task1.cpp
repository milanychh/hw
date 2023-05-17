#include <iostream>
using namespace std;

struct list{
    int inf;
    list*prev;
    list*next;
};

// Функция для добавления узла в конец списка
void addNode(list*& head, list*& tail, int num) {
    list*newlist= new list;
    newlist->inf = num;
    newlist->prev = tail;
    newlist->next = nullptr;
    if (tail != nullptr) tail->next = newlist;
    tail = newlist;
    if (head == nullptr) head = newlist; // если список пустой, то новый элемент будет первым и последним
}

// Функция для поиска последнего нечетного элемента списка
int findLastOdd(list*tail) {
    int last_odd;
    list*current = tail;
    while (current != nullptr) {
        if (current->inf % 2 == 1) {
            last_odd = current->inf;
            break;
        }
        current = current->prev;
    }
    return last_odd;
}

// Функция для вставки элемента в середину списка
void insertNode(list*head, list*& tail, int max_num, int last_odd) {
    list*current = head;
    while (current != nullptr) {
        if (current->inf == max_num) {
            list*newnode= new list;
            newnode->inf = last_odd;
            newnode->prev = current;
            newnode->next = current->next;
            current->next = newnode;
            if (newnode->next != nullptr) newnode->next->prev = newnode;
            if (current == tail) tail = newnode;
            current = newnode;
        }
        current = current->next;
    }
}

// Функция для вывода списка
void printList(list*head) {
    list*current = head;
    while (current != nullptr) {
        cout << current->inf << " ";
        current = current->next;
    }
}


int main() {
    list*head = nullptr;
    list*tail = nullptr;
    int num, max_num = 0, last_odd;
    
    // заполнение списка
    int n;
    cout << "Enter n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        addNode(head, tail, num);
        if (num > max_num) max_num = num;
    }

    // поиск последнего нечетного элемента
    last_odd = findLastOdd(tail);
    
    // вставка последнего нечетного элемента
    insertNode(head, tail, max_num, last_odd);
    
    // вывод списка
    printList(head);
}