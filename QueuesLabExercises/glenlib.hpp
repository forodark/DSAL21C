//==================================================================================================================        
//  ██████╗ ██╗     ███████╗███╗   ██╗██╗     ██╗██████╗      █  █  █▀▀█  █▀▀█
// ██╔════╝ ██║     ██╔════╝████╗  ██║██║     ██║██╔══██╗ ▄▄  █▀▀█  █▄▄█  █▄▄█
// ██║  ███╗██║     █████╗  ██╔██╗ ██║██║     ██║██████╔╝ ▀▀  █  █  █     █   
// ██║   ██║██║     ██╔══╝  ██║╚██╗██║██║     ██║██╔══██╗
// ╚██████╔╝███████╗███████╗██║ ╚████║███████╗██║██████╔╝  v2.2
//  ╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝╚═════╝   by Glen Angelo Bautista                                       
//==================================================================================================================
// This is my header file containing a bunch of useful functions that I made to make my life easier. The features
// available aren't limited to encryption though. Please explore the file to learn more.
//==================================================================================================================
// Changes (v2.2)
//  - revamped println and print functions to be able to take multiple args and concat them
//  - changed nl to use endl
//  - added a concat function that works with most datatypes
//  - fixed invalid and exit functions to both automatically have next line char
//  - added dontWait function for menus
//  - added quitMenu function to dont display menu again
//  - added showMenuOnce that only shows that exits after the function runs
//  - added displayOptions to reduce repeated code
//  - added functions for setting menu parameters
//      > noReturn
//      > setReturnText
//      > dontClear
//      > dontRepeat
//      > menuSettings (set multiple)
//      > dontClearAfter
//      > dontClearMenu
// Changes (v2.1)
//  - Fixed bug in error message for getBool
//  - added ctos function (char to string)
//  - added getOrdinal function
//  - added support for empty println function
//  - added alternative to COL (COLUMN) that doesnt use typeof (FIX THIS SOON)
//      > FIXED, changed COL to be compatible with non-compiler specific functions (removed typeof)
//  - fixed decimal formatting in tables
/// - fixed format string not being able to handle float and double strings
// Changes (v2.0)
//  - TLDR: i ported the updates from glenlib java to c++
//  - unified printLine and printLineWidth into line
//  - changed line macro to ln & lnw()
//  - changed legacy printColor to Win::color
//  - new printColor or color function using ansi codes
//  - added nl() to print new line
//  - added printTitle()
//  - added println and print that mimics java's print functions
//  - added clear function
//  - added sleep function
//  - added additional overloaded function for invalidChoice, renamed to invalid
//  - added additional overloaded function for exitProgram, added another alias quit
//  - fixed unintentional bug where truncate would call trimZeros
//  - added setPrecision (calls formatString)
//  - added a setter for default_line_width
//  - applied the new clear function on invalid inputs
//  - extractDecimal now returns -1 if none found
//  - fixed bug in input functions where several continue statements were missing
//  - accepted chars for getChar
//  - table shows N/A if no value found
//  - changed table column constructor from TCOL to COL
//  - table truncates header if it exceeds the column width
//  - better rand function
// Changes (v1.2)
//  - Fixed bug where menu titles caused incorrect choice selection
//  - Fixed bug where table pages printed the wrong data
//  - Fixed spacing bug in table pages
//  - temporarily removed run and compile functions that use unistd.h
// Changes (v1.1)
//  - Min Max parameter for int, float, double
//  - Fixed bug in creating table columns with TCOL()
//  - Added option to have no title in menus and tables
//  - Removed leftover debugging statements
//  - Unified customizable functions for invalidChoice and exitProgram
//  - Added a line() macro useable with std::cout
//  - Added more sample comments
// Changes (v1.0)
//  - Now converted to C++ (from glencrypt v0.6.1c)
//  - Redesigned the following functions:
//      > printCentered
//      > convertString
//      > formatString
//      > input
//          - Added value returning way to call function (getInt, getFloat, etc.)
//          - Added float
//          - Added min-max functionality for strings
//          - Use function overloading to allow multiple input types without specifying type
//      > inputCustom
//          - Now merged with input
//      > runProgram
//      > compileRunProgram
//      > showMenu
//      > showPageMenu
//      > printTableFull
//      > printTable
//  - Added the following functions:
//      > truncate
//      > trim
//      > trimZeros
//      > getFileName
//      > getFileExtension
//      > run (for handling runProgram() and compileRunProgram())
//      > extractDecimal
//  - Removed the following functions:
//      > openFile (no longer efficient, use ifstream/ofstream instead)
//  - Use std::string instead of char*
//  - Added and change many default configurations
// Upcoming Changes
//	- add the run and compile functions again
//==================================================================================================================

#ifndef GLENLIB_HPP
#define GLENLIB_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <Windows.h>  //
#include <cstddef>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <cstdint>
#include <chrono>
#include <thread>

