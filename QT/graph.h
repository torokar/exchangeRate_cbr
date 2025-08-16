// #ifndef GRAPH_H
// #define GRAPH_H

// #include <QDialog>
// #include <QGraphicsItem>
// #include <QPen>
// #include <QPainter>
// #include "GraphicsPlotLegend.h"
// #include "Global.h"
// #include "GraphicsPlotLegend.h"
// #include "GraphicsPlotItem.h"
// #include "GraphicsDataItem.h"

// namespace Ui
// {
// class Graph : public QGraphicsItem
// {
// public:
//     GraphicsPlotNocksTube(QGraphicsItem *parent): QGraphicsItem(parent){}
//     void updateNocks(const QList<QGraphicsSimpleTextItem*>& nocks);
//     QRectF boundingRect()const {return m_boundRect;}
//     void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *){}
//     inline const QFont &font(){return m_NocksFont;}
// private:
//     QList<QGraphicsSimpleTextItem*> m_nocks;
//     QFont m_NocksFont;
//     QPen m_nockPen;
//     QRectF m_boundRect;
// };

// class Graphics2DPlotGrid: public QGraphicsItem
// {
// public:
//     Graphics2DPlotGrid(QGraphicsItem * parent);
//     QRectF boundingRect() const;
//     const QRectF & rect() const;
//     void setRange(int axisNumber, double min, double max);

//     void setMainGrid(int axisNumber, double zero, double step);
//     void setSecondaryGrid(int axisNumber, double zero, double step);
//     void setMainGridPen(const QPen & pen);
//     void setSecondaryGridPen(const QPen &pen);
//     inline QPen mainGridPen(){return m_mainPen;}
//     inline QPen secondaryGridPen(){return m_secondaryPen;}

//     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
// public:
//     struct AxisGuideLines {
//         AxisGuideLines(): showLines(true){}
//         QVector<QLineF> lines;
//         bool showLines;
//     };
//     AxisGuideLines abscissMainLines;
//     AxisGuideLines abscissSecondaryLines;
//     AxisGuideLines ordinateMainLines;
//     AxisGuideLines ordinateSecondaryLines;
// private:

//     void paintAxeGuidLines(const AxisGuideLines& axe, QPainter *painter, const QPen &linePen);

//     QPen m_mainPen;
//     QPen m_secondaryPen;

//     QRectF m_rect;
// };
// void Graphics2DPlotGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// {
//     Q_UNUSED(option)
//     Q_UNUSED(widget)
//     paintAxeGuidLines(abscissSecondaryLines, painter, m_secondaryPen);
//     paintAxeGuidLines(abscissMainLines, painter, m_mainPen);
//     paintAxeGuidLines(ordinateSecondaryLines, painter, m_secondaryPen);
//     paintAxeGuidLines(ordinateMainLines, painter, m_mainPen);
//     painter->setPen(m_mainPen);
//     painter->drawRect(m_rect);
// }

// class GraphicsPlotItemPrivate
// {
//     Q_DECLARE_PUBLIC(GraphicsPlotItem)
//     GraphicsPlotItem* q_ptr;

//     GraphicsPlotItemPrivate(GraphicsPlotItem* parent);
//     void compose();
//     void calculateAndSetTransForm();
//     void autoSetRange();
//     void autoSetGrid();
//     void calculateOrdinateGrid();
//     void calculateAbscissGrid();
//     void setAxisRange(int axisNumber, double min, double max);

//     Graphics2DPlotGrid * gridItem;
//     QGraphicsSimpleTextItem * abscissText;
//     QGraphicsSimpleTextItem * ordinateText;
//     QGraphicsSimpleTextItem *titleText;
//     QFont titleFont;
//     QFont ordinaateFont;
//     QFont abscissFont;

//     QRectF rect;
//     QRectF m_sceneDataRect;
//     GraphicsPlotLegend *m_legend;
//     GraphicsPlotNocksTube* ordinateMainNocks;
//     GraphicsPlotNocksTube* ordinateSecondaryNocks;
//     GraphicsPlotNocksTube* abscissSecondaryNocks;
//     GraphicsPlotNocksTube* abscissMainNocks;

//     struct Range{
//         double min;
//         double max;
//     };
//     struct AxisGuideLines {
//         AxisGuideLines():baseValue(0.0), step(0.0){}
//         double baseValue;
//         double step;
//     };
//     AxisGuideLines abscissMainLines;
//     AxisGuideLines abscissSecondaryLines;
//     AxisGuideLines ordinateMainLines;
//     AxisGuideLines ordinateSecondaryLines;

//     Range abscissRange;
//     Range ordinateRange;
//     bool isAutoGrid;
//     bool isAutoSecondaryGrid;

// public:
//     void range(int axisNumber, double *min, double *max);
// };
// }
// #endif // GRAPH_H
