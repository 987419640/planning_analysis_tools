# planning_analysis_tools
# planning_uviz 规划算法可视化界面
planning_uviz 用于规划算法的可视化。目录中主要内容如下：
- base.cc 通过车辆中心生成车辆的polygon
- base.h 基础结构体
- main.cc 构造了主车和2个障碍物，并且让他们沿着x轴方向行驶
  - main中 主线程用于更新车辆位置，子线程用于可视化，在更新数据时，加锁避免数据读写冲突
  - main中 缺少地图相关信息
- planning_uviz 基于qt的可视化代码，具体包括：
  - QPainter的简单集成(见QPainter_wrapper.cc)，支持绘制点、线、多边形、文字等
  - 集成修改了鼠标和键盘的操作，(见uviz_mouse、uviz_keybroad)，支持放大、缩小
  - 集成了计时器类，用于每100毫秒更新一次界面

planning_uviz 整体数据输入来自于结构体uviz_data_t。即数据由主进程copy到uviz_data_t，然后在由planning_uviz模块进行绘制。
planning_uviz目前是作为一个线程显示的，所以能够拿到planning的全部数据，具体显示效果，可以根据实际的需求进行调整。下面是目前显示的内容：

https://github.com/wangxinchd/planning_analysis_tools/assets/49182176/9f7a2912-8f6c-4774-880e-def5524fc271
视频中，绿色表示主车，黑色表示障碍物。显示时主车始终放在视图的中心，具体也可以调整，读者可以自行实现。
