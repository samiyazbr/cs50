import math
from cs50 import get_string


def count_letters(text):
    letter_count = sum(1 for char in text if char.isalpha())
    return letter_count


def count_words(text):
    word_count = len(text.split())
    return word_count


def count_sentences(text):
    sentence_count = text.count(".") + text.count("!") + text.count("?")
    return sentence_count


def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


main()
