#include "Qt_vlc.h"
#include <QApplication>
#include <QWidget>
#include <iostream>
#include <QFile>

using namespace std;

// ���� ssize_t �����Ĵ���
#if defined(_MSC_VER)
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif

#include <vlc/vlc.h>
#include "Qt_vlc.h"

/* load qss file. */
class CommonHelper
{
public:
	static void setStyle(const QString &style) {
		QFile qss(style);
		qss.open(QFile::ReadOnly);
		qApp->setStyleSheet(qss.readAll());
		qss.close();
	}
};


int main(int argc, char *argv[])
{
	QString localMediaPath  = "G:\\QT_project\\Qt_vlc\\Qt_vlc\\eg.mkv";
	
	QApplication app(argc, argv);
	// ����QSS��ʽ
	CommonHelper::setStyle("styleBlack.qss");



	Qt_vlc myPlayer;
	//myPlayer.playNetUrlTv("http://ivi.bupt.edu.cn/hls/cctv6hd.m3u8");
	myPlayer.playLocalVideo(localMediaPath);
	myPlayer.show();

	return app.exec();
}
