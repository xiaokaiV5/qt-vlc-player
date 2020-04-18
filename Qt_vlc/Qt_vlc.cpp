#include <QListWidgetItem>
#include <QFileDialog>
#include <QDebug>
#include "Qt_vlc.h"
#include "ui_Qt_vlc.h"
#include "Tv_station.h"


Qt_vlc::Qt_vlc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Qt_vlcClass)
{
	ui->setupUi(this);
	ui->frame_playerAll->setFrameShape(QFrame::NoFrame);

	/* Enter TV station information. */
	for (size_t i = 0; i < sizeof(gs_tvstation) / sizeof(gs_tvstation[0]); i++) {
		if (gs_tvstation[i].tvName.length() > 0) {
			tvStation[i].setTvStationInfo(gs_tvstation[i].tvName, gs_tvstation[i].tvUrl);
			ui->listWidget_TvStation->addItem(tvStation + i);
		}
	}

	this->playerWId = ui->wiget_player_window->winId();

	menuAction_openFileAction = new QAction(QStringLiteral("打开文件"),this);
	menuAction_hideTvStationList = new QAction(QStringLiteral("隐藏点播栏"),this);
	ui->menu_operation->addAction(menuAction_openFileAction);
	ui->menu_operation->addAction(menuAction_hideTvStationList);
	connect(menuAction_openFileAction, &QAction::triggered, this, &Qt_vlc::openLocalVadio);
	connect(menuAction_hideTvStationList, &QAction::triggered, this, &Qt_vlc::hideTvStationList);
}

Qt_vlc::~Qt_vlc()
{
	this->release();
}

void Qt_vlc::playerInit()
{
	return;
}

void Qt_vlc::bindPlayerWindow(const WId window, libvlc_media_player_t *player)
{
#if defined (Q_OS_WIN)
	libvlc_media_player_set_hwnd(player, (void *)playerWId);
#elif defined (Q_OS_UNIX)
	libvlc_media_player_set_xwindow(player, currentWId);
#elif defined(Q_OS_MAC)
	libvlc_media_player_set_nsobject(player, (void *)currentWId);
#endif
	return;
}

/* TV , return 0 if playback started (and was already started), or -1 on error.*/
int Qt_vlc::playNetUrlTv(QString videoUrlPath)
{
	k_instance = libvlc_new(0, nullptr);
	k_media = libvlc_media_new_location(k_instance, videoUrlPath.toLatin1().data());
	k_player = libvlc_media_player_new_from_media(k_media);
	//Live broadcast cannot be controlled,so k_eventManager will be assigned a null;
	k_eventManager = nullptr;

	/* Bind the playback window*/
	bindPlayerWindow(this->playerWId, k_player);

	return libvlc_media_player_play(k_player);
}

/* Online video resources. */
int Qt_vlc::playNetUrlVideo(QString videoUrlPath)
{
	k_instance = libvlc_new(0, nullptr);
	k_media = libvlc_media_new_location(k_instance, videoUrlPath.toLatin1().data());
	k_player = libvlc_media_player_new_from_media(k_media);
	k_eventManager = libvlc_media_player_event_manager(k_player);
	/* Bind the playback window*/
	bindPlayerWindow(this->playerWId, k_player);

	return libvlc_media_player_play(k_player);
}

/* local video. */
int Qt_vlc::playLocalVideo(QString videoPath)
{
	k_instance = libvlc_new(0, nullptr);
	k_media = libvlc_media_new_path(k_instance, videoPath.toLatin1().data());
	k_player = libvlc_media_player_new_from_media(k_media);
	k_eventManager = libvlc_media_player_event_manager(k_player);
	/* Bind the playback window*/
	bindPlayerWindow(this->playerWId, k_player);

	return libvlc_media_player_play(k_player);
}

/* Free up resources of vlc. */
bool Qt_vlc::release()
{
	if (!k_media)
		return false;

	libvlc_media_release(this->k_media);
	libvlc_media_player_release(this->k_player);
	libvlc_release(this->k_instance);

	k_media = nullptr;
	k_player = nullptr;
	k_instance = nullptr;
	k_eventManager = nullptr;
	return true;
}

TvStationInfo *Qt_vlc::getTvStation(QListWidgetItem *item)
{
	for (size_t i = 0; i < sizeof(this->tvStation) / sizeof(this->tvStation[0]); i++)
	{
		if (item->text() == this->tvStation[i].getTvName())
			return this->tvStation + i;
	}
	return nullptr;
}

