#include <stdio.h>
#include <locale.h>
#include "string.h"

#define CRC_INDEX_START	50	// максимально допустимая длина входного предложения

char * s_gets (char * st, int n);

int main(void){

	char * locale = setlocale (LC_ALL, "");

	char rs_conf[CRC_INDEX_START];
	int hh = 0;

	puts("Введите текст для расчёта чек-суммы\r\nДля NMEA вводи без $ и *\r\n");
	s_gets(rs_conf, CRC_INDEX_START);

	while (rs_conf[0] != 'q'){

		for(int i = 0; i < strlen(rs_conf); i++)
			hh ^= rs_conf[i];

		printf("%s - строка\r\n", rs_conf);
		// printf("%d - длина\r\n", strlen(rs_conf));
		printf("%02X - чексумма\r\n\r\n", hh);

		hh = 0;
		for(int i = 0; i < CRC_INDEX_START; i++)
			rs_conf[i] = 0;
		
		puts("Введите текст для расчёта чек-суммы (q для выхода):");
		s_gets(rs_conf, CRC_INDEX_START);
	}

	return 0;
}

char * s_gets (char *st, int n){

	char *ret_val;
	ret_val = fgets(st, n, stdin);

	if (ret_val){

		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st  = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
