#include "Qt_vlc.h"
#include <QtWidgets/QApplication>
#include <QWidget>
#include <iostream>

using namespace std;

// ±ÜÃâ ssize_t Òý·¢µÄ´íÎó
#if defined(_MSC_VER)
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif

#include <vlc/vlc.h>
#include "Qt_vlc.h"


//void waitPlaying(libvlc_media_player_t *mp)
//{
//	libvlc_state_t state;
//	do {
//		state = libvlc_media_player_get_state(mp);
//	} while (state != libvlc_Error && state != libvlc_Ended);
//}

int main(int argc, char *argv[])
{
	QString localMediaPath  = "F:\\baozang\\xuexiziliaoC_C++\\06_QT\\01\\4.mov";
	QString rtsMediaPath = "http://ivi.bupt.edu.cn/hls/cctv6hd.m3u8";
	
	QApplication app(argc, argv);
	Qt_vlc myPlayer;
	//myPlayer.playNetUrlTv("http://ivi.bupt.edu.cn/hls/cctv6hd.m3u8");
	myPlayer.playLocalVideo(localMediaPath);
	myPlayer.show();

	return app.exec();
}
