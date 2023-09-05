#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <Windows.h>  //
#include <unistd.h> //
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

template <typename T>
std::string convertString(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string trimZeros(const std::string& numStr) {
    size_t decimalPointPos = numStr.find('.');
    
    if (decimalPointPos != std::string::npos) {
        size_t lastNonZeroDigit = numStr.find_last_not_of('0');
        
        if (lastNonZeroDigit == decimalPointPos) {
            // If there are no non-zero digits after the decimal point, remove it too.
            return numStr.substr(0, decimalPointPos);
        } else {
            // Remove trailing zeros after the decimal point.
            return numStr.substr(0, lastNonZeroDigit + 1);
        }
    }

    // If there's no decimal point, no action is needed.
    return numStr;
}

std::string truncate(const std::string& inputString, int width) {

    if (width == 0) {
        return inputString;
    }

    std::string input_buffer = trimZeros(inputString);

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

template <typename T>
std::string formatString(const T& value, int width = 0, int precision = -1) {
    std::stringstream ss;
    
    if ((precision >= 0 && typeid(T) == typeid(float)) || typeid(T) == typeid(double)) {
        ss << std::fixed << std::setprecision(precision);
    }

    ss << value;
    
    return truncate(ss.str(), width);
}

void printLineWidth(int width) { //print line with custom width
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

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



    // Calculate padding based on field_width and the formatted string length
    int left_padding = total_padding / 2;
    int right_padding = total_padding / 2;

    if (total_padding % 2 != 0) {
        right_padding++;
    }

    // std::cout << field_width << std::endl;
    // std::cout << length << std::endl;

    // std::cout << total_padding << std::endl;
    // std::cout << left_padding << std::endl;
    // std::cout << right_padding << std::endl;

    // Print the left padding
    for (int i = 0; i < left_padding; ++i) {
        std::cout << ' ';
    }

    // Print the formatted string
    vprintf(c_format, args);

    // Print the right padding
    for (int i = 0; i < right_padding; ++i) {
        std::cout << ' ';
    }

    va_end(args);
}

int extractNumber(const std::string& str) {
    // Skip leading whitespaces and non-digit characters
    size_t pos = 0;
    while (pos < str.length() && !isdigit(str[pos])) {
        pos++;
    }
    
    // Extract the numeric part (integral part only)
    int result = 0;
    while (pos < str.length() && isdigit(str[pos])) {
        result = result * 10 + (str[pos] - '0');
        pos++;
    }
    
    return result; // Return the extracted number
}

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


int extractDecimal(const std::string& str) {
    // Find the position of the decimal point
    size_t decimalPos = str.find('.');
    
    if (decimalPos == std::string::npos) {
        // No decimal point found, return 0
        return 0;
    }
    
    // Extract the digits after the decimal point
    int result = 0;
    
    for (size_t i = decimalPos + 1; i < str.length(); i++) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } else {
            // If a non-digit character is encountered, stop extracting
            break;
        }
    }
    
    return result; // Return the extracted decimal value
}



struct table {
    std::string header;
    void* sub_struct;
    size_t content_size;
    size_t struct_size;
    std::string format; 
    size_t offset;
};

#define END_TABLE {"end_table", NULL, 0, 0, "", 0}

void printTable(const std::string& title, table* data) {
    int num_columns = 0;
    while(data[num_columns].header != "end_table") {
        num_columns++;
    }

    // std::cout << num_columns;
    
    int table_width = num_columns + 1;
    for (int i = 0; i < num_columns; i++) {
        table_width += extractNumber(data[i].format);
    }
    // std::cout << table_width;

    //Print title
    printLineWidth(table_width);
    printCentered(table_width, title);
    std::cout << std::endl;
    printLineWidth(table_width);

    //Print headers
    std::cout << "|";
    for (int i = 0; i < num_columns; i++) {
        int column_width = extractNumber(data[i].format);
        printCentered(column_width, data[i].header);
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

            std::cout << " " << formatString(buffer, extractNumber(data[j].format) - 1) << "|";

        }
            
        std::cout << std::endl;
    }

}

typedef struct {
    int id;
    std::string name;
    float floatval;
    double doubleval;
    char charval;
    bool boolval;
} person;

person people[] = {
    {1, "John", 1.1f, 2.2, 'c', true},
    {2, "Jane", 3.3f, 4.4, 'd', false},
};

#define TCOL(HEADER, SOURCE, MEMBER, FORMAT) {HEADER, &SOURCE[0].MEMBER, sizeof(SOURCE)/sizeof(SOURCE[0]), sizeof(SOURCE[0]), FORMAT, offsetof(typeof(*(SOURCE)), MEMBER)}

table TEST[] = {
    TCOL("ID", people, id, "9d"),
    TCOL("Name", people, name, "12s"),
    TCOL("Float", people, floatval, "12f"),
    TCOL("Double", people, doubleval, "12lf"),
    TCOL("Char", people, charval, "12c"),
    TCOL("Bool", people, boolval, "12b"),
    END_TABLE
};

int main() {
    printTable("Title", TEST);

    // std::cout << formatString("asdfghj", 5);

    return 0;
}
