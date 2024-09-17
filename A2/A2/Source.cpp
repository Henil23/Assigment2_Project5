#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct STUDENT_DATA {
    std::string first_name;
    std::string last_name;
};
int main() {
    std::ifstream file("StudentData.txt");
    std::vector<STUDENT_DATA> student_list;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    // Read each line from the file
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string first_name, last_name;

        // Parse the first and last name, assuming they are separated by a comma
        if (std::getline(ss, first_name, ',') && std::getline(ss, last_name)) {
            STUDENT_DATA student = { last_name, first_name };
            student_list.push_back(student); // Add the student to the vector
        }
    }

    file.close();

    // Output the student data for confirmation
    for (const auto& student : student_list) {
        std::cout << "First Name:  "<< student.first_name << "  " << " Last Name: " << student.last_name << std::endl;
    }

    return 0;
}
