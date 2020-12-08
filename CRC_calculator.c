#include <stdio.h>
#include <locale.h>

#define CRC_INDEX_START		18 // ������ ������� ��������

char * s_gets (char * st, int n);

int main(void){

	char * locale = setlocale (LC_ALL, "");

	char rs_conf[CRC_INDEX_START];
	int hh = 0;

	puts("������� ����� ��� ������� ���-����� (q ��� ������):");
	s_gets(rs_conf, CRC_INDEX_START);

	while (rs_conf[0] != 'q'){

		for(int i = 0; i < CRC_INDEX_START - 1; i++)		//������� ����������� ����� (-1, �.�. ���� ������ ��� \0)
			hh ^= rs_conf[i];

		printf("%s - ������\r\n", rs_conf);
		printf("%x - ��������\r\n", hh);

		hh = 0;
		for(int i = 0; i < CRC_INDEX_START; i++)
			rs_conf[i] = 0;
		
		puts("������� ����� ��� ������� ���-����� (q ��� ������):");
		s_gets(rs_conf, CRC_INDEX_START);
	}

	return 0;
}

char * s_gets (char *st, int n){

	char *ret_val;
	// int i = 0;
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
