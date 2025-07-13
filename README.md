### Author: Musa Elqaq
----
# Basic Collatz Hailstone Generator

Based on the Collatz Conjecture, this lets you enter in a seed value and view some *basic* statistics related to the conjecture.   
_**NOTE: This does NOT support negative numbers at this time.**_

## Instructions:   
This should be a very easy program to use. All the user must do is enter in a value they wish to see go through the Collatz conjecture.
After they enter in their value, they will be presented with some options.  All the user must do is enter in the number corresponding
to the option they wish to use.  For example, to view all statistics (aka options `1`-`3`), they simply need to enter the number `4` when
prompted with the "`Your choice`" message.  

Importantly, this will loop until the user enters either `5`, to pick a different seed value,
or `6`, to exit the program entirely.

## Context:   
The collatz conjecture is a mathematical problem that can be summarized as follows:   
> If a number is `odd` , multiply by `3` and add `1`    
> If a number is `even`, divide by `2`    

  The conjecture asserts that all numbers end up in a `4-2-1` loop after some number of steps.  This is a rather gross over-simplification,   
  but it should suffice for this simple program.  For more information, [this is a good video resource by Veritasium](https://www.youtube.com/watch?v=094y1Z2wpJg) .   

----

## Basic Function Breakdown:   
`welcome()` - Displays a welcome message.    
`collatzer()` - Recursively calculates hailstone values until a value of 1 is found.   
`outputHailstones()` - Loops through all hailstone values and outputs them.   
`viewStatistics()` - Lets the user view some very basic statistics about the seed they entered.   
`main()` - The main function that calls the rest of these functions.   
