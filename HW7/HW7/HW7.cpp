// HW7.cpp 

#include "Students.pb.h"
#include <iostream>
#include <fstream>


const auto FILEPATH{ "./data.bin" };

using namespace Students;
using namespace std;

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    FullName SFullName;
    SFullName.set_surname("Syrodoeva");
    SFullName.set_name("Galina");
    SFullName.set_patronymic("Sergeevna");

    /*std::string Serialized = FullName.SerializeAsString();
    std::cout << Serialized << "\n";*/

    cout << "Student:\nSurname: " << SFullName.surname() << "\nName: " << SFullName.name() << "\nPatronymic: " << SFullName.patronymic() << "\n";

    ofstream out(FILEPATH, ios_base::binary);  //C:/Users/Tom/source/repos/GB3_Extra_CPP/HW7/
    SFullName.SerializeToOstream(&out);
}