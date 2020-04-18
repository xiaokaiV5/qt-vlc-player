# vlc 相关配置
win32 {
    INCLUDEPATH += $$PWD/../vlc-3.0.8/sdk/include
    LIBS += -L$$PWD/../vlc-3.0.8/sdk/lib -llibvlc -llibvlccore
} else {
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -lvlc -lvlccore
}
