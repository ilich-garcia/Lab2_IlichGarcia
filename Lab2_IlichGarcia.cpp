#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

// Para ordenar el polinomio.
int getEvaluation(int, int);
// Para encontrar las soluciones.
void getSolutions(int, int, int);
// Para saber si se puede formar un triángulo.
void getTriangle(float, float, float);

int main() {
	int option; // Para ejecutar los ejercicios.
	int power, evaluation; // Grado y valor a evaluar del ejercicio 1.
	float first, second, third;
   int a, b, c; // Parámetros del ejercicio 3.

	do {
		cout << "1) Ordenar polinomio. \n2) Triángulo. \n3) Encontrar soluciones.\n4) Salir. \nOpción: ";
		cin >> option;

		if (option == 1) {
			int result;

			cout << "Ingrese grado principal del polinomio: ";
			cin >> power;
			cout << "Ingrese valor a evaluar: ";
			cin >> evaluation;

			result = getEvaluation(power + 1, evaluation);

			cout << "El resultado de evaluar " << evaluation << " en la función es: " << result << "\n" << endl;
		} else if (option == 2) {
			cout << "Ingrese valor de a: ";
         cin >> first;
         cout << "Ingrese valor de b: ";
         cin >> second;
         cout << "Ingrese valor de c: ";
         cin >> third;

			cout << "Se puede construir?: ";
			getTriangle(first, second, third);
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

int getEvaluation(int power, int evaluation) {
	string ascendant, descendant;
	int result = 0, coefficient, value;
	int values[power];
	std::stringstream myAscendant;
	std::stringstream myDescendant;

	value = power - 1;

	for (int i = 0; i < power; i++) { // Ingresando los valores al arreglo
		cout << "Ingrese coeficiente de x^" << value << ": ";
		cin >> coefficient;
		
		values[i] = coefficient;
		value--;
	}

	value = power - 1;

	for (int i = 0; i < power; i++) { // Para mostrar los valores descendentes.
		if (i == power - 1) {
			if (values[i] > 0) {
				myDescendant << "+" << values[i];
			} else {
	         myDescendant << values[i];
			}
      } else if (values[i]  == -1) {
         myDescendant << "-x^" << value;
      } else if (values[i] == 1) {
			myDescendant << "x^" << value;
		} else if (values[i] == 0) {
		} else if (i == 0) {
			myDescendant << values[i] << "x^" << value;
		} else {
			if (values[i] > 0) {
				myDescendant << "+" << values[i] << "x^" << value;
			} else {
				myDescendant << values[i] << "x^" << value;
			}
		}

		value--;
	}

	descendant = myDescendant.str();
	value = 0;

	for (int i = 0; i < power; i++) { // Para mostrar los valores ascendentes.
      if (i == 0) {
         myAscendant << values[i];
      } else if (values[i] == -1) {
         myAscendant << "-x^" << value;
      } else if (values[i] == 1) {
			myAscendant << "x^" << value;
		} else if (values[i] == 0) {
		} else {
         if (values[i] > 0) {
            myAscendant << "+" << values[i] << "x^" << value;
         } else {
            myAscendant << values[i] << "x^" << value;
         }
      }


		value++;
	}

	ascendant = myAscendant.str();
	value = power - 1;

	for (int i = 0; i < power; i++) { // Para evaluar en f(x).
		if (value > 0) {
			result += pow(evaluation, value) * values[i];
		} else {
			result += values[i];
		}

		value--;
	}

	cout << "Ascendente: " << ascendant << endl; // Imprimiendo la función ascendente.
	cout << "Descendente: " << descendant << "\n" << endl; // Imprimiendo la función descendente.

	return result;
}

void getTriangle(float first, float second, float third) {
	bool canGet = false;

	if (first + second > third	&& first + third > second && second + third > first) {
		canGet = true;
	}

	if (canGet) {
		cout << "Sí!!\n" << endl;
	} else {
		cout << "Neles pasteles!!\n" << endl;
	}
}

void getSolutions(int a, int b, int c) {
	float determinant, solution1, solution2;

	determinant = (b * b) - 4 * a * c;
	
	if (determinant == 0) {
		cout << "Solución única: x = 0";
	} else if (determinant < 0) {
		cout << "No tiene soluciones en los Reales... Use la imaginación";
	} else {
		solution1 = float((-b + sqrt(determinant)) / (2 * a));
		solution2 = float((-b - sqrt(determinant)) / (2 * a));

		cout << "Soluciones: x1 = " << solution1 << ", x2 = " << solution2 << endl;
	}
}
