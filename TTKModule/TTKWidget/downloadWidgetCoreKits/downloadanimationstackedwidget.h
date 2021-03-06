#ifndef DOWNLOADANIMATIONSTACKEDWIDGET_H
#define DOWNLOADANIMATIONSTACKEDWIDGET_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (C) 2015 - 2017 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QPainter>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include "downloadglobaldefine.h"

/*! @brief The class of the statckwidget switch animation.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_WIDGET_EXPORT DownloadAnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    enum AnimationType
    {
        TopToBottom,    /*!< Animation from top to bottom*/
        BottomToTop,    /*!< Animation from bottom to top*/
        LeftToRight,    /*!< Animation from left to right*/
        RightToLeft     /*!< Animation from right to left*/
    };

    /*!
     * Object contsructor.
     */
    explicit DownloadAnimationStackedWidget(QWidget *parent = 0);

    virtual ~DownloadAnimationStackedWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Start to anmiation by index.
     */
    void start(int index);
    /*!
     * Set previoud and current index.
     */
    void setIndex(int previous, int current);
    /*!
     * Set animation start and end pos distance and animation type.
     */
    void setLength(int length, AnimationType type);
    /*!
     * Get previoud index.
     */
    int getPreviousIndex() const;
    /*!
     * Get current index.
     */
    int getCurrentIndex() const;

    /*!
     * Set animation duration.
     */
    void setDuration(int duration);
    /*!
     * Get animation duration.
     */
    int getDuration() const;

private Q_SLOTS:
    /*!
     * Animation value changed.
     */
    void valueChanged(const QVariant &value);
    /*!
     * Animation finished.
     */
    void animationFinished();

protected:
    /*!
     * Override the widget event.
     */
    virtual void paintEvent(QPaintEvent *event) override;
    /*!
     * Render previous widget.
     */
    void renderPreviousWidget(QPainter &painter);
    /*!
     * Render current widget.
     */
    void renderCurrentWidget(QPainter &painter);

    bool m_isAnimating;
    float m_currentValue;
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

};

#endif // DOWNLOADANIMATIONSTACKEDWIDGET_H
