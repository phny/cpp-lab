#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <typeinfo>
#include <unordered_map>
#include <vector>

/// @brief 序列化
template <typename T>
void SerializeToStream(std::ostream &stream, const T &object) {
  stream.write((char *)&object, sizeof(T));
}

/// @brief 反序列化
template <typename T>
void DeserializeFromStream(std::istream &stream, T &object) {
  stream.read((char *)&object, sizeof(T));
}

/// @brief 将 vector 对象序列化到一个流对象
template <typename T>
void SerializeVectorToStream(std::ostream &stream, const std::vector<T> &vec) {
  const int64_t size = vec.size();
  SerializeToStream(stream, size);
  stream.write((char *)&vec[0], size * sizeof(T));
}

/// @brief 从流对象反序列化出 vector
template <typename T>
void DeserializeVectorFromStream(std::istream &stream, std::vector<T> &vec) {
  int64_t size = 0;
  DeserializeFromStream(stream, size);
  vec.resize(size);
  stream.read((char *)&vec[0], size * sizeof(T));
}

/// @brief 将unordered_map序列化到流
template <typename KT, typename VT>
void SerializeUnorderedMapToStream(std::ostream &stream,
                                   const std::unordered_map<KT, VT> &map) {
  typeid(VT) == typeid(std::vector<KT>);
  for (auto i : map) {
    KT k = i.first;
    VT v = i.second;
    // serialize key
    SerializeToStream(stream, k);
    // serialize value
    if (typeid(v) == typeid(std::vector<int64_t>)) {
      SerializeVectorToStream(stream, v);
    } else {
      SerializeToStream(stream, v);
    }
  }
}

/// @brief 从流中反序列化出unordered_map
template <typename KT, typename VT>
void DeserializeUnorderedMapFromStream(std::istream &stream,
                                       std::unordered_map<KT, VT> &map) {
  while (!stream.eof()) {
    // deserialize key
    KT k;
    DeserializeFromStream(stream, k);
    // deserialize value
    VT v;
    if (typeid(v) == typeid(std::vector<int64_t>)) {
      DeserializeVectorFromStream(stream, v);
    } else {
      DeserializeFromStream(stream, v);
    }
    map.insert({k, v});
  }
}

// 具体化模板
// template
// void SerializeUnorderedMapToStream<int64_t,
// std::vector<int64_t>>(std::ostream& stream,
//                             const std::unordered_map<int64_t,
//                             std::vector<int64_t>>& map);

// template
// void SerializeUnorderedMapToStream<int64_t, int64_t>(std::ostream& stream,
//                             const std::unordered_map<int64_t, int64_t>& map);

// template
// void DeserializeUnorderedMapFromStream<int64_t,
// std::vector<int64_t>>(std::istream& stream,
//                             std::unordered_map<int64_t,
//                             std::vector<int64_t>>& map);

// template
// void DeserializeUnorderedMapFromStream<int64_t, int64_t>(std::istream&
// stream,
//                             std::unordered_map<int64_t, int64_t>& map);

// void test1() {
//     std::unordered_map<int64_t, int64_t> map;
//     map.insert({1, 1});
//     map.insert({2, 2});
//     map.insert({3, 3});
//     map.insert({4, 4});
//     map.insert({5, 5});

//     // serialize
//     std::ofstream out("test.bin", std::ios::binary);
//     SerializeUnorderedMapToStream(out, map);
//     out.close();

//     // deserialize
//     std::ifstream in("test.bin", std::ios::binary);
//     std::unordered_map<int64_t, int64_t> newmap;
//     DeserializeUnorderedMapFromStream(in, newmap);
//     in.close();

//     // print
//     for (auto i : newmap) {
//         std::cout <<i.first <<" " << i.second << std::endl;
//     }

// }

void test2() {
  std::unordered_map<int64_t, std::vector<int64_t>> map;
  map.insert({1, {1, 2, 3}});
  map.insert({2, {1, 2, 3}});
  map.insert({3, {1, 2, 3}});
  map.insert({4, {1, 2, 3}});
  map.insert({5, {1, 2, 3}});

  // serialize
  std::ofstream out("test1.bin", std::ios::binary);
  SerializeUnorderedMapToStream<int64_t, std::vector<int64_t>>(out, map);
  out.close();

  // deserialize
  std::ifstream in("test1.bin", std::ios::binary);
  std::unordered_map<int64_t, std::vector<int64_t>> newmap;
  DeserializeUnorderedMapFromStream<int64_t, std::vector<int64_t>>(in, newmap);
  in.close();

  // print
  for (auto i : newmap) {
    std::cout << i.first << ": ";
    for (auto j : i.second) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) { test2(); }