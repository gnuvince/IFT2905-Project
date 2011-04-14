/*
 * manote.h
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

#ifndef MANOTE_H
#define MANOTE_H

#include <QObject>
#include <QDateTime>
#include <QStringList>
#include "note.h"

class MaNote : public Note
{

public:
    MaNote(qint64 usager, QDateTime date, int type, qint64 destinataire, QString description, qreal value, QObject *parent = 0);

    QVariant field(uint column, int role) const;
    bool changeField(uint column, QVariant value);

private:
    qreal value;
    static const uint offset = 5;

    static QStringList headers;
};

#endif // MANOTE_H
