/***************************************************************************
 *   Copyright (C) 2007 by Jean-Baptiste Mardelle (jb@kdenlive.org)        *
 *               2014 by Jean-Nicolas Artaud (jeannicolasartaud@gmail.com) *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/

#ifndef VIDEOGLWIDGET_H
#define VIDEOGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class VideoGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit VideoGLWidget(QWidget *parent = 0);
    ~VideoGLWidget();
    void activateMonitor();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void setBackgroundColor(const QColor &color) {
        m_backgroundColor = color;
    }

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void resizeEvent(QResizeEvent* event);
    void paintGL();
    void mouseDoubleClickEvent(QMouseEvent * event);

private:
    int x, y, w, h;
    int m_image_width, m_image_height;
    GLuint m_texture;
    double m_display_ratio;
    QColor m_backgroundColor;
    Qt::WindowFlags m_baseFlags;
};

#endif
