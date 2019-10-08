# Colorspace tools
A set of simple C command-line tools to convert between the most common
colorspaces (not counting HSV, as of yet). They can be used either with
command-line arguments (the different component values in order), or
with user input prompted by the program if not run with the correct
number of arguments.

Currently, this package encompasses the following conversions:
* CMY → CMYK
* CMY → RGB
* CMYK → CMY
* CMYK → RGB
* RGB → CMY
* RGB → CMYK

This is my first time trying to really modularize parts of C code, so it is
also an experiment in compiling and linking object files for me. I still think
I can do more on this front, but am relatively happy with how much I was still
able to simplify everything regardless.

### Rationale
I have a couple of art books that give colors for the drawings within in CMYK
format. I mostly do digital art in the RGB24 (or RGBA) color spaces. While
CMYK -> RGB conversions are not necessarily 100% foolproof/reversible, it's
convenient to be able to easily adapt colors between them. Additionally, The
GTK+ color chooser does not allow entering CMYK or CMY colors, only RGB & HSV.
Thus, this 'suite' was born.

### Usage
```bash
$ ./rgb2cmyk <r> <g> <b>
```
Examples:
```
$ ./rgb2cmyk 242 0 0
C: 0%
M: 100%
Y: 100%
K: 5%
```
```
$ ./rgb2cmy 242 0 0
C: 5%
M: 100%
Y: 100%
```
```
$ ./cmy2rgb 5 100 100
R: 242
G: 0
B: 0
```
```
$ ./cmyk2rgb 0 100 100 5
R: 242
G: 0
B: 0
```
Interactive:
```
$ ./cmyk2rgb
Please enter a percentage for C, range 0 to 100: 0
Please enter a percentage for M, range 0 to 100: 100
Please enter a percentage for Y, range 0 to 100: 100
Please enter a percentage for K, range 0 to 100: 5
R: 242
G: 0
B: 0
```
### Todo
Add an option to print hexadecimal RGB codes for copypasting into CSS and some
color chooser software.

### Bugs
These programs may or may not handle invalid inputs properly. Bare minimum
effort has been made to ensure valid inputs, so while some invalid input may
be caught, others (alphabetical input) may silently be converted to zeroes.

The easy solution, of course, is to not input invalid entries. I may or
may not work on making input validation better in the future.

