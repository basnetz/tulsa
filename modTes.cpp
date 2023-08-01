#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A struct to represent a word and its corresponding mood.
struct Word {
  string word;
  string mood;
};

// A vector of words and their corresponding moods.
vector<Word> words = {
  {"happy", "positive"},
  {"sad", "negative"},
  {"angry", "negative"},
  {"excited", "positive"},
  {"bored", "negative"},
};

// A function to find the mood of a given text.
string findMood(string text) {
  // Split the text into words.
  vector<string> wordsInText = text.split(" ");

  // Initialize a counter for each mood.
  int positiveCount = 0;
  int negativeCount = 0;

  // Iterate over the words in the text.
  for (string word : wordsInText) {
    // Find the mood of the word.
    string mood = "";
    for (Word w : words) {
      if (w.word == word) {
        mood = w.mood;
        break;
      }
    }

    // Increment the counter for the corresponding mood.
    if (mood == "positive") {
      positiveCount++;
    } else if (mood == "negative") {
      negativeCount++;
    }
  }

  // Return the mood with the higher count.
  if (positiveCount > negativeCount) {
    return "positive";
  } else {
    return "negative";
  }
}

int main() {
  // Get the text from the user.
  string text;
  cout << "Enter some text: ";
  getline(cin, text);

  // Find the mood of the text.
  string mood = findMood(text);

  // Print the mood of the text.
  cout << "The mood of the text is: " << mood << endl;

  return 0;
}
