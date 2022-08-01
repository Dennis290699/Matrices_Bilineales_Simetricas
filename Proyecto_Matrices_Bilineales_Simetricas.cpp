#include <iostream>
using namespace std;

void GuardarValoresMatriz(float Matriz[100][100], int N);
void VerValoresMatriz(float Matriz[100][100], int N, int nivel);

int QueTipoCaso(float Matriz[100][100], int N);
void MultiplicarMatrices(float Matriz1[100][100], float Matriz2[100][100], float Resultado[100][100], int N, int nivel);
void Metodo1(float Matriz[100][100], int N, int nivel);

void Metodo2(float Matriz[100][100], int N, int aii);
// cuando el elememento
int main()
{
	int N;
	string Respuesta;

	float Matriz[100][100];

	do
	{

		int TipoCaso = 0;
		int Nivel = 1;

		int aii = 0;
		cout << endl
			 << endl
			 << "Ingresa el tamaño de la matriz: ";
		cin >> N;
		do // ingresar valores de matriz
		{
			GuardarValoresMatriz(Matriz, N);
			VerValoresMatriz(Matriz, N, 1);

			cout << endl
				 << "Los valores son correctos? (si/no): ";
			cin >> Respuesta;

		} while (Respuesta == "no");

		TipoCaso = QueTipoCaso(Matriz, N);

		switch (TipoCaso)
		{
		case 1:
			cout << endl
				 << "... Caso 1 ..." << endl;
			while (Nivel <= N - 1)
			{

				Metodo1(Matriz, N, Nivel);
				cout << endl
					 << "*******************" << endl;
				Nivel++;
			}
			cout << endl
				 << "D=" << endl;
			for (int i = 1; i <= Nivel; i++)
			{
				for (int j = 1; j <= Nivel; j++)
				{
					if (i == j)
					{
						cout << Matriz[i][i] << "\t";
					}
					else
					{
						cout << "\t";
					}
				}
				cout << endl;
			}

			break;
		case 2:
			cout << endl
				 << "... Caso 2 ..." << endl;
			Nivel = 2;
			while (Nivel <= N - 1)
			{
				cout << "AQUI";
				Metodo1(Matriz, N, Nivel);
				cout << endl
					 << "*******************" << endl;
				Nivel++;
			}
			cout << endl
				 << "D=" << endl;
			for (int i = 1; i <= Nivel; i++)
			{
				for (int j = 1; j <= Nivel; j++)
				{
					if (i == j)
					{
						cout << Matriz[i][i] << "\t";
					}
					else
					{
						cout << "\t";
					}
				}
				cout << endl;
			}
			break;
		case 3:
			cout << endl
				 << "... Caso 3  ..." << endl;
			for (int j = 1; j <= N; j++) // para recuperar el primero que valga algo diferente a cero
			{
				if (Matriz[1][j] != 0)
				{
					aii = j;
					break;
				}
			}

			// aqui hay dos ecenarios, o que valga diferente de cero aii o que valga cero:
			if (aii != 0) // diferente de cero
			{
				// Edito la matriz, colocamos 1 a las esquinas aii y las otrras esquinas ceros
				cout << endl
					 << "Con Diferente de Cero en aii" << endl;

				// Mando llamar el metodo 2
				Metodo2(Matriz, N, aii);

				cout << endl
					 << "D=" << endl;
				for (int i = 1; i <= Nivel; i++)
				{
					for (int j = 1; j <= Nivel; j++)
					{
						if (i == j)
						{
							cout << Matriz[i][i] << "\t";
						}
						else
						{
							cout << "\t";
						}
					}
					cout << endl;
				}
			}
			else // igual a cero
			{
				cout << endl
					 << "aii igual a Cero" << endl;
			}

			break;
		}
		cout << endl
			 << endl
			 << "Desea volver a ejecutar el programa? si/no: ";
		cin >> Respuesta;
	} while (Respuesta == "si");
	return 0;
}

void GuardarValoresMatriz(float Matriz[100][100], int N)
{
	cout << endl
		 << "Ingresa los valores para la matriz: " << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << "Ingresa el valor para Matriz[" << i << "][" << j << "]: ";
			cin >> Matriz[i][j];
		}
	}
}
void VerValoresMatriz(float Matriz[100][100], int N, int nivel)
{
	// cout<<endl<<"Valores de la matriz: "<<endl;
	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			cout << Matriz[i][j] << "\t";
		}
		cout << endl;
	}
}

