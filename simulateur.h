/*
 * simulateur.h
 * Copyright (C) 2011 Nicolas Martin, Université de Montréal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include <QObject>
#include <QDateTime>

class Simulateur : public QObject
{
    Q_OBJECT

public:
    enum Scale {
        ARRETE,
        TEMPS_REEL,
        S_MIN,
        S_DMIN,
        S_HEURE,
        S_JOUR
    };
    static QStringList& labels();

public:
    explicit Simulateur(QObject *parent = 0);
    QDateTime getCurrentDateAndTime(bool reset=true);
    void resetBegin(QDateTime now);

signals:
    void currentDateAndTime(const QDateTime &date);
    //void currentScale(const QString &scaleStr);


public slots:
    void setScale(int scale);

protected:
    void timerEvent(QTimerEvent *);


private:
    qreal scale;
    qreal offset;
    QDateTime begin;
};

#endif // SIMULATEUR_H
