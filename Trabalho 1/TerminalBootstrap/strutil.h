#include <iomanip>
#include <clocale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <codecvt>

using namespace std;

namespace strutil {
    int charCount(string);
    string repeat(string, int);
    string centerify(string, int, int);
    string wrap(string, string);
    string wrapd(string, string, string);
    wstring str2wstr(string);
    string wstr2str(wstring);
    string substring(string, int, int);
    string double2str(double, int);
};

string strutil::double2str(double num, int precision) {
    std::stringstream nums;
    nums << std::fixed << std::setprecision(precision) << num;
    return nums.str();
};

wstring strutil::str2wstr(string str) {
    wstring wstr(str.length(), L' ');
    std::copy(str.begin(), str.end(), wstr.begin());
    return wstr;
};

string strutil::wstr2str(wstring wstr) {
    string str(wstr.length(), ' ');
    copy(wstr.begin(), wstr.end(), str.begin());
    return str;
};

string strutil::repeat(string str, int times) {
    string result = "";

    for (int i = 0; i < times; i++) {
        result += str;
    }

    return result;
};

string strutil::centerify(string text, int length, int textLen = -1) {
    if (textLen == -1) textLen = strutil::charCount(text);
    string result = "";
    for (int i = 0; i < length - textLen; result += " ", i++);

    if (length >= textLen) {
        result.insert((length - textLen) / 2, text);
    }

    return result;
};

string strutil::wrap(string text, string wrapper) {
    string result = wrapper;
    result += text;
    result += wrapper;
    return result;
};

string strutil::wrapd(string text, string wrapperLeft, string wrapperRight) {
    string result = wrapperLeft;
    result += text;
    result += wrapperRight;
    return result;
};

int strutil::charCount(string text) {
    std::size_t result = 0;
    const char* ptr = text.data();
    const char* end = ptr + text.size();
    std::mblen(NULL, 0);

    while (ptr < end) {
        int next = std::mblen(ptr, end - ptr);
        if (next == -1) {
            throw std::runtime_error("strlen_mb(): conversion error");
        }

        ptr += next;
        ++result;
    }

    return result;
};

// string strutil::substring(string str, int start, int leng) {
//     if (leng==0) { return ""; }
//     unsigned int c, i, ix, q, min=string::npos, max=string::npos;
//     for (q=0, i=0, ix=str.length(); i < ix; i++, q++) {
//         if (q==start){ min=i; }
//         if (q<=start+leng || leng==string::npos){ max=i; }
 
//         c = (unsigned char) str[i];
//         if (c>=0   && c<=127) i+=0;
//         else if ((c & 0xE0) == 0xC0) i+=1;
//         else if ((c & 0xF0) == 0xE0) i+=2;
//         else if ((c & 0xF8) == 0xF0) i+=3;
//         else return "";
//     }
//     if (q<=start+leng || leng==string::npos){ max=i; }
//     if (min==string::npos || max==string::npos) { return ""; }
//     return str.substr(min, max);
// };