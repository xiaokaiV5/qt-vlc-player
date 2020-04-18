#ifndef TV_STATION_H
#define TV_STATION_H
#include <QString>
#include <QListWidgetItem>

struct TvStation_st
{
	QString tvName;
	QString tvUrl;
};

extern struct TvStation_st gs_tvstation[100];

const int tvStationNum = 100;
class TvStationInfo : public QListWidgetItem
{
public:
	TvStationInfo();
	~TvStationInfo();
	void setTvStationInfo(QString tvName, QString tvUrl);
	inline QString getTvName() { return this->tvName; };
	inline QString getTvUrl() { return tvUrl; };
	inline void setState(int state) { currentState = state; };
	inline int getState() { return currentState; };

public:
	enum tvStatusEm
	{
		Idle,
		Initing,
		Playing,
		Releasing
	};
private:
	QString tvName;
	QString tvUrl;
	int currentState;
};

#endif // TV_STATION_H
