#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <string>
=======
>>>>>>> upstream/main


void removeCopies(std::vector<int>& data){

<<<<<<< HEAD
    if (data.size() == 0) { // if the vector is empty, it will do nothing and return
        return;
    }

    int origin = 1; // position where the next new number should go

    for (int i = 1; i < data.size(); i++) { // starts going through the vector after the first number
        if (data[i] != data[i - 1]) { // if current number is different from the one before it, it becomes a new number
            data[origin] = data[i]; // put this new number in the correct spot
            origin++; // goes to the next spot adding 1
        }
    }

    data.resize(origin); // it removes the extra numbers that repeated
=======
    // The vector is sorted in non-decreasing order.
    // Remove all duplicate values in-place so that
    // each value appears exactly once.
    //
    // Do not create another vector.
    // Modify the vector named "data" directly.
    //
    // Maybe two-pointer method? Hmm?
    // Hint: resize() function
>>>>>>> upstream/main

}

void isAnagram(std::string officer_name, std::string spy_name){

<<<<<<< HEAD
    if (officer_name.length() != spy_name.length()) { // if its different lengths, it cannot be anagrams
        std::cout << "IMPOSTER!" << std::endl;
        return;
    }

    std::vector<int> letters(26, 0); // all the spaces between a-z

    for (int i = 0; i < officer_name.length(); i++) { // going through the officers name
        letters[officer_name[i] - 'a']++; // counting each letter and adding 1 at the end
    }

    for (int i = 0; i < spy_name.length(); i++) { // looping through the spy name
        letters[spy_name[i] - 'a']--; // subtract each letter
    }

    for (int i = 0; i < 26; i++) { // check every letter count
        if (letters[i] != 0) { // if any of the counts is not equal to zero, it means they are not anagrams
            std::cout << "IMPOSTER!" << std::endl;
            return;
        }
    }

    std::cout << "No imposter found!" << std::endl; 
=======
    // Write code to see if the spy name is an anagram of the officer name 
    // Maybe a vector of size 26? Hmm?
>>>>>>> upstream/main

}

int main(){

    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    /*Print out the original server vector before function called*/
     for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
    }
<<<<<<< HEAD
    std::cout << std::endl;
=======
>>>>>>> upstream/main

    removeCopies(server);
    
    /*Print out the modification of the server vector after function called*/
    for (auto data : server){
        std::cout << data << " ";
    }

    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/

    isAnagram("syeda", "aysed"); // No imposter detected!
    isAnagram("angelo", "annabeth"); // IMPOSTER! IMPOSTER!

    return 0;

}
