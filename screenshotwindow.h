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

#ifndef SCREENSHOTWINDOW_H
#define SCREENSHOTWINDOW_H

#include <QDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <tpropertyanimation.h>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QClipboard>
#include <QSoundEffect>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QDir>
#include <QFileDialog>
#include <QDateTime>
#include <QRubberBand>
#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

#undef None


namespace Ui {
class screenshotWindow;
}

class screenshotWindow : public QDialog
{
    Q_OBJECT

public:
    explicit screenshotWindow(QWidget *parent = 0);
    ~screenshotWindow();

public slots:
    void show();

    void close();

private slots:
    void on_discardButton_clicked();

    void on_copyButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::screenshotWindow *ui;

    QPixmap screenshotPixmap;
    QPixmap savePixmap;
    QRubberBand* band;
    QPoint bandOrigin;
    QRectF originalGeometry;

    void paintEvent(QPaintEvent* event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // SCREENSHOTWINDOW_H
