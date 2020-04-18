#include "Tv_station.h"

struct TvStation_st gs_tvstation[100] =
{
	{QStringLiteral("CCTV-1高清"), "http://ivi.bupt.edu.cn/hls/cctv1hd.m3u8"},
	{QStringLiteral("CCTV-2高清"), "http://ivi.bupt.edu.cn/hls/cctv2hd.m3u8"},
	{QStringLiteral("CCTV-3高清"), "http://ivi.bupt.edu.cn/hls/cctv3hd.m3u8"},
	{QStringLiteral("CCTV-4高清"), "http://ivi.bupt.edu.cn/hls/cctv4hd.m3u8"},
	{QStringLiteral("CCTV-5高清"), "http://ivi.bupt.edu.cn/hls/cctv5hd.m3u8"},
	{QStringLiteral("CCTV-6高清"), "http://ivi.bupt.edu.cn/hls/cctv6hd.m3u8"},
	{QStringLiteral("CCTV-7高清"), "http://ivi.bupt.edu.cn/hls/cctv7hd.m3u8"},
	{QStringLiteral("CCTV-8高清"), "http://ivi.bupt.edu.cn/hls/cctv8hd.m3u8"},
	{QStringLiteral("CCTV-9高清"), "http://ivi.bupt.edu.cn/hls/cctv9hd.m3u8"},
	{QStringLiteral("CCTV-10高清"), "http://ivi.bupt.edu.cn/hls/cctv10hd.m3u8"},
	{QStringLiteral("CCTV-12高清"), "http://ivi.bupt.edu.cn/hls/cctv12hd.m3u8"},
	{QStringLiteral("CCTV-13高清"), "http://ivi.bupt.edu.cn/hls/cctv13hd.m3u8"},
	{QStringLiteral("CCTV-14高清"), "http://ivi.bupt.edu.cn/hls/cctv14hd.m3u8"},
	{QStringLiteral("CCTV-17高清"), "http://ivi.bupt.edu.cn/hls/cctv17hd.m3u8"},
	{QStringLiteral("CGTN高清"), "http://ivi.bupt.edu.cn/hls/cgtnhd.m3u8"},
	{QStringLiteral("CGTN DOC高清"), "http://ivi.bupt.edu.cn/hls/cgtndochd.m3u8"},
	{QStringLiteral("CHC高清电影"), "http://ivi.bupt.edu.cn/hls/chchd.m3u8"}	,
	{QStringLiteral("北京卫视高清"), "http://ivi.bupt.edu.cn/hls/btv1hd.m3u8"},
	{QStringLiteral("北京文艺高清"), "http://ivi.bupt.edu.cn/hls/btv2hd.m3u8"},
	{QStringLiteral("北京影视高清"), "http://ivi.bupt.edu.cn/hls/btv4hd.m3u8"},
	{QStringLiteral("北京新闻高清"), "http://ivi.bupt.edu.cn/hls/btv9hd.m3u8"},
	{QStringLiteral("北京冬奥纪实高清"), "http://ivi.bupt.edu.cn/hls/btv11hd.m3u8"},
	{QStringLiteral("湖南卫视高清"), "http://ivi.bupt.edu.cn/hls/hunanhd.m3u8"},
	{QStringLiteral("浙江卫视高清"), "http://ivi.bupt.edu.cn/hls/zjhd.m3u8"},
	{QStringLiteral("江苏卫视高清"), "http://ivi.bupt.edu.cn/hls/jshd.m3u8"},
	{QStringLiteral("东方卫视高清"), "http://ivi.bupt.edu.cn/hls/dfhd.m3u8"},
	{QStringLiteral("安徽卫视高清"), "http://ivi.bupt.edu.cn/hls/ahhd.m3u8"},
	{QStringLiteral("黑龙江卫视高清"), "http://ivi.bupt.edu.cn/hls/hljhd.m3u8"},
	{QStringLiteral("辽宁卫视高清"), "http://ivi.bupt.edu.cn/hls/lnhd.m3u8"},
	{QStringLiteral("深圳卫视高清"), "http://ivi.bupt.edu.cn/hls/szhd.m3u8"},
	{QStringLiteral("广东卫视高清"), "http://ivi.bupt.edu.cn/hls/gdhd.m3u8"},
	{QStringLiteral("天津卫视高清"), "http://ivi.bupt.edu.cn/hls/tjhd.m3u8"},
	{QStringLiteral("湖北卫视高清"), "http://ivi.bupt.edu.cn/hls/hbhd.m3u8"},
	{QStringLiteral("山东卫视高清"), "http://ivi.bupt.edu.cn/hls/sdhd.m3u8"},
	{QStringLiteral("重庆卫视高清"), "http://ivi.bupt.edu.cn/hls/cqhd.m3u8"},
	{QStringLiteral("上海纪实高清"), "http://ivi.bupt.edu.cn/hls/docuchina.m3u8"},
	{QStringLiteral("金鹰纪实高清"), "http://ivi.bupt.edu.cn/hls/gedocu.m3u8"},
	{QStringLiteral("福建东南卫视高清"), "http://ivi.bupt.edu.cn/hls/dnhd.m3u8"},
	{QStringLiteral("四川卫视高清"), "http://ivi.bupt.edu.cn/hls/schd.m3u8"},
	{QStringLiteral("河北卫视高清"), "http://ivi.bupt.edu.cn/hls/hebhd.m3u8"},
	{QStringLiteral("江西卫视高清"), "http://ivi.bupt.edu.cn/hls/jxhd.m3u8"},
	{QStringLiteral("河南卫视高清"), "http://ivi.bupt.edu.cn/hls/hnhd.m3u8"},
	{QStringLiteral("广西卫视高清"), "http://ivi.bupt.edu.cn/hls/gxhd.m3u8"},
	{QStringLiteral("吉林卫视高清"), "http://ivi.bupt.edu.cn/hls/jlhd.m3u8"},
	{QStringLiteral("CETV-1高清"), "http://ivi.bupt.edu.cn/hls/cetv1hd.m3u8"},
	{QStringLiteral("海南卫视高清"), "http://ivi.bupt.edu.cn/hls/lyhd.m3u8"},
	{QStringLiteral("贵州卫视高清"), "http://ivi.bupt.edu.cn/hls/gzhd.m3u8"},
	{QStringLiteral("CCTV-1综合"), "http://ivi.bupt.edu.cn/hls/cctv1.m3u8"},
	{QStringLiteral("CCTV-2财经"), "http://ivi.bupt.edu.cn/hls/cctv2.m3u8"},
	{QStringLiteral("CCTV-3综艺"), "http://ivi.bupt.edu.cn/hls/cctv3.m3u8"},
	{QStringLiteral("CCTV-4中文国际"), "http://ivi.bupt.edu.cn/hls/cctv4.m3u8"},
	{QStringLiteral("CCTV-7国防军事"), "http://ivi.bupt.edu.cn/hls/cctv7.m3u8"},
	{QStringLiteral("CCTV-8电视剧"), "http://ivi.bupt.edu.cn/hls/cctv8.m3u8"},
	{QStringLiteral("CCTV-9纪录"), "http://ivi.bupt.edu.cn/hls/cctv9.m3u8"}

};



TvStationInfo::TvStationInfo()
{
	this->currentState = this->Idle;
}

void TvStationInfo::setTvStationInfo(QString tvName, QString tvUrl)
{
	this->setText(tvName);

	this->currentState = this->Idle;
	this->tvName = tvName;
	this->tvUrl = tvUrl;
}

TvStationInfo::~TvStationInfo()
{
}
