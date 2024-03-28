#pragma once

namespace lvgl {

class OnClickListener {
public:
  virtual void onClick() = 0;
};

class OnLongPressListener {
public:
  virtual void onLongPress() = 0;
};

} // namespace lvgl