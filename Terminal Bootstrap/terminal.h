#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <string>
#include <sstream>
#include <string.h>
#include <unistd.h>
#include "strutil.h"

using namespace std;

class Terminal {
  private:
    static int width;

    static string TOP_LEFT_DBL;
    static string BOTTOM_LEFT_DBL;
    static string TOP_RIGHT_DBL;
    static string BOTTOM_RIGHT_DBL;
    static string V_SIDE_DBL;
    static string V_SIDE_CONNECT_BOTTOM_DBL;
    static string V_SIDE_CONNECT_TOP_DBL;
    static string H_SIDE_DBL;

    static string TOP_LEFT_SGL;
    static string BOTTOM_LEFT_SGL;
    static string TOP_RIGHT_SGL;
    static string BOTTOM_RIGHT_SGL;
    static string V_SIDE_SGL;
    static string V_SIDE_CONNECT_BOTTOM_SGL;
    static string V_SIDE_CONNECT_TOP_SGL;
    static string H_SIDE_SGL;

  public:
    static void setBoxWidth(int);
    static string insertHeader(string);
    static string insertSectionStart();
    static string insertTitle(string);
    static string insertSubtitle(string);
    static string insertRow(int, string[]);
    static string insertHR();
    static string insertHalfHR();
    static string insertParagraph(string, const string);
    static string insertBlankSpace();
    static string insertBottomLine();
    static string insertTopLine();
    static string insertCenteredMatrix(float **M, int, int);
    static void insertInput(string, string&);
    static void insertInput(string, int&, const string);
    static void insertInput(string, float&, const string);
    static void insertInput(string);
    static void clear();
};

int Terminal::width = 120;

string Terminal::TOP_LEFT_DBL = "╔";
string Terminal::BOTTOM_LEFT_DBL = "╚";
string Terminal::TOP_RIGHT_DBL = "╗";
string Terminal::BOTTOM_RIGHT_DBL = "╝";
string Terminal::V_SIDE_DBL = "═";
string Terminal::V_SIDE_CONNECT_BOTTOM_DBL = "╤";
string Terminal::V_SIDE_CONNECT_TOP_DBL = "╧";
string Terminal::H_SIDE_DBL = "║";

string Terminal::TOP_LEFT_SGL = "┌";
string Terminal::BOTTOM_LEFT_SGL = "└";
string Terminal::TOP_RIGHT_SGL = "┐";
string Terminal::BOTTOM_RIGHT_SGL = "┘";
string Terminal::V_SIDE_SGL = "─";
string Terminal::V_SIDE_CONNECT_BOTTOM_SGL = "┬";
string Terminal::V_SIDE_CONNECT_TOP_SGL = "┴";
string Terminal::H_SIDE_SGL = "│";

void Terminal::clear() {
    printf("\033c");
    system("clear");
};

void Terminal::setBoxWidth(int w) {
    width = w;
};

string Terminal::insertTitle(string title) {
    string top = strutil::repeat(V_SIDE_DBL, width - 2);
    top = strutil::wrapd(top, TOP_LEFT_DBL, TOP_RIGHT_DBL);
    string text = strutil::centerify(title, width - 2);
    text = strutil::wrap(text, H_SIDE_DBL);
    string bottom = strutil::repeat(V_SIDE_DBL, width - 2);
    bottom = strutil::wrapd(bottom, BOTTOM_LEFT_DBL, BOTTOM_RIGHT_DBL);
    return top + "\n" + text + "\n" + bottom;
};

string Terminal::insertSubtitle(string title) {
    string top = strutil::repeat(V_SIDE_SGL, width - 2);
    top = strutil::wrapd(top, TOP_LEFT_SGL, TOP_RIGHT_SGL);
    string text = strutil::centerify(title, width - 2);
    text = strutil::wrap(text, H_SIDE_SGL);
    string bottom = strutil::repeat(V_SIDE_SGL, width - 2);
    bottom = strutil::wrapd(bottom, BOTTOM_LEFT_SGL, BOTTOM_RIGHT_SGL);
    return top + "\n" + text + "\n" + bottom;
};

string Terminal::insertHR() {
    return strutil::repeat(V_SIDE_SGL, width);
};

string Terminal::insertHalfHR() {
    return strutil::centerify(strutil::repeat(V_SIDE_SGL, width / 2), width);
};

string Terminal::insertHeader(string title) {
    string top = strutil::repeat(V_SIDE_DBL, width - 2);
    top = strutil::wrapd(top, TOP_LEFT_DBL, TOP_RIGHT_DBL);
    string text = strutil::centerify(title, width - 2);
    text = strutil::wrap(text, H_SIDE_DBL);
    string bottom = strutil::repeat(V_SIDE_DBL, width - 4);
    bottom = strutil::wrap(bottom, V_SIDE_CONNECT_BOTTOM_DBL);
    bottom = strutil::wrapd(bottom, BOTTOM_LEFT_DBL, BOTTOM_RIGHT_DBL);
    return top + "\n" + text + "\n" + bottom;
};

