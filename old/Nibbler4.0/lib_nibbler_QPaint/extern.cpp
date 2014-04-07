#include "Canvas.hpp"

# if defined(__GNUG__)
# define EXPORT /*Nothing to do here*/
#elif defined(_MSC_VER)
# define EXPORT __declspec(dllexport)
# else
#  error G++ or MS compiler required
#endif

extern "C"
{
  typedef std::deque<QPoint> SnakeBody;

  EXPORT Canvas   *newCanvas(QWidget &parent, const QPoint &pos, const QSize &size, const QPoint &head, const SnakeBody &body, const Direction &dir, const bool &die, char **&land, uint width, uint height, uint unit) {
    return new Canvas(parent, pos, size, head, body, dir, die, land, width, height, unit);
  };
  EXPORT void     showCanvas(Canvas *canvas) { canvas->show(); };
}
