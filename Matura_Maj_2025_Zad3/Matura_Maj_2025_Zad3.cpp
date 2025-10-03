
#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <cmath>

using namespace std; 

ifstream fin("dron_przyklad.txt");

int main()
{
	cout << "Zad.3.1\n";
	int a,b; 
	while (fin>>a>>b ) // automatycznie czyta dwie liczby z linii
		if (gcd (abs(a),abs(b))>1)
		cout << a << ";" << b << endl;

	



}

