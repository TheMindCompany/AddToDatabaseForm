#ifndef CARD_H
#define CARD_H

#include "cardui.h"
#include <QSqlQueryModel>
#include <QDataWidgetMapper>

class QDataWidgetMapper;

class Card : public CardUI
{
    Q_OBJECT
public:
    explicit Card(QSqlQueryModel *model, QWidget *parent = 0);

    void setFormMap(QSqlQueryModel *model);

    QDataWidgetMapper *formMap;
};

#endif // CARD_H
