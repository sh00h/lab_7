#include <iostream>
#include <ctime>
using namespace std;


int hashTableIndex;// ������ � ���-�������
int* hashTable;// ���-�������
bool* used; // ������ ������������ ��������
int sizeEl;// ���-�� ���������
int tableSize; // ������ �������

// ���-�������
int func(int value) {
	return (value % tableSize);
}


void vivod()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (used[i])
		{
			cout << "[" << i << "] = " << hashTable[i] << endl;
		}
		else
		{
			cout << "[" << i << "] = " << endl;
		}
	}

}
// ���� ����� ���� �������� � ��������� �������� � �������
bool pushEl(int value) {
	int ind = func(value);
	int i = 1;
	while (used[ind] && hashTable[ind] != value)
	{
		if (hashTable[ind] == value) return false;
		ind = func(value) + i;
		i++;
	}
	if (!used[ind]) {
		used[ind] = true;
		hashTable[ind] = value;
		return true;
	}
	return false;
	//cout << ind << " " << value << endl;
}

// ������� ������
int findEl(int value) {
	int ind = func(value);
	int i = 1;
	while (used[ind] && hashTable[ind] != value)
	{
		ind = func(value) + i;
		i++;
	}
	if (used[ind] && hashTable[ind] == value)
	{
		return ind;
	}
	else return -1;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "�������� �����: \n" <<
		"1 - ��������� ������ ��������������\n"
		"2 - ��������� ������ ���������� �������\n";

	int choise;
	int t1, t2, t3, t4;
	cin >> choise;
	if (choise == 1)
	{
		cout << "������� ���������� ���������: ";
		cin >> sizeEl;
		cout << "������� ������ ���-�������: ";
		cin >> tableSize;
		if (sizeEl > tableSize)
		{
			cout << "��������� ������ ��� ������ ���-�������!\n";
			system("pause");
			return 0;
		}
		hashTable = new int[tableSize];
		used = new bool[tableSize];
		for (int i = 0; i < tableSize; i++) {
			hashTable[i] = 0;
			used[i] = false;
		}
		cout << "������� ��������: " << endl;
		int el;
		for (int i = 0; i < sizeEl; i++)
		{
			cin >> el;
			pushEl(el);
		}
	}
	else if (choise == 2)
	{
		cout << "������� ���������� ���������: ";
		cin >> sizeEl;
		cout << "������� ������ ���-�������: ";
		cin >> tableSize;
		if (sizeEl > tableSize)
		{
			cout << "��������� ������ ��� ������ ���-�������!\n";
			system("pause");
			return 0;
		}
		hashTable = new int[tableSize];
		used = new bool[tableSize];
		for (int i = 0; i < tableSize; i++) {
			hashTable[i] = 0;
			used[i] = false;
		}
		cout << "������: \n";
		int m;
		int* temp = new int[sizeEl];
		for (int i = 0; i < sizeEl; i++)
		{
			//if (i == 0) t1 = clock();
			m = rand();
			pushEl(m);
			temp[i] = m;
			//if (i == 100) t2 = clock();
			//if (i == sizeEl - 100) t3 = clock();
			//if (i == sizeEl - 1) t4 = clock();
			cout << m << " ";
		}
		cout << endl;
		/*t1 = clock();
		for (int i = 0; i < sizeEl; i++)
		{
			findEl(temp[i]);
		}
		t2 = clock();
		cout << endl << "time " << t2 - t1 << endl;*/
		//cout << "first 100: " << (double)(t2 - t1) << " , last 100: " << t4 - t3 << " ,  " << t4 - t1 << endl;

	}
	else {
		system("pause");
		return 0;
	}

	while (true)
	{
		cout << "�������� �����: \n" <<
			"1 - ����� ��������\n"
			"2 - �������� �������\n"
			"3 - ����� �������\n";
		cin >> choise;
		if (choise == 1)
		{
			int ser;
			cout << "������� ������� \n";
			cin >> ser;
			int k = findEl(ser);
			if (k != -1)
			{
				cout << "����� ������� ���������� � �������\n��� ������: " << k << endl;
			}
			else cout << "������ �������� �� ����������\n";

		}
		else if (choise == 2)
		{
			if (sizeEl >= tableSize)
			{
				cout << "������� ���������!\n";
			}
			else
			{
				int ser;
				cout << "������� ������� \n";
				cin >> ser;
				if (pushEl(ser)) {
					sizeEl++;
					cout << "������� ��������!\n";
				}
				else
				{
					cout << "������� �� ��������!\n";
				}
			}
		}
		else if (choise == 3)
		{
			vivod();
		}
	}

	system("pause");
	return 0;
}
