# Partition Numbers

## Generates partition numbers.


So pretty much today I watched a mathologer video in which mathologer explained how partition numbers work. He challenged the viewers to create an algorithm which would yield the 666th partition number. Depending on the indexing, the 666th partition number is either 11393868451739000294452939 (starting from 0 yielding 1) or 11956824258286445517629485 (1 yielding 1), though the partitions of the number 666 is 11956824258286445517629485 for certain.

The input you enter will return the number of partitions for that input.

I wrote this in C++ to mix things up a little.

## Some output
![](https://i.imgur.com/wpioZ9o.png)

*I updated some code*

## How to compile

Because overflow was an issue in this project, I decided to use the [mpz_class from GMP](https://gmplib.org/manual/C_002b_002b-Interface-General). This library can be installed using ``sudo apt-get install libgmp-dev`` on the command line. Then the code can be compiled with ``g++ partitionNumbers.cpp -lgmpxx -lgmp -o partitionNumbers`` of course.
