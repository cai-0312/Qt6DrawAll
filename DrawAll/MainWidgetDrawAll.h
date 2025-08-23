#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <memory>
#include <QTreeView>
#include "CPaintWidget.h"

using namespace std;


class MainWidgetDrawAll : public QWidget
{
    Q_OBJECT

public:
    MainWidgetDrawAll(QWidget* parent = nullptr);
    ~MainWidgetDrawAll();

private:
    void treeView();

private slots:
    void treeViewExpand(const QModelIndex& index);

private:
    QTreeView* m_pLeftTree = nullptr;
    CPaintWidget* m_pPaintWidget = nullptr;
};

#endif // WIDGET_H
