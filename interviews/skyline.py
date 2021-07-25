"""
Boxes in the Sky

7 |
6 | ---
5 | | |   --- ---
4 | | |   | | | |
3 | | |   | --- |
2 | | |---|     |--
1 | |             |
  -----------------
  0 1 2 3 4 5 6 7 8

In this skyline, you could have a box of width
1 at position 1 of height 5 (area 5), but the
optimal box is of height 3 and width 3 starting
at position 4 (area 9).

For an arbitrary skyline, find the area of
the optimal box.

Input: The height of the skyline at each position:
[0, 6, 2, 4, 5, 7, 9, 0]
Output: The area of the optimal box: 9
"""

def area_of_best_box(skyline):
        
    raise NotImplementedError

def run():
    # ([Skyline], Area of best box)
    skylines = [
        ([5,4], 8),
        ([4,2,3,1], 6),
        ([4,3,2,1], 6),
        ([5,5,5,5], 20),
        ([1,3,7,4,2], 9),
        ([1,2,3,4,5,6,7,8,9], 25),
        ]

    for s in skylines:
        print (f"Testing on skyline: {s[0]}. Expect area to be: {s[1]}")
        assert area_of_best_box(s[0]) == s[1]

    print ("Success!")

run()
