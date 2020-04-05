#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Client
{
private:
	string name;
	int code;
public:
	Client(int, string);
	~Client();
	int GetCode();
	string GetName();
};