string Terminal::insertSectionStart() {
    string line = strutil::repeat(V_SIDE_SGL, width - 4);
    line = strutil::wrap(line, V_SIDE_CONNECT_TOP_SGL);
    line = strutil::wrapd(line, TOP_LEFT_SGL, TOP_RIGHT_SGL);
    return line;
};

string Terminal::insertRow(int columns, string cells[]) {
    int columnSize = width/columns;
    string result = "";

    for (int i = 0; i < columns; i++) {
        result += H_SIDE_SGL;
        result += strutil::centerify(cells[i], columnSize - 1);
    }

    result += H_SIDE_SGL;

    return result;
};

string Terminal::insertParagraph(string text, const string wrapper=Terminal::H_SIDE_SGL) {
    int widthMargined = width - width / 10 * 2.2;
    int textLen = text.length();
    int breaks = ceil((float)textLen / (float)widthMargined) - 1;
    string lines[breaks + 1];

    int offset = 0;
    for (int i = 0; i < breaks + 1; i++) {
        int start = i * widthMargined + offset;
        while (text[start] != ' ' && start != 0) start++;
        
        offset = 0;
        int end = widthMargined;
        while (text[start + end] != ' ' && text[start + end]) {
            end++;
            offset++;
        }

        lines[i] = text.substr(start, end);
    }

    string result = "";
    for (int i = 0; i < breaks + 1; i++) {
        result += i == 0 ? "" : "\n";
        result += strutil::wrap(strutil::centerify(lines[i], width - 2), H_SIDE_SGL);
    }

    return result;
}

string Terminal::insertBlankSpace() {
    return strutil::wrap(strutil::centerify("", width - 2), H_SIDE_SGL);
};

string Terminal::insertBottomLine() {
    return strutil::wrapd(strutil::repeat(V_SIDE_SGL, width - 2), BOTTOM_LEFT_SGL, BOTTOM_RIGHT_SGL);
};

string Terminal::insertTopLine() {
    return strutil::wrapd(strutil::repeat(V_SIDE_SGL, width - 2), TOP_LEFT_SGL, TOP_RIGHT_SGL);
};

string Terminal::insertCenteredMatrix(float **M, int matrixRows, int matrixCols) {
    int maxLength = 0;

    string M_str[matrixRows][matrixCols];

    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            ostringstream ss;
            ss << M[i][j];
            string s(ss.str());
            M_str[i][j] = s;
            int s_len = s.length();
            if (s_len > maxLength) {
                maxLength = s_len;
            }
        }
    }
    
    string result = "";
    string m_header = "";
    m_header += Terminal::TOP_LEFT_SGL + " ";

    for (int j = 0; j < matrixCols + 1; j++) {
        if (j == matrixCols) {
            m_header += Terminal::TOP_RIGHT_SGL;
        } else {
            m_header += strutil::repeat(" ", maxLength + 1);
        }
    }

    result += strutil::centerify(m_header, Terminal::width) + "\n";

    for (int i = 0; i < matrixRows; i++) {
        string line = "";
        line += Terminal::H_SIDE_SGL;

        for (int j = 0; j < matrixCols + 1; j++) {
            line += " ";

            if (j < matrixCols) {
                line += strutil::centerify(M_str[i][j], maxLength);
            } else {
                line += Terminal::H_SIDE_SGL;
            }
        }

        result += strutil::centerify(line, Terminal::width) + "\n";
    }

    string m_footer = "";
    m_footer += Terminal::BOTTOM_LEFT_SGL + " ";

    for (int j = 0; j <= matrixCols; j++) {
        if (j == matrixCols) {
            m_footer += Terminal::BOTTOM_RIGHT_SGL;
        } else {
            m_footer += strutil::repeat(" ", maxLength + 1);
        }
    }
    result += strutil::centerify(m_footer, Terminal::width);

    return result;
};

void Terminal::insertInput(string text, string& input) {
    cout << "    " + text;
    getline(cin, input);
};

void Terminal::insertInput(string text, int& input, const string errorMsg="") {
    cout << "    " + text;
    cin >> input;
    while (cin.fail()) {
        cout << "       " + errorMsg << endl;
        cout << "    " + text;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        cin >> input;
    }
};

void Terminal::insertInput(string text, float &input, const string errorMsg="") {
    cout << "    " + text;
    cin >> input;
    while (cin.fail()) {
        cout << "       " + errorMsg << endl;
        cout << "    " + text;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        cin >> input;
    }
};

void Terminal::insertInput(string text) {
    cout << "    " + text;
    fgetc(stdin);
    std::cin.ignore(1e10, '\n');
};