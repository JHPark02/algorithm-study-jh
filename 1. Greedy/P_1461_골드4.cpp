#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

// �����ּ� : https://www.acmicpc.net/problem/1461
// �޸�, ����ð� : 2080KB, 0ms

int main(){
	// å ����
	int N;
	// �ѹ��� �� �� å ����
	int M;
	cin >> N >> M;
	cin.ignore();

	string coordinates;
	getline(cin, coordinates);

	stringstream sstream(coordinates);
	vector<int> books_n;
	vector<int> books_a;
	string coordinate;

	while (getline(sstream, coordinate, ' ')) {
		int temp = stoi(coordinate);

		if (temp < 0)
			books_n.push_back(abs(temp));
		else
			books_a.push_back(abs(temp));
	}

	if (books_n.size() == 0)
		books_n.push_back(0);
	if (books_a.size() == 0)
		books_a.push_back(0);

	sort(books_n.begin(), books_n.end());
	sort(books_a.begin(), books_a.end());

	int result = 0;
	int removed = 0;


	int tempn = books_n.back();
	int tempa = books_a.back();
	
	if (tempn >= tempa) {
		result += books_n.back();
		while (removed < M && books_n.size() > 0) {
			books_n.erase(books_n.end() - 1);
			removed++;
		}
	}
	else {
		result += books_a.back();
		while (removed < M && books_a.size() > 0) {
			books_a.erase(books_a.end() - 1);
			removed++;
		}
	}

	removed = 0;

	while (books_n.size() > 0 && books_a.size() > 0) {;
		if (books_n.back() >= books_a.back()) {
			result += (books_n.back() * 2);
			while (removed < M && books_n.size() > 0) {
				books_n.erase(books_n.end() - 1);
				removed++;
			}
		}
		else {
			result += (books_a.back() * 2);
			while (removed < M && books_a.size() > 0) {
				books_a.erase(books_a.end() - 1);
				removed++;
			}
		}
		removed = 0;
	}

	while (books_n.size() > 0) {
		result += (books_n.back() * 2);
		while (removed < M && books_n.size() > 0) {
			books_n.erase(books_n.end() - 1);
			removed++;
		}
		removed = 0;
	}

	while (books_a.size() > 0) {
		result += (books_a.back() * 2);
		while (removed < M && books_a.size() > 0) {
			books_a.erase(books_a.end() - 1);
			removed++;
		}
		removed = 0;
	}

	cout << result;

	return 0;
}