#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data;
    data.name = "John";
    data.age = 30;
    data.next = NULL;

    // Print the original data
    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Next: " << data.next << std::endl;

    // Create a Serializer object
    Serializer serializer;

    // Serialize the Data object
    uintptr_t serializedData = serializer.serialize(&data);

    // Print the serialized data
    std::cout << "Serialized Data: " << serializedData << std::endl;

    // Unserialize the serialized data
    Data *unserializedData = serializer.unserialize(serializedData);

    // Print the unserialized data
    std::cout << "Unserialized Data:" << std::endl;
    std::cout << "Name: " << unserializedData->name << std::endl;
    std::cout << "Age: " << unserializedData->age << std::endl;
    std::cout << "Next: " << unserializedData->next << std::endl;

    // Free the memory allocated for the unserialized data
    delete unserializedData;

    return 0;
}