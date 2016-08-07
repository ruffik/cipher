#include "Text.h"

Text::Text()
{
	try {
		validate();
		encode();
		decode();
	}
	catch (char *err) {
		cout << this << " exception: " << err;
	}

}

Text::Text(char* t, int f)
{
	try {
		validate(t, f);
		encode();
		decode();
	}
	catch (char *err) {
		cout << this << " exception: " << err;
	}
}

void Text::validate() {

	cout <<"input text to encode (max "<<N<<" chars): ";
	cin.getline(text, N);
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw "wrong input of text\n";
	}

	cout <<"input encoding factor (integer): ";
	cin >> factor;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw "wrong input of factor\n";
	}

	if (strlen(text) == 0) {
		throw "no text\n";
	}

	if (factor < 0) {
		throw "factor can not be smaller than 0!\n";
	}
}

void Text::validate(char *t, int f) {

	if (strlen(t) == 0 || strlen(t) > N) {
		throw "no text\n";
	}
	else
		strcpy_s(text, t);

	if (f < 0) {
		throw "factor can not be smaller than 0!\n";
	}
	else
		factor = f;
}

Text::~Text() {}

void Text::encode() {
	cout << "text to encode -> " << text << endl;
	for (int i = 0; i <= (strlen(text) - 1); i++)
		text[i] = (text[i] + factor) % 255;
	cout <<"encoded text -> " << text << endl;
}

void Text::decode() {
	for (int i = 0; i <= (strlen(text) - 1); i++)
		text[i] = (text[i] - factor) % 255;
	cout <<"decoded text -> " << text << endl;
}

