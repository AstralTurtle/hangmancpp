#include <iostream>
#include <string>
#include <array>
#include <random>



class Hangman {
    std::string solution;
    std::array<char, 26> guessed = {};
    int attempts;
    int length;

public:
    bool isSolved;

    explicit Hangman(std::string sol) {
        solution = sol;
        length = sol.length();
        attempts = 0;
        isSolved = false;

    }

    int search(char c) {
        for (int i = 0; i < 26; i++) {
            if (guessed[i] == c) {
                return i;
            }
        }
        return -1;
    }


    std::string displayedWord() {
        std::string ret = "";
        for (int i = 0; i < length; i++) {
//            DEBUG: print search result and the current letter
//            std::cout << search(solution[i]) << " " << solution[i] << std::endl;
            if (search(solution[i]) != -1) {
                ret += solution[i];
            } else {
                ret += "_";
            }
        }
return ret;
    }


    void guess(char c) {
        if (solution.find(c) != std::string::npos) {
            guessed[c - 'a'] = c;
//            DEBUG: Print the guessed array
//            for (int i = 0; i < 26; i++) {
//                std::cout << guessed[i];
//            }
//            std::cout << "Correct guess!, attempts left: " << 6 - attempts << std::endl;
        } else {
            attempts++;
            std::cout << "Wrong guess, attempts left: " << 6 - attempts << std::endl;
        }


        if (displayedWord() == solution) {
            std::cout << "You won! The word was " << solution << std::endl;
            isSolved = true;
        } else if (attempts >= 6) {
            std::cout << "You lost! The word was " << solution << std::endl;
            isSolved = true;
        } else
            std::cout << "current word: " << displayedWord() << std::endl;
    }

};


std::string randomWord() {
//    list of words
    std::string words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi",
                           "lemon", "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry",
                           "tangerine", "watermelon", "yuzu","paper", "pencil", "eraser", "notebook", "book",
                           "laptop", "computer", "keyboard", "solve", "exam", "switch", "development", "programming",
                            "language", "english", "spanish", "french", "german", "italian", "portuguese", "russian",
                            "aptitude", "reasoning", "verbal", "nonverbal", "quantitative", "logical", "analytical",
                            "data", "interpretation","hope", "faith", "love", "peace", "joy", "happiness", "sadness"};

//    gen random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 56);
    return words[dis(gen)];
}



int main() {
    Hangman game = Hangman(randomWord());
    while (!game.isSolved){
        std::cout << "Guess a letter: ";
        char c;
        std::cin >> c;
        game.guess(c);
    }

    return 0;
}
