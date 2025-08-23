#include "CPaintWidget.h"
#include <QPainter>
#include <QPainterPath>

CPaintWidget::CPaintWidget(QWidget* p)
	:QWidget(p)
{
	this->setMinimumSize(800, 600);

	m_drawType = DRAW_TYPE::polygon;
}

void CPaintWidget::paintEvent(QPaintEvent* event)
{
	W = this->width();
	H = this->height();

	switch (m_drawType)
	{
	case DRAW_TYPE::point:
		draw_point();
		break;

	case DRAW_TYPE::multipoints:
		draw_multipoints();
		break;

	case DRAW_TYPE::line:
		draw_line();
		break;

	case DRAW_TYPE::arc:
		draw_arc();
		break;

	case DRAW_TYPE::rect:
		draw_rect();
		break;

	case DRAW_TYPE::roundrect:
		draw_roundrect();
		break;

	case DRAW_TYPE::chord:
		draw_chord();
		break;

	case DRAW_TYPE::ellipse:
		draw_ellipse();
		break;

	case DRAW_TYPE::polygon:
		draw_polygon();
		break;

	case DRAW_TYPE::polyline:
		draw_polyline();
		break;

	case DRAW_TYPE::ConvexPloygon:
		draw_ConvexPloygon();
		break;

	case DRAW_TYPE::lines:
		draw_lines();
		break;

	case DRAW_TYPE::path:
		draw_path();
		break;

	case DRAW_TYPE::pie:
		draw_pie();
		break;

	case DRAW_TYPE::image:
		draw_image();
		break;

	case DRAW_TYPE::pixmap:
		draw_pixmap();
		break;

	case DRAW_TYPE::draw_text:
		draw_text();
		break;

	case DRAW_TYPE::draw_erase:
		draw_erase();
		break;

	case DRAW_TYPE::draw_fillpath:
		draw_fillpath();
		break;

	case DRAW_TYPE::draw_fillrect:
		draw_fillrect();
		break;

	default:
		break;
	}
}

void CPaintWidget::draw_point()
{
	QPainter painter(this);
	QPen pen;
	pen.setWidth(10);
	pen.setColor(Qt::red);
	pen.setStyle(Qt::SolidLine);
	painter.setPen(pen);
	painter.drawPoint(QPoint(W / 2, H / 2));
}

void CPaintWidget::draw_multipoints()
{
	QPainter painter(this);
	QPen pen;
	pen.setWidth(10);
	pen.setColor(Qt::blue);
	pen.setStyle(Qt::SolidLine);
	painter.setPen(pen);

	
	QPoint points[] = {
	QPoint(5 * W / 12,H / 4),
	QPoint(3 * W / 4, 5 * H / 12),
	QPoint(2 * W / 4, 5 * H / 12) };
	painter.drawPoints(points, 3);
}

void CPaintWidget::draw_line()
{
	QPainter painter(this);

	//QLine Line(W / 4, H / 4, W / 2, H / 2);
	QLine Line(W / 4, H / 4, W / 2, H / 4);
	painter.drawLine(Line);
}

void CPaintWidget::draw_arc()
{
	QPainter painter(this);
	QRect rect(W / 4, H / 4, W / 2, H / 2);
	int startAngle = 90 * 16;
	int spanAngle = 90 * 16;       
	painter.drawArc(rect, startAngle, spanAngle);
}

void CPaintWidget::draw_rect()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	painter.drawRect(rect);
}

void CPaintWidget::draw_roundrect()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	painter.drawRoundedRect(rect, 20, 20);
}

void CPaintWidget::draw_chord()
{
	QPainter painter(this);
	QRect rect(W / 4, H / 4, W / 2, H / 2);
	int startAngle = 90 * 16;
	int spanAngle = 90 * 16;
	painter.drawChord(rect, startAngle, spanAngle);
}

void CPaintWidget::draw_ellipse()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	painter.drawEllipse(rect);
}

void CPaintWidget::draw_polygon()
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	QPen pen;
	pen.setWidth(10);
	pen.setColor(Qt::red);
	pen.setStyle(Qt::SolidLine);
	pen.setCapStyle(Qt::SquareCap);
	pen.setJoinStyle(Qt::MiterJoin);  
	painter.setPen(pen);

	QBrush brush;
	brush.setColor(Qt::yellow);
	brush.setStyle(Qt::SolidPattern);
	painter.setBrush(brush);

	QPoint points[] = {
	QPoint(5 * W / 12,H / 4),
	QPoint(3 * W / 4,5 * H / 12),
	QPoint(5 * W / 12,3 * H / 4),
	QPoint(2 * W / 4,5 * H / 12) };
	painter.drawPolygon(points, 4);
}

void CPaintWidget::draw_polyline()
{
	QPainter painter(this);

	QPoint points[] = {
	QPoint(5 * W / 12, H / 4),
	QPoint(3 * W / 4, 5 * H / 12),
	QPoint(5 * W / 12, 3 * H / 4),
	QPoint(2 * W / 4, 5 * H / 12) };
	painter.drawPolyline(points, 4);
}

void CPaintWidget::draw_ConvexPloygon()
{
	QPainter painter(this);

	QPoint points[4] = {
		QPoint(5 * W / 12, H / 4),
		QPoint(3 * W / 4, 5 * H / 12),
		QPoint(5 * W / 12, 3 * H / 4),
		QPoint(W / 4, 5 * H / 12) };

	painter.drawConvexPolygon(points, 4);
}

void CPaintWidget::draw_lines()
{
	QPainter painter(this);


	QRect rect(W / 4, H / 4, W / 2, H / 2);
	QVector<QLine> Lines;
	Lines.append(QLine(rect.topLeft(), rect.bottomRight()));
	Lines.append(QLine(rect.topRight(), rect.bottomLeft()));
	Lines.append(QLine(rect.topLeft(), rect.bottomLeft()));
	Lines.append(QLine(rect.topRight(), rect.bottomRight()));
	painter.drawLines(Lines);
}

void CPaintWidget::draw_path()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	QPainterPath path;
	path.addEllipse(rect);
	path.addRect(rect);
	painter.drawPath(path);
}

void CPaintWidget::draw_pie()
{
	QPainter painter(this);
	QRect    rect(W / 4, H / 4, W / 2, H / 2);
	int startAngle = 40 * 16; 
	int spanAngle = 120 * 16; 
	painter.drawPie(rect, startAngle, spanAngle);
}

void CPaintWidget::draw_image()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	QImage image(":/resources/tupian.png");
	painter.drawImage(rect, image);
}

void CPaintWidget::draw_pixmap()
{
	QPainter painter(this);
	QRect    rect(W / 4, H / 4, W / 2, H / 2);
	QPixmap    pixmap(":/resources/tupix.png");
	painter.drawPixmap(rect, pixmap);
}

void CPaintWidget::draw_text()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	QFont font;
	font.setPointSize(30);
	font.setBold(true);
	painter.setFont(font);
	painter.drawText(rect, "Hello,Qt");
}

void CPaintWidget::draw_erase()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	painter.eraseRect(rect);
}

void CPaintWidget::draw_fillpath()
{
	QPainter painter(this);

	QRect rect(W / 4, H / 4, W / 2, H / 2);
	QPainterPath path;
	path.addEllipse(rect);
	path.addRect(rect);
	painter.fillPath(path, Qt::red);
}

void CPaintWidget::draw_fillrect()
{
	QPainter painter(this);
	QRect rect(W / 4, H / 4, W / 2, H / 2);
	painter.fillRect(rect, Qt::green);
}

void CPaintWidget::setDrawType(DRAW_TYPE type)
{
	m_drawType = type;
}