namespace gl {

//==================================================================================================================
// Max Defaults (Can be configured)
#define MAX_STRING_LENGTH 256
#define MAX_KEY_LENGTH 256
#define MAX_COMMAND_LENGTH 128
#define MAX_ELEMENTS 256

#define MIN_INT -2147483647
#define MAX_INT 2147483647

#define MIN_FLOAT -2147483647.0f
#define MAX_FLOAT 2147483647.0f

#define MIN_DOUBLE -2147483647.0
#define MAX_DOUBLE 2147483647.0

//Default Messages
#define INVALID_CHOICE "Invalid Choice."
#define EXIT_PROGRAM "Exiting Program."

//Line Defaults
static int default_line_width = 31;
#define INVALID_CLEAR 4

//Input Defaults
#define INPUT_PROMPT "Input: "
#define STRING_INPUT_MIN 0
#define STRING_INPUT_MAX 256

//Menu Defaults
#define MENU_WIDTH 31
#define MENU_PAGE_LENGTH 7

//Table Defaults
#define TABLE_PAGE_LENGTH 10

//=========================================================menu=========================================================
// Character list definitions, used for inputCustom()
#define ALPHANUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMERIC "0123456789."
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Character list definitions, used for encryption/decryption
#define CHAR_LIB "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ "
#define DEFAULT_KEY "}Pj? THrxT_{Dh^Q.UdrG&s-X'?zaPBJ-2]dyFD23IV9:'&tT%]:}$m@<~[,oT$"
#define KEYGEN "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[]^_`{|}~ "

//==================================================================================================================
// Setter functions

void setLineWidth(int width) {
    default_line_width = width;
}

//==================================================================================================================
// Print Line Functions

// Sample: line(10); 
void line(int width) { //print line with custom width
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

void line() { //print lines in different styles
	line(default_line_width);
}

void nl() {
    std::cout << std::endl;
}

#define lnw(width) std::string(width, '-') + '\n'
#define ln std::string(default_line_width, '-') + '\n'

//==================================================================================================================
// Color Macros & Print Functions

std::string concat() {
    return "";
}

template <typename T, typename... Args>
std::string concat(const T& value, const Args&... args) {
    std::ostringstream oss;
    oss << value;
    oss << concat(args...);
    return oss.str();
}

template <typename T>
void print(const T& value) {
    std::cout << value;
}

template <typename T, typename... Args>
void print(const T& value, const Args&... args) {
    std::cout << value;
    print(args...);
}

template <typename T>
void println(const T& value) {
    print(value);
    nl();
}

void println() {
    std::cout << std::endl;
}

class Win {
public:
    static const int BLACK;
    static const int RED;
    static const int GREEN;
    static const int BLUE;
    static const int YELLOW;
    static const int MAGENTA;
    static const int CYAN;
    static const int WHITE;

    static void color(int text_color, const std::string& format, ...) {
        va_list args;
        va_start(args, format);
        setTextColor(text_color);
        vprintf(format.c_str(), args);
        va_end(args);
        resetColor();
    }

private:
    static HANDLE h_console_;
    static CONSOLE_SCREEN_BUFFER_INFO original_info_;

    static void setTextColor(int text_color) {
        h_console_ = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(h_console_, &original_info_);
        SetConsoleTextAttribute(h_console_, static_cast<WORD>(text_color));
    }

    static void resetColor() {
        SetConsoleTextAttribute(h_console_, original_info_.wAttributes);
    }
};

const int Win::BLACK = 0;
const int Win::RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
const int Win::GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int Win::BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int Win::YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int Win::MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int Win::CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int Win::WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

HANDLE Win::h_console_ = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO Win::original_info_;


const std::string RESET = "\x1B[0m";
const std::string BLACK = "\x1B[30m";
const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string PURPLE = "\x1B[35m";
const std::string CYAN = "\x1B[36m";
const std::string WHITE = "\x1B[37m";

void printColor(const std::string& color, const std::string& format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format.c_str(), args);
    va_end(args);
    std::string formatted_text(buffer);
    std::cout << color << formatted_text << RESET;
}

std::string color(const std::string& color, const std::string& format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format.c_str(), args);
    va_end(args);
    std::string formatted_text(buffer);
    return (color + formatted_text + RESET);
}

void color(const std::string& color) {
    std::cout << color;
}

void color() {
    std::cout << RESET;
}


// Sample: printCentered("Hello", 15); | Result: "     Hello     "
void printCentered(int field_width, const std::string& format, ...) {
    va_list args;
    va_start(args, format);

    // Convert the C++ string to a C-style string
    const char* c_format = format.c_str();

    // Calculate the length of the formatted string
    int length = vsnprintf(nullptr, 0, c_format, args);

    va_end(args);

    va_start(args, format);

    int total_padding = field_width - length;

    int left_padding = total_padding / 2;
    int right_padding = total_padding / 2;

    if (total_padding % 2 != 0) {
        right_padding++;
    }

    for (int i = 0; i < left_padding; ++i) {
        std::cout << ' ';
    }

    vprintf(c_format, args);

    for (int i = 0; i < right_padding; ++i) {
        std::cout << ' ';
    }

    va_end(args);
}

void printTitle(int width, const std::string& title) {
    line(width);
    printCentered(width, title);
    nl();
    line(width);
}

void printTitle(const std::string& title) {
    printTitle(default_line_width, title);
}

//==================================================================================================================
// Miscelaneous Functions

