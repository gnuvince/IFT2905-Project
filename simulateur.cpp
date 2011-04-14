/*
 * simulateur.cpp
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

#include "simulateur.h"
#include <QtCore>

QStringList& Simulateur::labels()
{
    static QStringList _labels = QStringList()
            << trUtf8("Arrété") <<
               trUtf8("Temps réel") <<
               trUtf8("1s => 1m") <<
               trUtf8("1s => 10m") <<
               trUtf8("1s => 1h") <<
               trUtf8("1s => 24h");
    return _labels;
}

Simulateur::Simulateur(QObject *parent) :
    QObject(parent), scale(1.0)
{
    begin = QDateTime::currentDateTime();
    offset=0.0;
    startTimer(1000);
    setScale(0);
}

//
// on passe ici quand on tourne le dial de vitesse...
//
void Simulateur::setScale(int scale)
{
    //QString res;

    double num,denum;
    num=denum=1.0;

    switch(scale) {
    case ARRETE:
        num=0;
        break;
    case TEMPS_REEL:
        num=1;
        break;
    case S_MIN:
        num=60;
        break;
    case S_DMIN:
        num=10*60;
        break;
    case S_HEURE:
        num=60*60;
        break;
    case S_JOUR:
        num=24*60*60;
        break;
    }

    this->scale=num/denum;
}

QDateTime Simulateur::getCurrentDateAndTime(bool reset)
{
    QDateTime now = QDateTime::currentDateTime();
    qint64 delta = begin.msecsTo(now);
    QDateTime virtualNow=begin.addMSecs(qRound(delta*scale+offset));

    if( reset ) resetBegin(now);
    return virtualNow;
}

void Simulateur::resetBegin(QDateTime now)
{
    qint64 delta = begin.msecsTo(now);
    offset+=delta*(scale-1);
    begin=now;
}

void Simulateur::timerEvent(QTimerEvent *)
{
    QDateTime virtualNow = getCurrentDateAndTime();
    emit currentDateAndTime(virtualNow);
}


