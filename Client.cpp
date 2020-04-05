#include "Client.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

Client::Client(int code, string name)
{
	this->code = code;
	this->name = name;
}

Client::~Client()
{
	
}

int Client::GetCode()
{
	return code;
}

string Client::GetName()
{
	return name;
}