int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double random(double min, double max, int precision = 2) {
    double result = (double)rand() / RAND_MAX * (max - min) + min;
    double multiplier = pow(10, precision);
    return std::round(result * multiplier) / multiplier;
}

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void clear() {
    system("cls");
}

void clear(int lines) {
    for (int i = 0; i < lines; ++i) {
        std::cout << "\033[2K";
        std::cout << "\033[A";
    }
    std::cout << "\033[2K";
    std::cout.flush();
}

// Sample: getCharPos("Hello", 'e'); | Result: 1
int getCharPos(const std::string& str, char ch) {
    auto pos = str.find(ch);
    if (pos == std::string::npos) {
        return -1;
    } else {
        return static_cast<int>(pos);
    }
}


void waitEnter() { //waits for user to press enter
    std::cout << "Press Enter to continue...";
    std::cout.flush();
    while (std::cin.get() != '\n') {
        
    }
}

// Sample: invalid("Invalid choice", 10);
void invalid(const std::string& message, int width, bool clear_after = true) { //returns invalid choice with custom parameters
    Win::color(Win::RED, message);
    nl();
    line(width);
    if(clear_after) {
        waitEnter();
        clear(INVALID_CLEAR);
    }
}

void invalid(const std::string& message, bool clear_after = true) {
    invalid(message, default_line_width, clear_after);
}

void invalid() {
    invalid(INVALID_CHOICE, default_line_width);
}

//Sample: exitProgram("BYE!", 10);
void exitProgram(const std::string& message, int width) { //exits program with custom parameters
    system("cls");
    line(width);
    std::cout << message << std::endl;
    line(width);
    exit(0);
}

void exitProgram(const std::string& message) { //exits program
    exitProgram(message, default_line_width);
}

void exitProgram() { //exits program
    exitProgram(EXIT_PROGRAM, default_line_width);
}

//aliases for exitProgram
void quit(const std::string& message, int width) {exitProgram(message, width);}
void quit(const std::string& message) {exitProgram(message);}
void quit() {exitProgram();}


//==================================================================================================================
// Data Type & String Formatting Functions
		
// Sample: convertString(100); | Result: "100"
template <typename T>
std::string convertString(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

// Sample: trim("   Hello   "); | Result: "Hello"
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(start, end - start + 1);
}

// Sample: trimZeros("123.45000"); | Result: "123.45"
std::string trimZeros(const std::string& numStr) {
    size_t decimalPointPos = numStr.find('.');
    
    if (decimalPointPos != std::string::npos) {
        size_t lastNonZeroDigit = numStr.find_last_not_of('0');
        
        if (lastNonZeroDigit == decimalPointPos) {
            return numStr.substr(0, decimalPointPos);
        } else {
            return numStr.substr(0, lastNonZeroDigit + 1);
        }
    }

    return numStr;
}

// Sample: truncate("Hello", 3); | Result: "Hel"
std::string truncate(const std::string& inputString, int width) {

    if (width == 0) {
        return inputString;
    }

    std::string input_buffer = inputString;

    if (static_cast<int>(input_buffer.length()) > width) {
        std::string truncated = input_buffer.substr(0, static_cast<std::string::size_type>(width - 2)) + "..";
        return truncated;
    }
    if (static_cast<int>(input_buffer.length()) < width) {
        std::string truncated = input_buffer;
        for (int i = 0; i < (width - static_cast<int>(input_buffer.length())); i++) {
            truncated += " ";
        }
        return truncated;
    }
    return input_buffer;
}

// Sample: formatString("Hello", 9); | Result: "Hello    "
// Sample: formatString(123.4567, 8, 2); | Result: "123.45  "
template <typename T>
std::string formatString(const T& value, int width = 0, int precision = -1) {
    std::stringstream ss;
    
    if (precision >= 0) {
        try {
            std::stringstream buffer;
            buffer << value;
            double number = std::stod(buffer.str());
            ss << std::setprecision(precision) << std::fixed << number;
        }
        catch (const std::exception& e) {
            ss << value;
        }
    }
    else {
        ss << value;
    }


    
    return truncate(ss.str(), width);
}

template <typename T>
std::string setPrecision(const T& value, int precision) {
    return formatString(value, 0, precision);
}

// Sample: typeFromFormat("%s"); | Result: "string"
std::string typeFromFormat(const std::string& format) {
    if (format.find("s") != std::string::npos) {
        return "string";
    }
    else if (format.find("lf") != std::string::npos){
        return "double";
    }
    else if (format.find("f") != std::string::npos) {
        return "float";
    }
    else if (format.find("c") != std::string::npos) {
        return "char";
    }
    else if (format.find("d") != std::string::npos) {
        return "int";
    }
    else if (format.find("b") != std::string::npos) {
        return "bool";
    }
    else {
        return "unknown";
    }
}

// Sample: extractNumber("abc123.45"); | Result: 123
int extractNumber(const std::string& str) {
    size_t pos = 0;
    while (pos < str.length() && !isdigit(str[pos])) {
        pos++;
    }

    int result = 0;
    while (pos < str.length() && isdigit(str[pos])) {
        result = result * 10 + (str[pos] - '0');
        pos++;
    }
    
    return result;
}

