
先在https://github.com/lizhi0755/下创建项目：pro_acload

打开git bash命令行，执行下面的命令：

# 进入你的项目目录
# cd /path/to/your/project
cd /H/cases/projects/pro_acload/sources

# 初始化 Git（如果尚未初始化）
git init

# 添加远程仓库
git remote add origin https://github.com/lizhi0755/pro_acload.git

# 如果远程仓库的README.MD 不在本地仓库，需先拉去远程仓库，与本地仓库合并
git pull origin main --rebase

# 添加所有文件
git add .

# 提交更改
git commit -m "Initial commit"

# 推送到 GitHub（如果 main 分支不存在，可能需要使用 -u 选项）
git branch -M main
git push -u origin main





项目跟目录
├──documents                         # 项目文档（比如需求文档）
├──installs                          # 安装目录
├──sources		    	        # 源代码根目录
│   ├── CMakeLists.txt              # 主 CMake 配置文件，定义项目全局设置（编译标准、模块加载、跨平台检测）
│   ├── cmake                       # 自定义 CMake 模块目录（封装通用构建逻辑，如宏定义、函数封装）
│   │   ├── macros                 # 自定义 CMake 宏（如快速添加 QML 模块、处理第三方库）
│   │   │   └── qml_module.cmake
│   │   └── find_third_party.cmake # 第三方库查找脚本（统一管理 fmt、json 等库的查找逻辑）
│   ├── config                      # 平台特定配置目录（按平台细分编译选项、资源路径、系统依赖）
│   │   ├── windows                # Windows 平台专属配置
│   │   │   ├── CMakeLists.txt    # Windows 特有的编译选项（预定义宏、图标资源、清单文件配置）
│   │   │   └── manifest.xml      # 应用程序清单（定义 Windows 程序图标、权限等）
│   │   ├── linux                  # Linux 平台专属配置
│   │   │   ├── CMakeLists.txt    # Linux 特有的编译选项（系统库链接、桌面文件配置）
│   │   │   └── app.desktop       # 桌面快捷方式配置文件
│   │   └── macos                  # macOS 平台专属配置
│   │        ├── CMakeLists.txt    # macOS 特有的编译选项（.app 包配置、框架链接）
│   │        └── info.plist        # macOS 应用信息清单（版本、图标、权限等）
│   ├── common                      # 公共模块目录（可复用的核心功能模块，供多个 App 共享）
│   │   ├── module1                # 公共模块 1（如网络请求模块、数据解析模块）
│   │   │   ├── include           # 模块对外公开头文件（仅暴露接口，命名空间隔离，如 Module1/PublicClass.h）
│   │   │   ├── src               # 模块实现代码（内部头文件和源文件，不对外公开）
│   │   │   ├── qml               # 模块专属 QML 组件/模型（可被其他模块或 App 引用）
│   │   │   ├── translations      # 模块级翻译文件（.ts 格式，支持多语言）
│   │   │   └── CMakeLists.txt    # 模块编译配置（生成静态库/动态库，导出 QML 模块）
│   │   ├── module2                # 公共模块 2（结构同 module1，按需扩展）
│   │   └── resources              # 公共资源目录（全局共享资源，如图标、字体、公共样式表）
│   │        ├── images            # 公共图片资源（如应用图标、加载动画）
│   │        └── fonts             # 公共字体资源（如思源黑体、Roboto）
│   ├── apps                        # 应用模块目录（每个 App 为独立子目录，包含专属业务逻辑）
│   │   ├── app_1                  # 应用模块 1（如主程序、客户端应用）
│   │   │   ├── qml               # App 专属 QML 页面与组件（页面级逻辑，不跨 App 复用）
│   │   │   ├── src               # App 专属 C++ 逻辑（主入口、平台适配代码）
│   │   │   ├── resources         # App 专属资源（如启动画面、配置文件）
│   │   │   ├── translations      # App 级翻译文件（覆盖公共模块翻译或新增文案）
│   │   │   └── CMakeLists.txt    # App 编译配置（链接公共模块，生成可执行文件）
│   │   ├── app_2                  # 应用模块 2（结构同 app1，支持多应用并行开发）
│   │   └── main.cpp               # 公共入口文件（可选，多个 App 可共享启动逻辑）
│   ├── thirdparty                  # 第三方库目录（管理外部依赖，支持本地路径或远程获取）
│   │   ├── fmt                    # fmt 库（示例第三方库，可替换为其他库如 jsoncpp、openssl）
│   │   │   ├── include           # 第三方库头文件
│   │   │   └── lib               # 第三方库二进制文件（.lib/.so/.dylib）
│   │   └── CMakeLists.txt         # 第三方库统一管理脚本（使用 FetchContent 或本地查找）
│   ├── docs                        # 项目文档目录（技术文档、API 说明、使用指南）
│   │   ├── api                    # API 文档（自动生成或手动编写，如 Doxygen 输出）
│   │   └── dev_guide.md           # 开发者指南（项目架构、编码规范、构建流程）
│   ├── tests                       # 测试目录（集中管理单元测试、集成测试、端到端测试）
│   │   ├── unit                   # 单元测试（测试公共模块或 App 内部函数）
│   │   │   └── module1_test.cpp  # 模块 1 单元测试文件
│   │   └── integration            # 集成测试（测试模块间交互、QML 组件功能）
│   │        └── app1_test.cpp     # 应用 1 集成测试文件
│   └── scripts                     # 跨平台脚本目录（自动化构建、打包、代码检查脚本）
│        ├── build                  # 构建相关脚本
│        │   ├── ci_pipeline.sh    # CI 流水线脚本（支持 GitHub Actions/Jenkins）
│        │   └── cmake_format.sh   # CMake 代码格式化脚本
│        └── package.py             # 跨平台打包脚本（生成安装包/压缩包，支持 Windows/Linux/macOS）
└── build                            # 外置构建目录（不纳入版本控制，存放各平台编译产物）
     ├── windows-x64                 # Windows x64 构建结果（自动生成，非手动创建）
     │   ├── bin/                   # 可执行文件（.exe）及依赖动态库（.dll）
     │   ├── lib/                   # 静态库（.lib）/ 模块库文件
     │   ├── tmp/                   # 生成的临时文件
     │   └── resources/             # 平台特定资源（如 Windows 图标、配置文件）
     ├── linux-x64                   # Linux x64 构建结果
     │   ├── bin/                   # 可执行文件（无后缀）
     │   ├── lib/                   # 动态库（.so）/ 静态库（.a）
     │   ├── tmp/                   # 生成的临时文件
     │   └── etc/                   # 系统配置文件（如 .desktop 文件）
     └── macos-arm64                 # macOS arm64 构建结果
          ├── bin/                   # 可执行文件（包含 .app 应用包）
          ├── lib/                   # 动态库（.dylib）
          ├── tmp/                   # 生成的临时文件
          └── resources/             # macOS 资源目录（Info.plist、图标等）

　
　
