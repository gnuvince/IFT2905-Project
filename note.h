/*
 * note.h
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

#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QDateTime>
#include <QVariant>
#include <QStringList>

class NoteModel;

class Note : public QObject
{
    Q_OBJECT    

public:
    enum Colonnes { COL_ID, COL_USAGER, COL_DATE, COL_TYPE, COL_DEST, COL_DESC, COL_PERSO };
    enum Types { TYPE_VEHICULE, TYPE_STATION, TYPE_USAGER, TYPE_RESERVATION, TYPE_PERSO };

public:
    explicit Note(qint64 usager, QDateTime date, int type, qint64 destinataire, QString description, QObject *parent = 0);

    virtual QVariant field(uint column, int role) const;
    virtual bool changeField(uint column, QVariant value);

    qint64 getId() const { return id; }

    qint64 getDestinataire() const { return destinataire; }
    void setDestinataire(qint64 destinataire) { if (destinataire>=0) this->destinataire = destinataire; }

    qint64 getUsager() const { return usager; }
    void setUsager(qint64 usager) { if (usager>=0) this->usager = usager; }

    QDateTime getDate() const { return date; }
    void setDate(const QDateTime &date) { if (date.isValid()>0) this->date = date; }

    int getType() const { return type; }
    void setType(int type) { if (type>=0) this->type = type; }

    QString getDescription() const { return description; }
    void setDescription(const QString &description) { if (!description.isNull()) this->description = description; }

    static uint headerCount();
    static QVariant header(uint column);

private:
    static qint64 idCount;
    qint64 id;

signals:

public slots:

protected:
    qint64 usager;
    qint64 destinataire;
    QDateTime date;
    int type;
    QString description;

    static QStringList& headers();

private:
    friend QDataStream& operator<<(QDataStream& ds, const Note &pos);
    friend QDataStream& operator>>(QDataStream& ds, Note &pos);
    friend QDataStream& operator<<(QDataStream& ds, const NoteModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, NoteModel &pos);
    //pour le déserialisateur seulement ...
    Note(QObject *parent=0) : QObject(parent) {}
    Note(const Note &n);
};

QDataStream& operator<<(QDataStream& ds, const Note &pos);
QDataStream& operator>>(QDataStream& ds, Note &pos);


#endif // NOTE_H