// Sample: extractDecimal("abc123.45"); | Result: 45
int extractDecimal(const std::string& str) {
    size_t decimalPos = str.find('.');
    
    if (decimalPos == std::string::npos) {
        return -1;
    }

    int result = 0;
    
    for (size_t i = decimalPos + 1; i < str.length(); i++) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
    }
    
    return result; // Return the extracted decimal value
}

// Sample: getFileExtension("abc.txt"); | Result: "txt"
std::string getFileExtension(const std::string& filename) {
    size_t dotPosition = filename.find_last_of(".");
    
    if (dotPosition != std::string::npos && dotPosition != 0 && dotPosition != filename.length() - 1) {
        return filename.substr(dotPosition + 1);
    } else {
        return "";
    }
}

// Sample: getFileName("abc.txt"); | Result: "abc"
std::string getFileName(const std::string& filename) {
    size_t dotPosition = filename.find_last_of(".");
    
    if (dotPosition != std::string::npos && dotPosition != 0 && dotPosition != filename.length() - 1) {
        return filename.substr(0, dotPosition);
    } else {
        return filename;
    }
}

//char to string
std::string ctos(char c) {
    return std::string(1, c);
}

//==================================================================================================================
// Cryptography Functions (glencrypt)

// Sample: keyEncrypt("Hello", "testkey"); | Result: "+sNOI"
std::string keyEncrypt(const std::string& input, const std::string& key) {
    std::string output;
    std::string::size_type n = input.length();
    std::string::size_type m = key.length();
    
    const std::string lib = CHAR_LIB;
    
    for (std::string::size_type i = 0; i < n; i++) {
        std::string::size_type converted_input = lib.find(input[i]); 
        std::string::size_type converted_key = lib.find(key[i % m]);
        
        std::string::size_type a = (converted_input + converted_key) % lib.length();
        output += lib[a];
    }
    
    return output;
}

// Sample: keyDecrypt("+sNOI", "testkey"); | Result: "Hello"
std::string keyDecrypt(const std::string& input, const std::string& key) {
    std::string output;
    std::string::size_type n = input.length();
    std::string::size_type m = key.length();
    
    const std::string lib = CHAR_LIB;
    
    for (std::string::size_type i = 0; i < n; i++) { 
        std::string::size_type converted_input = lib.find(input[i]);
        std::string::size_type converted_key = lib.find(key[i % m]); 
        
        std::string::size_type a = (converted_input - converted_key + lib.length()) % lib.length(); 
        output += lib[a];
    }
    
    return output;
}

// Sample: encrypt("Hello"); | Result: "E$E8n"
std::string encrypt(const std::string& input) {
    return keyEncrypt(input.c_str(), DEFAULT_KEY);
}

// Sample: decrypt("E$E8n"); | Result: "Hello"
std::string decrypt(const std::string& input) {
    return keyDecrypt(input.c_str(), DEFAULT_KEY);
}

// Sample: generateKey(10); | Result: "**********" (10 character random key)
std::string generateKey(int length) { 
    static int initialized = 0;
    if (!initialized) {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); 
        initialized = 1;
    }
    
    std::string key;
    for (int i = 0; i < length; i++) {
        key += KEYGEN[static_cast<size_t>(std::rand()) % std::strlen(KEYGEN)]; 
    }
    
    return key;
}

//==================================================================================================================
// Check Functions

// Sample: IsNumericChar('a'); | Result: 0
bool isNumericChar(char ch) {
    return std::isdigit(ch) || ch == '.' || ch == '-' || ch == '+';
}

// Sample: isEmpty(""); | Result: 1
bool isEmpty(const std::string& input) {
    for (char ch : input) {
        if (!std::isspace(ch)) {
            return false;
        }
    }
    return true;
}

//==================================================================================================================
// Improved Input with error handling and specifiers

// Sample: input(int_var, "Enter int: ");
// Sample: input(string_var, "Enter string: ", "abcd1234", 2, 6);
// Sample: input(bool_var, "Enter bool: ", 'T', 'F') | the last 2 parameters control the error message, 0/1 by default

// Function for integer input
void input(int& output, const std::string& prompt, int min = MIN_INT, int max = MAX_INT) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        

        if (input.empty()) {
            invalid("Invalid input. Input must not be empty.");
        }
        else {
            try {
                int temp = std::stoi(input);
                if (temp < min || temp > max) {
                    invalid("Invalid input. Input must be between " + std::to_string(min) + " and " + std::to_string(max) + ".");
                    continue;
                }
                output = temp;
                return;
            }
            catch (const std::invalid_argument&) {
                invalid("Invalid input. Input must be an integer.");
            }
        }
    }
}

// Function for float input
void input(float& output, const std::string& prompt, float min = MIN_FLOAT, float max = MAX_FLOAT) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.empty()) {
            invalid("Invalid input. Input must not be empty.");
        }
        else {
            try {
                float temp = std::stof(input);
                if (temp < min || temp > max) {
                    invalid("Invalid input. Input must be between " + std::to_string(min) + " and " + std::to_string(max) + ".");            
                    continue;
                }
                output = temp;
                return;
            }
            catch (const std::invalid_argument&) {
                invalid("Invalid input. Please enter a valid float.");
            }
        }
    }
}


