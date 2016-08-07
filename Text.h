#pragma once
#include <iostream>
#define N 100
using namespace std;

class Text
{
	char text[N];
	int factor;
public:
	Text();
	Text(char *t, int f);
	~Text();
	void validate();
	void validate(char *t, int f);
	void encode();
	void decode();
};

