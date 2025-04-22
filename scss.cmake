
---

### 🛠️ CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(QRGenPro)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(QRENCODE REQUIRED libqrencode)
pkg_check_modules(PNG REQUIRED libpng)

include_directories(${QRENCODE_INCLUDE_DIRS})
include_directories(${PNG_INCLUDE_DIRS})

link_directories(${QRENCODE_LIBRARY_DIRS})
link_directories(${PNG_LIBRARY_DIRS})

add_executable(QRGenPro src/main.cpp)

target_link_libraries(QRGenPro ${QRENCODE_LIBRARIES} ${PNG_LIBRARIES})
