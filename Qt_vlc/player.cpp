#include "player.h"
//
//Player::~Player()
//{
//}
//
//void Player::setVideoWindow(QWidget * window)
//{
//}
//
//void Player::setVolume(int vol)
//{
//}
//
//void Player::seek(int pos)
//{
//}
//
//void Player::play()
//{
//}
//
//void Player::pause()
//{
//}
//
//void Player::stop()
//{
//}
//
//void Player::attachEvents()
//{
//	// 事件列表
//	QList<libvlc_event_e> events;
//	events << libvlc_MediaPlayerOpening
//		<< libvlc_MediaPlayerBuffering
//		<< libvlc_MediaPlayerPlaying
//		<< libvlc_MediaPlayerPaused
//		<< libvlc_MediaPlayerStopped
//		<< libvlc_MediaPlayerEncounteredError
//		<< libvlc_MediaPlayerMuted
//		<< libvlc_MediaPlayerUnmuted
//		<< libvlc_MediaPlayerAudioVolume
//		<< libvlc_MediaPlayerLengthChanged
//		<< libvlc_MediaPlayerTimeChanged
//		<< libvlc_MediaPlayerPositionChanged;
//
//	// 订阅事件
//	foreach(const libvlc_event_e &e, events) {
//		libvlc_event_attach(m_eventManager, e, handleEvents, this);
//	}
//}
