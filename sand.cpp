#include <iostream>
using namespace std;

int main()
{ 
   int o;//주문수량,
   float rh = 0.89;  //햄버거         가격
   float rc = 0.99;  //치즈버거
   float fs = 1.29;  //샌드위치
   float hp = 2.49;  //치즈파운더
   float fr = 0.79;  //프랜치프라이즈
   float sd = 0.99;  //소프트드링크
   char m;  //더 실킬건지 안시킬건지
   

   float slc1, slc2, slc3; //메뉴고르는 3번 과정
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
   //여기부터 조건문 
   
   cout << " select 1, 2, 3, 4, 5 or 6 -->"; 
   cin >> slc1;
   cout << "주문할 수량을 입력하시오 -->";
   cin >> o; //주문수량 입력
   cout << "추가로 주문하시겠습니까?<Y/N>";
   cin >> m;
   switch (m) {
   case'y': 
      cout << " select 1, 2, 3, 4, 5 or 6 -->";
      cin >> slc2;
      cout << "주문할 수량을 입력하시오 -->";
      cin >> o; //주문수량 입력
      cout << "추가로 주문하시겠습니까?<Y/N>";
      cin >> m;
         switch (m) {
         case'y':cout << " select 1, 2, 3, 4, 5 or 6 -->";
            cin >> slc3;
            cout << "주문할 수량을 입력하시오 -->";
            cin >> o; //주문수량 입력
         default: break;
            }
      break;
   default: break; //첫번째 상품 가격만 
   }
    cout << "Thank you for eating at McDowe11's";
}
