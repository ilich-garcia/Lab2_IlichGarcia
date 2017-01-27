#include <iostream>
#include <cmath>

using namespace std;

// Para encontrar las soluciones 

void getSolutions(int, int, int);

int main() {
	int a, b, c, option;

	do {
		cout << "1) Ordenar polinomio. \n2) Triángulo. \n3) Encontrar soluciones.\nEjercicio a ejecutar: ";
		cin >> option;

		if (option == 1) {
		} else if (option == 2) {
		} else if (option == 3) {
			cout << "Ingrese valor de a: ";
		 	cin >> a;
			cout << "Ingrese valor de b: ";
         cin >> b;
			cout << "Ingrese valor de c: ";
         cin >> c;

			getSolutions(a, b, c);
		}
	} while (option != 4);

	return 0;
}

void getSolutions(int a, int b, int c) {
	float determinant, solution1, solution2;

	determinant = (b * b) - 4 * a * c;
	
	if (determinant == 0) {
		cout << "Solución única: x = 0";
	} else if (determinant < 0) {
		cout << "No tiene soluciones en los Reales... Use la imaginación";
	} else {
		solution1 = (-b + sqrt(determinant)) / 2;
		solution2 = (-b - sqrt(determinant)) / 2;

		cout << "Soluciones: x1 = " << solution1 << ", x2 = " << solution2 << endl;
	}
}
