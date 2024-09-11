#include "Serializer.hpp"
#include  "Data.hpp"

// void leaks(void)
// {
// 	system("leaks Reinterpret_Cast");
// }

int main()
{
	// atexit(leaks);

    Data* afterData = new Data("HTTP/1.1", "GET", "Hello CPP06", 200);

    uintptr_t serializedData = Serializer::Serialize(afterData);
    Data* deserializedData = Serializer::Deserialize(serializedData);

    afterData->PrintData();
	std::cout << std::endl;

    deserializedData->PrintData();
	std::cout << std::endl;


	std::cout << "Original pointer address: " << afterData << std::endl;
	std::cout << "Serialized pointer address: " << reinterpret_cast<void*>(serializedData) << std::endl;
	std::cout << "deserializedData pointer address: " << deserializedData << std::endl;
	std::cout << std::endl;

    delete(afterData);
    return (0);
}