Tower of Hanoi | GeeksforGeeks - YouTube

Towers of Hanoi: A Complete Recursive Visualization - YouTube

The Tower of Hanoi is a puzzle where n disks of different sizes are
stacked in ascending order on one rod and there are two other rods with no
disks on them. The objective is to move all disks from the first rod to the
third, such that:
- only one disk is moved at a time
- a larger disk can never be placed on top of a smaller one

Write a recursive function that outputs the sequence of steps needed to
solve the puzzle with n disks.

Write a test program that allows the user to input number of disks and
then uses your function to output the steps needed to solve the puzzle.
Hint: If you could move up n−1 of the disks from the first post to the
third post using the second post as a spare, the last disk could be moved from
the first post to the second post. Then by using the same technique you can
move the n−1 disks from the third post to the second post, using the first
disk as a spare. There! You have the puzzle solved. You only have to decide
what the nonrecursive case is, what the recursive case is, and when to output
instructions to move the disks.