void Qt_vlc::waitPlaying(libvlc_media_player_t *mp)
{
	libvlc_state_t state;
	do {
		state = libvlc_media_player_get_state(mp);
	} while (state != libvlc_Error && state != libvlc_Ended);
}

void Qt_vlc::attachEvent()
{
	/* event list */
	QList<libvlc_event_e> events;
	events << libvlc_MediaPlayerOpening
		<< libvlc_MediaPlayerBuffering
		<< libvlc_MediaPlayerPlaying
		<< libvlc_MediaPlayerPaused
		<< libvlc_MediaPlayerStopped
		<< libvlc_MediaPlayerEncounteredError
		<< libvlc_MediaPlayerMuted
		<< libvlc_MediaPlayerUnmuted
		<< libvlc_MediaPlayerAudioVolume
		<< libvlc_MediaPlayerLengthChanged
		<< libvlc_MediaPlayerTimeChanged
		<< libvlc_MediaPlayerPositionChanged;
	/* Subscribe to events */
	foreach(const libvlc_event_e &e, events) {
		libvlc_event_attach(k_eventManager, e, handleEvents, this);
	}
}

static void handleEvents(const libvlc_event_t *event, void *userData)
{
	Qt_vlc *player = static_cast<Qt_vlc *>(userData);
	switch (event->type)
	{
	// Player status changed.
	case libvlc_MediaPlayerOpening:
	case libvlc_MediaPlayerBuffering:
		break;
	case libvlc_MediaPlayerPlaying: {
		emit player->stateChanged(Qt_vlc::Playing);
		break;
	}
	case libvlc_MediaPlayerPaused: {
		emit player->stateChanged(Qt_vlc::Paused);
		break;
	}
	case libvlc_MediaPlayerStopped: {
		emit player->stateChanged(Qt_vlc::Stopped);
		break;
	}
	case libvlc_MediaPlayerEncounteredError: {
		emit player->stateChanged(Qt_vlc::Error);
		break;
	}
	// 时长改变
	case libvlc_MediaPlayerLengthChanged: {
		qint64 dur = event->u.media_player_length_changed.new_length;
		emit player->durationChanged(dur);
		break;
	}
	// 播放时间改变
	case libvlc_MediaPlayerTimeChanged: {
		qint64 time = event->u.media_player_time_changed.new_time;
		emit player->timeChanged(time);
		break;
	}
	// 播放位置改变
	case libvlc_MediaPlayerPositionChanged: {
		float pos = event->u.media_player_position_changed.new_position;
		emit player->positionChanged(pos);
		break;
	}
	default:
		break;
	}
}



/******************************************************************
*******************************slot********************************
******************************************************************/

/* Double clicked to change TV station. */
void Qt_vlc::on_listWidget_TvStation_itemDoubleClicked(QListWidgetItem *item)
{
	TvStationInfo* station = this->getTvStation(item);
	if (station && station->getState() == TvStationInfo::Idle)
	{
		this->currentTvStation.setState(TvStationInfo::Initing);
		qDebug() << station->getState();
		this->release();
		if (!this->playNetUrlTv(station->getTvUrl()))
			this->currentTvStation.setState(TvStationInfo::Playing);
	}
}


/* Adjust the playback progress by dragging the slider. */
void Qt_vlc::on_playerSlider_sliderReleased()
{
	qDebug() << "player time change, wait to code" << endl;
	return;
}

void Qt_vlc::openLocalVadio()
{
	QString file = QFileDialog::getOpenFileName(this,
		QStringLiteral("打开文件"),
		QDir::homePath(),
		QStringLiteral("多媒体文件(*)"));
	if (!file.isEmpty()) {
		file = QDir::toNativeSeparators(file);
		this->openFile(file);
	}
	return;
}

void Qt_vlc::hideTvStationList()
{
	if (!ui->listWidget_TvStation->isHidden()) {
		ui->listWidget_TvStation->hide();
	}
	else {
		ui->listWidget_TvStation->show();
	}
	return;
}


void Qt_vlc::openFile(const QString & file)
{
	this->release();
	this->playLocalVideo(file.toUtf8().data());
}

void Qt_vlc::setVolume(int vol)
{
}

void Qt_vlc::seek(int pos)
{
}

void Qt_vlc::play()
{
}

void Qt_vlc::pause()
{
	if (libvlc_media_player_can_pause(k_player))
		libvlc_media_player_set_pause(k_player, true);
}

void Qt_vlc::stop()
{
	libvlc_media_player_stop(k_player);
}
