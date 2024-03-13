/*집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다.
박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다.
박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다.
예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는
경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도
N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다.
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다.
그리고 항상 K ≦ N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다.
랜선의 길이는 2^31 -1보다 작거나 같은 자연수이다.

4 11		K = 4개(항상 <= 10,000), N = 11개(1 <= N <= 1,000,000), K <= N
802			K1 : 802cm
743			K2 : 743cm
457			K3 : 457cm
539			K4 : 539cm

200			최대 200cm 길이의 랜선을 11개를 만들 수 있음
            랜선의 길이 <= 2^31 -1

802cm 랜선에서 4개, 743cm 랜선에서 3개, 457cm 랜선에서 2개, 539cm 랜선에서 2개를 잘라내 모두 11개를 만들 수 있다.


1. N / K -> 2...3

457 2 228 / 228 / 1                 x
539 2 228 / 228 / ...               1.17943x
743 2 228 / 228 / 228 / ...			1.62582x
802 2 228 / 228 / 228 / ...			1.7549x

*/

#include <iostream>
#include <vector>

int main()
{
    int K, N;

    std::cin >> K >> N;
    std::vector<long long> lanCables(K);
    long long maxCableLength = 0;
    for (int i = 0; i < K; ++i)
    {
        std::cin >> lanCables[i];
        maxCableLength = std::max(maxCableLength, lanCables[i]);
    }

    long long up = 1;
    long long down = maxCableLength;
    long long cableLength;
	int result;

    while (up <= down)
    {
		cableLength = (up + down) / 2;
        int cableCount = 0;
        for (int i = 0; i < K; ++i)
        {
            cableCount += lanCables[i] / cableLength;
        }
		// cableCount가 N개 미만일 때 -> 길이(cableLength)를 줄여야함
        if (cableCount < N)
        {
            down = cableLength - 1;
        }
		// cableCount 가 N개 이상일때 -> 길이(cableLength)를 늘려야함
        else
        {
			result = cableLength;
            up = cableLength + 1;
        }
    }

    std::cout << result << std::endl;
    return 0;
}

// 802(MAX) + 0(UP) / 2 = 401(D)
// cableCount = 5 (<N)
// down = 401, newD = up(0) + down(401) /2 = 200(D)
// cableCount = 11(>=N)

// up = 200(D), newD = up(200) + down(401) / 2 = 300(D)
// cableCount = 6(<N)

// down = 300, newD = up(200) + down(300) / 2 = 250(D)
// cableCount = 8(<N)

// down = 250, newD = 225(D)
// cableCount = 9(<N)

// down = 225, newD = 212(D)
// cableCount = 10(<N)

// down = 212, newD = 206(D)
// cableCount = 10(<N)

// down = 206, newD = 203(D)
// cableCount = 10(<N)

// down = 203, newD = 201(D)
// cableCount = 11(>=N)

// up = 201, newD = 202(D)
// cableCount = 10(<N)

// down = 202, newD = 201(D)
// cableCount = 10(<N)

// down = 201, newD = 201(D)
// cableCount = 11(>=N)

// up = 201, newD = 201(D)
// ...

// #include <iostream>
// #include <vector>

// int main()
//{
//	long long N, K;

//	std::cin >> K >> N;
//	std::vector<long long> lanCables(K);
//	long long maxLanCableLength = 0;
//	for (long long i = 0; i < K; i++)
//	{
//		std::cin >> lanCables[i];
//		maxLanCableLength = std::max(maxLanCableLength, lanCables[i]);
//	}

//	long long left = 1;
//	long long right = maxLanCableLength;
//	long long answer = 0;
//	while (left <= right)
//	{
//		long long mid = (left + right) / 2;
//		long long lanCount = 0;

//		for (int i = 0; i < K; ++i)
//		{
//			lanCount += lanCables[i] / mid;
//		}
//		if (lanCount >= N)
//		{
//			answer = mid;
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	std::cout << answer << std::endl;
//	return 0;
//}