// Function for double input
void input(double& output, const std::string& prompt, double min = MIN_DOUBLE, double max = MAX_DOUBLE) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.empty()) {
            invalid("Invalid input. Input must not be empty.");
        }
        else {
            try {
                double temp = std::stod(input);
                if (temp < min || temp > max) {
                    invalid("Invalid input. Input must be between " + std::to_string(min) + " and " + std::to_string(max) + ".");            
                    continue;
                }
                output = temp;
                return;
            }
            catch (const std::invalid_argument&) {
                invalid("Invalid input. Please enter a valid double.");
            }
        }
    }
}


// Function for character input
void input(char& output, const std::string& prompt, const std::string& accepted = CHAR_LIB) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.empty()) {
            invalid("Invalid input. Input must not be empty.");
        }
        else if (input.length() != 1) {
            invalid("Invalid input. Input must be a single character.");
        }
        else {
            if (accepted.find(input[0]) == std::string::npos) {
                invalid("Invalid input. Input cannot be '" + input + "'.");
                continue;
            }
            output = input[0];
            return;
        }
    }
}

// Function for string input
void input(std::string& output, const std::string& prompt, const std::string& accepted = CHAR_LIB, std::string::size_type min_length = STRING_INPUT_MIN, std::string::size_type max_length = STRING_INPUT_MAX) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            invalid("Invalid input. Input must not be empty.");
        } else if (input.length() < min_length || input.length() > max_length) {
            invalid("Invalid input. Input must be between " + std::to_string(min_length) + " and " + std::to_string(max_length) + " characters.");
        } else {
            bool is_invalid = false;
            std::string invalid_chars;

            for (char c : input) {
                if (accepted.find(c) == std::string::npos) {
                    is_invalid = true;
                    if (invalid_chars.find(c) == std::string::npos) {
                        invalid_chars += c;
                    }
                }
            }

            if (!is_invalid) {
                output = input;
                return;
            } else {
                invalid("Invalid input. Input cannot contain '" + invalid_chars + "'.");
            }
        }
    }
}

// Function for boolean input
void input(bool& output, const std::string& prompt, const char default_choice_0 = '0', const char default_choice_1 = '1') {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.length() == 1) {
            char ch = input[0];
            if (ch == 'y' || ch == 'Y' || ch == '1' || ch == 't' || ch == 'T' || ch == default_choice_1) {
                output = true;
                return;
            }
            else if (ch == 'n' || ch == 'N' || ch == '0' || ch == 'f' || ch == 'F' || ch == default_choice_0) {
                output = false;
                return;
            }
        }
        
        invalid("Invalid input. Input must be '" + ctos(default_choice_0) + "' or '" + ctos(default_choice_1) + "'.");
    }
}

// Alternative way to use input functionality (Value returning)

int getInt(const std::string& prompt, int min = MIN_INT, int max = MAX_INT) {
    int buffer;
    input(buffer, prompt, min, max);
    return buffer;
}

float getFloat(const std::string& prompt, float min = MIN_FLOAT, float max = MAX_FLOAT) {
    float buffer;
    input(buffer, prompt, min, max);
    return buffer;
}

double getDouble(const std::string& prompt, double min = MIN_DOUBLE, double max = MAX_DOUBLE) {
    double buffer;
    input(buffer, prompt, min, max);
    return buffer;
}

char getChar(const std::string& prompt, const std::string& accepted = CHAR_LIB) {
    char buffer;
    input(buffer, prompt, accepted);
    return buffer;
}

std::string getString(const std::string& prompt, const std::string& accepted = CHAR_LIB, std::string::size_type min_length = STRING_INPUT_MIN, std::string::size_type max_length = STRING_INPUT_MAX) {
    std::string buffer;
    input(buffer, prompt, accepted, min_length, max_length);
    return buffer;
}

bool getBool(const std::string& prompt, const char default_choice_0 = '0', const char default_choice_1 = '1') {
    bool buffer;
    input(buffer, prompt, default_choice_0, default_choice_1);
    return buffer;
}

//==================================================================================================================
// Menu Functions

struct menu {
    const char* text;
    void (*function)();
};

void showMenu_title() {}
void showMenu_subtitle() {}
void showMenu_line() {}
void showMenu_end() {}

bool showMenu_functionCheck(const menu& options, void (*comparisonFunction)()) {
    return options.function == comparisonFunction;
}

int showMenu_findPosition(menu* options, int option) {
    int result = 0;
    int valid_options = 0;
    while(valid_options != option) {
        if (showMenu_functionCheck(options[result], showMenu_title)) {
            result++;
        }
        else if (showMenu_functionCheck(options[result], showMenu_subtitle)) {
            result++;
        }
        else if (showMenu_functionCheck(options[result], showMenu_line)) {
            result++;
        }
        else {
            result++; valid_options++;
        }
    }
    return result-1;
}

#define TITLE showMenu_title
#define SUBTITLE showMenu_subtitle
#define LINE {nullptr, showMenu_line}
#define END_MENU {nullptr, showMenu_end}

const std::string RETURN_TEXT = "Return";

