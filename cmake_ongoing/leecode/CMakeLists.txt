#build a variable to save the filename that need build 
set(SRC_LIST_LEECODE lc_exer.cpp)
add_compile_options(-std=c++11)
add_library  (leecode ${SRC_LIST_LEECODE})
