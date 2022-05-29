clear ; cc -Wall -Werror -Wextra -g3 -D BUFFER_SIZE=$1 testmain.c get_next_line.c get_next_line_utils.c debugtest.c ; ./a.out $2 ; rm ./a.out 
