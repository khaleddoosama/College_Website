#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
using namespace std;

string toString(int s)    //convert from int to string
{
    string ss;

    while (s > 0)
    {
        ss.push_back(s % 10 + '0');
        s /= 10;
    }
    return ss;
}
class student;

class Course
{
protected:
    string name;
    string code;
    int minStudentLevel;
    int creditHours;
    static int count;
    static vector<Course*> courses;
public:
    Course()
    {
        name = "";
        code = "";
        minStudentLevel = 0;
        creditHours = 0;

    }
    Course(string name, int level, int creditHours)
    {
        this->name = name;
        this->minStudentLevel = level;
        this->creditHours = creditHours;
        count++;
    }
    string getName()
    {
        return name;
    }
    string getCode()
    {
        return code;
    }
    int getMinStudentLevel()
    {
        return minStudentLevel;
    }
    int getCreditHours()
    {
        return creditHours;
    }
    Course* searchCourse(string s)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i]->getCode() == s)
            {
                return courses[i];
            }
        }
        return NULL;
    }

    friend ostream& operator<<(ostream& output, Course& s)
    {
        output << "course name = " << s.name << "\ncourse code = " << s.code << "\nmin student level = " << s.minStudentLevel << "\ncredit hours = " << s.creditHours;
        return output;
    }
    friend istream& operator>>(istream& input, student& s);
    friend ostream& operator<<(ostream& output, student& s);

};
class NormalCourse : public Course
{
public:
    NormalCourse()
    {
        name = "";
        code = "";
        minStudentLevel = 0;
        creditHours = 0;
    }
    NormalCourse(string name, int level, int creditHours) : Course(name, level, creditHours)
    {
        this->name = name;
        this->minStudentLevel = level;
        this->creditHours = creditHours;
        string a = toString(level);
        this->code = name + "_N" + a;
        courses.push_back(this);
    }


};
class SummerCourse : public Course
{
public:
    SummerCourse()
    {
        name = "";
        code = "";
        minStudentLevel = 0;
        creditHours = 0;
    }
    SummerCourse(string name, int level, int creditHours) : Course(name, level, creditHours)
    {
        this->name = name;
        this->minStudentLevel = level;
        this->creditHours = creditHours;
        string a = toString(level);
        this->code = name + "_S" + a;
        courses.push_back(this);
    }

};

class Rational
{
    int numerator;
    int denominator;

    //gcd function
    int gcd(int a, int b)
    {
        if (a == 0 || b == 0)
            return 0;
        else if (a == b)
            return a;
        else if (a > b)
            return gcd(a - b, b);
        else return gcd(a, b - a);
    }
public:
    friend istream& operator>>(istream& input, student& s);
    friend ostream& operator<<(ostream& output, student& s);

