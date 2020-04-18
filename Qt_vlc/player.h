#pragma once
#include <QtWidgets/QMainWindow>

#if defined(_MSC_VER)
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif
#include <vlc/vlc.h>
#include "Tv_station.h"
//
//class Player : public QObject
//{
//	Q_OBJECT
//
//public:
//	// 播放状态
//	typedef enum State {
//		Idle,
//		Opening,
//		Buffering,
//		Playing,
//		Paused,
//		Stopped,
//		Ended,
//		Error
//	} State;
//	/**
//	 **在C++中，explicit关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换
//	 **防止入参发生隐式声明导致调用的构造函数非我们希望调用的函数
//	 **/
//	explicit Player(QObject *parent = nullptr);
//	~Player();
//	// 设置视频输出窗口
//	void setVideoWindow(QWidget *window);
//	// 获取当前状态
//	Player::State state();
//
//Q_SIGNALS:
//	// 总时长发生变化
//	void durationChanged(qint64 dur);
//	// 当前时间发生变化
//	void timeChanged(qint64 time);
//	// 播放位置发生变化
//	void positionChanged(float pos);
//	// 状态发生变化
//	void stateChanged(Player::State state);
//
//public Q_SLOTS:
//	// 打开文件
//	void openFile(const QString &file);
//	// 设置音量
//	void setVolume(int vol);
//	// 跳播
//	void seek(int pos);
//	// 播放
//	void play();
//	// 暂停
//	void pause();
//	// 停止
//	void stop();
//
//private:
//	// 订阅事件
//	void attachEvents();
//
//private:
//	libvlc_instance_t *m_instance{ nullptr };
//	libvlc_media_player_t *m_player{ nullptr };
//	libvlc_media_t *m_media{ nullptr };
//	libvlc_event_manager_t *m_eventManager{ nullptr };
//
//	QWidget *m_videoWindow{ nullptr };
//};