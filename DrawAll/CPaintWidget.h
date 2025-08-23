#pragma once
#include <QWidget>
#include "drawtype.h"

class CPaintWidget : public QWidget
{
    Q_OBJECT

public:
    CPaintWidget(QWidget* p = nullptr);
    ~CPaintWidget() {}

    void setDrawType(DRAW_TYPE type);

private:
    void paintEvent(QPaintEvent* event) override;

private:
    void draw_point();
    void draw_multipoints();
    void draw_line();
    void draw_arc();
    void draw_rect();
    void draw_roundrect();
    void draw_chord();
    void draw_ellipse();
    void draw_polygon();
    void draw_polyline();
    void draw_ConvexPloygon();
    void draw_lines();
    void draw_path();
    void draw_pie();
    void draw_image();
    void draw_pixmap();
    void draw_text();
    void draw_erase();
    void draw_fillpath();
    void draw_fillrect();

private:
    DRAW_TYPE m_drawType;

    int W = 0;
    int H = 0;
};

