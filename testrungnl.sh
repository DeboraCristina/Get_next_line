clear ; cc -Wall -Werror -Wextra -g3 -D BUFFER_SIZE=$1 main.c get_next_line.c get_next_line_utils.c debugtest.c ; ./a.out ; rm ./a.out
