#include <iostream>
#include "./includes/Serializer.hpp"

int main() {
	{
		std::cout << "----normal test----" << std::endl;
		Data *data = new Data;
		data->id = 42;
		data->name = "John Doe";
		std::cout << "Data id: " << data->id << std::endl;
		std::cout << "Data name: " << data->name << std::endl;
		uintptr_t raw = Serializer::serialize(data);
		std::cout << "Serialized data: " << raw << std::endl;
		Data *deserializedData = Serializer::deserialize(raw);
		std::cout << "Deserialized data id: " << deserializedData->id << std::endl;
		std::cout << "Deserialized data name: " << deserializedData->name << std::endl;
		delete data;
	}
	{
		std::cout << "----null test----" << std::endl;
		Data *data = NULL;
		std::cout << "Origin: " << data << std::endl;
		uintptr_t raw = Serializer::serialize(data);
		std::cout << "Serialized: " << raw << std::endl;
		Data *deserializedData = Serializer::deserialize(raw);
		std::cout << "Deserialized: " << deserializedData << std::endl;
	}
	return (0);
}