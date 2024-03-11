// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <algorithm>
#include <functional>
#include <vector>

int main(void)
{

    typedef std::vector<Account::t> accounts_t; // 계좌 벡터(동적 배열 컨테이너 클래스)
    typedef std::vector<int> ints_t;            // int 벡터
    typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // 계좌와 int의 반복자 쌍

    int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576}; // 상수 int배열 amounts[] : 잔액의 배열?
    size_t const amounts_size(sizeof(amounts) / sizeof(int)); // 상수 amounts_size(잔액이 몇갠지? amounts[]의 크기 : 8)
    accounts_t accounts(amounts, amounts + amounts_size); // vector와 같은 컨테이너 타입에서 사용되는 초기화 방식
    // 계좌벡터 accounts(amounts배열의 첫번째 요소를 가리키는 포인터(42), amounts 배열의 마지막 주소 다음을 가리키는
    // 포인터(16576 다음))
    //  따라서 accounts의 생성자는 이 두 포인터 사이에 있는 배열 요소들을 accounts에 복사하여 저장한다.
    //  결과적으로 accounts는 amounts 배열의 요소들을 가지는 std::vector<account::t>가 된다.
    accounts_t::iterator acc_begin = accounts.begin(); // accounts의 시작 위치(첫 번째 요소)를 가리키는 반복자
    accounts_t::iterator acc_end = accounts.end(); // accounts의 끝 위치(마지막 요소 이후의 위치)를 가리키는 반복자

    // 같은 방식으로 int 벡터(deposit) 초기화, 반복자(iterator) 초기화 : 입금
    int const d[] = {5, 765, 564, 2, 87, 23, 9, 20};
    size_t const d_size(sizeof(d) / sizeof(int));
    ints_t deposits(d, d + d_size);
    ints_t::iterator dep_begin = deposits.begin();
    ints_t::iterator dep_end = deposits.end();

    // 같은 방식으로 int 벡터(withdrawals) 초기화, 반복자 초기화 : 출금
    int const w[] = {321, 34, 657, 4, 76, 275, 657, 7654};
    size_t const w_size(sizeof(w) / sizeof(int));
    ints_t withdrawals(w, w + w_size);
    ints_t::iterator wit_begin = withdrawals.begin();c
    ints_t::iterator wit_end = withdrawals.end();

    Account::displayAccountsInfos(); // 계좌 정보 표시
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus)); // accounts벡터의 각 요소에 대해 displayStatus()를 호출해 계좌 상태 표시

	// it.first 는 acc_begin, it.second 는 dep_begin을 가리키는 반복자이다
    for (acc_int_t it(acc_begin, dep_begin); it.first != acc_end && it.second != dep_end; ++(it.first), ++(it.second))
    {
        (*(it.first)).makeDeposit(*(it.second)); // accounts 벡터와 deposits 벡터를 순회하면서 예금
    }

    Account::displayAccountsInfos(); // 계좌 정보 표시
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus)); // accounts벡터의 각 요소에 대해 displayStatus()를 호출해 계좌 상태 표시

    for (acc_int_t it(acc_begin, wit_begin); it.first != acc_end && it.second != wit_end; ++(it.first), ++(it.second))
    {
        (*(it.first)).makeWithdrawal(*(it.second)); // accounts 벡터와 withdrawal 벡터를 순회하면서 출금
    }

    Account::displayAccountsInfos(); // 계좌 정보 표시
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus)); // accounts벡터의 각 요소에 대해 displayStatus()를 호출해 계좌 상태 표시

    return 0;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
