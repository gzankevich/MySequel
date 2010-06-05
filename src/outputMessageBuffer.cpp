#include "outputMessageBuffer.h"

QueryOutputMessage::QueryOutputMessage(std::string message, QueryOutputMessage::Type type)
{
	this->message = message;
	this->type = type;
}

QueryOutputMessage::~QueryOutputMessage()
{

}

std::string QueryOutputMessage::getMessage()
{
	return this->message;
}

QueryOutputMessage::Type QueryOutputMessage::getType()
{
	return this->type;
}
