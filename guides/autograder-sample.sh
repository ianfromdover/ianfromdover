#!/bin/bash
# the same commands in C# will be in multi-line comments

# Check if we have enough arguments
: "
if (numOfArgs != 1)
    print(Usage: ./grade.sh <filename>); imagine it's a string
else
    foreach (var i in ./ref/*.out)
        removeForce(i);
"
if [[ $# -ne 1 ]]; then
  echo "Usage: ./grade.sh <filename>"

else
  # Delete temporary files
  for i in ./ref/*.out; do
    rm -f $i
    # if the file name has special characters, add inverted commas
  done

  echo -e "Test date and time: $(date +%A), $(date +%d) $(date +%B) $(date +%Y), $(date +%T)\n"

  # Compile the reference program
  c_file="./ref/$1.c"
  u_file="./ref/utils.h"
  u1_file="./ref/utils.c"
  exe_out="./ref/$1"

  gcc "$c_file" "$u_file" "$u1_file"  -o "$exe_out"

  # Generate reference output files
  for in_file in ./ref/*.in; do
    new_file="$in_file.out"
    $exe_out < $in_file > $new_file
  done

  # Mark submissions

  dir_mark=0
  # Iterate over every submission directory
  for dir in ./subs/* ; do
    ((dir_mark++))
    mark=0
    total_tests=0

    # Compile C code
    stu_file="$dir/$1.c"
    stu_ufile="$dir/utils.c"
    stu_u1file="$dir/utils.h"

    stu_output="stuSum"
    gcc $stu_file $stu_ufile $stu_u1file -o $stu_output >/dev/null 2>&1
    if [ $? -ne 0 ]; then
      # if (!isCompileSuccessful) 
      # Print compile error message to output file
      echo "Directory $(basename "$dir") has a compile error."
    fi
    # Generate output from C code using *.in files in ref
    for input in ./ref/*.in; do
      ((total_tests++))

      "./$stu_output" < $input > "output.out" 2>&1
      # Compare with reference output files and award 1 mark if they are identical
      # compare output.out with the $input + ".out" files
      model_file="$input.out"
      if  diff -q $model_file "output.out" >/dev/null 2>&1 ; then
          ((mark++))
      fi
    done

    # print score for student
    echo "Directory $(basename $dir) score $mark / $total_tests."

  done
  # print total files marked.
  echo -e "\nProcessed $dir_mark files."
fi
