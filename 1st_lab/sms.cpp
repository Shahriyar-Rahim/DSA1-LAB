#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Data
{
public:
    virtual string calGrade() const = 0;
    virtual void showData() const = 0;
    virtual ~Data() = default;
};

class Student : public Data
{
private:
    long long id;
    double mark;

public:
    Student(long long i, double m) : id(i), mark(m) {}

    string calGrade() const override
    {
        if (mark >= 80.0 && mark <= 100.0)
            return "A+ (4.00)";
        else if (mark >= 75.0 && mark < 80.0)
            return "A  (3.75)";
        else if (mark >= 70.0 && mark < 75.0)
            return "A- (3.50)";
        else if (mark >= 65.0 && mark < 70.0)
            return "B+ (3.25)";
        else if (mark >= 60.0 && mark < 65.0)
            return "B  (3.00)";
        else if (mark >= 55.0 && mark < 60.0)
            return "B- (2.75)";
        else if (mark >= 50.0 && mark < 55.0)
            return "C+ (2.50)";
        else if (mark >= 45.0 && mark < 50.0)
            return "C  (2.25)";
        else if (mark >= 40.0 && mark < 45.0)
            return "D  (2.00)";
        else if (mark >= 0.0 && mark < 40.0)
            return "F  (0.00)";
        else
            return "Invalid Mark";
    }

    void showData() const override
    {
        cout << "Student ID : " << id << endl;
        cout << "Mark       : " << mark << endl;
        cout << "Grade      : " << calGrade() << endl;
    }
};

int main()
{
    int ts;
    cout << "Enter total number of students: ";
    cin >> ts;

    vector<shared_ptr<Data>> studens;

    for (int i = 0; i < ts; ++i)
    {
        long long id;
        double mark;

        cout << "\nInput for Student " << (i + 1) << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Mark: ";
        cin >> mark;

        studens.push_back(make_shared<Student>(id, mark));
    }

    cout<< endl;
    for (size_t i = 0; i < studens.size(); ++i)
    {
        cout << "\nStudent " << (i + 1) << ":" << endl;
        studens[i]->showData();
    }

    return 0;
}