int QueTipoCaso(float Matriz[100][100], int N)
{
	int Respuesta;
	float Suma = 0;
	// sacar la suma de la primera fila y de la primera columna para saber si es el caso 2
	for (int i = 1; i <= N; i++)
	{
		Suma = Suma + Matriz[i][1];
	}
	for (int j = 1; j <= N; j++)
	{
		Suma = Suma + Matriz[1][j];
	}
	cout << "--" << Suma << "--";
	if (Matriz[1][1] != 0)
	{
		Respuesta = 1;
	}
	else if (Suma == 0)
	{
		Respuesta = 2;
	}
	else if (Matriz[1][1] == 0)
	{

		Respuesta = 3;
	}

	return Respuesta;
}

void Metodo1(float Matriz[100][100], int N, int nivel)
{
	float C[100][100];	// nueva matriz C
	float Ct[100][100]; // matriz C transpuesta
	float ResultadoMultiplicarCporCt[100][100];
	float ResultadoFinal[100][100];
	// colocar puros ceros
	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			C[i][j] = 0;
			Ct[i][j] = 0;
		}
	}

	// colocar 1 en la diagonal en la matriz C
	for (int i = nivel; i <= N; i++)
	{
		for (int j = i; j <= i; j++)
		{
			C[i][j] = 1;
		}
	}

	// calcular la primera fila de C
	for (int j = nivel + 1; j <= N; j++)
	{
		C[nivel][j] = Matriz[nivel][j] / Matriz[nivel][nivel];
		// cambiar signo
		C[nivel][j] = C[nivel][j] * -1;
	}
	// transpuesta de C
	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			Ct[i][j] = C[j][i];
		}
	}

	// Multiplicacion de Original, C y C transpuesta

	cout << endl
		 << "Matriz C: " << endl;
	VerValoresMatriz(C, N, nivel);
	cout << endl
		 << "Matriz C Transpuesta: " << endl;
	VerValoresMatriz(Ct, N, nivel);

	cout << endl
		 << "Matriz Original: " << endl;
	VerValoresMatriz(Matriz, N, nivel);

	cout << endl
		 << "Matriz Resultado de Matriz Original Por  C : " << endl;
	MultiplicarMatrices(Matriz, C, ResultadoMultiplicarCporCt, N, nivel);
	VerValoresMatriz(ResultadoMultiplicarCporCt, N, nivel);

	cout << endl
		 << "Matriz Resultado de multiplicar Ct por resultado Anterior: " << endl;
	MultiplicarMatrices(Ct, ResultadoMultiplicarCporCt, ResultadoFinal, N, nivel);
	VerValoresMatriz(ResultadoFinal, N, nivel);

	// mardar valores de resultado final a la matriz

	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			Matriz[i][j] = ResultadoFinal[i][j];
		}
	}
}

void Metodo2(float Matriz[100][100], int N, int aii)
{
	int nivel = 1;
	float C[100][100];	// nueva matriz C
	float Ct[100][100]; // matriz C transpuesta
	float ResultadoMultiplicar1[100][100];
	float ResultadoMultiplicar2[100][100];
	float P[100][100];
	// colocar puros ceros
	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			C[i][j] = 0;
			Ct[i][j] = 0;
			P[i][j] = 0;
		}
	}

	// le coloco a P

	// colocar 1 en la diagonal en la matriz C y P
	for (int i = nivel; i <= N; i++)
	{
		for (int j = i; j <= i; j++)
		{
			C[i][j] = 1;
			P[i][j] = 1;
		}
	}

	P[1][1] = 0;
	P[1][aii] = 1;
	P[aii][1] = 1;
	P[aii][aii] = 0;

	cout << "Matriz P:" << endl;
	VerValoresMatriz(P, N, 1);

	// Multiplicacion de Original, P y P

	cout << endl
		 << "Matriz Original: " << endl;
	VerValoresMatriz(Matriz, N, nivel);

	cout << endl
		 << "Matriz  Original Por  P : " << endl;
	MultiplicarMatrices(Matriz, P, ResultadoMultiplicar1, N, nivel);
	VerValoresMatriz(ResultadoMultiplicar1, N, nivel);

	cout << endl
		 << "Matriz Resultado de multiplicar P por resultado Anterior: " << endl;
	MultiplicarMatrices(P, ResultadoMultiplicar1, ResultadoMultiplicar2, N, nivel);
	VerValoresMatriz(ResultadoMultiplicar2, N, nivel);

	// mardar valores de resultado final a la matriz

	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			Matriz[i][j] = ResultadoMultiplicar2[i][j];
		}
	}
}

void MultiplicarMatrices(float Matriz1[100][100], float Matriz2[100][100], float Resultado[100][100], int N, int nivel)
{
	float Suma = 0;
	for (int i = nivel; i <= N; i++)
	{
		for (int j = nivel; j <= N; j++)
		{
			Suma = 0;
			for (int ii = nivel; ii <= N; ii++)
			{

				Suma = Suma + (Matriz1[i][ii] * Matriz2[ii][j]);
			}
			Resultado[i][j] = Suma;
		}
	}
}
