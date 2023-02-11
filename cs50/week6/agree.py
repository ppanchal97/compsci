s = input("do you agree? ")

if s.lower() in ["y", "yes"]:
    print("agreed.")
elif s.lower() in ["n", "no"]:
    print("not agreed.")
else:
    print("not recognized.")