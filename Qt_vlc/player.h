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
//	// ����״̬
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
//	 **��C++�У�explicit�ؼ�������������Ĺ��캯���������εĹ��캯�����࣬���ܷ�����Ӧ����ʽ����ת��
//	 **��ֹ��η�����ʽ�������µ��õĹ��캯��������ϣ�����õĺ���
//	 **/
//	explicit Player(QObject *parent = nullptr);
//	~Player();
//	// ������Ƶ�������
//	void setVideoWindow(QWidget *window);
//	// ��ȡ��ǰ״̬
//	Player::State state();
//
//Q_SIGNALS:
//	// ��ʱ�������仯
//	void durationChanged(qint64 dur);
//	// ��ǰʱ�䷢���仯
//	void timeChanged(qint64 time);
//	// ����λ�÷����仯
//	void positionChanged(float pos);
//	// ״̬�����仯
//	void stateChanged(Player::State state);
//
//public Q_SLOTS:
//	// ���ļ�
//	void openFile(const QString &file);
//	// ��������
//	void setVolume(int vol);
//	// ����
//	void seek(int pos);
//	// ����
//	void play();
//	// ��ͣ
//	void pause();
//	// ֹͣ
//	void stop();
//
//private:
//	// �����¼�
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