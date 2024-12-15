#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "wordle_solver.h"

using std::string;
using std::cout;
using std::endl;

std::ifstream word_list_file("word_list.txt");
std::vector<std::string> candidates;
WordleSolver solver(candidates);

bool all_tests_passed = true;

void check(bool condition, const std::string& message, const char* file, int line) {
    if (!condition) {
        std::cerr << "Test failed: " << message << " in file " << file << " at line " << line << std::endl;
        all_tests_passed = false;
    }
}

#define CHECK(condition, message) check(condition, message, __FILE__, __LINE__)

bool startup() {
    if (!word_list_file) {
        std::cerr << "Error: Could not open file " << std::endl;
        return false;
    } else {
        solver.read_candidates(word_list_file);
        candidates = solver.getCandidates();
        return true;
    }
}

void testfunctions() {
    // Test so that the list in wordle actually gets bigger when a file is inputted.
    CHECK(solver.getCandidates().size() > 0, "Candidates list should not be empty after reading from file");

    // Check so the vector doesn't contain any gaps and all words are 5 letters long.
    for (const string& str : solver.getCandidates()) {
        CHECK(!str.empty(), "Candidate should not be an empty string");
        CHECK(str.length() == 5, "Candidate should be 5 letters long");
    }

    // Test contains_at indirectly through contains_any_of
    CHECK(solver.contains_any_of("apple", "a"), "contains_any_of should return true for 'a' in 'apple'");
    CHECK(!solver.contains_any_of("apple", "z"), "contains_any_of should return false for 'z' in 'apple'");

    // Test contains_but_not_at indirectly through contains_any_of
    CHECK(solver.contains_any_of("apple", "p"), "contains_any_of should return true for 'p' in 'apple'");
    CHECK(!solver.contains_any_of("apple", "x"), "contains_any_of should return false for 'x' in 'apple'");

    // Additional tests for contains_any_of
    CHECK(solver.contains_any_of("apple", "ae"), "contains_any_of should return true for 'a' or 'e' in 'apple'");
    CHECK(!solver.contains_any_of("apple", "xyz"), "contains_any_of should return false for 'x', 'y', or 'z' in 'apple'");

    if (all_tests_passed) {
        cout << "testfunctions: All tests passed." << endl;
    }
}

void test_functors() {
    // Test wrong_fn
    WordleSolver::wrong_fn wrong("aeiou");
    CHECK(wrong("apple"), "wrong_fn should return true for 'apple' with vowels 'aeiou'");
    CHECK(!wrong("bcdfg"), "wrong_fn should return false for 'bcdfg' with vowels 'aeiou'");

    // Test correct_fn 
    WordleSolver::correct_fn correct({{0, "a"}, {1, "p"}});
    CHECK(!correct("apple"), "correct_fn should return false for 'apple' with positions {0, 'a'} and {1, 'p'}");

    // Test misplaced_fn
    WordleSolver::misplaced_fn misplaced({{0, "a"}, {1, "p"}});
    CHECK(!misplaced("apple"), "misplaced_fn should return false for 'apple' with positions {0, 'a'} and {1, 'p'}");

    if (all_tests_passed) {
        cout << "test_functors: All tests passed." << endl;
    }
}

int main() {
    if (startup()) {
        testfunctions();
        test_functors();
    }

    return 0;
}