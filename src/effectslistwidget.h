/***************************************************************************
 *   Copyright (C) 2007 by Jean-Baptiste Mardelle (jb@kdenlive.org)        *
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


#ifndef EFFECTLISTWIDGET_H
#define EFFECTLISTWIDGET_H

#include <KListWidget>
#include "effectslist.h"

class EffectsListWidget : public KListWidget
{
  Q_OBJECT
  
  public:
    EffectsListWidget(EffectsList *audioEffectList, EffectsList *videoEffectList, EffectsList *customEffectList, QWidget *parent=0);
    virtual ~EffectsListWidget();
    QDomElement currentEffect();
    QString currentInfo();
    QDomElement itemEffect(QListWidgetItem *item);

  protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);

  private:
    bool m_dragStarted;
    QPoint m_DragStartPosition;
    EffectsList *m_audioList;
    EffectsList *m_videoList;
    EffectsList *m_customList;
    void initList();

 };

#endif
