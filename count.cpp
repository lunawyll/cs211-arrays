#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/* count digits, white space, others */

/* TODO: (1) fix all errors; 
 *       (2) add code for painting histogram in console,
 *           cf. picture in https://en.wikipedia.org/wiki/Histogram
 * 
 */

void print_diagramm(const int * dig, int white, int other){
	int mx = max(*max_element(dig, dig + 10), max(white, other));
	int pr[12];
	for (int i = 0; i < 10; i++)
		pr[i] = mx - dig[i];
	pr[10] = mx - white;
	pr[11] = mx - other;
	for (int i = mx; i > 0; --i){
		
		for (int j = 0; j < 12; j++){
			cout << (pr[j]-- ? ' ' : '*') << ' ';
			pr[j] = max(pr[j], 0);
		}
		cout << endl;
	}
	for (int i = 0; i < 10; i++)
		cout << i << ' ';
	cout << "w o\n";
}

int main()
{
	string src("12 plus 45 minus 39 is 18\n");
	int i = 0, nwhite, nother;
	const int size = 10;
	int ndigit[size]{0};
	nwhite = nother = 0;

	char c;
	while ((c = src[i++]) != '\0')
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	
	cout << "source string: " << src << endl << "digits =";
	for (int i = 0; i < size; ++i)
		cout << " " << ndigit[i];
	
	cout << ", white space = " << nwhite 
		 << ", other = " << nother << endl;
	print_diagramm(ndigit, nwhite, nother);
}
