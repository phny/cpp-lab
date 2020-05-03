template <typename T> struct the_class {
  static int id;
  the_class() { ++id; }
};

// 初始化静态变量
template <typename T> int the_class<T>::id = 0;
