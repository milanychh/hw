#include <iostream>
using namespace std;

struct list { 
    int data;
    list*next; 
    list*prev;
};

list*head = NULL; 
list*tail = NULL; 

// функция добавления элемента в конец списка
void add(int value) { 
    list*temp = new list; 
    temp->data = value;
    temp->next = NULL;
    temp->prev = tail;
    if (tail != NULL) { 
        tail->next = temp;
    }
    tail = temp; 
    if (head == NULL) { 
        head = temp; 
    }
}

void deleteExtra() { // функция удаления лишних элементов
    int sum = 0; 
    int count = 0; 
    list*current = head; 
    while (current != NULL) { 
        list*temp = current->next; 
        while (temp != NULL) { 
            sum += temp->data; 
            count++; 
            temp = temp->next; 
        }
        if (count > 0 && current->data < sum / count) { // если текущий элемент меньше среднего арифметического следующих за ним
            list*temp = current; 
            current = current->next; 
            if (temp->prev != NULL) { 
                temp->prev->next = current; 
            } else {
                head = current; 
            }
            if (current != NULL) { 
                current->prev = temp->prev;
            } else {
                tail = temp->prev; 
            }
            delete temp; 
        } else {
            current = current->next; 
        }
        sum = 0; 
        count = 0;
    }
}

void print() { // функция вывода списка на экран
    list*temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++) { // ввод элементов списка
        int value;
        cin >> value;
        add(value);
    }
    deleteExtra(); // удаление лишних элементов
    print();
}