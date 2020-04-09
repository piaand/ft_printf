# ft_printf
This is a project for Hive Helsinki to implement my own version of the printf function from C stdio.h library. To create this project we are allowed to use only functions `write`, `malloc`, `free`, `exit` and the functions of `man 3 stdarg`. All the rest we have to code ourselves.

**During this project I learnt**
- Planning for building greater and and complex software
- Implementing the variable argument lists
- Exercising the separation of concerns and coding along the DRY principle

# Conversions and features
If you do not know the original printf function see the `man printf` first.

My printf does the following conversions
- `c s p`
- `d i o u x X` with length modifiers `hh, l, ll`
- `f` with length modifiers `l` and `L`
- `%%`
- flags `0, #, ' ', +, -` with the correct specifiers
- width
- precision

In addition my printf handles color printing with the following format tag:
```
ft_printf("{color name} text to be printed in color {eoc}");
```
Colors available
- `{red}`
- `{yellow}`
- `{magenta}`
- `{blue}`
- `{green}`
- `{cyan}`
- `{eoc}` i.e. end of color

# Compiling and using ft_printf
- Clone this repository
- run `make && make clean` inside the repository
- in the repository you will find libftprintf.a library that you may use with your .c files to apply `int ft_printf(const char *format, ...)`

# Notes
Since this is a school project we are bound to some syntax rules, such as:
- Functions max. 25 lines long
- Lines max. 81 characters long
- Only 5 functions allowed per .c file

Also it was forbidden to do the [buffer management](https://stackoverflow.com/questions/45385807/what-is-it-with-printf-sending-output-to-buffer/45386520#45386520) inside the ft_printf function which makes my printf to perform significantly slower than the actual one: my ft_printf writes the character to standard output one at the time.
