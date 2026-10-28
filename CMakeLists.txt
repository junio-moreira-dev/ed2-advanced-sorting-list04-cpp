cmake_minimum_required(VERSION 4.2)
project(ed2_advanced_sorting_list04_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed2_advanced_sorting_list04_cpp main.cpp
#        src/Exer01_MergeSortCountInversions.cpp
#        src/Exer02_StabilityMergeSortVsQuickSort.cpp
#        src/Exer03_QuickSelectLomutoKthLargest.cpp
#        src/Exer04_HoarePartitionParitySort.cpp)

# Executáveis individuais para cada exercício da Lista 04
add_executable(Exer01_MergeSortCountInversions src/Exer01_MergeSortCountInversions.cpp)
add_executable(Exer02_StabilityMergeSortVsQuickSort src/Exer02_StabilityMergeSortVsQuickSort.cpp)
add_executable(Exer03_QuickselectLomutoKthLargest src/Exer03_QuickselectLomutoKthLargest.cpp)
add_executable(Exer04_HoarePartitionParitySort src/Exer04_HoarePartitionParitySort.cpp)

# Se ainda mantiver um main.cpp na raiz, declare-o aqui:
add_executable(main_app main.cpp)
