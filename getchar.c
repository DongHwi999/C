#include <stdio.h>

int main()
{
	char data[250]; // �����͸� �Է¹��� �迭
	char mem_data[250]; //�Է¹��� ������ �� ���� �� �����͸� ������ �迭
	
	int max = 0;
	int l, i;
	
	while (1) {
		printf("������ �Է��ϼ��� (�Է� �ߴ��� ctrl + z): ");

		l = 0;

		//������ �Է¹ޱ�
		while (1) { 
			data[l] = getchar();
			//�Է¹��� �����Ͱ� '\n'�̰ų� EOF�̸� �Է�����
			if (data[l] == '\n' || data[l] == EOF) { break; }
			l++;
		}

		//�Ӱ��� ���� max���� Ŭ ��
		if (l > max) {
			//mem_data[]�� ���� data[]�� ����
			for (i = 0; i <= l; i++) {
				mem_data[i] = data[i];
			}
			max = l;
		}

		if (data[l] == EOF) { break; }
	} //�Է¹ޱ� ��

	//�Է¹��� �����Ͱ� ������
	if (max == 0) {
		printf("�Է��Ͻ� �����Ͱ� �����ϴ�. \n");
	}
	else {
		printf("���� �� ���� : ");
		for (i = 0; i <= max - 1; i++) {
			putchar(mem_data[i]);
		}
		printf("\n ���� : %d \n", max);
	}
}
