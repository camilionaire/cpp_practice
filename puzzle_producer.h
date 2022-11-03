#ifndef PUZZLE_PRODUCER_H
#define PUZZLE_PRODUCER_H

#include <vector>

namespace Puzzler 
{
    class Puzzle_producer
    {
        private: // list of words for puzzle
        std::vector<char[]> word_list;

        public:
        // constructor
        Puzzle_producer();

        // adds a word to the list, true for success
        bool add_word(char[]);
        // returns a width by height vector of vector of chars puzzle
        // with the words in the word list.
        std::vector<std::vector<char>> get_that_puzzle(int, int);
        
        // extra stuff that I thought might be useful
        bool remove_word(char[]);
        std::vector<char[]> get_word_list();
    };
}
#endif