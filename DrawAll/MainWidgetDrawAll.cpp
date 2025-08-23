#include "MainWidgetDrawAll.h"
#pragma execution_character_set("utf-8")
#include <QStandardItemModel>
#include <QHBoxLayout>
#include "drawtype.h"

MainWidgetDrawAll::MainWidgetDrawAll(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle(u8"draw all");

    QHBoxLayout* pHLay = new QHBoxLayout(this);
    m_pLeftTree = new QTreeView(this);
    m_pLeftTree->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置不可编辑
    m_pLeftTree->setFixedWidth(300);

    m_pPaintWidget = new CPaintWidget(this);
    pHLay->addWidget(m_pLeftTree);
    pHLay->addWidget(m_pPaintWidget);

    treeView();
}

MainWidgetDrawAll::~MainWidgetDrawAll()
{

}

void MainWidgetDrawAll::treeView()
{
    m_pLeftTree->setFrameShape(QFrame::NoFrame);

    QStandardItemModel* model = new QStandardItemModel(m_pLeftTree);
    model->setHorizontalHeaderLabels(QStringList() << "draw all");

    QStandardItem* pParentItem = NULL;
    QStandardItem* pChildItem = NULL;

    // 点
    pParentItem = new QStandardItem(QIcon(":/resources/point.png"), "draw ponit");
    model->appendRow(pParentItem);

    pChildItem = new QStandardItem(QIcon(":/resources/point.png"), "point");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/multipoints.png"), "multipoints");
    pParentItem->appendRow(pChildItem);

    // 线
    pParentItem = new QStandardItem(QIcon(":/resources/line.png"), "draw line");
    model->appendRow(pParentItem);

    pChildItem = new QStandardItem(QIcon(":/resources/line.png"), "line");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/arc.png"), "arc");
    pParentItem->appendRow(pChildItem);

    // 封闭的图形
    pParentItem = new QStandardItem(QIcon(":/resources/rect.png"), "draw rect");
    model->appendRow(pParentItem);

    pChildItem = new QStandardItem(QIcon(":/resources/rect.png"), "rect");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/roundrect.png"), "roundrect");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/chord.png"), "chord");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/ellipse.png"), "ellipse");
    pParentItem->appendRow(pChildItem);

    // 任意路径绘制
    pParentItem = new QStandardItem(QIcon(":/resources/polygon.png"), "draw polygon");
    model->appendRow(pParentItem);

    pChildItem = new QStandardItem(QIcon(":/resources/polygon.png"), "polygon");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/polyline.png"), "polyline");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/ConvexPloygon.png"), "ConvexPloygon");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/lines.png"), "lines");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/path.png"), "path");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/pie.png"), "pie");
    pParentItem->appendRow(pChildItem);

    // 图片绘制
    pParentItem = new QStandardItem(QIcon(":/resources/image.png"), "draw image");
    model->appendRow(pParentItem);

    pChildItem = new QStandardItem(QIcon(":/resources/image.png"), "image");
    pParentItem->appendRow(pChildItem);

    pChildItem = new QStandardItem(QIcon(":/resources/pixmap.png"), "pixmap");
    pParentItem->appendRow(pChildItem);

    // 文本绘制
    pParentItem = new QStandardItem(QIcon(":/resources/text.png"), "draw text");
    model->appendRow(pParentItem);

    // 擦除
    pParentItem = new QStandardItem(QIcon(":/resources/erase.png"), "draw erase");
    model->appendRow(pParentItem);

    // 路径填充
    pParentItem = new QStandardItem(QIcon(":/resources/fillpath.png"), "draw fillpath");
    model->appendRow(pParentItem);

    // 矩形填充
    pParentItem = new QStandardItem(QIcon(":/resources/fillrect.png"), "draw fillrect");
    model->appendRow(pParentItem);

    m_pLeftTree->setModel(model);

    connect(m_pLeftTree, &QAbstractItemView::clicked, this, &MainWidgetDrawAll::treeViewExpand);
}

void MainWidgetDrawAll::treeViewExpand(const QModelIndex& index)
{
    QString text = index.data().toString();

    if (text.compare("point") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::point);
        m_pPaintWidget->update();  //不更新就不会立即显示
    }
    else if (text.compare("multipoints") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::multipoints);
        m_pPaintWidget->update();
    }
    else if (text.compare("line") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::line);
        m_pPaintWidget->update();
    }
    else if (text.compare("arc") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::arc);
        m_pPaintWidget->update();
    }
    else if (text.compare("rect") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::rect);
        m_pPaintWidget->update();
    }
    else if (text.compare("roundrect") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::roundrect);
        m_pPaintWidget->update();
    }
    else if (text.compare("chord") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::chord);
        m_pPaintWidget->update();
    }
    else if (text.compare("ellipse") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::ellipse);
        m_pPaintWidget->update();
    }
    else if (text.compare("polygon") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::polygon);
        m_pPaintWidget->update();
    }
    else if (text.compare("polyline") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::polyline);
        m_pPaintWidget->update();
    }
    else if (text.compare("ConvexPloygon") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::ConvexPloygon);
        m_pPaintWidget->update();
    }
    else if (text.compare("lines") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::lines);
        m_pPaintWidget->update();
    }
    else if (text.compare("path") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::path);
        m_pPaintWidget->update();
    }
    else if (text.compare("pie") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::pie);
        m_pPaintWidget->update();
    }
    else if (text.compare("image") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::image);
        m_pPaintWidget->update();
    }
    else if (text.compare("pixmap") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::pixmap);
        m_pPaintWidget->update();
    }
    else if (text.compare("draw text") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::draw_text);
        m_pPaintWidget->update();
    }
    else if (text.compare("draw erase") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::draw_erase);
        m_pPaintWidget->update();
    }
    else if (text.compare("draw fillpath") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::draw_fillpath);
        m_pPaintWidget->update();
    }
    else if (text.compare("draw fillrect") == 0)
    {
        m_pPaintWidget->setDrawType(DRAW_TYPE::draw_fillrect);
        m_pPaintWidget->update();
    }
}

