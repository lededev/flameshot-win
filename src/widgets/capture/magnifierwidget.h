#pragma once

#include <QWidget>

class QPropertyAnimation;

class MagnifierWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MagnifierWidget(const QPixmap& p,
                             const QColor& c,
                             bool isSquare,
                             QWidget* parent = nullptr);
    QRgb getRgb() const;

protected:
    void paintEvent(QPaintEvent*) override;

private:
    const int m_magPixels = 10;
    const int m_magOffset = 16;
    const int magZoom = 10;
    const int m_pixels = 2 * m_magPixels + 1;
    const int m_devicePixelRatio = 1;
    const int m_RgbBoxHeight = 60;
    bool m_square;
    QColor m_color;
    QColor m_borderColor;
    QPixmap m_screenshot;
    QPixmap m_paddedScreenshot;
    QRgb m_rgb;
    void drawMagnifier(QPainter& painter);
    void drawMagnifierCircle(QPainter& painter);
};
