// Variant 3

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 3 % 3 = 0 (Bubble sorting)
// Exercise 1 function
void bubbleSort(std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = 0; j < v.size() - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}


// Exercise 2 functions
struct Student
{
    std::string surname;
    std::string name;
    std::string middleName;
    std::string birthDate;
    int history;
    int physics;
    int english;
    int math;
    int biology;
    int sum;
};


bool isLess(const Student& a, const Student& b)
{
    return a.sum < b.sum;
}


void ex2()
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open())
    {
        std::cerr << "Input file is not found!" << std::endl;
    }
    else if (!output.is_open())
    {
        std::cerr << "Output file is not opened!" << std::endl;
    }
    else
    {
        std::vector<Student> students;

        int group;
        if (input >> group)
        {
            for (int i = 0; i < group; ++i)
            {
                Student student;

                input >> student.surname
                >> student.name
                >> student.middleName
                >> student.birthDate
                >> student.history
                >> student.physics
                >> student.english
                >> student.math
                >> student.biology;

                student.sum = student.history
                + student.physics
                + student.english
                + student.math
                + student.biology;

                students.push_back(student);
            }
        }


        for (size_t i = 0; i < students.size(); ++i)
        {
            for (size_t j = 0; j < students.size() - i - 1; ++j)
            {
                if (isLess(students[j], students[j + 1]))
                {
                    Student tmp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = tmp;
                }
            }
        }


        for (int i = 0; i < group; ++i)
        {
            output << students[i].surname << " "
            << students[i].name << " "
            << students[i].middleName << " "
            << students[i].birthDate << " "
            << students[i].history << " "
            << students[i].physics << " "
            << students[i].english << " "
            << students[i].math << " "
            << students[i].biology << " "
            << students[i].sum << std::endl;
        }
    }

    
}

int main()
{
    // Exercise 1
    std::vector<int> v1 = {3, 5, 2, 7, 1, 8, 1, 15, 3};
    bubbleSort(v1);

    // Exercise 2
    ex2();

    return 0;
}