以下是按照项目目录结构编写的 CMakeLists.txt 系列文件，包含详细注释和模块化配置，严格适配 Qt6 Quick 项目需求：
一、主目录 sources/CMakeLists.txt（核心配置）
cmake
cmake_minimum_required(VERSION 3.21)
project(MyQt6QuickProject VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "Building ${PROJECT_NAME} (Version ${PROJECT_VERSION})")

# ---------------------------
# Qt6 组件查找（核心模块）
# ---------------------------
find_package(Qt6 REQUIRED COMPONENTS
    Quick          # QML 运行时核心
    QuickControls2 # 控件库
    Core           # Qt 核心功能
    LinguistTools  # 翻译工具（支持 .ts 文件处理）
)
qt_standard_project_setup()  # 应用 Qt 标准项目配置（如自动 MOC/UIC/RCC）

# ---------------------------
# 全局编译选项（跨平台）
# ---------------------------
add_compile_options(
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>  # GCC/Clang 严格警告
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /utf-8>            # MSVC 高警告等级 + UTF-8 编码
)

# ---------------------------
# 平台检测与配置加载
# ---------------------------
if(WIN32)
    set(PLATFORM "Windows")
elif(APPLE)
    set(PLATFORM "macOS")
else()
    set(PLATFORM "Linux")
endif()
add_subdirectory(config/${PLATFORM})  # 加载平台专属配置

# ---------------------------
# 子目录添加（模块化构建）
# ---------------------------
add_subdirectory(cmake)       # 自定义 CMake 模块
add_subdirectory(common)      # 公共模块
add_subdirectory(apps)        # 应用模块
add_subdirectory(thirdparty)  # 第三方库
add_subdirectory(tests)       # 测试代码
add_subdirectory(scripts)     # 构建脚本

