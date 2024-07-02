#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

void writeListToFile(const string& filename, Node* head) {
	ofstream file("file.txt");
	if (!file.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		return;
	}

	Node* current = head;
	while (current != nullptr) {
		file << current->data << endl;
		current = current->next;
	}

	file.close();
}

void insertNode(Node** head, int position, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (*head == nullptr || position <= 0) {
		newNode->next = *head;
		if (*head != nullptr) {
			(*head)->prev = newNode;
		}
		*head = newNode;
	}
	else {
		Node* current = *head;
		int currentPosition = 0;
		while (currentPosition < position - 1 && current->next != nullptr) {
			current = current->next;
			currentPosition++;
		}
		newNode->next = current->next;
		if (current->next != nullptr) {
			current->next->prev = newNode;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}


void deleteFromEnd(Node** head, int k) {
	if (*head == nullptr || k <= 0) {
		return;
	}
	Node* last = *head;
	while (last->next != nullptr) {
		last = last->next;
	}
	for (int i = 0; i < k; ++i) {
		if (last == *head) {
			*head = last->next;
			if (*head != nullptr) {
				(*head)->prev = nullptr;
			}
			delete last;
			last = nullptr;
			break;
		}
		else {
			Node* prev = last->prev;
			prev->next = nullptr;
			delete last;
			last = prev;
		}
	}
}

void printList(Node* head) {
	if (head == nullptr) {
		cout << "Список пуст" << endl;
	}
	else {
		cout << "Элементы списка:" << endl;
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Node* head = nullptr;
	insertNode(&head, 0, 1);
	insertNode(&head, 1, 2);
	insertNode(&head, 2, 3);
	insertNode(&head, 3, 4);
	printList(head);
	insertNode(&head, 2, 15);
	printList(head);
	deleteFromEnd(&head, 3);
	printList(head);
	writeListToFile("list.txt", head);
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}