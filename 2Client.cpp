#include "Client.h"

Client::Client(int code, string name)
{
	this->name = name;
	this->code = code;
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