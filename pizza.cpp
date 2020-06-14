#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> pizzas;
int main() {
	cout << "ciao" << endl;
	fstream in, out;
	in.open("./a_example.in", ios::in);
	out.open("out.txt", ios::out);
	int max_slice = 0;

	int numb_of_pizzas = 0;

	in >> max_slice;
	in >> numb_of_pizzas;

	int pizza = 0;
	while (in >> pizza) {
		pizzas.push_back(pizza);
	}

	int mat[max_slice + 1][pizzas.size() + 1];

	for (int j = 0; j < pizzas.size() + 1; j++) {
		mat[0][j] = 0;
	}
	for (int j = 0; j < max_slice + 1; j++) {
		mat[j][0] = 0;
	}

	for (int i = 1; i < max_slice + 1; i++) {
		for (int j = 1; j < pizzas.size() + 1; j++) {
			if (pizzas[i - 1] <= j) {
				mat[i][j] = max(mat[i - 1][j - pizzas[i - 1]] + pizzas[i - 1],
								mat[i - 1][j]);
			} else {
				mat[i][j] = mat[i - 1][j];
			}
		}
	}
	cout << mat[max_slice - 1][pizzas.size() - 1] << endl;

	return 0;
}
