#include <iostream>
#include <locale>
#include "queue.h"
#include "queue1.h"

using namespace std;

/*8-Нахождение последнего элемента, меньшего среднего арифметического*/

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

		cout << "1 - Добавление элемента очереди" << endl;
		cout << "2 - Извлечение элемента очереди" << endl;
		cout << "3 - Вывод очереди на экран" << endl;
		cout << "4 - Нахождение последнего элемента, меньшего среднего арифметического" << endl;
		cout << "5 - Создание копии очереди" << endl;
		cout << "6 - Слияние двух очередей" << endl;
		cout << "7 - Выбор иной очереди" << endl;
		cout << "8 - С какой очередью я сейчас работаю?" << endl;
		cout << "0 - Вернуться к выбору класса-наследника" << endl;
		cout << "> ";
		cin >> c;

		switch (c) {

		case 1:
			system("cls");
			cout << "Введите значение: ";
			cin >> value;
			queue[index].push(value);
			cout << "Значение добавлено в очередь.\n " << endl;
			break;

		case 2: 
			if (queue[index].isEmpty()) {
				cout << "Очередь уже пуста, извлекать нечего.\n " << endl;
				system("pause");
				break;
			} else {
				system("cls");
				value = queue[index].pop();
				cout << "Извлеченный элемент: " << value << endl;
				cout << "\n";
			}
			break;

		case 3:
			if (queue[index].isEmpty()) {
				cout << "Очередь пуста, выводить нечего.\n" << endl;
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
				cout << "Очередь пуста, задание выполнить невозможно.\n" << endl;
				system("pause");
				break;
			} else {
				system("cls");
				res= queue[index].fun();
				cout << "Искомый элемент: " << res<< endl;
				cout << "\n";
			}
			break;

		case 5:
			if (queue[index].isEmpty()) {
				cout << "Очередь пуста, копировать нечего.\n" << endl;
				system("pause");
				break;
			}
			else {
				if (count == num) {
					cout << "Невозможно создать копию очереди, так как количество очередей достигло максимума.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				queue[count].copy(queue[index]);
				cout << "Очередь успешно скопирована. Теперь существует две равных очереди.\n" << endl;
				count++; 
			}
			break;

		case 6:

			if (count == 1) {
				cout << "Существует только одна очередь.\n" << endl;
				system("pause");
				break;
			}
			else {
				cout << "С какой очередью произвести слияние?" << endl;
				cin >> choseNum;
				if ((choseNum <= 0) || (choseNum > num) || (choseNum == index)) {
					cout << "Некорректное значение!\n" << endl;
					system("pause");
					break;
				}
				if (queue[choseNum-1].isEmpty()) {
					cout << "Невозможно произвести слияние, так как вторая очередь пуста.\n" << endl;
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
			cout << "Сейчас вы работаете с очередью №" << index+1 << endl;
			cout << "Введите номер очереди (от 1 до " << num << ") , на которую хотите переключиться: ";
			cin >> choseNum;

			if ((choseNum <= 0) || (choseNum > num) || (choseNum == index)) {
				cout << "Некорректное значение или количество очередей превышено!\n" << endl;
				system("pause");
			} else {
				index = choseNum-1;
				system("cls");
				cout << "Вы переключились на очередь №" << index+1 << endl;
				cout << "\n";
			}
			break;

		case 8:
			system("cls");
			cout << "Вы сейчас работаете с очередью №" << index+1 << endl;
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
	cout << "Введите колчество очередей: ";
	cin >> numOfq;
	system("cls");
	cout << "Выберите, с каким классом-наследником Вы будете работать: " << endl;

	while (flag == 1) {
		cout << "1 - Приватный" << endl;
		cout << "2 - Защищенный" << endl;
		cout << "3 - Публичный" << endl;
		cout << "0 - Выход из программы" << endl;
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
			cout << "Некорректный ввод!" << endl;
			break;
		}
	}
	return 0;
}