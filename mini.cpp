#include <iostream>
using namespace std;

class String
{
private:
    char *str;
    int len;

public:

    //Default constructor
    String()
    {
        len = 0;
//        str = new char[1];
  //      str[0] = '\0';
    	str=0;
    }

    //Parameterized constructor
    String(const char *s)
    {
        len = 0;

        // Find length manually
        while (s[len] != '\0')
            len++;

        str = new char[len + 1];

        for (int i = 0; i < len; i++)
            str[i] = s[i];

        str[len] = '\0';
    }

    // 3. Copy constructor
    String(const String &s)
    {
        len = s.len;

        str = new char[len + 1];

        for (int i = 0; i < len; i++)
            str[i] = s.str[i];

        str[len] = '\0';
    }

    // 4. Assignment operator
    String& operator=(const String &s)
    {
        if (this != &s)
        {
            delete[] str;

            len = s.len;
            str = new char[len + 1];

            for (int i = 0; i < len; i++)
                str[i] = s.str[i];

            str[len] = '\0';
        }

        return *this;
    }

    // 5. Addition operator 
    String operator+(const String &s)
    {
        String temp;

        delete[] temp.str;

        temp.len = len + s.len;
        temp.str = new char[temp.len + 1];

        int i;

        for (i = 0; i < len; i++)
            temp.str[i] = str[i];

        for (int j = 0; j < s.len; j++)
            temp.str[i++] = s.str[j];

        temp.str[temp.len] = '\0';

        return temp;
    }

    // 6. Subscript operator
    char& operator[](int index)
    {
        return str[index];
    }

    // Comparison operators

    bool operator==(const String &s)
    {
        if (len != s.len)
            return false;

        for (int i = 0; i < len; i++)
        {
            if (str[i] != s.str[i])
                return false;
        }

        return true;
    }

    bool operator!=(const String &s)
    {
        return !(*this == s);
    }

    bool operator>(const String &s)
    {
        int i = 0;

        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] > s.str[i])
                return true;

            if (str[i] < s.str[i])
                return false;

            i++;
        }

        return len > s.len;
    }

    bool operator<(const String &s)
    {
        if (*this == s)
            return false;

        return !(*this > s);
    }

    bool operator>=(const String &s)
    {
        return (*this > s || *this == s);
    }

    bool operator<=(const String &s)
    {
        return (*this < s || *this == s);
    }

    // 7. Stream insertion operator <<
    friend ostream& operator<<(ostream &out, const String &s)
    {
        out << s.str;
        return out;
    }

    // 8. Stream extraction operator >>
    friend istream& operator>>(istream &in, String &s)
    {
      //  char temp[100];

        in >> temp;

        delete[] s.str;

        s.len = 0;

        while (temp[s.len] != '\0')
            s.len++;

        s.str = new char[s.len + 1];

        for (int i = 0; i < s.len; i++)
            s.str[i] = temp[i];

        s.str[s.len] = '\0';

        return in;
    }

    // Friend string functions

    // 1. strcpy(s2,s1)
    friend void strcpy(String &s2, const String &s1)
    {
        delete[] s2.str;

        s2.len = s1.len;
        s2.str = new char[s2.len + 1];

        for (int i = 0; i < s1.len; i++)
            s2.str[i] = s1.str[i];

        s2.str[s2.len] = '\0';
    }

    // 2. strncpy(s2,s1,n)
    friend void strncpy(String &s2, const String &s1, int n)
    {
        delete[] s2.str;

        int count = (n < s1.len) ? n : s1.len;

        s2.len = count;
        s2.str = new char[count + 1];

        for (int i = 0; i < count; i++)
            s2.str[i] = s1.str[i];

        s2.str[count] = '\0';
    }

    // 3. strcmp(s2,s1)
    friend int strcmp(const String &s2, const String &s1)
    {
        int i = 0;

        while (s2.str[i] != '\0' && s1.str[i] != '\0')
        {
            if (s2.str[i] != s1.str[i])
                return s2.str[i] - s1.str[i];

            i++;
        }

        return s2.str[i] - s1.str[i];
    }

    // 4. strncmp(s2,s1,n)
    friend int strncmp(const String &s2, const String &s1, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (s2.str[i] != s1.str[i])
                return s2.str[i] - s1.str[i];

            if (s2.str[i] == '\0' || s1.str[i] == '\0')
                return 0;
        }

        return 0;
    }

    // 5. strcat(s2,s1)
    friend void strcat(String &s2, const String &s1)
    {
        int oldLen = s2.len;

        char *temp = new char[oldLen + s1.len + 1];

        for (int i = 0; i < oldLen; i++)
            temp[i] = s2.str[i];

        for (int i = 0; i < s1.len; i++)
            temp[oldLen + i] = s1.str[i];

        temp[oldLen + s1.len] = '\0';

        delete[] s2.str;

        s2.str = temp;
        s2.len = oldLen + s1.len;
    }

    // 6. strncat(s2,s1,n)
    friend void strncat(String &s2, const String &s1, int n)
    {
        int count = (n < s1.len) ? n : s1.len;

        int oldLen = s2.len;

        char *temp = new char[oldLen + count + 1];

        for (int i = 0; i < oldLen; i++)
            temp[i] = s2.str[i];

        for (int i = 0; i < count; i++)
            temp[oldLen + i] = s1.str[i];

        temp[oldLen + count] = '\0';

        delete[] s2.str;

        s2.str = temp;
        s2.len = oldLen + count;
    }

    // 7. strrev(s1)
    friend void strrev(String &s1)
    {
        int i = 0;
        int j = s1.len - 1;

        while (i < j)
        {
            char temp = s1.str[i];
            s1.str[i] = s1.str[j];
            s1.str[j] = temp;

            i++;
            j--;
        }
    }

    // 8. strupr(s1)
    friend void strupr(String &s1)
    {
        for (int i = 0; i < s1.len; i++)
        {
            if (s1.str[i] >= 'a' && s1.str[i] <= 'z')
                s1.str[i] = s1.str[i] - 32;
        }
    }

    // 9. strlwr(s1)
    friend void strlwr(String &s1)
    {
        for (int i = 0; i < s1.len; i++)
        {
            if (s1.str[i] >= 'A' && s1.str[i] <= 'Z')
                s1.str[i] = s1.str[i] + 32;
        }
    }

    // 10. strchr(s1,ch)
    friend int strchr(const String &s1, char ch)
    {
        for (int i = 0; i < s1.len; i++)
        {
            if (s1.str[i] == ch)
                return i;
        }

        return -1;
    }

    // 11. strrchr(s1,ch)
    friend int strrchr(const String &s1, char ch)
    {
        for (int i = s1.len - 1; i >= 0; i--)
        {
            if (s1.str[i] == ch)
                return i;
        }

        return -1;
    }

    // 12. strstr(s1, char*)
    friend int strstr(const String &s1, const char *sub)
    {
        int subLen = 0;

        while (sub[subLen] != '\0')
            subLen++;

        if (subLen == 0)
            return 0;

        for (int i = 0; i <= s1.len - subLen; i++)
        {
            int j = 0;

            while (j < subLen && s1.str[i + j] == sub[j])
                j++;

            if (j == subLen)
                return i;
        }

        return -1;
    }

    // 13. strlen(s1)
    friend int strlen(const String &s1)
    {
        return s1.len;
    }

    // Destructor
    ~String()
    {
        delete[] str;
    }
};