# ---------------------------
# 输出路径配置（跨平台隔离）
# ---------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PLATFORM}")  # 可执行文件
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${PLATFORM}")  # 动态库
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${PLATFORM}")  # 静态库
二、公共模块目录 sources/common/module1/CMakeLists.txt
cmake
# 模块基础配置（以 module1 为例，其他模块结构一致）
set(MODULE_NAME "module1")
set(MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# ---------------------------
# 源文件收集（C++ + QML + 翻译）
# ---------------------------
file(GLOB_RECURSE MODULE_CXX_SRC "${MODULE_PATH}/src/*.cpp")
file(GLOB_RECURSE MODULE_PUBLIC_HDR "${MODULE_PATH}/include/*.h")  # 对外头文件
file(GLOB_RECURSE MODULE_QML_FILES "${MODULE_PATH}/qml/*.qml")     # QML 组件
file(GLOB_RECURSE MODULE_TRANSLATIONS "${MODULE_PATH}/translations/*.ts")  # 翻译文件

# ---------------------------
# 创建静态库（公共模块通常编译为静态库，便于复用）
# ---------------------------
add_library(${MODULE_NAME} STATIC
    ${MODULE_CXX_SRC}
    ${MODULE_PUBLIC_HDR}  # 头文件参与编译（可选，视模板需求）
)
set_target_properties(${MODULE_NAME} PROPERTIES
    OUTPUT_NAME "${MODULE_NAME}"  # 生成库文件名为 libmodule1.a（Linux）或 module1.lib（Windows）
)

# ---------------------------
# 导出公共接口（头文件 + QML 模块）
# ---------------------------
target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${MODULE_PATH}/include>          # 构建时头文件路径
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>  # 安装时头文件路径（配合 install()）
)

# 注册 QML 模块（URI 需全局唯一，格式：项目名.模块名）
qt6_add_qml_module(MyProject.${MODULE_NAME}
    URI MyProject.${MODULE_NAME}
    VERSION 1.0
    QML_FILES ${MODULE_QML_FILES}
)

# ---------------------------
# 依赖链接（Qt 模块 + 公共依赖）
# ---------------------------
target_link_libraries(${MODULE_NAME} PRIVATE
    Qt6::Quick  # 模块依赖 Qt Quick 核心
    Qt6::Core   # 依赖 Qt 核心模块
)

# ---------------------------
# 翻译文件处理（生成 .qm 文件）
# ---------------------------
qt6_add_translation(MODULE_QM_FILES ${MODULE_TRANSLATIONS})
target_sources(${MODULE_NAME} PRIVATE ${MODULE_QM_FILES})  # 翻译文件加入目标
三、应用模块目录 sources/apps/app_1/CMakeLists.txt
cmake
# 应用模块基础配置（以 app_1 为例）
set(APP_NAME "app_1")
set(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# ---------------------------
# 源文件收集（入口 + QML + 翻译）
# ---------------------------
file(GLOB_RECURSE APP_CXX_SRC "${APP_PATH}/src/*.cpp" "${APP_PATH}/main.cpp")  # 包含主入口
file(GLOB_RECURSE APP_QML_FILES "${APP_PATH}/qml/*.qml")                       # 应用专属 QML 页面
file(GLOB_RECURSE APP_TRANSLATIONS "${APP_PATH}/translations/*.ts")             # 应用级翻译

# ---------------------------
# 创建可执行文件
# ---------------------------
add_executable(${APP_NAME}
    ${APP_CXX_SRC}
    ${APP_QML_FILES}  # QML 文件自动通过 Qt6 资源系统处理
)
set_target_properties(${APP_NAME} PROPERTIES
    OUTPUT_NAME "${APP_NAME}"  # 生成可执行文件名为 app_1（Linux/macOS）或 app_1.exe（Windows）
)

# ---------------------------
# 依赖链接（公共模块 + Qt 控件 + 第三方库）
# ---------------------------
target_link_libraries(${APP_NAME} PRIVATE
    module1              # 链接公共模块 1（假设依赖）
    Qt6::QuickControls2  # 链接 Qt 控件库
    Qt6::Core
    fmt::fmt             # 链接第三方库（如 fmt，需在 thirdparty 中配置）
)

# ---------------------------
# QML 模块与翻译处理
# ---------------------------
# 注册应用专属 QML 模块（URI 包含应用名，避免冲突）
qt6_add_qml_module(MyProject.${APP_NAME}
    URI MyProject.${APP_NAME}
    VERSION 1.0
    QML_FILES ${APP_QML_FILES}
)

# 生成翻译文件（.qm）并添加到目标
qt6_add_translation(APP_QM_FILES ${APP_TRANSLATIONS})
target_sources(${APP_NAME} PRIVATE ${APP_QM_FILES})

# ---------------------------
# 平台特定配置（通过 config/ 目录加载）
# ---------------------------
# 示例：Windows 清单文件或 macOS 应用包配置在对应平台的 CMakeLists.txt 中处理
四、平台配置目录 sources/config/windows/CMakeLists.txt
cmake
# Windows 平台专属配置
message(STATUS "Configuring for Windows platform")

# ---------------------------
# 预定义宏与编译选项
# ---------------------------
add_compile_definitions(
    _WINDOWS  # Windows 特有宏
    UNICODE  # 启用 Unicode 支持
    _UNICODE
)
add_compile_options(/MP)  # 多处理器编译，提升速度

# ---------------------------
# 资源文件处理（如图标、清单）
# ---------------------------
set(WIN_ICON "${CMAKE_CURRENT_SOURCE_DIR}/manifest.xml")  # Windows 应用清单
qt6_add_resources(WIN_RESOURCES "${WIN_ICON}")
target_sources(MyQt6QuickProject PRIVATE ${WIN_RESOURCES})  # 添加到全局资源

# ---------------------------
# 可执行文件属性（如生成 .exe 后缀）
# ---------------------------
set_target_properties(ALL_TARGETS PROPERTIES
    WIN32_EXECUTABLE TRUE  # 生成带 .exe 后缀的可执行文件
)
五、第三方库目录 sources/thirdparty/CMakeLists.txt
cmake
# 第三方库统一管理（以 fmt 库为例）
message(STATUS "Configuring third-party libraries")

# ---------------------------
# 使用 FetchContent 下载 fmt 库（若未本地安装）
# ---------------------------
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 8.1.1
    DOWNLOAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fmt"
)
FetchContent_MakeAvailable(fmt)  # 生成 fmt::fmt 目标

