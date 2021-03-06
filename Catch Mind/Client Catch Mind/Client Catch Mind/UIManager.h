#pragma once
#include <Windows.h>
#include <vector>
#include <map>
#include <deque>
#include <string>
#include "Resource.h"
#include "../../Common/defineSize.h"

using std::vector;
using std::map;
using std::deque;
using std::make_pair;
using std::string;


class Player;
class UI;
class UIRoomList;
class UIManager
{
	static UIManager*		m_pThis;
	UIManager();

	HWND					m_hWnd;
	HWND					m_hEdit[EDIT_TYPE_END];
	HINSTANCE				m_hInstance;
	WNDPROC					m_hOldEdit[EDIT_TYPE_END];
	LONG					m_lEditSubProc;

	map<UI_TYPE, UI*>		m_mapUIObjects;
	map<int, UserInfo*>		m_mapUserList;
	map<int, UIRoomList*>	m_mapRoomList;
	map<int, UIRoomList*>::iterator	m_prevSelectRoomList;
	map<int, Player*>		m_mapJoinRoomUserList;


	vector<string>			m_vStrChattingText;

	void CreateUISelectCharacter();
	void CreateUIWaitingRoom();
	void CreateUIWaitingRoomInGame();
	void CreateUIJoinRoomUserList();

public:
	static UIManager* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new UIManager;
		return m_pThis;
	}

	void Init(HWND hWnd, HINSTANCE hInstance, LONG EditSubProc);
	void Draw();
	void Release();

	void InitUIObjects();
	void SettingSelectCharacterUI();
	void SettingWaittingRoomUI();
	void SettingWaitingRoomInGameUI();

	// 방 생성창
	void ShowCreateRoomWindowPop();
	void HideCreateRoomWindowPop();

	// 방 Join
	short GetSelectedRoomNumber();
	short GetSelectedHeadCount();

	void RefreshUserList(deque<UserInfo>& dequeUserInfo);
	void RemoveUserList(int nIdentifyKey);
	
	void RefreshRoomList(deque<RoomInfo>&	dequeRoomList);
	void RemoveRoomList();
	void RemoveRoomList(int nRoomNumber);

	void RefreshJoinRoomUserList(deque<UserInfo>& dequeUserInfo);

	void AddChattingText(string str);

	HWND GetEditHandle(EDIT_TYPE type);
	WNDPROC GetEditOldHandle(EDIT_TYPE type);
	const map<int, UserInfo*>& GetUserListMap() const;
	const map<int, UIRoomList*>& GetRoomListMap() const;
	const vector<string>& GetChatHistory() const;
	char*	GetEditText(EDIT_TYPE type);

	bool InputMouseLButtonDown(POINT& ptMouse);

	bool IsSelectedRoomList(short roomNumber, bool isSelected);

	
	~UIManager();
};

