#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course; // Forward declaration

class Teacher {
    string name;
    int teacherID;
    string specialization;

public:
    Teacher(string name = "", int id = 0, string spec = "") : name(name), teacherID(id), specialization(spec) {}

    void displayTeacherDetails() const {
        cout << "Instructor: " << name << " (ID: " << teacherID << "), Specialization: " << specialization << endl;
    }

    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
};

class Course {
protected:
    string courseName;
    string courseCode;
    Teacher* teacher;

public:
    Course(string name = "", string code = "", Teacher* t = nullptr)
        : courseName(name), courseCode(code), teacher(t) {}

    virtual void displayCourseDetails() const {
        cout << "Course: " << courseName << " (Code: " << courseCode << ")" << endl;
        if (teacher) teacher->displayTeacherDetails();
    }

    virtual ~Course() {}

    string getCourseCode() const { return courseCode; }
    string getCourseName() const { return courseName; }
};

class TheoryCourse : public Course {
    int hoursPerWeek;

public:
    TheoryCourse(string name, string code, Teacher* t, int hours)
        : Course(name, code, t), hoursPerWeek(hours) {}

    void displayCourseDetails() const override {
        Course::displayCourseDetails();
        cout << "Weekly Hours: " << hoursPerWeek << " hours/week\n";
    }
};

class PracticalCourse : public Course {
    double labFee;

public:
    PracticalCourse(string name, string code, Teacher* t, double fee)
        : Course(name, code, t), labFee(fee) {}

    void displayCourseDetails() const override {
        Course::displayCourseDetails();
        cout << "Lab Fee: $" << labFee << endl;
    }
};

class Student {
    string name;
    int studentID;
    vector<Course*> enrolledCourses;

public:
    Student(string name = "", int id = 0) : name(name), studentID(id) {}

    void enrollInCourse(Course* course) {
        enrolledCourses.push_back(course);
    }

    void displayStudentDetails() const {
        cout << "Student: " << name << " (ID: " << studentID << ")" << endl;
        cout << "Enrolled in courses:\n";
        for (const auto& c : enrolledCourses) {
            cout << "- ";
            c->displayCourseDetails();
            cout << endl;
        }
    }

    bool isEnrolledInCourse(const string& code) const {
        for (const auto& c : enrolledCourses) {
            if (c->getCourseCode() == code)
                return true;
        }
        return false;
    }

    int getID() const { return studentID; }
};

class OnlineSchool {
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course*> courses; // Store base class pointers for polymorphism

public:
    ~OnlineSchool() {
        for (Course* c : courses)
            delete c;
    }

    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void addTeacher(const Teacher& t) {
        teachers.push_back(t);
    }

    void addCourse(Course* c) {
        courses.push_back(c);
    }

    void enrollStudentInCourse(int studentID, const string& courseCode) {
        Course* coursePtr = nullptr;
        for (auto* c : courses) {
            if (c->getCourseCode() == courseCode) {
                coursePtr = c;
                break;
            }
        }

        if (!coursePtr) {
            cout << "Course not found!\n";
            return;
        }

        for (auto& s : students) {
            if (s.getID() == studentID) {
                s.enrollInCourse(coursePtr);
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void displayAllStudentsInCourse(const string& courseCode) const {
        cout << "Students enrolled in course " << courseCode << ":\n";
        for (const auto& s : students) {
            if (s.isEnrolledInCourse(courseCode))
                s.displayStudentDetails();
        }
    }

    void displayAllCoursesOfStudent(int studentID) const {
        for (const auto& s : students) {
            if (s.getID() == studentID) {
                s.displayStudentDetails();
                return;
            }
        }
        cout << "Student not found!\n";
    }
};

// Sample usage
int main() {
    OnlineSchool os;

    Teacher t1("Dr. Smith", 2001, "Mathematics");
    Teacher t2("Dr. Johnson", 2002, "Chemistry");

    os.addTeacher(t1);
    os.addTeacher(t2);

    Course* c1 = new TheoryCourse("Math 101", "MTH101", &t1, 3);
    Course* c2 = new PracticalCourse("Chemistry Lab", "CHM101", &t2, 50.0);

    os.addCourse(c1);
    os.addCourse(c2);

    Student s1("John Doe", 101);
    Student s2("Alice Smith", 102);

    os.addStudent(s1);
    os.addStudent(s2);

    os.enrollStudentInCourse(101, "MTH101");
    os.enrollStudentInCourse(101, "CHM101");
    os.enrollStudentInCourse(102, "CHM101");

    os.displayAllCoursesOfStudent(101);
    os.displayAllStudentsInCourse("CHM101");

    return 0;
}
