#!/bin/bash
# This is called the shebang, it tells the com to use the bash interpreter located at bin/bash to execute this file.

: "
Hi! If you're a Java / C# developer, this guide is for you to start bash scripting! Enjoy automating your life!

you run bash files by:
chmod a+x <filename.sh>
./<filename.sh>

but if you only wanna do once then just
bash <filename.sh>

This is how you do a multiline comment btw

Note that by default, bash treats EVERYTHING as a string or a command, and the default action is concat.

"

: "
=--------------------------=
= variables and arithmetic
=--------------------------=
"
# variables int a = 5
# you don't have to define the types
# use $ to retrieve variables
# $(( arithmetic ))
a=15 # NO SPACES IN THE STATEMENT
b=20
c=$a-$b
echo "$a - $b = $c" # prints "15 – 20 = 15-20"
c=$(( a - b ))
echo "$a - $b = $c" # prints "15 – 20 = -5"


# concat
x="with spaces"
c="$a $x"
echo $c # prints "15 with spaces"

# run commands like whoami and date
echo "Hello $(whoami), today is $(date +%A), $(date +%d) $(date +%B) $(date +%y), and the time is $(date +%X)."

: "
=---------=
= printing

echo
-e (include newlines)
-n ??
=---------=
"

: "
=---------=
= test statements
=---------=
"

# isStringEmpty()
[[ -z "this returns false" ]]

# isStringNotEmpty()
[[ -n "this returns true" ]]

[[ "hehe" != "returns false" ]] # == exists too

# numbers
[[ $a -eq $b ]]
: "
-eq ==
-ne !=
-lt <
-ge <=
-gt >
-ge >=
"

# files
FILE="."
FILE2="."
[[ -e $FILE ]]
: "
-e does file exist?
-d is file directory?
-x is file executable
-s is file size > 0?
"
[[ $FILE -nt $FILE2 ]]
: "
-ef is FILE the same as FILE2?
-nt is FILE newer than FILE2?
-ot is FILE older than FILE2?
"

: "
=---------=
= user input,
= if-else 
=---------=
"

echo "Enter the first number: "
read NUM1
echo "Enter the second number: "
read NUM2

if [[ NUM1 -eq NUM2 ]]; then
    echo "$NUM1 = $NUM2"
elif [[ NUM1 -gt NUM2 ]]; then
    echo "$NUM1 > $NUM2"
else
    echo "$NUM1 < $NUM2"
fi


: "
=-----------=
= for loops
=-----------=
"

# print all the files in /etc/
for i in /etc/*; do
    echo $i
done

# prints 1 to 5 inclusive on newlines
end=5
for i in $(seq 1 $end); do
    echo $i
done

i=0
while [[ $i -le 5 ]]; do
    echo $i
    ((i++))
    # alternatively, you can do "let i=i+1"
done;

: "
=-----------=
= functions
= params are accessed using $1 and $2 for first and 2nd param

Special Variables
$# holds the number of command-line arguments,
excluding the command name itself.

$@ holds all of the arguments as separate values.
It is often used to loop through them.

$? holds the exit status of the last executed command or script,
where 0 typically indicates success and anything else indicates failure.
This takes on a value from 0 to 255.
=-----------=
"

function func {
    count=1
    echo Called with $# parameters.
    for i in $@; do
        echo Parameter $count is $i
        ((count++))
    done
    return 55;
}

func hello world 13.5
echo $?
# returns the following
: "
Called with 3 parameters.
Parameter 1 is hello
Parameter 2 is world
Parameter 3 is 13.5
55
"

: "
=-----------------------=
Sick features about bash
=-----------------------=
"
# write output to a file >
ls > ls.out
# append output to a file >>
echo "" >> ls.out
ls -l >> ls.out
# using files as input <
# imagine you compiled something here with gcc, then u can test it
cat < ls.out
rm ls.out
# using prev cmd success code
# eg. "if prev cmd ran successfully"
# (in prev cmd) exit(11);
# (in this cmd) if [[ $? -eq 0 ]] # false cuz $? == 11

# piping commands |
# channel the output of prev cmd into input of second cmd

ls | less

# executing stuff in parallel &
# sequentially ;
ls; date
ls & date
# a sample bash script is utils/picker.sh

rm ls.out

# what does this mean Y C?
# if  diff -q $model_file "output.out" >/dev/null 2>&1 ; then