    //Default constructor
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }
    Rational(int x1, int x2)
    {
        numerator = x1;
        denominator = x2;
    }
    //getters "ACCESSOR FUNCTIONS"
    int getnumerator()
    {
        return numerator;
    }
    int getdenominator()
    {
        return denominator;
    }
    //Add Function using operator "+" overloading
    Rational operator+(Rational n1) const
    {
        Rational n2;
        n2.numerator = (numerator * n1.denominator) + (n1.numerator * denominator);
        n2.denominator = (denominator * n1.denominator);
        return n2;
    }
    //subtruct Function using operator "-" overloading
    Rational operator -(Rational x1) const
    {
        Rational x2;
        x2.numerator = (numerator * x1.denominator) - (x1.numerator * denominator);
        x2.denominator = (denominator * x1.denominator);
        return x2;
    }
    //Multiply Function using operator "*" overloading
    Rational  operator *(Rational x1)const
    {
        Rational x2;
        x2.numerator = numerator * x1.numerator;
        x2.denominator = denominator * x1.denominator;
        return x2;
    }
    //Devide Function using operator "/" overloading

    Rational operator /(Rational x1) const
    {
        Rational x2;
        x2.numerator = numerator * x1.denominator;
        x2.denominator = denominator * x1.denominator;
        return x2;
    }
    //equals function using operator "==" overloading
    bool operator ==(Rational x) const
    {
        return(numerator == x.numerator && denominator == x.denominator);
    }

    //intValue function
    int  IntValue() const
    {
        return (numerator / denominator);
    }

    //doubleValue function
    double doubleValue() const
    {
        double x = (double)numerator / (double)denominator;
        return x;
    }

    //toString function
    void tostring()
    {
        if (denominator == 1)
            cout << numerator;
        else
            cout << numerator << "/" << denominator;;
    }

    //Compare function
    int compareto(const Rational& obj) ///9
    {
        if ((numerator / denominator) > (obj.numerator / obj.denominator)) {
            return 1;
        }
        if ((obj.numerator / obj.denominator) == (numerator / denominator)) {
            return 0;
        }
        if ((numerator / denominator) < (obj.numerator / obj.denominator)) {
            return -1;
        }
    }

    //GCD function
    int GCD()
    {
        // cout <<gcd(25,15)<<endl;
    }
    int setNumerator(int n) {
        numerator = n;
        return numerator;
    }
    int setDenominator(int d) {
        denominator = d;
        return denominator;
    }
};
class student
{
protected:
    string name;
    string id;
    int arrsize, level, noOfCourses;
    int* Credit_Hours = new int[6];
    Rational* Grades = new Rational[6];
    Course* courses = new Course[6];
public:
    student()
    {
        name = "";
        id = "";
        arrsize = 0;
        noOfCourses = 0;
        level = 0;
    }
    Rational calculateGPA()
    {
        Rational gpa;
        int numerator = 0;
        int denominator = 0;
        for (int i = 0; i < arrsize; i++)
        {
            numerator += (Grades[i].getnumerator() * courses[i].getCreditHours());
            denominator += courses[i].getCreditHours();
        }
        gpa.setNumerator(numerator);
        gpa.setDenominator(denominator);
        return gpa;
    }
    Rational courseGPA(int i)
    {
        Rational gpa;
        int numerator = 0;
        int denominator = 0;
        numerator = (Grades[i].getnumerator());
        gpa.setNumerator(numerator);
        gpa.setDenominator(100);
        return gpa;
    }

    friend istream& operator>>(istream& input, student& s);
    friend ostream& operator<<(ostream& output, student& s);

    void printRegisteredCourses()
    {
        for (int i = 0; i < noOfCourses; i++)
        {
            cout << "Course " << i + 1 << ":\n------\n";
            cout << "Name: " << courses[i].getName() << endl;
            cout << "Code: " << courses[i].getCode() << endl;
            cout << "level: " << courses[i].getMinStudentLevel() << endl;
            cout << "Credit hours: " << courses[i].getCreditHours() << endl;
            cout << "Grade: " << Grades[i].getnumerator() << endl;
            cout << "-----------\n";
        }
    }
    virtual float CalculateExpenses() = 0;

    virtual bool RegisterCourse(Course* course) = 0;

    double getTotalGPA()
    {
        double totalGPA = 0;
        int sum = 0;
        for (int i = 0; i < noOfCourses; i++)
        {
            totalGPA += (getCourseGPA(courseGPA(i)) * courses[i].getCreditHours());
            sum += courses[i].getCreditHours();
        }
        return totalGPA / sum;
    }
    double getCourseGPA(Rational grade)
    {


        if (grade.getnumerator() > 97)
            return 4.0;
        else if (grade.getnumerator() > 92)
            return 4.0;
        else if (grade.getnumerator() > 89)
            return 3.7;
        else if (grade.getnumerator() > 86)
            return 3.3;
        else if (grade.getnumerator() >= 83)
            return 3.0;
        else if (grade.getnumerator() >= 80)
            return 2.7;
        else if (grade.getnumerator() >= 77)
            return 2.3;
        else if (grade.getnumerator() >= 73)
            return 2.0;
        else if (grade.getnumerator() >= 70)
            return 1.7;
        else if (grade.getnumerator() >= 67)
            return 1.3;
        else if (grade.getnumerator() >= 63)
            return 1.0;
        else if (grade.getnumerator() >= 60)
            return 0.7;
        else
            return 0.0;

    }
    int getLevel()
    {
        return level;
    }
    int getNoOfCourses()
    {
        return noOfCourses;
    }
};


