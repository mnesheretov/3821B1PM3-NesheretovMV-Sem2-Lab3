#include <iostream>
#include "String.h"

using namespace std;

int main() {

	char* s1 = nullptr;

	String a("Hello");
	String b = a;
	String c;

	cout << a + b << endl;

	cout << a.FindSymbol('l') << endl;

	b.SetConstString("vet");
	s1 = b.GetString();

	c.SetConstString("Privet. Privet.Privet");

	cout << c.FindWord(s1) << endl;

	c.SplitWord('.');

}