int menu_return = 0;
int end_menu = 0;
int dont_clear_before = 0;
int dont_clear_menu = 0;
int dont_clear_after = 0;
int no_return = 0;
int dont_repeat = 0;
std::string return_text = RETURN_TEXT;

void dontWait() {menu_return = 1;}
void quitMenu() {end_menu = 1;}
void dontClearBefore() {dont_clear_before = 1;}
void dontClearMenu() {dont_clear_menu = 1;}
void dontClearAfter() {dont_clear_after = 1;}
void noReturn() {no_return = 1;}
void dontRepeat() {dont_repeat = 1;}
void setReturnText(const std::string& text) {return_text = text;}

void menuSettings(int dont_clear_before_, int no_return_, int dont_repeat_, int dont_clear_after_, int dont_clear_menu_) {
    dont_clear_before = dont_clear_before_;
    no_return = no_return_;
    dont_repeat = dont_repeat_;
    dont_clear_after = dont_clear_after_;
    dont_clear_menu = dont_clear_menu_;
}

void menuSettings(int dont_clear_before_, int no_return_, int dont_repeat_, int dont_clear_after_, int dont_clear_menu_, const std::string& return_text_) {
    menuSettings(dont_clear_before_, no_return_, dont_repeat_, dont_clear_after_, dont_clear_menu_);
    return_text = return_text_;
}

int displayOptions(const std::string& title, menu* options, int menu_width) {
    line(menu_width);
    if (title != "") {
        printCentered(menu_width, title);
        std::cout << std::endl;
        line(menu_width);
    }

    int i = 0; int excess = 0;
    while (true) {
        if (showMenu_functionCheck(options[i + excess], showMenu_end)) {
            break;
        }
        if (showMenu_functionCheck(options[i + excess], showMenu_title)) {
            line(menu_width);
            printCentered(menu_width, options[i + excess].text);
            std::cout << std::endl;
            line(menu_width);
            excess++;
            continue;
        }
        if (showMenu_functionCheck(options[i + excess], showMenu_subtitle)) {
            std::cout << options[i+excess].text << std::endl;
            excess++;
            continue;
        }
        if (showMenu_functionCheck(options[i + excess], showMenu_line)) {
            line(menu_width);
            excess++;
            continue;
        }

        std::cout << "[" << i+1 << "] " << options[i + excess].text << std::endl;
        i++;
    }

    if (no_return != 1) {
        std::cout << "[0] " << return_text << std::endl;
    }
    return_text = RETURN_TEXT;

    line(menu_width);

    return i;
}

void showMenu(const std::string& title, menu* options, int menu_width = MENU_WIDTH) {
    int count = 0;
    while (count == 0) {
        if (end_menu == 1) {
            end_menu = 0;
            return;
        }
        if (dont_clear_before != 1) {
            system("cls");
        } else {
            dont_clear_before = 0;
        }

        int option_count = displayOptions(title, options, menu_width);

        int choice;
        input(choice, "Enter Choice: ");

        if (choice == 0 && no_return != 1) {
            menu_return = 1;
            return;
        } else if (choice == 0 && no_return == 1) {
            invalid(INVALID_CHOICE, menu_width);
            continue;
        }

        if (choice > option_count || choice < 0) {
            invalid(INVALID_CHOICE, menu_width);
            continue;
        }

        if (dont_clear_menu != 1) {
            system("cls");
        } else {
            dont_clear_menu = 0;
        }

        options[showMenu_findPosition(options, choice)].function();
        if (menu_return != 1) {
            waitEnter();
            if (dont_clear_after != 1) {
                system("cls");
            } else {
                dont_clear_after = 0;
            }
        }

        if (dont_repeat == 1) {
            dont_repeat = 0;
            end_menu = 0;
            count++;
        }
        
        no_return = 0;
        menu_return = 0;
    }
}

void showMenuOnce(const std::string& title, menu* options, int menu_width = MENU_WIDTH) {
    dontRepeat();
    showMenu(title, options, menu_width);
}

/* Sample for showMenu()
    menu test[] = {
        {"Option 1", function1},
        LINE,
        {"Test subtitle", SUBTITLE},
        {"Option 2", function2},
        END_MENU
    };
    showMenu("Menu", test)
*/

#define END_PAGE_MENU nullptr

struct page_menu {
    menu* options;
};

