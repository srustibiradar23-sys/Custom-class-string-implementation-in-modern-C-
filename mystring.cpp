#include <iostream>
using namespace std;

unsigned int strlen(const char *);



class String
{
    char *ptr;

public:

    String()
    {
        ptr = new char[1];
        ptr[0] = '\0';
    }

    String(const char *p)
    {
        ptr = nullptr;
        strcpy(*this, p);
    }

    String(const String &rv)
    {
        ptr = nullptr;
        strcpy(*this, rv);
    }

    String &operator=(const String &s)
    {
        if(this == &s)
            return *this;

        strcpy(*this, s);

        return *this;
    }

    String operator+(const String &s)
    {
        String p;

        strcpy(p, *this);
        strcat(p, s);

        return p;
    }

    char &operator[](int i)
    {
        return ptr[i];
    }

    ~String()
    {
        delete []ptr;
    }

    bool operator>(const String &s)
    {
        return strcmp(*this, s) > 0;
    }

    bool operator<(const String &s)
    {
        return strcmp(*this, s) < 0;
    }

    bool operator>=(const String &s)
    {
        return strcmp(*this, s) >= 0;
    }

    bool operator<=(const String &s)
    {
        return strcmp(*this, s) <= 0;
    }

    bool operator==(const String &s)
    {
        return strcmp(*this, s) == 0;
    }

    bool operator!=(const String &s)
    {
        return strcmp(*this, s) != 0;
    }

    friend int strcmp(const String &, const String &);

    friend istream &operator>>(istream &, String &);

    friend ostream &operator<<(ostream &, const String &);

    friend String &strcat(String &, const String &);

    friend String &strcpy(String &, const String &);

    friend String &strcpy(String &, const char *);

    friend unsigned int strlen(const String &);

    friend String &strncpy(String &, const String &, unsigned int);

    friend int strncmp(const String &, const String &, unsigned int);

    friend String &strncat(String &, const String &, unsigned int);

    friend void strupr(String &);

    friend void strlwr(String &);

    friend void strrev(String &);

    friend char *strchr(const String &, char);

    friend char *strrchr(const String &, char);

    friend char *strstr(const String &, const char *);
};

//////////////////////////////////////

istream &operator>>(istream &in, String &s)
{
    char temp[100];

    in.getline(temp, 100);
    strcpy(s, temp);

    return in;
}

ostream &operator<<(ostream &out, const String &s)
{
    out << s.ptr;

    return out;
}

String &strcat(String &s2, const String &s1)
{
    int i = 0;

    int len = strlen(s2);
    len += strlen(s1);

    char *temp = new char[len + 1];

    for(i = 0; s2.ptr[i] != '\0'; i++)
        temp[i] = s2.ptr[i];

    for(int j = 0; s1.ptr[j] != '\0'; i++, j++)
        temp[i] = s1.ptr[j];

    temp[i] = '\0';

    strcpy(s2, temp);

    delete []temp;

    return s2;
}

String &strncat(String &s2, const String &s1, unsigned int n)
{
    int i = 0;

    int len = strlen(s2);
    len += n + 1;

    char *temp = new char[len + 1];

    for(i = 0; s2.ptr[i] != '\0'; i++)
        temp[i] = s2.ptr[i];

    for(int j = 0; s1.ptr[j] != '\0' && j < n; i++, j++)
        temp[i] = s1.ptr[j];

    temp[i] = '\0';

    strcpy(s2, temp);

    delete []temp;

    return s2;
}

unsigned int strlen(const String &s1)
{
    int i;

    for(i = 0; s1.ptr[i] != '\0'; i++);

    return i;
}

unsigned int strlen(const char *s1)
{
    int i;

    for(i = 0; s1[i] != '\0'; i++);

    return i;
}

String &strcpy(String &s2, const String &s1)
{
    int i;

    int len1 = strlen(s1);

    delete []s2.ptr;

    s2.ptr = new char[len1 + 1];

    for(i = 0; s1.ptr[i] != '\0'; i++)
        s2.ptr[i] = s1.ptr[i];

    s2.ptr[i] = '\0';

    return s2;
}

String &strncpy(String &s2, const String &s1, unsigned int n)
{
    int i;

    delete []s2.ptr;

    s2.ptr = new char[n + 1];

    for(i = 0; s1.ptr[i] != '\0' && i < n; i++)
        s2.ptr[i] = s1.ptr[i];

    s2.ptr[i] = '\0';

    return s2;
}

String &strcpy(String &s2, const char *s1)
{
    int i;

    int len1 = strlen(s1);

    delete []s2.ptr;

    s2.ptr = new char[len1 + 1];

    for(i = 0; s1[i] != '\0'; i++)
        s2.ptr[i] = s1[i];

    s2.ptr[i] = '\0';

    return s2;
}

int strcmp(const String &s2, const String &s1)
{
    int i;

    for(i = 0;
        s2.ptr[i] != '\0' && s1.ptr[i] != '\0';
        i++)
    {
        if(s2.ptr[i] != s1.ptr[i])
            return s2.ptr[i] - s1.ptr[i];
    }

    return s2.ptr[i] - s1.ptr[i];
}

