from cs50 import get_string

text = get_string("Text: ")


def number_of_words(text):
    words = len(text.split())
    return words

def number_of_letters(text):
    count = 0
    for letters in text:
        if letters.isalpha() is True:
            count +=1
    return count

def number_of_sentences(text):
    sentence1 = text.count('.')
    sentence2 = text.count('!')
    sentence3 = text.count('?')
    sentences = sentence1 + sentence2 + sentence3
    return sentences

L = 100 * number_of_letters(text) / number_of_words(text)
S = 100 * number_of_sentences(text) / number_of_words(text)

answer = round( 0.0588 * L - 0.296 * S - 15.8 )

if answer > 1 and answer < 16:
    print("Grade: " + str(answer))
elif answer < 1:
    print("Grade: Before Grade 1")
elif answer > 16:
    print("Grade: 16+")
else:
    print("Error")