void showPageMenu(const std::string& title, page_menu* page, int menu_width = MENU_WIDTH) {
    int current_page = 0;
    int page_count = 0;

    while (page[page_count].options != nullptr) {
        page_count++;
    }
    
    while(true) {

        if (end_menu == 1) {
            end_menu = 0;
            return;
        }
        
        system("cls");
        line(menu_width);
        if (title != "") {
            printCentered(menu_width, title + " [" + std::to_string(current_page+1) + "/" + std::to_string(page_count) + "]");
            std::cout << std::endl;
            line(menu_width);
        }
        int i = 0; int excess = 0;

        while (true) {
            if(i >= MENU_PAGE_LENGTH) {
                Win::color(Win::RED, "ERROR: Page Overflow.\n");
                return;
            }

            if (showMenu_functionCheck(page[current_page].options[i+excess], showMenu_end)) {
                break;
            }
            if (showMenu_functionCheck(page[current_page].options[i+excess], showMenu_title)) {
                line(menu_width);
                printCentered(menu_width, page[current_page].options[i + excess].text);
                std::cout << std::endl;
                line(menu_width);
                excess++;
                continue;
            }
            if (showMenu_functionCheck(page[current_page].options[i+excess], showMenu_subtitle)) {
                std::cout << page[current_page].options[i+excess].text << std::endl;
                excess++;
                continue;
            }
            if (showMenu_functionCheck(page[current_page].options[i+excess], showMenu_line)) {
                line(menu_width);
                excess++;
                continue;
            }

            std::cout << "[" << i+1 << "] " << page[current_page].options[i + excess].text << std::endl;
            i++;
        }
        
        line(menu_width);

		if (current_page > 0) {
			std::cout << "[8] Previous Page" << std::endl;
		}
		if (current_page != page_count-1) {
			std::cout << "[9] Next Page" << std::endl;
		}
        std::cout << "[0] Return" << std::endl;
        if (title == "") {
            std::cout << "Page [" + std::to_string(current_page+1) + "/" + std::to_string(page_count) + "]" << std::endl;
        }
        line(menu_width);
        int choice;
        input(choice, "Enter Choice: ");
        
        switch(choice) {
            case 8: 
                if (current_page > 0) {	
                    current_page--;				
                    continue;
                }
                else {
                    invalid();
                    continue;
                }
            case 0: menu_return = 1; return;
            case 9: 
                if (current_page != page_count-1) {	
                    current_page++;
                    continue;
                }
                else {
                    invalid();
                    continue;
                }
            default: break;
        }

        if ((choice > i && choice != 8 && choice != 9) || choice < 0) {
            invalid(INVALID_CHOICE, menu_width);
            continue;
        }

        if (dont_clear_menu != 1) {
            system("cls");
        } else {
            dont_clear_menu = 0;
        }


        page[current_page].options[showMenu_findPosition(page[current_page].options, choice)].function();


        if (menu_return != 1) {
            waitEnter();
            if (dont_clear_after != 1) {
                system("cls");
            } else {
                dont_clear_after = 0;
            }
        }

        menu_return = 0;
    }
}
/*
menu page1[] = {
    {"Option 1", function1},
    LINE,
    {"Test subtitle", SUBTITLE},
    {"Option 2", function2},
    END_MENU
};

menu page2[] = {
    {"Option 3", function3},
    {"Option 4", function4},
    END_MENU
};

page_menu test2[] = {
    page1,
    page2,
    END_PAGE_MENU
};

showPageMenu("Page Menu", test2);
*/

//==================================================================================================================
// Table Functions

struct table {
    std::string header;
    void* sub_struct;
    size_t content_size;
    size_t struct_size;
    std::string format; 
    size_t offset;
};

template <typename T, typename U>
std::size_t getOffset(const T& array, const U& member) {
    return reinterpret_cast<std::size_t>(&member) - reinterpret_cast<std::size_t>(&array);
}

// #define COL(HEADER, SOURCE, MEMBER, FORMAT) {HEADER, &SOURCE[0].MEMBER, sizeof(SOURCE)/sizeof(SOURCE[0]), sizeof(SOURCE[0]), FORMAT, offsetof(typeof(*(SOURCE)), MEMBER)}
#define COL(HEADER, SOURCE, MEMBER, FORMAT) {HEADER, &SOURCE[0].MEMBER, sizeof(SOURCE)/sizeof(SOURCE[0]), sizeof(SOURCE[0]), FORMAT, getOffset(SOURCE, SOURCE[0].MEMBER)}
#define END_TABLE {"end_table", NULL, 0, 0, "", 0}

void printTableFull(const std::string& title, table* data) {
    int num_columns = 0;
    while(data[num_columns].header != "end_table") {
        num_columns++;
    }

    int table_width = num_columns + 1;
    for (int i = 0; i < num_columns; i++) {
        table_width += extractNumber(data[i].format);
    }

    //Print title
    line(table_width);

    if (title != "") {  
        printCentered(table_width, title);
        std::cout << std::endl;
        line(table_width);
    }

    //Print headers
    std::cout << "|";
    for (int i = 0; i < num_columns; i++) {
        int column_width = extractNumber(data[i].format);
        
        if (data[i].header.length() > column_width) {
            print(truncate(data[i].header, column_width));
        }
        else {
        printCentered(column_width, data[i].header);
        }

        std::cout << "|";
    }
    std::cout << std::endl;

    //Print content
    for (size_t i = 0; i < data->content_size; i++) {
        std::cout << "|";
        for (int j = 0; j < num_columns; j++) {
            uintptr_t address = ((uintptr_t)data[0].sub_struct + data[j].offset) + (i * data[j].struct_size);

            std::string buffer;

            if (typeFromFormat(data[j].format) == "int") {
                buffer = convertString(*reinterpret_cast<int*>(address));
            } 
            else if (typeFromFormat(data[j].format) == "string") {
                buffer = convertString(*reinterpret_cast<std::string*>(address));
            } 
            else if (typeFromFormat(data[j].format) == "float") {
                buffer = convertString(*reinterpret_cast<float*>(address));
            }
            else if (typeFromFormat(data[j].format) == "double") {
                buffer = convertString(*reinterpret_cast<double*>(address));
            }
            else if (typeFromFormat(data[j].format) == "char") {
                buffer = convertString(*reinterpret_cast<char*>(address));
            }
            else if (typeFromFormat(data[j].format) == "bool") {
                buffer = convertString((*reinterpret_cast<bool*>(address) ? "True" : "False"));
            }
            else {
                buffer = "Unknown";
            }
            std::cout << " " << formatString(buffer, extractNumber(data[j].format) - 1, extractDecimal(data[j].format)) << "|";

        }
            
        std::cout << std::endl;
    }
    line(table_width);
}

