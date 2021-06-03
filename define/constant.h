#ifndef CONSTANT_H
#define CONSTANT_H
#include <QVariant>

#define BORDER 1
#define GAME_BG_WIDTH 960
#define GAME_BG_HEIGHT 540
#define LOGIN_BG_WIDTH 958
#define LOGIN_BG_HEIGHT 538
#define HALL_BG_WIDTH 958
#define HALL_BG_HEIGHT 958
#define PACKAGE_HEAD_LEN 4 + 4 + 4 + 1

#define GAME_BG_IMG ":/images/bg/bg_black.jpg"
#define RES_LOGIN_BG_IMG ":/images/scene/s_login_v1.jpg"
#define RES_HALL_BG_IMG ":/images/bg/hall_bg_1.jpg"

#define GAMEHOST "ws://127.0.0.1"
#define GAMEPORT 10001


// enum des
enum USER_STATE {USER_NOTAUTH, USER_AUTH, ONLINE, OUTLINE};

typedef void (*QCallFunc)(QVariant element, void *user_data);
typedef std::function<void(QVariant)> QKeyFunc;

#endif // CONSTANT_H
