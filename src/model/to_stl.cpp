#include <cstddef>
#include <cstdint>
#include <iostream>

#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

namespace g3d::model{
void to_stl(std::ostream &os, const float *points, size_t count) {
  int t_size = count / 3;
  // std::ostringstream oss{std::ios::binary};
  auto &oss = os;
  char header[80]{};
  oss.write(header, sizeof header);
  oss.write((const char *)&t_size, 4);

  for (int i = 0; i < t_size; i++) {
    auto base = i * 3;
    constexpr auto vec3_bytes = 4 * 3;

    char normal[vec3_bytes]{};
    oss.write(normal, vec3_bytes);

    for (int offset = 0; offset < 3; offset++) {
      oss.write((const char *)(&points[base + offset]), vec3_bytes);
    }

    uint16_t attribute{};
    oss.write((const char *)&attribute, sizeof(attribute));
  }
}
}