class GeneralProgramStudent : public student
{
public:
    bool RegisterCourse(Course* course) {
        if (level >= course->getMinStudentLevel() && noOfCourses < 7)
        {
            courses[noOfCourses] = *course;
            noOfCourses++;
            return true;
        }
        else
        {
            return false;
        }
    }
    float CalculateExpenses()
    {

        return level * 1000;
    }

};
class SpecialProgramStudent : public student
{
public:
    bool RegisterCourse(Course* course) {
        if (noOfCourses < 7)
        {
            courses[noOfCourses] = *course;
            noOfCourses++;
            return true;
        }
        else
        {
            return false;
        }
    }
    float CalculateExpenses()
    {

        float expenses = 0;
        for (int i = 0; i < noOfCourses; i++)
        {
            expenses += (courses[i].getCreditHours() * 500);
        }
        return expenses;
    }
};
istream& operator>> (istream& input, student& s)
{
    cout << "Enter student name: "; input >> s.name;
    cout << "Enter student id: "; input >> s.id;
    cout << "Enter student level: "; input >> s.level;
    cout << "Enter number of courses: "; input >> s.arrsize;
    for (int i = 0; i < s.arrsize; i++)
    {
        string code;
        cout << "Enter the course code " << i + 1 << ": "; input >> code;
        Course* c = new Course();
        if (s.courses[i].searchCourse(code) != NULL)
        {
            c = s.courses[i].searchCourse(code);
            if (!s.RegisterCourse(c))
                cout << "Error: You cannot register in this course" << endl;
            else
            {
                cout << "Enter your grade for this course: "; input >> s.Grades[(s.noOfCourses) - 1].numerator;
            }
        }
        else
        {
            cout << "Course not found" << endl;
        }
    }
    return input;
}

ostream& operator<<(ostream& output, student& s)
{
    cout << "--------------------------------------------\n";
    cout << "name: "; output << s.name; cout << endl;
    cout << "id: "; output << s.id; cout << endl;
    cout << "Student level: " << s.level << endl;
    s.printRegisteredCourses();
    cout << showpoint << setprecision(2);
    cout << "Overall GPA = " << s.getTotalGPA() << endl;
    cout << "Student Expenses = " << (int)s.CalculateExpenses() << " EGP" << endl;

    cout << "------------------" << endl;
    return output;
}

int Course::count = 0;
vector<Course*>Course::courses;

int main()
{
    Course* COURSES[] = { new NormalCourse("Math", 1, 2),
                   new NormalCourse("Programming_1", 1, 3),
                    new NormalCourse("Technical_Writing", 1, 3),
    new NormalCourse("Electronics", 2, 4),
    new NormalCourse("Data_Structures", 2, 3),
    new NormalCourse("OOP", 2, 3),
    new NormalCourse("Algorithms", 3, 2),
    new NormalCourse("Operating_Systems", 3, 3),
    new NormalCourse("Databases", 3, 3),
    new NormalCourse("Machine_Learning", 4, 3),
    new NormalCourse("Compilers", 4, 4),
    new NormalCourse("Programming_Concepts", 4, 4),
    new SummerCourse("Math", 1, 2),
    new SummerCourse("Compilers", 4, 4),
    new SummerCourse("Algorithms", 3, 2),
    new SummerCourse("OOP", 2, 3)
    };

    int v, type; //n students
    cout << "Enter total number of students: ";
    student* s[100000];
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        cout << "Enter student type (0: general, 1: special): "; cin >> type;
        if (type == 0)
        {
            s[i] = new GeneralProgramStudent();
            cin >> *s[i];
        }
        else if (type == 1)
        {
            s[i] = new SpecialProgramStudent();
            cin >> *s[i];
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << *s[i];
    }
    return 0;


}