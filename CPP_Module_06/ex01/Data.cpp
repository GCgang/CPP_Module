#include "Data.hpp"

Data::Data()
    : mProtocolVersion("HTTP/1.1")
    , mCommnadType("GET")
    , mPayload("Hello Serialization!")
    , mStatusCode(200)
{
}

Data::Data(std::string protocolVersion, std::string commandType, std::string payload, int statusCode)
    : mProtocolVersion(protocolVersion)
    , mCommnadType(commandType)
    , mPayload(payload)
    , mStatusCode(statusCode)
{
}

Data::Data(Data const& other)
    : mProtocolVersion(other.mProtocolVersion)
    , mCommnadType(other.mCommnadType)
    , mPayload(other.mPayload)
    , mStatusCode(other.mStatusCode)
{
}

Data& Data::operator=(Data const& other)
{
	if (this != &other)
	{
    	mProtocolVersion = other.mProtocolVersion;
    	mCommnadType = other.mCommnadType;
    	mPayload = other.mPayload;
    	mStatusCode = other.mStatusCode;
	}
	return (*this);
}

Data::~Data()
{ 
}

std::string Data::GetProtocolVersion() const
{
    return (mProtocolVersion);
}

std::string Data::GetCommandType() const
{
    return (mCommnadType);
}

std::string Data::GetPayload() const
{
    return (mPayload);
}

int Data::GetStatusCode() const
{
    return (mStatusCode);
}

void Data::PrintData() const
{
    std::cout << "Protocol Version: " << mProtocolVersion << std::endl;
    std::cout << "Command Type: " << mCommnadType << std::endl;
    std::cout << "Payload: " << mPayload << std::endl;
    std::cout << "Status Code: " << mStatusCode << std::endl;
}
