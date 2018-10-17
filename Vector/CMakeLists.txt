file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h

add_executable(${Vector} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${Vector}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

target_link_libraries(${Vector} ${Vectorlib}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}