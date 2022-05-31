if [ -z $1 ]
then
	echo "code file - buffersize - mode - show"
	exit
fi

buffer=$2
#
comp="cc -Wall -Werror -Wextra -g3 -D BUFFER_SIZE=$buffer "
files="main.c get_next_line.c get_next_line_utils.c debugtest.c "
run="./a.out $1 $3 ; rm ./a.out "

comand="$comp $files"

clear ; $comand

if [ -z $4 ]
then
	echo hide
else
	if [ "$4" = "-s" ]
	then
		$run
	else
		if [ "$4" = "-v" ]
		then
			run="valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./a.out $1 $3 ; rm ./a.out "
			$run
		fi
	fi
fi

#
#if [ "$1" = "-bi" ]
