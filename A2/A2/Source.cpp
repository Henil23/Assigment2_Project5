#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//#define PRE_RELEASE

 //Struct for student data
struct STUDENT_DATA {
    std::string first_name;
    std::string last_name;
    std::string email; // Added for pre-release email data
};

int main() {
    //Open the StudentData.txt file
    std::ifstream file("StudentData.txt");
    std::vector<STUDENT_DATA> student_list;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open StudentData.txt" << std::endl;
        return 1;
    }

    //Read each line from StudentData.txt
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string first_name, last_name;

        //Parse the first and last name, assuming they are separated by a comma
        if (std::getline(ss, first_name, ',') && std::getline(ss, last_name)) {
            STUDENT_DATA student = { last_name, first_name, "" };  // Leave email empty for now
            student_list.push_back(student);
        }
    }
    file.close();

    // Check if compiled with PRE_RELEASE to add email data
#ifdef PRE_RELEASE
    std::ifstream email_file("StudentData_Emails.txt");

    if (!email_file.is_open()) {
        std::cerr << "Unable to open StudentData_Emails.txt" << std::endl;
        return 1;
    }

    // Read each line from StudentData_Emails.txt and add emails to the corresponding students
    int index = 0;
    while (std::getline(email_file, line) && index < student_list.size()) {
        student_list[index].email = line;  // Assign email to the corresponding student
        index++;
    }
    email_file.close();

    std:: cout<< "Running Pre-Relase version\n\n" << std::endl;
#else
    std::cout << "Running Standard Version\n\n" << std::endl;
#endif

    // Debug output: Print student data
#ifdef _DEBUG 
    for (const auto& student : student_list)

    {
        std::cout << "First Name: " << student.first_name
            << ", Last Name: " << student.last_name;

#ifdef PRE_RELEASE
        std::cout << ", Email: " << student.email;

#endif
        std::cout << std::endl;
    }
#endif


    return 0;
}



