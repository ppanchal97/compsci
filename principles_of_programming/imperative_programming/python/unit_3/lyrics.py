import string

# Get frequencies of each lyric
def lyrics_to_frequencies(lyrics):
    freqs = {}

    for lyric in lyrics.split(" "):
        lyric = lyric.translate(str.maketrans('', '', string.punctuation))
        if lyric.lower() in freqs.keys() and lyric != ' ':
            freqs[lyric.lower()] += 1
        else:
            freqs[lyric.lower()] = 1

    return freqs


# Words with the highest frequency
def most_common_words(freqs):
    max_frequency = max(freqs.values())
    most_common = []

    for lyric, count in freqs.items():
        if count == max_frequency:
            most_common.append(lyric)

    return most_common

# List of words that occur at-least min_times
def words_often(freqs, min_times):
    words = []
    for lyric, count in freqs.items():
        if count >= min_times:
            words.append(lyric)

    return words


def main():
    lyrics = "Love, love me do You know I love you I'll always be true So me please, love me do Whoa, love me do Love, love me do You know I love me I'll always be me, true So me please, love me do Whoa, love me do"

    freqs = lyrics_to_frequencies(lyrics)
    
    most_common_lyrics = most_common_words(freqs)

    print(words_often(freqs, 5))


main()