int main()
{
    //Default constructor
    String s1;

    //Parameterized constructor
    String s2("Hello");
    String s3("World");

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;


    //Copy constructor
    String s4(s2);

    cout << "\nCopy constructor:";
    cout << "\ns4 = " << s4 << endl;


    //Assignment operator
    s1 = s3;

    cout << "\nAssignment operator:";
    cout << "\ns1 = " << s1 << endl;


    //Addition operator
    String s5 = s2 + s3;

    cout << "\nAddition operator:";
    cout << "\ns2 + s3 = " << s5 << endl;


    //Subscript operator
    cout << "\nSubscript operator:";
    cout << "\ns2[1] = " << s2[1] << endl;


    //Comparison operators
    String a("Apple");
    String b("Banana");

    cout << "\nComparison operators:" << endl;

    cout << "(a == b) : " << (a == b) << endl;
    cout << "(a != b) : " << (a != b) << endl;
    cout << "(a > b)  : " << (a > b) << endl;
    cout << "(a < b)  : " << (a < b) << endl;
    cout << "(a >= b) : " << (a >= b) << endl;
    cout << "(a <= b) : " << (a <= b) << endl;


    //strcpy
    String x("AAAA");
    String y("BBBB");

    strcpy(x, y);

    cout << "\nstrcpy:";
    cout << "\nx = " << x << endl;


    //strncpy
    String p("Computer");
    String q;

    strncpy(q, p, 4);

    cout << "\nstrncpy:";
    cout << "\nq = " << q << endl;


    //strcmp
    cout << "\nstrcmp:";
    cout << "\nstrcmp(a,b) = " << strcmp(a, b) << endl;


    //strncmp
    cout << "\nstrncmp:";
    cout << "\nstrncmp(a,b,2) = " << strncmp(a, b, 2) << endl;


    //strcat
    String c("Hello ");
    String d("World");

    strcat(c, d);

    cout << "\nstrcat:";
    cout << "\nc = " << c << endl;


    //strncat
    String e("Good ");
    String f("Morning");

    strncat(e, f, 3);

    cout << "\nstrncat:";
    cout << "\ne = " << e << endl;


    //strrev
    String r("Hello");

    strrev(r);

    cout << "\nstrrev:";
    cout << "\nr = " << r << endl;


    //strupr
    String u("hello");

    strupr(u);

    cout << "\nstrupr:";
    cout << "\nu = " << u << endl;


    //strlwr
    String l("HELLO");

    strlwr(l);

    cout << "\nstrlwr:";
    cout << "\nl = " << l << endl;


    //strchr
    String ch("Computer");

    cout << "\nstrchr:";
    cout << "\nPosition of 'p' = " << strchr(ch, 'p') << endl;


    //strrchr
    String ch2("programming");

    cout << "\nstrrchr:";
    cout << "\nLast position of 'm' = " << strrchr(ch2, 'm') << endl;


    //strstr
    String mainStr("Hello Computer");

    cout << "\nstrstr:";
    cout << "\nPosition of Computer = "
         << strstr(mainStr, "Computer") << endl;


    //strlen
    cout << "\nstrlen:";
    cout << "\nLength = " << strlen(mainStr) << endl;


    //Stream extraction operator
    String input;

    cout << "\nEnter a string: ";
    cin >> input;

    cout << "You entered: " << input << endl;

    return 0;
}
