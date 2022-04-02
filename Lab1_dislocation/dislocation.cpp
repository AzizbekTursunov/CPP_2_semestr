#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void move_dislocation(int dislocation[][3], int &size_of_crystal, int &n) {
	auto copyparticles = dislocation;
	for (int i = 0; i != n; i++) {
		int way = rand() % 4;
		int subway = way / 2;
		int p = dislocation[i][way % 2];
		p += pow(-1, subway) * dislocation[i][2];
		if (p < 0) {
			p = p + 2;
		}
		if (p > size_of_crystal) {
			p = p - 2;
		}
		dislocation[i][way % 2] = p;
	}
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			if (i != j && dislocation[i][0] == dislocation[j][0] && dislocation[i][1] == dislocation[j][1]) {
				dislocation[i][0] = copyparticles[i][0];
				dislocation[i][1] = copyparticles[i][1];
			}
		}
	}
}
void stand(int dislocation[][3], int &size_of_crystal, int &n) {
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			if (i != j && abs(dislocation[i][0] - dislocation[j][0]) + abs(dislocation[i][1] - dislocation[j][1]) <= 1) {
				dislocation[i][2] = 0;
				dislocation[j][2] = 0;
			}
		}
		if (dislocation[i][0] == 0 && dislocation[i][1] == 0) {
			dislocation[i][2] = 0;
		}
		if (dislocation[i][0] == 0 && dislocation[i][1] == size_of_crystal) {
			dislocation[i][2] = 0;
		}
		if (dislocation[i][0] == size_of_crystal && dislocation[i][1] == 0) {
			dislocation[i][2] = 0;
		}
		if (dislocation[i][0] == size_of_crystal && dislocation[i][1] == size_of_crystal) {
			dislocation[i][2] = 0;
		}
	}
}

void check(int dislocation[][3], bool &life, int &n) {
	int r = 0;
	for (int i = 0; i != n; i++) {
		r += dislocation[i][2];
	}
	if (r == 0) {
		life =  false;
	}
	else {
		life = true;
	}
}

int main() {
	srand(time(0));
	int size_of_crystal = 20;
	int n = 3;
	const int const_for_arr = 3;
	int x_coord = 0;
	int y_coord = 0;
	int dislocation[const_for_arr][3] = { x_coord, y_coord, 1 };
	for (int i = 0; i < n; i++) {

		dislocation[i][0] = rand() % size_of_crystal;
		dislocation[i][1] = rand() % size_of_crystal;
	}
	bool life = true;
	int time = 0;
	while (life) {
		move_dislocation(dislocation, size_of_crystal, n);
		stand(dislocation, size_of_crystal, n);
		check(dislocation, life, n);
		time++;
	}
	cout << time;

	return 0;
}