# ---------------------------
# 其他第三方库（如 jsoncpp）类似处理
# ---------------------------
# FetchContent_Declare(jsoncpp ...)
# FetchContent_MakeAvailable(jsoncpp)
六、测试目录 sources/tests/CMakeLists.txt
cmake
# 测试框架配置
enable_testing()
message(STATUS "Configuring tests")

# ---------------------------
# 查找 Google Test（需提前安装或通过 thirdparty 管理）
# ---------------------------
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# ---------------------------
# 收集单元测试文件（以 module1 为例）
# ---------------------------
file(GLOB_RECURSE UNIT_TESTS "unit/*.cpp")
add_executable(UnitTests ${UNIT_TESTS})

# ---------------------------
# 链接测试依赖
# ---------------------------
target_link_libraries(UnitTests PRIVATE
    GTest::gtest
    GTest::gtest_main
    module1  # 测试公共模块 1
)

# ---------------------------
# 注册测试用例
# ---------------------------
add_test(NAME UnitTests COMMAND UnitTests)
set_tests_properties(UnitTests PROPERTIES PASS_REGULAR_EXPRESSION "PASSED")
关键设计说明
模块化隔离：
公共模块（common/）通过静态库封装，应用模块（apps/）仅链接所需库，避免源码直接依赖，提升编译速度。
QML 模块通过 qt6_add_qml_module 注册唯一 URI（如 MyProject.module1），确保跨模块引用时命名空间清晰。
跨平台适配：
平台特定配置（如 Windows 清单、macOS Info.plist）集中在 config/ 目录，通过主 CMake 的 if(WIN32) 条件加载，避免全局污染。
输出路径按 平台/架构 隔离（如 build/windows-x64/bin），确保不同平台产物不冲突。
依赖管理：
第三方库统一通过 FetchContent 或 find_package 管理，thirdparty/CMakeLists.txt 作为依赖入口，避免重复配置。
翻译文件（.ts）通过 qt6_add_translation 自动生成 .qm 文件，无需手动处理。
编译优化：
公共模块编译为静态库（STATIC），减少动态链接依赖，提升发布时的兼容性。
启用严格编译警告（-Wall -Wextra），确保代码质量，早期发现潜在问题。
将以上文件按目录结构放置后，通过以下命令构建项目：
bash
# 外置构建目录（推荐）
mkdir -p ../../build/${PLATFORM} && cd ../../build/${PLATFORM}
cmake ../sources -G "Unix Makefiles"  # Linux/macOS
# 或
cmake ../sources -G "Visual Studio 17 2022" -A x64  # Windows
make -j8  # 编译项目
此配置方案严格遵循 Qt6 官方最佳实践，适用于大型团队协作和持续集成（CI/CD），确保项目可维护性和跨平台兼容性。



























