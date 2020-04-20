#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_vlc.h"


#if defined(_MSC_VER)
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif
#include <vlc/vlc.h>
#include "Tv_station.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Qt_vlcClass; }
QT_END_NAMESPACE


class Qt_vlc : public QMainWindow
{
	Q_OBJECT

public:
public:
	// ����״̬
	typedef enum State {
		Idle,
		Opening,
		Buffering,
		Playing,
		Paused,
		Stopped,
		Ended,
		Error
	} State;

	Qt_vlc(QWidget *parent = Q_NULLPTR);

	~Qt_vlc();

	void setBackgroundPicture(const QString file);

	void playerInit();

	void bindPlayerWindow(const WId window, libvlc_media_player_t * player);

	int playNetUrlTv(QString videoUrl);
	int playNetUrlVideo(QString videoUrlPath);
	int playLocalVideo(QString videoUrl);
	bool release();
	TvStationInfo * getTvStation(QListWidgetItem * item);
	void waitPlaying(libvlc_media_player_t * mp);
	void attachEvent();
Q_SIGNALS:
	// The total durtion has changed.
	void durationChanged(qint64 dur);
	// The current durtion has changed.
	void timeChanged(qint64 time);
	// Play position changed.
	void positionChanged(float pos);
	// state changed.
	void stateChanged(Qt_vlc::State state);


private slots:
	/* ������ز��� */
	void on_listWidget_TvStation_itemDoubleClicked(QListWidgetItem *item);

	void openLocalVadio();

	void hideTvStationList();
	void ChangeBackgroundPicture();
	void on_playerSlider_valueChanged(int value);


	/* ��������ز��� */
	// ���ļ�
	void openFile(const QString &file);
	// ��������
	void setVolume(int vol);
	// ����
	void seek(int pos);
	// ����
	void play();
	// ��ͣ
	void pause();
	// ֹͣ
	void stop();
    
private:
	Ui::Qt_vlcClass *ui;

	libvlc_instance_t *k_instance{ nullptr };
	libvlc_media_player_t *k_player{ nullptr };
	libvlc_media_t *k_media{ nullptr };
	libvlc_event_manager_t *k_eventManager{ nullptr };
	WId playerWId;

	TvStationInfo currentTvStation;
	TvStationInfo tvStation[tvStationNum];

	QAction *menuAction_openFileAction;
	QAction *menuAction_hideTvStationList;
	QAction *menuBackgroundPictureChange;
};

static void handleEvents(const libvlc_event_t *event, void *userData);
