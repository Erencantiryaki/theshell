/****************************************
 *
 *   theShell - Desktop Environment
 *   Copyright (C) 2017 Victor Tran
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * *************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <QProcess>
#include <QSignalMapper>
#include <QDesktopWidget>
#include <QDateTime>
#include <QtDBus/QDBusConnection>
#include <QMessageBox>
#include <QSettings>
#include <QSoundEffect>
#include <QPainter>
#include <QMenu>
#include <QAction>
#include <math.h>
#include "window.h"
#include "menu.h"
#include "notificationdbus.h"
#include "upowerdbus.h"
#include "infopanedropdown.h"
#include "touchkeyboard.h"
#include "systrayicons.h"
#include "fadebutton.h"
#include "FlowLayout/flowlayout.h"
#include "tutorialwindow.h"
#include "audiomanager.h"
#include "taskbarmanager.h"
#include <systemd/sd-login.h>
#include <systemd/sd-daemon.h>
#include "locationservices.h"

class Menu;

class InfoPaneDropdown;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry)

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setGeometry(int x, int y, int w, int h);
    void setGeometry(QRect geometry);
    InfoPaneDropdown* getInfoPane();
    void show();

    bool isMprisAvailable();
    bool isMprisPlaying();
    void nextSong();
    void playPause();
    void play();
    void pause();
    void previousSong();
    QString mprisApp();
    QString songName();
    QString songArtist();
    QString songAlbum();

public slots:
    void openMenu(bool openTotheWave = false, bool startListening = false);

    void doUpdate();

    void updateStruts();

private slots:
    void on_time_clicked();

    void on_date_clicked();

    void on_pushButton_2_clicked();

    void internetLabelChanged(QString text, QIcon icon);

    void on_networkLabel_clicked();

    void on_notifications_clicked();

    void on_batteryLabel_clicked();

    void on_volumeFrame_MouseEnter();

    void on_volumeFrame_MouseExit();

    void on_volumeSlider_sliderMoved(int position);

    void on_volumeSlider_valueChanged(int value);

    void on_brightnessFrame_MouseEnter();

    void on_brightnessFrame_MouseExit();

    void on_brightnessSlider_sliderMoved(int position);

    void on_brightnessSlider_valueChanged(int value);

    void on_volumeSlider_sliderReleased();

    void numNotificationsChanged(int notifications);

    void pullDownGesture();

    void on_pushButton_4_clicked();

    void setTimer(QString timer);

    void setTimerVisible(bool visible);

    void setTimerEnabled(bool enable);

    void on_timerIcon_clicked();

    void on_timer_clicked();

    void DBusNewService(QString name);

    void on_mprisPause_clicked();

    void on_mprisBack_clicked();

    void on_mprisForward_clicked();

    void on_mprisSongName_clicked();

    void ActivateWindow();

    void reloadScreens();

    void on_desktopNext_clicked();

    void on_desktopBack_clicked();

    void on_openMenu_clicked();

    void on_mprisSelection_triggered(QAction *arg1);

    void updateMpris();

    void on_time_dragging(int , int );

    void on_time_mouseReleased();

    void on_date_dragging(int , int );

    void on_date_mouseReleased();

    void on_batteryLabel_dragging(int , int );

    void on_batteryLabel_mouseReleased();

    void on_networkLabel_dragging(int , int );

    void on_networkLabel_mouseReleased();

    void on_notifications_dragging(int , int );

    void on_notifications_mouseReleased();

    void on_actionNone_triggered();

    void on_actionNotifications_triggered();

    void on_actionMute_triggered();

    void updateWindow(WmWindow window);

    void deleteWindow(WmWindow window);

signals:
    void reloadBackgrounds();

private:
    Ui::MainWindow *ui;
    //QList<WmWindow> windowList;
    Menu* gatewayMenu;
    TaskbarManager* taskbarManager;

    QMap<Window, FadeButton*> buttonWindowMap;

    QSettings settings;

    int hideTop = 0;
    bool hiding = false;
    bool lockHide = false;
    int attentionDemandingWindows = 0;
    int oldDesktop = 0;
    Window oldActiveWindow = 0;
    bool borderBlinkOn = true;
    bool warningAnimCreated = false;
    int warningWidth = 0;
    bool forceWindowMove = false;

    QString mprisCurrentAppName = "";
    QStringList mprisDetectedApps;
    QString mprisTitle;
    QString mprisArtist;
    QString mprisAlbum;
    bool mprisPlaying;
    bool pauseMprisMenuUpdate = false;

    void closeEvent(QCloseEvent*);
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

    InfoPaneDropdown *infoPane;

    QGraphicsOpacityEffect* statusBarOpacityEffect;
    bool statusBarVisible = false;
};

#endif // MAINWINDOW_H
