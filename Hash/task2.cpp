#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

ifstream in("employees.txt");

struct date { // ��������� ����
	int d, m, y; 
};

struct employer { // ��������� ���������
	string surn, work;
	date dob;
	int exp, sal;	
};

bool operator == (date a, date b) {
	if (a.d == b.d && a.m == b.m && a.y == b.y)
		return true;
	return false;
}

bool operator == (employer a, employer b) {
	if ((a.dob == b.dob) && (a.exp == b.exp) && (a.sal = b.sal) && (a.surn == b.surn) && (a.work == b.work))
		return true;

	return false;
}

void print(date b) {
	cout << b.d << "." << b.m << "." << b.y << " ";
}

void print(employer a) {
	cout << a.surn << " " << a.work << " "; print(a.dob); cout << a.exp << " " << a.sal; // ������� ������ ���������� � ���������� � ���� �� �����
}

date StrToDate(string abc) { // �������, ����������� ������ � ����
	date chislo;
	int dd, mm, yyyy;
	chislo.d = 0;
	chislo.m = 0;
	chislo.y = 0;
	if (abc.size() != 10) {
		cout << "Incorrect input" << endl;
	}
	else {
		dd = stoi(abc.substr(0, 2));
		mm = stoi(abc.substr(3, 2));
		yyyy = stoi(abc.substr(6, 4));
		chislo.d = dd;
		chislo.m = mm;
		chislo.y = yyyy;
	}
	return chislo;
}

employer InputInfo() {  // ���� ���������� � ����������
  employer chel;
  cout << "Enter surname: ";
  cin >> chel.surn;
  cout << "Enter position: ";
  cin >> chel.work;
  cout << "Enter date of birth (dd.mm.yyyy): ";
  string date_str;
  cin >> date_str;
  chel.dob = StrToDate(date_str);
  cout << "Enter experience: ";
  cin >> chel.exp;
  cout << "Enter salary: ";
  cin >> chel.sal;
  return chel;
}

employer GetInfo(string rab) {	// ������� ��������� ���������� � ���������� �� ������
	employer chel;
	int spc, c;
	c = 0;
	while (rab.size() > 0) {
		string t = rab.substr(0, rab.find_first_of(' '));
		rab.erase(0, rab.find_first_of(' ') + 1);
		if (c == 0) chel.surn = t;
		if (c == 1) chel.work = t;
		if (c == 2) chel.dob = StrToDate(t);
		if (c == 3) chel.exp = stoi(t);
		if (c == 4) {
			chel.sal = stoi(t);
			break;
		}
		c++;
	}
	return chel;
}

int help_h(int s) {	// ������� ��������� ���������������� ���� ������� ���������
	float s_frac = s * 0.61803;
	int integ = int(s_frac);
	float frac = s_frac - integ;
	frac *= 32;
	return int(frac);
}

int lin_h(int h_s, int i) {
  return ((h_s + i) % 32); // ����� ������� �� ������� ����� ���������������� ���� � ������ ���� �� ������ ���-�������
}

void create(vector <employer> a, vector<employer> &table) {
  table.resize(32);
  for (int i = 0; i < a.size(); i++) {
    int k = help_h(a[i].dob.y); // ����� ��������������� ��� �� ���� ��������
    int j = 0;
    while (true) {
      int p = lin_h(k, j); // ������� �������� ��� ��� ������� �������� � ����� ����
      if (table[p].exp == 0) { // ���� ������ ������, �� ������� �������
        table[p] = a[i];
        break;
      }
      else
        j++; // ����� ������������ ������ �� �������
    }
  }
}

void find_el_on_hash(int x, vector<employer> table) {
  int k = help_h(x); // ������� ��������������� ��� ��� �������� ��������
  int j = 0;
  while (true) {
    int p = lin_h(k, j); // ������� �������� ��� ��� ������� �������� � ����� ����
    if (table[p].dob.y == x) { // ���� ������ �������� ������� ��������, ������� ���������� � ���������
      cout << "Information about the employee: "; print(table[p]);
      cout << endl;
      break;
    }
    else if (table[p].exp == 0) { // ���� ������ ������, �� �������� �������� � ������� ���
      cout << "No such element";
      break;
    }
    else
      j++; // ����� ������������ ������ �� �������
  }
}

int main() {
	vector<employer> tab;
	vector<employer> people;
	people.resize(20);
	for (int i = 0; i < 20; i++) {
		string a;
		getline(in, a);
		employer chel = GetInfo(a);
		people[i] = chel;
	} // ������� ������ ����������
	create(people, tab); // ������� ���-������� ����������
	for (int i = 0; i <tab.size(); i++) {
		cout<<" "<< i << ": "; print(tab[i]);
		cout << endl;
	}
	cout << endl;
	int e;
    cout << "Enter the new employee";
    cout << endl;
    employer new_emp = InputInfo();
    int k = help_h(new_emp.dob.y); //����� ��������������� ��� �� ���� ��������
    int j = 0;
    while (true) {
      int p = lin_h(k, j); //������� �������� ��� ��� ������� �������� � ����� ����
      if (tab[p].exp == 0) { // ���� ������ ������, �� ������� �������
        tab[p] = new_emp;
        break;
      }
      else
        j++; //����� ������������ ������ �� �������
    }

	cout << "Enter the birth year of the employee: ";
	cin >> e;
	find_el_on_hash(e, tab);
}