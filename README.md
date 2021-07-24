# Printf
Because putnbr and putstr aren’t enough

## Brief
Write a library that contains ft_printf, a function
that will mimic the real printf

* The prototype of ft_printf should be int ft_printf(const char *, ...);
* You have to recode the libc’s printf function
* It must not do the buffer management like the real printf
* It will manage the following conversions: cspdiuxX%
* It will be compared with the real printf
* You must use the command ar to create your librairy, using the command libtool
is forbidden.

## Allowed functions
```
malloc, free, write, va_start, va_arg, va_copy, va_end
```

## Description

A small description of the required conversion:
* %c print a single character.
* %s print a string of characters.
* %p The void * pointer argument is printed in hexadecimal.
* %d print a decimal (base 10) number.
* %i print an integer in base 10.
* %u print an unsigned decimal (base 10) number.
* %x print a number in hexadecimal (base 16).
* %% print a percent sign

## Bonus Part

If the Mandatory part is not perfect don’t even think about bonuses
* You don’t need to do all the bonuses
* Manage any combination of the following flags: ’-0.’ and minimum field width
with all conversions
* Manage all the following flags: ’# +’ (yes, one of them is a space)

## Personal Extras
* It works with wildcards "*"

## Makefile to create the library
```
make
make all
make clean
make fclean
make re
make bonus
```

## Subject
[Printf Subject](./subject/en.subject.pdf)
