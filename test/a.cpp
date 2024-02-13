
//int	main()	{
//	int		i;
//	char	c;
//	double	d;
//	float	f;
	
//	int		arr[10];
//	int		*parr = arr;

//	int		i;
//	int		*pi = &i;

//	return 0:
//}

//int	main()	{
//	int	i, sum = 0;

//	for (i = 1; i <= 10; i++)	{
//		sum += i;
//	}
//	std::cout << "합은 : " << sum << std::endl;
//	return 0;
//}

//int	main()	{
//	int	lucky_number = 3;
//	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

//	int	user_input;	// 사용자 입력

//	while(1)
//	{
//		std::cout << "입력 : ";
//		std::cin >> user_input;
//		if (lucky_number == user_input)
//		{
//			std::cout << "맞추셨습니다~~" << std::endl;
//			break ;
//		}
//		else
//		{
//			std::cout << "다시 생각해보세요~" << std::endl;
//		}
//	}
//	return 0;
//}

//using	std::cout;
//using	std::endl;
//using	std::cin;

//int	main(void)
//{
//	int	user_input;
//	cout << "저의 정보를 표시해줍니다" << endl;
//	cout << "1. 이름" << endl;
//	cout << "2. 나이" << endl;
//	cout << "3. 성별" << endl;
//	cin >> user_input;

//	switch (user_input)
//	{
//		case 1:
//			cout << "Psi !" << endl;
//			break;
//		case 2:
//			cout << "99 살" << endl;
//			break;
//		case 3:
//			cout << "남자" << endl;
//			break;
//		default:
//			cout << "궁금한게 없군요~" << endl;
//			break;
//	}
//	return 0;
//}

//int	change_val(int *p)
//{
//	*p = 3;

//	return 0;
//}

//int	main(void)
//{
//	int	number = 5;

//	std::cout << number << std::endl;
//	change_val(&number);
//	std::cout << number << std::endl;
//}

//void	foo(int *a)
//{
//	std::cout << *a << std::endl;
//}

//void	fooo(int a)
//{
//	std::cout << a << std::endl;
//}

//int	main(void)
//{
//	int	a = 3;
//	int& ref = a;

//	fooo(a);
//	fooo(ref);

//	//std::cout << "a : " << a << std::endl;
//	//std::cout << "another_a : " << another_a << std::endl;

//	return 0;
//}

//void foo(int& b) {
//    std::cout << b << std::endl;
//	b = 5;
//}

//int	main(void)
//{
//	int	a = 3;
//	//int& ref = a;

//	foo(a);
//	std::cout << a << std::endl;
//	return 0;
//}

//#include <iostream>

//int change_val(int &p) {
//  p = 3;

//  return 0;
//}
//int main() {
//  int number = 5;

//  std::cout << number << std::endl;
//  change_val(number);
//  std::cout << number << std::endl;
//}

//#include <iostream>

//int main() {
//  const int &ref = 4;

//  std::cout << &ref << std::endl;
//}

//int& function() {
//  int a = 2;
//  return a;
//}

//int main() {
//  int b = function();
//  b = 3;
//  return 0;
//}

//#include <iostream>

//int function() {
//  int a = 5;
//  return a;
//}

//int main() {
//  const int& c = function();
//  std::cout << "c : " << c << std::endl;
//  return 0;
//}

///* new 와 delete 의 사용 */
//#include <iostream>

//int main() {
//  int* p = new int;
//  *p = 10;

//  std::cout << *p << std::endl;

//  delete p;
//  return 0;
//}

#include <iostream>
#include <stdlib.h>

int	main()
{
	int	a = 5;
	delete(&a);
	return 0;
}