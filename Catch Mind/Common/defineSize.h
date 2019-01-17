#pragma once
#define SERVERPORT		9000
#define WM_SOCKET		(WM_USER+1)

#define BUFSIZE			512

#define USERLIST		50
#define	NAMESIZE		40
#define LEVELSZIE		20
#define POSITIONSIZE	20

#define ROOM_NAMESIZE	40


#define IDC_ROOM_NAME	2000
#define IDC_PASSWORD	2001
#define IDC_CHATTING	2002

#define	MAX_HEADCOUNT		9		// 방접속 최대인원수 = 값 -1

enum PLAYER_TYPE
{
	PLAYER_TYPE_CHARACTER_BANANA = 3000,
	PLAYER_TYPE_CHARACTER_BEANCAKE,
	PLAYER_TYPE_CHARACTER_DONG,
	PLAYER_TYPE_CHARACTER_EGG,
	PLAYER_TYPE_CHARACTER_EGGHALF,
	PLAYER_TYPE_CHARACTER_GARLIC,
	PLAYER_TYPE_CHARACTER_GRAPE,
	PLAYER_TYPE_CHARACTER_KIMCHI,
	PLAYER_TYPE_CHARACTER_LETTUCE,
	PLAYER_TYPE_CHARACTER_MUSHROOM,
	PLAYER_TYPE_CHARACTER_ONION,
	PLAYER_TYPE_CHARACTER_ORANGE,
	PLAYER_TYPE_CHARACTER_PEPPER,
	PLAYER_TYPE_CHARACTER_RADISH,
	PLAYER_TYPE_CHARACTER_RICEROCK,
	PLAYER_TYPE_CHARACTER_SALAD,
	PLAYER_TYPE_CHARACTER_TOMATO,
	PLAYER_TYPE_END
};



struct UserInfo
{
	int				identifyKey;
	PLAYER_TYPE		m_ePlayerType;
	char			szNickName[NAMESIZE];
	char			szLevel[LEVELSZIE];
	char			szPosition[POSITIONSIZE];
	short			joinRoomSequence;
};

struct RoomInfo
{
	short			roomNumber;
	char			roomName[ROOM_NAMESIZE];
	char			superVisorName[NAMESIZE];
	short			roomSize;
};




