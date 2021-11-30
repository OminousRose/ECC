Define a class named Complex that will represent complex numbers. A
complex number is a number of the form

a+b*i,

where, for our purposes, a and b are integers and i represents sqrt(-1).
In your class, include a constructor that takes two parameters and
initializes a and b to the first and second parameter respectively, and include
a constructor that takes one parameter and initializes a to the value of the
parameter and b to 0. Also include a default constructor that initializes both a
and b to 0. Overload all of the followind operators so that they correctly apply
to the class Complex: ==, +, -, *, >>, and <<.

Using your Complex class, write a program that would let the user input two
complex numbers, and then print out their sum, difference, product, and whether
they are equal to one another.