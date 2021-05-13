#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

typedef std::map<std::string, std::string> Map;

void serialize(std::ostream &out, const Map &map) {
  out << map.size();
  for (auto const &p : map) {
    out << p.first << p.second;
  }
}

void deserialize(std::istream &in, Map &map) {
  size_t size = 0;
  in >> size;
  for (size_t i = 0; i != size; ++i) {
    Map::key_type key;
    Map::mapped_type value;
    in >> key >> value;
    map[key] = value;
  }
}

int main(int argc, char *argv[]) {
  Map m;
  m["c"] = "C++";
  m["p"] = "python";
  m["g"] = "golang";

  // serialize
  std::ofstream out("1.bin", std::ios::binary);
  serialize(out, m);
  out.close();

  // deserialize
  Map mm;
  std::ifstream in("1.bin", std::ios::binary);
  deserialize(in, mm);
  in.close();

  // print
  for (auto i : mm) {
    std::cout << i.first << std::endl;
  }
  std::cout << mm.size() << std::endl;

  return 0;
}