#!/bin/bash

#!/bin/bash

filelist=`git ls-files`

# return 0: format, return 1: not format
function checkCPP(){
    # source file
    if [[ $1 == *.cc ]];then
		  return 0
    elif [[ $1 == *.cpp ]];then
		  return 0
    elif [[ $1 == *.cxx ]];then
		  return 0
    elif [[ $1 == *.C ]];then
		  return 0
    elif [[ $1 == *.c++ ]];then
		  return 0
    elif [[ $1 == *.c ]];then
		  return 0
    elif [[ $1 == *.CPP ]];then
		  return 0
	# header files
    elif [[ $1 == *.h ]];then
		  return 0
    elif [[ $1 == *.hpp ]];then
		  return 0
    elif [[ $1 == *.hh ]];then
		  return 0
    elif [[ $1 == *.icc ]];then
		  return 0
    else
      return 1
    fi
}

for f in $filelist; do
  checkCPP $f
  ret=`echo $?`
  if [ $ret = "0" ];then
    echo "CONVERTING MATCHING FILE ${f}"
    # apply the clang-format script
	  clang-format -style=file -i ${f}
  fi
done

exit 0


