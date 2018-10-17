cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME CmakeTest) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта
set (Vector Vector)
set (Vectorlib Vectorlib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

add_subdirectory(Vector) #Собираем проект в поддиректории lib1
add_subdirectory(Vectorlib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Vectorlib)