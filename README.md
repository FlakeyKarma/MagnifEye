# MagnifEye
Do you need to check the amount of times you use each word in an essay? Do you fear redundancy? Do you want to have a more diverse array of wording in your essay? As ironic as these questions are, this program is here to let you know how many times you use each word in an essay! It's still in development, so don't get too comfortable yet.

It's just a simple command-line-based function at the moment. You just type the path to the text file you wish to have analyzed and it returns the documents text, the amount of times each word is used above the word used *n* times.

`Usage:
MagnifEye <options> <file>


[-h, --help][-c, --cli][-red, --red-check][-l, --legend]


options:
	-h, --help       	Display this screen
	-c, --cli        	Display the CLI(Command Line Interface)
	-red, --red-check	Display redundancy of phrases used in document
	-l, --legend     	Display legend to understand color coding for
				output

`

# Example
##### test.txt

`The quick red fox jumps over the big brown log.`

*Windows*:

`C:\foo\bar\ MagnifEye test.txt`

*Linux*

`foo@bar:~$ ./MagnifEye test.txt`

##### returns this

```
MagnifEye

By FlakeyKarma


---------
OUTPUT =| 1 | :
                 quick
                 red
                 fox
                 hopped
                 big
                 brown
                 log
OUTPUT =| 2 | :
                 the


--=goodbye=--

```
