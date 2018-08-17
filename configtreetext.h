/*
CoreInfo give's a file's detail informations.

CoreInfo is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef CONFIGTREETEXT_H
#define CONFIGTREETEXT_H

#include <QVector>
#include <QString>
#include <QStringList>
#include <QSettings>
#include <QComboBox>
#include <QDebug>


class ConfigTreeText
{
public:
    static ConfigTreeText* getConfigTreeText();
    static ConfigTreeText* get(int i);
    static int getNbConfigTreeTexts();
    static int getIndex();
    static void setDefault(int i);
    static ConfigTreeText* add(QString name);
    static void load(QSettings* settings);
    static void save(QSettings* settings);
    static void remove(int i);
    static void removeLast();

    static void fillComboBox(QComboBox* qcb);

    QString getName();
    void setName(QString n);
    QList<QStringList> getFields();
    QStringList getFields(int i);
    void setFields(int i, QStringList fs);
    void addField(int i, QString f);
    void removeField(int i, QString f);

private:
    ConfigTreeText(QString name);
    QString name;
    QList<QStringList> fields;

    static QVector<ConfigTreeText*> configs;
    static QStringList names;
    static int indexDefault;
};

#endif // CONFIGTREETEXT_H
