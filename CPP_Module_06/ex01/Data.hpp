#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
    public:
        Data();
        Data(std::string protocolVersion, std::string commandType, std::string payload, int statusCode);
        Data(Data const& other);
        Data& operator=(Data const& other);
        ~Data();

        std::string GetProtocolVersion() const;
        std::string GetCommandType() const;
        std::string GetPayload() const;
        int GetStatusCode() const;
        void PrintData() const;
    private:
        std::string mProtocolVersion;
        std::string mCommnadType;
        std::string mPayload;
        int mStatusCode;
};

#endif