void printTable(const std::string& title, table* data) {
    int num_columns = 0;
    while(data[num_columns].header != "end_table") {
        num_columns++;
    }

    size_t page = 0;
    size_t max_page = ((data->content_size) / TABLE_PAGE_LENGTH) - 1 ;
    size_t page_row_counter = 0; size_t table_row_counter = 0;

    if ((data->content_size) % TABLE_PAGE_LENGTH != 0) {
        max_page++;
    }
    

    while(1) {
        system("cls");
        int table_width = num_columns + 1;
        for (int i = 0; i < num_columns; i++) {
            table_width += extractNumber(data[i].format);
        }
        
        //Print title
        line(table_width);
        if (title != "") {  
            printCentered(table_width, title);
            std::cout << std::endl;
            line(table_width);
        }

        //Print headers
        std::cout << "|";
        for (int i = 0; i < num_columns; i++) {
            int column_width = extractNumber(data[i].format);

            if (data[i].header.length() > column_width) {
                print(truncate(data[i].header, column_width));
            }
            else {
            printCentered(column_width, data[i].header);
            }

            std::cout << "|";
        }
        std::cout << std::endl;

        //Print content
        for (; page_row_counter < TABLE_PAGE_LENGTH && table_row_counter < data->content_size; page_row_counter++, table_row_counter++) {
            std::cout << "|";
            for (int j = 0; j < num_columns; j++) {
                uintptr_t address = ((uintptr_t)data[0].sub_struct + data[j].offset) + (table_row_counter * data[j].struct_size);

                std::string buffer;

                if (typeFromFormat(data[j].format) == "int") {
                    buffer = convertString(*reinterpret_cast<int*>(address));
                } 
                else if (typeFromFormat(data[j].format) == "string") {
                    buffer = convertString(*reinterpret_cast<std::string*>(address));
                } 
                else if (typeFromFormat(data[j].format) == "float") {
                    buffer = convertString(*reinterpret_cast<float*>(address));
                }
                else if (typeFromFormat(data[j].format) == "double") {
                    buffer = convertString(*reinterpret_cast<double*>(address));
                }
                else if (typeFromFormat(data[j].format) == "char") {
                    buffer = convertString(*reinterpret_cast<char*>(address));
                }
                else if (typeFromFormat(data[j].format) == "bool") {
                    buffer = convertString((*reinterpret_cast<bool*>(address) ? "True" : "False"));
                }
                else {
                    buffer = "N/A";
                }

                std::cout << " " << formatString(buffer, extractNumber(data[j].format) - 1, extractDecimal(data[j].format)) << "|";

            }
                
            std::cout << std::endl;
        }
        page_row_counter = 0;
        line(table_width);

        std::cout << " Page " << page+1 << " of " << max_page+1 << "   ";
        if (page > 0) {
            std::cout << " [8] Previous   ";
        }
        if (table_width < 31) {
            std::cout << std::endl;
        }
        if (page != max_page) {
            std::cout << " [9] Next   ";
        }
        std::cout << " [0] Return" << std::endl;

        line(table_width);

        int choice;
        input(choice, "Enter Choice: ");
        
        switch (choice) {
            case 8:
                if (page > 0) {	
                    page--;
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    break;
                }
                else {
                    invalid(INVALID_CHOICE, table_width);
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    continue;
                }
                
            case 9:
                if (page != max_page) {	
                    page++;
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    break;
                }
                else {
                    invalid(INVALID_CHOICE, table_width);
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    continue;
                }
            case 0:
                line(table_width);
                return;
                break;
            default:
                invalid(INVALID_CHOICE, table_width);
                table_row_counter = page*TABLE_PAGE_LENGTH;
                continue; 
        }

    }

    // sample table
    // table record[] = {
    //     COL("Name", students, name, "20s"),
    //     COL("GWA", students, gwa, "7.2lf"),
    //     END_TABLE
    // }; printTableFull("Students by GWA", record);


}

//==================================================================================================================
// New Misc Functions

std::string getOrdinal(int n) {
    if (n % 10 == 1 && n % 100 != 11) {
        return std::to_string(n) + "st";
    }
    else if (n % 10 == 2 && n % 100 != 12) {
        return std::to_string(n) + "nd";
    }
    else if (n % 10 == 3 && n % 100 != 13) {
        return std::to_string(n) + "rd";
    }
    else {
        return std::to_string(n) + "th";
    }
}





}
#endif // GLENLIB_HPP