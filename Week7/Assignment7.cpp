#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fname;
    std::string targetWord; // these are the string variable names
    std::string replaceWord;
    
    std::cout << "Enter the input file name: ";
    std::cin >> fname; // takes the input file name from the user
    
    std::cout << "Enter the word to search for: ";
    std::cin >> targetWord; // takes the word to search for from the user
    
    std::cout << "Enter the replacement word: ";
    std::cin >> replaceWord; // takes the replacement word from the user
    
    // open files
    std::ifstream inFile; // ifstream opens the input file
    inFile.open(fname); // open the actual file inputted by the user
    
    if(!inFile) { // if statement to check if the file is opened successfully, if not it will print an error message and return 1
        std::cout << "Error opening file!" << std::endl;
        return 1; // returns 1 to indicate an error
    }
    
    std::ofstream outFile("output.txt"); // ofstream opens the output file named output.txt
    
    std::string currentWord; // variable to hold the current word from the input file
    int matches = 0;
    
    // read word by word
    while (inFile >> currentWord) { // while loop to read the input file word by word
        if (currentWord == targetWord) { // if current word is the same as the target word, it will replace it with replacement
            currentWord = replaceWord;
            matches++; // increases the matches by 1
        }
        outFile << currentWord << " "; // writes the current word to the output file
    }
    
    inFile.close(); // file closes
    outFile.close(); // file closes
    
    std::cout << "Total replacements: " << matches << std::endl; // output message to show how many replacements were made
    std::cout << "Done writing to output.txt" << std::endl; // output message to show that the program is done writing to the output file
    
    return 0;
}