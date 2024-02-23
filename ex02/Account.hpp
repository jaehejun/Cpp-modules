// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public: // 클래스 외부에서 접근 가능

	typedef Account		t; // Account를 t로도 쓸 수 있게 별칭. 일반적인 방법은 아닌듯...?

	// static 멤버 함수로 클래스의 인스턴스와 관계없이 모든 Account 객체에 대해 동일한 값을 반환한다(클래스 전역)
	static int	getNbAccounts( void ); // 생성된 총 계좌 수를 반환
	static int	getTotalAmount( void ); // 생성된 모든 계좌의 총 잔액을 반환
	static int	getNbDeposits( void ); // 생성된 모든 계좌에 대한 입금 횟수를 반환
	static int	getNbWithdrawals( void ); // 생성된 모든 계좌에 대한 출금 횟수를 반환
	static void	displayAccountsInfos( void ); // 생성된 계좌의 정보를 출력

	Account( int initial_deposit ); // Account 생성자(초기 입금액을 매개변수로 받아서 생성)
	~Account( void ); // 소멸자

	void	makeDeposit( int deposit ); // deposit 만큼을 입금한다
	bool	makeWithdrawal( int withdrawal ); // withdrawal 만큼을 출금한다. 출금 성공여부를 bool 타입으로 반환
	int		checkAmount( void ) const; // 현재 계좌의 잔액을 반환
	void	displayStatus( void ) const; // 현재 계좌의 상태를 출력


private: // 클래스 내부에서만 접근 가능

	// static 멤버 함수는 반드시 초기화를 해줘야 한다.
	static int	_nbAccounts; // 생성된 총 계좌의 수를 저장
	static int	_totalAmount; // 생성된 총 계좌의 총 잔액을 저장
	static int	_totalNbDeposits; // 모든 계좌에 대한 총 입금 횟수를 저장
	static int	_totalNbWithdrawals; // 모든 계좌에 대한 총 출금 횟수를 저장

	static void	_displayTimestamp( void ); // 타임스탬프 출력

	int				_accountIndex; // 단일 계좌의 인덱스를 저장
	int				_amount; // 단일 계좌의 잔액을 저장
	int				_nbDeposits; // 단일 계좌의 입금 횟수를 저장
	int				_nbWithdrawals; // 단일 계좌의 출금 횟수를 저장

	Account( void ); // private으로 선언된 생성자. 외부에서 객체를 직접 생성하는 것을 막기 위해 private으로 선언
					 // initial_deposit 없이 Account를 생성하지 못하도록(default 생성자) 하는 역할을 한다.

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
