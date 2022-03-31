/*
 * main.cpp
 *
 */

//
// Programa principal

// C++ headers
#include <iostream>
#include <fstream>
#include <cstdlib> // EXIT_SUCCESS
using namespace std;

// Llista de includes a afegir
#include "repte030a.h"

int
main(int argc, char const *argv[])
{
	ofstream fitxer;


	fitxer.open("repte030a.txt");
	Repte030a(cout);
	Repte030a(fitxer);
	fitxer.close();

    return EXIT_SUCCESS;
}
