#include <stdio.h>

int main()
{
	char data[250]; // 데이터를 입력받을 배열
	char mem_data[250]; //입력받은 데이터 중 가장 긴 데이터를 저장할 배열
	
	int max = 0;
	int l, i;
	
	while (1) {
		printf("문장을 입력하세요 (입력 중단은 ctrl + z): ");

		l = 0;

		//데이터 입력받기
		while (1) { 
			data[l] = getchar();
			//입력받은 데이터가 '\n'이거나 EOF이면 입력중지
			if (data[l] == '\n' || data[l] == EOF) { break; }
			l++;
		}

		//ㅣ값이 현재 max보다 클 때
		if (l > max) {
			//mem_data[]에 현재 data[]값 복사
			for (i = 0; i <= l; i++) {
				mem_data[i] = data[i];
			}
			max = l;
		}

		if (data[l] == EOF) { break; }
	} //입력받기 끝

	//입력받은 데이터가 없으면
	if (max == 0) {
		printf("입력하신 데이터가 없습니다. \n");
	}
	else {
		printf("가장 긴 줄은 : ");
		for (i = 0; i <= max - 1; i++) {
			putchar(mem_data[i]);
		}
		printf("\n 길이 : %d \n", max);
	}
}
