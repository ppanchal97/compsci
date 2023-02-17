'''
example facts:
 m = 3.20ft
 ft = 12 in
 hr = 60 min

example queries:
 2 m = ? in   --> answer = 78.72
 13 in = ? m  --> answer = 0.330 (roughly)
 13 in = ? hr --> "not convertible!"
'''


def load_facts():
    # load and return facts as dictionary
    return {
        "m": {"ft": 3.20, "in": 39.3701},
        "ft": {"in": 12, "m": "0.3048"},
        "in": {"ft": 0.0833333, "m": 0.0254},
        "hr": {"min": 60}
    }


def unit_conversion(facts, query):
    if query[1] in facts.keys():
        f = facts[query[1]]
        if query[2] in f.keys():
            print(f"answer = {query[0] * f[query[2]]}{query[2]}")
        else:
            print("not a valid conversion!")
            return
    else:
        print("not a valid unit!")
        return


def main():
    query = (2, "m", "in")
    facts = load_facts()
    unit_conversion(facts, query)


main()
