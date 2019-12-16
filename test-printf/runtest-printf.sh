GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> test-printf/result.log
	test-printf/test.out $2 > test-printf/original_output
	echo $? >> test-printf/original_output
	sh test-printf/timeout.sh 1 test-printf/test.out $2 user > test-printf/user_output 2> /dev/null
	ret=$(echo $?)
	echo $ret >> test-printf/user_output
	if diff "test-printf/original_output" "test-printf/user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> test-printf/result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		if [ $ret -eq 142 ] #timeout
		then
			printf "${RED}TIMEOUT${NC}"
			printf "${RED}TIMEOUT${NC}\n" >> test-printf/result.log
		else
			printf "${RED}FAILED${NC}"
			printf "${RED}FAILED${NC}\n" >> test-printf/result.log
		fi
		error=1
	fi
	((i++))
}

rm test-printf/result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a -o test-printf/test.out
printf "\n${BLUE}[F - Tests with minimum field width and .]${NC}\n"
test "$i - (\"%%1.0%%\") : ${NC}" $i 
test "$i - (\"%%1.1%%\") : ${NC}" $i 
test "$i - (\"%%1.2%%\") : ${NC}" $i 
test "$i - (\"%%1.10%%\") : ${NC}" $i 
test "$i - (\"%%2.0%%\") : ${NC}" $i 
test "$i - (\"%%2.1%%\") : ${NC}" $i 
test "$i - (\"%%2.2%%\") : ${NC}" $i 
test "$i - (\"%%2.10%%\") : ${NC}" $i 
test "$i - (\"%%10.0%%\") : ${NC}" $i 
test "$i - (\"%%10.1%%\") : ${NC}" $i 
test "$i - (\"%%10.2%%\") : ${NC}" $i 
test "$i - (\"%%10.10%%\") : ${NC}" $i 
test "$i - (\"%%1.0s\", \"\") : ${NC}" $i 
test "$i - (\"%%1.1s\", \"\") : ${NC}" $i 
test "$i - (\"%%1.2s\", \"\") : ${NC}" $i 
test "$i - (\"%%1.10s\", \"\") : ${NC}" $i 
test "$i - (\"%%5.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%5.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%5.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%5.10s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.10s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%1.0i\", 0) : ${NC}" $i 
test "$i - (\"%%1.1i\", 0) : ${NC}" $i 
test "$i - (\"%%1.2i\", 0) : ${NC}" $i 
test "$i - (\"%%1.10i\", 0) : ${NC}" $i 
test "$i - (\"%%2.0i\", 0) : ${NC}" $i 
test "$i - (\"%%2.1i\", 0) : ${NC}" $i 
test "$i - (\"%%2.2i\", 0) : ${NC}" $i 
test "$i - (\"%%2.10i\", 0) : ${NC}" $i 
test "$i - (\"%%10.0i\", 0) : ${NC}" $i 
test "$i - (\"%%10.1i\", 0) : ${NC}" $i 
test "$i - (\"%%10.2i\", 0) : ${NC}" $i 
test "$i - (\"%%10.10i\", 0) : ${NC}" $i 
test "$i - (\"%%1.0i\", -1) : ${NC}" $i 
test "$i - (\"%%1.1i\", -1) : ${NC}" $i 
test "$i - (\"%%1.2i\", -1) : ${NC}" $i 
test "$i - (\"%%1.10i\", -1) : ${NC}" $i 
test "$i - (\"%%2.0i\", -1) : ${NC}" $i 
test "$i - (\"%%2.1i\", -1) : ${NC}" $i 
test "$i - (\"%%2.2i\", -1) : ${NC}" $i 
test "$i - (\"%%2.10i\", -1) : ${NC}" $i 
test "$i - (\"%%3.0i\", -1) : ${NC}" $i 
test "$i - (\"%%3.1i\", -1) : ${NC}" $i 
test "$i - (\"%%3.2i\", -1) : ${NC}" $i 
test "$i - (\"%%3.10i\", -1) : ${NC}" $i 
test "$i - (\"%%9.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0d\", 0) : ${NC}" $i 
test "$i - (\"%%1.1d\", 0) : ${NC}" $i 
test "$i - (\"%%1.2d\", 0) : ${NC}" $i 
test "$i - (\"%%1.10d\", 0) : ${NC}" $i 
test "$i - (\"%%2.0d\", 0) : ${NC}" $i 
test "$i - (\"%%2.1d\", 0) : ${NC}" $i 
test "$i - (\"%%2.2d\", 0) : ${NC}" $i 
test "$i - (\"%%2.10d\", 0) : ${NC}" $i 
test "$i - (\"%%10.0d\", 0) : ${NC}" $i 
test "$i - (\"%%10.1d\", 0) : ${NC}" $i 
test "$i - (\"%%10.2d\", 0) : ${NC}" $i 
test "$i - (\"%%10.10d\", 0) : ${NC}" $i 
test "$i - (\"%%1.0d\", -1) : ${NC}" $i 
test "$i - (\"%%1.1d\", -1) : ${NC}" $i 
test "$i - (\"%%1.2d\", -1) : ${NC}" $i 
test "$i - (\"%%1.10d\", -1) : ${NC}" $i 
test "$i - (\"%%2.0d\", -1) : ${NC}" $i 
test "$i - (\"%%2.1d\", -1) : ${NC}" $i 
test "$i - (\"%%2.2d\", -1) : ${NC}" $i 
test "$i - (\"%%2.10d\", -1) : ${NC}" $i 
test "$i - (\"%%3.0d\", -1) : ${NC}" $i 
test "$i - (\"%%3.1d\", -1) : ${NC}" $i 
test "$i - (\"%%3.2d\", -1) : ${NC}" $i 
test "$i - (\"%%3.10d\", -1) : ${NC}" $i 
test "$i - (\"%%9.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0u\", 0) : ${NC}" $i 
test "$i - (\"%%1.1u\", 0) : ${NC}" $i 
test "$i - (\"%%1.2u\", 0) : ${NC}" $i 
test "$i - (\"%%1.10u\", 0) : ${NC}" $i 
test "$i - (\"%%2.0u\", 0) : ${NC}" $i 
test "$i - (\"%%2.1u\", 0) : ${NC}" $i 
test "$i - (\"%%2.2u\", 0) : ${NC}" $i 
test "$i - (\"%%2.10u\", 0) : ${NC}" $i 
test "$i - (\"%%10.0u\", 0) : ${NC}" $i 
test "$i - (\"%%10.1u\", 0) : ${NC}" $i 
test "$i - (\"%%10.2u\", 0) : ${NC}" $i 
test "$i - (\"%%10.10u\", 0) : ${NC}" $i 
test "$i - (\"%%1.0u\", -1) : ${NC}" $i 
test "$i - (\"%%1.1u\", -1) : ${NC}" $i 
test "$i - (\"%%1.2u\", -1) : ${NC}" $i 
test "$i - (\"%%1.10u\", -1) : ${NC}" $i 
test "$i - (\"%%2.0u\", -1) : ${NC}" $i 
test "$i - (\"%%2.1u\", -1) : ${NC}" $i 
test "$i - (\"%%2.2u\", -1) : ${NC}" $i 
test "$i - (\"%%2.10u\", -1) : ${NC}" $i 
test "$i - (\"%%3.0u\", -1) : ${NC}" $i 
test "$i - (\"%%3.1u\", -1) : ${NC}" $i 
test "$i - (\"%%3.2u\", -1) : ${NC}" $i 
test "$i - (\"%%3.10u\", -1) : ${NC}" $i 
test "$i - (\"%%9.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0x\", 0) : ${NC}" $i 
test "$i - (\"%%1.1x\", 0) : ${NC}" $i 
test "$i - (\"%%1.2x\", 0) : ${NC}" $i 
test "$i - (\"%%1.10x\", 0) : ${NC}" $i 
test "$i - (\"%%2.0x\", 0) : ${NC}" $i 
test "$i - (\"%%2.1x\", 0) : ${NC}" $i 
test "$i - (\"%%2.2x\", 0) : ${NC}" $i 
test "$i - (\"%%2.10x\", 0) : ${NC}" $i 
test "$i - (\"%%10.0x\", 0) : ${NC}" $i 
test "$i - (\"%%10.1x\", 0) : ${NC}" $i 
test "$i - (\"%%10.2x\", 0) : ${NC}" $i 
test "$i - (\"%%10.10x\", 0) : ${NC}" $i 
test "$i - (\"%%1.0x\", -1) : ${NC}" $i 
test "$i - (\"%%1.1x\", -1) : ${NC}" $i 
test "$i - (\"%%1.2x\", -1) : ${NC}" $i 
test "$i - (\"%%1.10x\", -1) : ${NC}" $i 
test "$i - (\"%%2.0x\", -1) : ${NC}" $i 
test "$i - (\"%%2.1x\", -1) : ${NC}" $i 
test "$i - (\"%%2.2x\", -1) : ${NC}" $i 
test "$i - (\"%%2.10x\", -1) : ${NC}" $i 
test "$i - (\"%%3.0x\", -1) : ${NC}" $i 
test "$i - (\"%%3.1x\", -1) : ${NC}" $i 
test "$i - (\"%%3.2x\", -1) : ${NC}" $i 
test "$i - (\"%%3.10x\", -1) : ${NC}" $i 
test "$i - (\"%%9.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0X\", 0) : ${NC}" $i 
test "$i - (\"%%1.1X\", 0) : ${NC}" $i 
test "$i - (\"%%1.2X\", 0) : ${NC}" $i 
test "$i - (\"%%1.10X\", 0) : ${NC}" $i 
test "$i - (\"%%2.0X\", 0) : ${NC}" $i 
test "$i - (\"%%2.1X\", 0) : ${NC}" $i 
test "$i - (\"%%2.2X\", 0) : ${NC}" $i 
test "$i - (\"%%2.10X\", 0) : ${NC}" $i 
test "$i - (\"%%10.0X\", 0) : ${NC}" $i 
test "$i - (\"%%10.1X\", 0) : ${NC}" $i 
test "$i - (\"%%10.2X\", 0) : ${NC}" $i 
test "$i - (\"%%10.10X\", 0) : ${NC}" $i 
test "$i - (\"%%1.0X\", -1) : ${NC}" $i 
test "$i - (\"%%1.1X\", -1) : ${NC}" $i 
test "$i - (\"%%1.2X\", -1) : ${NC}" $i 
test "$i - (\"%%1.10X\", -1) : ${NC}" $i 
test "$i - (\"%%2.0X\", -1) : ${NC}" $i 
test "$i - (\"%%2.1X\", -1) : ${NC}" $i 
test "$i - (\"%%2.2X\", -1) : ${NC}" $i 
test "$i - (\"%%2.10X\", -1) : ${NC}" $i 
test "$i - (\"%%3.0X\", -1) : ${NC}" $i 
test "$i - (\"%%3.1X\", -1) : ${NC}" $i 
test "$i - (\"%%3.2X\", -1) : ${NC}" $i 
test "$i - (\"%%3.10X\", -1) : ${NC}" $i 
test "$i - (\"%%9.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10X\", UINT_MAX) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
