/*
 * geopositiondelegate.cpp
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

#include "geoposition.h"
#include "geopositiondelegate.h"
#include "cartewidget.h"
#include <QtGui>

GeoPositionDelegate::GeoPositionDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QSize GeoPositionDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant data = index.model()->data(index);
    if (qVariantCanConvert<GeoPosition>(data)) {

        GeoPosition pos = qVariantValue<GeoPosition>(data);
        QFontMetrics fm = option.fontMetrics;
        return fm.size(0, pos.toString());
    }
    return QStyledItemDelegate::sizeHint(option,index);
}

void GeoPositionDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant data = index.model()->data(index);
    if (qVariantCanConvert<GeoPosition>(data)) {
        painter->save();

        GeoPosition pos = qVariantValue<GeoPosition>(data);
        painter->drawText(option.rect,pos.toString(),QTextOption(Qt::AlignCenter));

        painter->restore();
    } else
        QStyledItemDelegate::paint(painter,option,index);
}


QWidget* GeoPositionDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant data = index.model()->data(index);
    if (qVariantCanConvert<GeoPosition>(data)) {

        CarteWidget *editor = new CarteWidget(parent);
        connect(editor, SIGNAL(editFinished()), this, SLOT(commitAndSave()));
        return editor;
    } else {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}

void GeoPositionDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QVariant data = index.model()->data(index);
    if (qVariantCanConvert<GeoPosition>(data)) {
        GeoPosition pos = qVariantValue<GeoPosition>(data);
        CarteWidget *carteEditor = qobject_cast<CarteWidget*>(editor);
        if (carteEditor)
            carteEditor->setFlagPosition(pos);
    } else {
        QStyledItemDelegate::setEditorData(editor,index);
    }
}

void GeoPositionDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QVariant data = index.model()->data(index);
    if (qVariantCanConvert<GeoPosition>(data)) {
        CarteWidget *carteEditor = qobject_cast<CarteWidget*>(editor);
        if (carteEditor)
            model->setData(index, qVariantFromValue<GeoPosition>(carteEditor->getFlagPosition()));
    } else {
        QStyledItemDelegate::setModelData(editor,model,index);
    }
}

void GeoPositionDelegate::commitAndSave() {
    CarteWidget *editor = qobject_cast<CarteWidget*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}
