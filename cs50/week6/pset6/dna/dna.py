import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/large.csv sequences/5.txt")
        return

    # TODO: Read database file into a variable
    database = sys.argv[1]
    
    # TODO: Read DNA sequence file into a variable
    sequence = sys.argv[2]

    shortTandemRepeats = dict()

    # use full paths for testing
    with open(f"/Users/parik97/Desktop/code/cs50/week6/pset6/dna/{database}") as dna_database:
        with open(f"/Users/parik97/Desktop/code/cs50/week6/pset6/dna/{sequence}") as dna_sequence:
            csv_reader = csv.reader(dna_database, delimiter=",")
            line_count = 0
            for row in csv_reader:
                if line_count == 0:
                    for i in range(1, len(row)):
                        shortTandemRepeats[row[i]] = 0
                    sq = dna_sequence.read()
                    # populate STR dict
                    for str in shortTandemRepeats.keys():
                        shortTandemRepeats[str] = longest_match(sq, str)
                    line_count += 1
                else:
                    # start comparing
                    for i in range(0, len(shortTandemRepeats)):
                        if int(row[i + 1]) != shortTandemRepeats[list(shortTandemRepeats.keys())[i]]:
                            break
                        # reached end
                        if i == len(shortTandemRepeats) - 1:
                            print(row[0])
                            return


    
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
