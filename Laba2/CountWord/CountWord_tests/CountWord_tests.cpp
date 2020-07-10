#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../CountWord/MapCount.h"

using namespace std;
TEST_CASE("One word") {
	map<string, size_t> wordMap;
	stringstream test("Hello");
	wordMap = CreateWordsMap(test);
	CHECK(wordMap.count("hello") == 1);
	CHECK(wordMap.size() == 1);
}

TEST_CASE("One word string") {
	map<string, size_t> wordMap;
	stringstream test("Hello Big World !");
	wordMap = CreateWordsMap(test);
	CHECK(wordMap.count("hello") == 1);
	CHECK(wordMap.count("big") == 1);
	CHECK(wordMap.count("world") == 1);
	CHECK(wordMap.count("!") == 1);
	CHECK(wordMap.size() == 4);
}

TEST_CASE("Empty line") {
	map<string, size_t> wordMap;
	stringstream test("");
	wordMap = CreateWordsMap(test);
	CHECK(wordMap.size() == 0);
}

TEST_CASE("Different spelling of the word") {
	map<string, size_t> wordMap;
	stringstream test("Hello HELLO hellO WORLD world");
	wordMap = CreateWordsMap(test);
	CHECK(wordMap["hello"] == 3);
	CHECK(wordMap["world"] == 2);
	CHECK(wordMap.size() == 2);
}

TEST_CASE("Single word output") {
	stringstream test("Hello");
	string wordMapString = WordsMapToString(CreateWordsMap(test));
	CHECK(wordMapString == "hello - 1\n");
}

TEST_CASE("String word output") {
	stringstream test("Hello World !");
	string wordMapString = WordsMapToString(CreateWordsMap(test));
	CHECK(wordMapString == "! - 1\nhello - 1\nworld - 1\n");
}

TEST_CASE("Miscellaneous spelling of the word conclusion") {
	stringstream test("Hello HELLO hellO WORLD world !");
	string wordMapString = WordsMapToString(CreateWordsMap(test));
	CHECK(wordMapString == "! - 1\nhello - 3\nworld - 2\n");
}

TEST_CASE("Output empty string") {
	stringstream test("");
	string wordMapString = WordsMapToString(CreateWordsMap(test));
	CHECK(wordMapString == "");
}
