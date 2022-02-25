#include <iostream>
#include <locale>
#include "queue.h"
#include "queue1.h"

using namespace std;

/*8-���������� ���������� ��������, �������� �������� ���������������*/

template <class T>

void chosen_class(T* queue, int num) {

	int c;
	int flag = 1;
	int value;
	int index = 0;
	int count = 1;
	int res= 0;
	int choseNum;

	while (flag == 1) {

		cout << "1 - ���������� �������� �������" << endl;
		cout << "2 - ���������� �������� �������" << endl;
		cout << "3 - ����� ������� �� �����" << endl;
		cout << "4 - ���������� ���������� ��������, �������� �������� ���������������" << endl;
		cout << "5 - �������� ����� �������" << endl;
		cout << "6 - ������� ���� ��������" << endl;
		cout << "7 - ����� ���� �������" << endl;
		cout << "8 - � ����� �������� � ������ �������?" << endl;
		cout << "0 - ��������� � ������ ������-����������" << endl;
		cout << "> ";
		cin >> c;

		switch (c) {

		case 1:
			system("cls");
			cout << "������� ��������: ";
			cin >> value;
			queue[index].push(value);
			cout << "�������� ��������� � �������.\n " << endl;
			break;

		case 2: 
			if (queue[index].isEmpty()) {
				cout << "������� ��� �����, ��������� ������.\n " << endl;
				system("pause");
				break;
			} else {
				system("cls");
				value = queue[index].pop();
				cout << "����������� �������: " << value << endl;
				cout << "\n";
			}
			break;

		case 3:
			if (queue[index].isEmpty()) {
				cout << "������� �����, �������� ������.\n" << endl;
				system("pause");
				break;
			} else {
				system("cls");
				queue[index].print();
				cout << "\n";
			}
			break;

		case 4:

			if (queue[index].isEmpty()) {
				cout << "������� �����, ������� ��������� ����������.\n" << endl;
				system("pause");
				break;
			} else {
				system("cls");
				res= queue[index].fun();
				cout << "������� �������: " << res<< endl;
				cout << "\n";
			}
			break;

		case 5:
			if (queue[index].isEmpty()) {
				cout << "������� �����, ���������� ������.\n" << endl;
				system("pause");
				break;
			}
			else {
				if (count == num) {
					cout << "���������� ������� ����� �������, ��� ��� ���������� �������� �������� ���������.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				queue[count].copy(queue[index]);
				cout << "������� ������� �����������. ������ ���������� ��� ������ �������.\n" << endl;
				count++; 
			}
			break;

		case 6:

			if (count == 1) {
				cout << "���������� ������ ���� �������.\n" << endl;
				system("pause");
				break;
			}
			else {
				cout << "� ����� �������� ���������� �������?" << endl;
				cin >> choseNum;
				if ((choseNum <= 0) || (choseNum > num) || (choseNum == index)) {
					cout << "������������ ��������!\n" << endl;
					system("pause");
					break;
				}
				if (queue[choseNum-1].isEmpty()) {
					cout << "���������� ���������� �������, ��� ��� ������ ������� �����.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				queue[index].merge(queue[choseNum-1]);
				
				cout << "\n";
			}
			break;

		case 7: 
			system("cls");
			cout << "������ �� ��������� � �������� �" << index+1 << endl;
			cout << "������� ����� ������� (�� 1 �� " << num << ") , �� ������� ������ �������������: ";
			cin >> choseNum;

			if ((choseNum <= 0) || (choseNum > num) || (choseNum == index)) {
				cout << "������������ �������� ��� ���������� �������� ���������!\n" << endl;
				system("pause");
			} else {
				index = choseNum-1;
				system("cls");
				cout << "�� ������������� �� ������� �" << index+1 << endl;
				cout << "\n";
			}
			break;

		case 8:
			system("cls");
			cout << "�� ������ ��������� � �������� �" << index+1 << endl;
			cout << "\n";
			break;

		case 0:
			cout << "\n";
			flag = 0;
			break;
		}
	}
}

int main() {

	setlocale(LC_ALL, "");
	int numOfq; 
	int c;
	int flag = 1;
	childQueuePrivate* qF = NULL;
	childQueueProtected* qS = NULL;
	childQueuePublic* qT = NULL;
	cout << "������� ��������� ��������: ";
	cin >> numOfq;
	system("cls");
	cout << "��������, � ����� �������-����������� �� ������ ��������: " << endl;

	while (flag == 1) {
		cout << "1 - ���������" << endl;
		cout << "2 - ����������" << endl;
		cout << "3 - ���������" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "-> ";
		cin >> c;

		switch (c) {

		case 1:
			qF = new childQueuePrivate[numOfq];
			system("cls");
			chosen_class(qF, numOfq);
			delete[] qF;

			break;

		case 2:

			qS = new childQueueProtected[numOfq];
			system("cls");
			chosen_class(qS, numOfq);
			delete[] qS;
			break;

		case 3:

			qT = new childQueuePublic[numOfq];
			system("cls");
			chosen_class(qT, numOfq);
			delete[] qT;

			break;

		case 0:
			flag = 0;
			break;

		default:
			system("cls");
			cout << "������������ ����!" << endl;
			break;
		}
	}
	return 0;
}