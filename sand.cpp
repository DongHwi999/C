#include <iostream>
using namespace std;

int main()
{ 
   int o;//�ֹ�����,
   float rh = 0.89;  //�ܹ���         ����
   float rc = 0.99;  //ġ�����
   float fs = 1.29;  //������ġ
   float hp = 2.49;  //ġ���Ŀ��
   float fr = 0.79;  //����ġ��������
   float sd = 0.99;  //����Ʈ�帵ũ
   char m;  //�� ��ų���� �Ƚ�ų����
   

   float slc1, slc2, slc3; //�޴����� 3�� ����
   cout << "*********************************************************************\n";
   cout << "McDowe11's Restraurant\n";
   cout << "*********************************************************************\n";
   cout << "Make your Selection from the menu below  :\n";
   cout << "1.Regular Hamburger                               \t\t$0.89\n";
   cout << "2.Regular Cheeseburger                            \t\t$0.99\n";
   cout << "3.Fish Sandwich                                   \t\t$1.29\n";
   cout << "4.Half-pounder with cheese                        \t\t$2.49\n";
   cout << "5.French fries                                    \t\t$0.79\n";
   cout << "6.Large soft drink                                \t\t$0.99 \n";
   cout << "*********************************************************************\n";
   //������� ���ǹ� 
   
   cout << " select 1, 2, 3, 4, 5 or 6 -->"; 
   cin >> slc1;
   cout << "�ֹ��� ������ �Է��Ͻÿ� -->";
   cin >> o; //�ֹ����� �Է�
   cout << "�߰��� �ֹ��Ͻðڽ��ϱ�?<Y/N>";
   cin >> m;
   switch (m) {
   case'y': 
      cout << " select 1, 2, 3, 4, 5 or 6 -->";
      cin >> slc2;
      cout << "�ֹ��� ������ �Է��Ͻÿ� -->";
      cin >> o; //�ֹ����� �Է�
      cout << "�߰��� �ֹ��Ͻðڽ��ϱ�?<Y/N>";
      cin >> m;
         switch (m) {
         case'y':cout << " select 1, 2, 3, 4, 5 or 6 -->";
            cin >> slc3;
            cout << "�ֹ��� ������ �Է��Ͻÿ� -->";
            cin >> o; //�ֹ����� �Է�
         default: break;
            }
      break;
   default: break; //ù��° ��ǰ ���ݸ� 
   }
    cout << "Thank you for eating at McDowe11's";
}