int strncmp(const String &s2, const String &s1, unsigned int n)
{
    int i;

    for(i = 0;
        s2.ptr[i] != '\0' &&
        s1.ptr[i] != '\0' &&
        i < n;
        i++)
    {
        if(s2.ptr[i] != s1.ptr[i])
            return s2.ptr[i] - s1.ptr[i];
    }

    if(i == n)
        return 0;

    return s2.ptr[i] - s1.ptr[i];
}

void strupr(String &s)
{
    int i = 0;

    while(s.ptr[i] != '\0')
    {
        if(s.ptr[i] >= 'a' && s.ptr[i] <= 'z')
            s.ptr[i] = (s.ptr[i] & 0xDF);

        i++;
    }
}

void strlwr(String &s)
{
    int i = 0;

    while(s.ptr[i] != '\0')
    {
        if(s.ptr[i] >= 'A' && s.ptr[i] <= 'Z')
            s.ptr[i] = (s.ptr[i] | 0x20);

        i++;
    }
}

void strrev(String &s)
{
    int len = strlen(s);

    char temp;

    int i, j;

    for(i = 0, j = len - 1;
        i < len / 2;
        i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char *strchr(const String &s, char ch)
{
    int i = 0;

    while(s.ptr[i] != '\0')
    {
        if(s.ptr[i] == ch)
            return &s.ptr[i];

        i++;
    }

    return nullptr;
}

char *strrchr(const String &s, char ch)
{
    int i = strlen(s) - 1;

    while(i >= 0)
    {
        if(s.ptr[i] == ch)
            return &s.ptr[i];

        i--;
    }

    return nullptr;
}

char *strstr(const String &s, const char *p)
{
    int i = 0;
    int j = 0;
    int k = 0;

    char *q;

    while(s.ptr[i] != '\0')
    {
        if(s.ptr[i] == p[j])
        {
            q = &s.ptr[i];

            k = i + 1;
            j++;

            if(p[j] == '\0')
                return q;

            while(p[j] != '\0')
            {
                if(s.ptr[k] != p[j])
                {
                    j = 0;
                    break;
                }
                else
                {
                    k++;
                    j++;
                }

                if(p[j] == '\0')
                    return q;
            }
        }

        i++;
    }

    return nullptr;
}

//////////////////////////////////////

int main()
{
    // 1. Default and parameterized constructors
    cout << "\n--- Constructors ---\n";

    String v1;
    String v2("hello");


    // 2. Copy construction and assignment
    cout << "\n--- Copy constructor ---\n";

    String v3(v2);

    cout << "\n--- Assignment operator ---\n";

    v1 = v2;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;


    // 3. Concatenation using + operator
    cout << "\n--- Addition operator ---\n";

    String v4("Hello ");
    String v5("World");

    String v6 = v4 + v5;

    cout << "v6 = " << v6 << endl;


    // 4. Character access using [] operator
    cout << "\n--- Subscript operator ---\n";

    cout << "v6[0] = " << v6[0] << endl;

    v6[0] = 'h';

    cout << "After modification: " << v6 << endl;


    // 5. Input and output using stream operators
    cout << "\n--- Stream operators ---\n";

    String v7;

    cout << "Enter a string: ";
    cin >> v7;

    cout << "You entered: " << v7 << endl;


    // 6. All comparison operators
    cout << "\n--- Comparison operators ---\n";

    String a("abc");
    String b("def");
    String c("abc");

    cout << "a > b  : " << (a > b) << endl;
    cout << "a < b  : " << (a < b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
    cout << "a <= b : " << (a <= b) << endl;
    cout << "a == c : " << (a == c) << endl;
    cout << "a != b : " << (a != b) << endl;


    // 7. All required friend string functions
    cout << "\n--- Friend string functions ---\n";

    String s1("Hello");
    String s2("World");
    String s3;


    // strlen()
    cout << "strlen(s1) = " << strlen(s1) << endl;


    // strcpy()
    strcpy(s3, s1);

    cout << "After strcpy: " << s3 << endl;


    // strncpy()
    strncpy(s3, s2, 3);

    cout << "After strncpy: " << s3 << endl;


    // strcat()
    strcat(s1, s2);

    cout << "After strcat: " << s1 << endl;


    // strncat()
    String s4("Hello");

    strncat(s4, s2, 3);

    cout << "After strncat: " << s4 << endl;


    // strcmp()
    cout << "strcmp(s1, s2) = "
         << strcmp(s1, s2) << endl;


    // strncmp()
    cout << "strncmp(s1, s2, 3) = "
         << strncmp(s1, s2, 3) << endl;


    // strupr()
    String s5("hello world");

    strupr(s5);

    cout << "After strupr: " << s5 << endl;


    // strlwr()
    String s6("HELLO WORLD");

    strlwr(s6);

    cout << "After strlwr: " << s6 << endl;


    // strrev()
    String s7("hello");

    strrev(s7);

    cout << "After strrev: " << s7 << endl;


    // strchr()
    String s8("hello world");

    char *p1 = strchr(s8, 'w');

    if(p1 != nullptr)
        cout << "strchr: " << p1 << endl;


    // strrchr()
    String s9("hello world");

    char *p2 = strrchr(s9, 'l');

    if(p2 != nullptr)
        cout << "strrchr: " << p2 << endl;


    // strstr()
    String s10("hello world");

    char *p3 = strstr(s10, "world");

    if(p3 != nullptr)
        cout << "strstr: " << p3 << endl;


    return 0;
}
